// nCr (��, ���չ����̴�)
// ���� : ���� �ٸ� n������ ������ ������� �ʰ� ���� �ٸ� r���� �����ϴ� Combination 

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
