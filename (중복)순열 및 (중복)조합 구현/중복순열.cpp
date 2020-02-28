// ������ ��Ҹ� ��� �̾Ƶ� �� �� �̿�
// nPr �� ����ó�� �����Ű�Ƚ�� �ϹǷ�  (112) (121) (211) �̷��Ÿ� ���� �ٸ����̽��� ���� ��! 

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
