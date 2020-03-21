
// 노드들로 구성된 이진트리를 (전위 순회), (후위 순회)한
// 결과를 2차원 배열에 순서대로 담아 return

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct NODE{
	int num;
	int x, y;
	NODE* left;
	NODE* right;
};

vector<vector<int>> answer;
vector<int> pre;
vector<int> post;

vector<pair<pair<int, int>, int>> nodes;	// ( (x,y), 노드번호 )
vector<vector<pair<pair<int, int>, int>>> levels;

NODE root = {0, 0, 0, NULL, NULL};

int max_x = -1;

bool comp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b){
	
	if(a.first.second == b.first.second && a.first.first == b.first.first)	return a.second < b.second;
	if(a.first.second == b.first.second)	return a.first.first < b.first.first;
	return a.first.second > b.first.second;
	
}

void tree(vector<vector<int>>& input){
	
	for(int i = 0 ; i < input.size() ; ++i)	{
		int x = input[i][0];	int y = input[i][1];
		max_x = max(x, max_x);
		nodes.push_back(make_pair(make_pair(x,y), i+1));
	}
	
	sort(nodes.begin(), nodes.end(), comp);
	
	int start_level = nodes[0].first.second;
	vector<pair<pair<int, int>, int>> tmp;
	for(int i = 0 ; i < nodes.size() ; ++i)	{
		
		if(start_level == nodes[i].first.second){
			tmp.push_back(nodes[i]);
		}
		else{
			start_level = nodes[i].first.second;
			levels.push_back(tmp);
			tmp.clear();
			tmp.push_back(nodes[i]);
		}
		
	}
	levels.push_back(tmp);
	
}

void build_tree(int left, NODE* node, int right, int level){
	
	if(level >= levels.size()){
		return;
	}
	
	for(int i = 0 ; i < levels[level].size() ; ++i){
		
		if(left <= levels[level][i].first.first && levels[level][i].first.first < node->x){
			
			NODE* left_child = (NODE*)malloc(sizeof(NODE));
			left_child->num = levels[level][i].second;	left_child->x = levels[level][i].first.first;	left_child->y = levels[level][i].first.second;
			left_child->left = NULL;	left_child->right = NULL;
			node->left = left_child;
			
			build_tree(left, left_child, node->x, level+1);
			
		}
		else if(node->x < levels[level][i].first.first && levels[level][i].first.first <= right){
			
			NODE* right_child = (NODE*)malloc(sizeof(NODE));
			right_child->num = levels[level][i].second;	right_child->x = levels[level][i].first.first;	right_child->y = levels[level][i].first.second;
			right_child->left = NULL;	right_child->right = NULL;
			node->right = right_child;
			
			build_tree(node->x, right_child, right, level+1);
						
		}
		
	}
	
}

void preOrder(NODE* node){		// R l r
	
	pre.push_back(node->num);
		
	if(node->left != NULL){
		preOrder(node->left);
	}
	if(node->right != NULL){
		preOrder(node->right);
	}
	
}

void postOrder(NODE* node){		// l r R
			
	if(node->left != NULL){
		postOrder(node->left);
	}
	if(node->right != NULL){
		postOrder(node->right);
	}
	post.push_back(node->num);
	
}

void construct(){

	root.num = nodes[0].second;
	root.x = nodes[0].first.first;	root.y = nodes[0].first.second;
	
	build_tree(0, &root, max_x, 1);
	
	// 전위 순회(PreOrder)
	preOrder(&root);
	
	// 후위 순회(PostOrder)
	postOrder(&root);	
	
	answer.push_back(pre);
	answer.push_back(post);
	
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    tree(nodeinfo);
    
    construct();
    
    return answer;
    
}

//int main(){
//	
//	vector<vector<int>> tmp({
//		vector<int>	({5,3}),
//		vector<int>	({11, 5}),
//		vector<int>	({13, 3}),
//		vector<int>	({3, 5}),
//		vector<int>	({6, 1}),
//		vector<int>	({1, 3}),
//		vector<int>	({8, 6}),
//		vector<int>	({7, 2}),
//		vector<int>	({2, 2})
//	});
//	
//	solution(tmp);
//	
//}
