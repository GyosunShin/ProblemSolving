// 동일한 요소를 계속 뽑아도 될 때 이용
// nCr 즉 조합처럼 순서신경안써야 하므로  (112) (121) (211) 이런거는 하나만 나와야 한다.

// 이거 구현하는게 제일 어려웠는데 
// 그냥 중복순열이랑 구현은 거의 똑같지만  (112) (121) (211) 이거를 오직 (112) 에서만 count하고 나머지에서는 무시하도록
// 하기 위해 임의로 오름차순이라는 조건을 추가해서 구현하면 된다. 

#include <iostream>
#include <vector>

using namespace std;

int map[5];
vector<int> picked;

void dfs(){
	if(picked.size() == 3){
		for(int i = 0 ; i < picked.size() ; ++i){
			cout << picked[i] << " / ";
		}
		cout << endl;
		return;
	}
	
	for(int i = 0 ; i < sizeof(map) / sizeof(int) ; ++i){
		if(picked.size() == 0 || picked[picked.size() - 1] <= map[i]){
			picked.push_back(map[i]);
			dfs();
			picked.pop_back();
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
	
	return 0;
} 
