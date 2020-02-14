// 동일한 요소를 계속 뽑아도 될 때 이용
// nPr 즉 조합처럼 순서신경안써야 하므로  (112) (121) (211) 이런거를 각각 다른케이스로 봐도 됨! 

#include <iostream>
#include <vector>

using namespace std;

int map[5];
vector<int> picked;

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
		picked.push_back(map[i]);
		dfs();
		picked.pop_back();
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
