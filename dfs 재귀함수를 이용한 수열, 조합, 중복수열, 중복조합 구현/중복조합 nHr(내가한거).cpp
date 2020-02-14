// nCr (즉, 조합문제이다)
// 조합 : 서로 다른 n개에서 순서를 고려하지 않고 서로 다른 r개를 선택하는 Combination 

#include <iostream>
#include <vector>

using namespace std;

int map[5];
vector<int> picked;

int cnt; 

void dfs(int start){
	if(picked.size() == 3){
		for(int i = 0 ; i < picked.size() ; ++i){
			cout << picked[i] << " / ";
		}
		cout << endl;
		++cnt;
		return;
	}
	
	for(int i = start ; i < sizeof(map) / sizeof(int) ; ++i){
		picked.push_back(map[i]);
		dfs(i);
		picked.pop_back();
	}
}

int main(){
	map[0] = 1;
	map[1] = 2;
	map[2] = 3;
	map[3] = 4;
	map[4] = 5;
	
	
	dfs(0);
	
	printf("CNT : %d\n", cnt);
	
	return 0;
}
