// nCr (��, ���չ����̴�)
// ���� : ���� �ٸ� n������ ������ ������� �ʰ� ���� �ٸ� r���� �����ϴ� Combination 

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
