// nPr (즉, 순열문제이다)
// 순열 : 서로 다른 n개에서 서로 다른 r개를 일렬로 나열하는 Permutation

#include <iostream>
#include <vector>

using namespace std;

int map[5];
vector<int> picked;
int visited[5];	

int cnt;

void dfs(){
	
	if(picked.size() == 3){
		for(int i = 0 ; i < picked.size() ; ++i){
			cout << picked[i] << " / ";
		}
		cout << endl;
		++cnt;
		return;
	}
	
	for(int i = 0 ; i < sizeof(map) / sizeof(int) ; ++i){
		if(visited[i] == 0){
			picked.push_back(map[i]);
			visited[i] = 1;
			dfs();
			picked.pop_back();
			visited[i] = 0;
		}
	}
}

int main(){
	map[0] = 1;
	map[1] = 2;
	map[2] = 3;
	map[3] = 4;
	map[4] = 5;
	
	dfs();
	
	printf("CNT : %d\n", cnt);
	
	return 0;
}
