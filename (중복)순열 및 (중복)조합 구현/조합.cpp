// nCr (즉, 조합문제이다)
// 조합 : 서로 다른 n개에서 순서를 고려하지 않고 서로 다른 r개를 선택하는 Combination 

#include <iostream>
#include <vector>

using namespace std;

int map[4];
vector<int> picked;

int cnt;

void dfs(int start){
	for(int i = 0 ; i < picked.size() ; ++i){
		cout << picked[i] << " / ";
	}
	cout << endl;
	
	if(picked.size() == 4){
//		for(int i = 0 ; i < picked.size() ; ++i){
//			cout << picked[i] << " / ";
//		}
//		cout << endl;
//		++cnt;
		return;
	}
	
	for(int i = start ; i < sizeof(map) / sizeof(int) ; ++i){
		picked.push_back(map[i]);
		dfs(i+1);
		picked.pop_back();
	}
}

int main(){
	map[0] = 0;
	map[1] = 1;
	map[2] = 2;
	map[3] = 3;
	
	dfs(0);
	
	printf("CNT : %d\n", cnt);
	
	return 0;
}
