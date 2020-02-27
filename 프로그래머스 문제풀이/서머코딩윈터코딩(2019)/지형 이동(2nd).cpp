// 모든 칸을 방문하기 위해 필요한 사다리 설치 비용의 최솟값을 return 

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

vector<vector<int> > pan;
int H;

bool visited[300][300];
int cnt = 1;
int divided[300][300];
int len;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<pair<int, pair<int, int> > > ladders;

struct DisjointSet{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n+1), rank(n+1, 1){
		for(int i = 1 ; i < parent.size() ; ++i)	parent[i] = i;
	}
	
	int find(int input){
		if(parent[input] == input)	return input;
		return parent[input] = find(parent[input]);
//		return parent[input] = find(input);
	}
	
	void merge(int a, int b){
		a = find(a);	b = find(b);
		
		if(a == b)	return;
		
		if(rank[a] > rank[b])	swap(a, b);
		
		parent[a] = b;
		if(rank[a] == rank[b])	++rank[b];
	}
	
};

void bfs(int r, int c){
	
	visited[r][c] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(r,c));
	divided[r][c] = cnt;
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;	q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= len || 0 > next_c || next_c >= len || visited[next_r][next_c] || 
			(abs(pan[cur_r][cur_c] - pan[next_r][next_c]) > H) ) 	continue;
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
			divided[next_r][next_c] = cnt;
		}
		
	}
	
}

void divide(){
	for(int i = 0 ; i < pan.size() ; ++i){
		for(int j = 0 ; j < pan[i].size() ; ++j){
			if(!visited[i][j]){
				bfs(i, j);
				cnt++;
			}
		}
	}
	cnt--;
}

int solution(vector<vector<int> > land, int height) {
	len = land.size();
    pan = land;
    H = height;
    
    divide();
    
    for(int i = 0 ; i < len ; ++i){
		for(int j = 0 ; j < len - 1 ; ++j){
			if(divided[i][j] != divided[i][j+1]){
				int tmp_dis = abs(pan[i][j] - pan[i][j+1]);
				ladders.push_back(make_pair(tmp_dis, make_pair(divided[i][j], divided[i][j+1])));
			}
			if(divided[j][i] != divided[j+1][i]){
				int tmp_dis = abs(pan[j][i] - pan[j+1][i]);
				ladders.push_back(make_pair(tmp_dis, make_pair(divided[j][i], divided[j+1][i])));
			}
		}
    }
    
    sort(ladders.begin(), ladders.end());
//    for(int i =0 ; i < ladders.size() ; ++i){
//    	printf("%d  [%d / %d]\n", ladders[i].first, ladders[i].second.first, ladders[i].second.second);
//	}

	DisjointSet sets(cnt);
	
	int ans = 0;
	
	// 모든 칸을 방문하기 위해 필요한 사다리 설치 비용의 최솟값을 return 
	for(int i = 0 ; i < ladders.size() ; ++i){
		int cost = ladders[i].first;	int src = ladders[i].second.first;	int dst = ladders[i].second.second;
		
		if(sets.find(src) == sets.find(dst))	continue;
		
		ans += cost;
		sets.merge(src, dst);
	}
	
	return ans;
}
