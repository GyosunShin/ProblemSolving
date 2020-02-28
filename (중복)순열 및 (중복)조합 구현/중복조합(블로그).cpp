// ������ ��Ҹ� ��� �̾Ƶ� �� �� �̿�
// nCr �� ����ó�� �����Ű�Ƚ�� �ϹǷ�  (112) (121) (211) �̷��Ŵ� �ϳ��� ���;� �Ѵ�.

// �̰� �����ϴ°� ���� ������µ� 
// �׳� �ߺ������̶� ������ ���� �Ȱ�����  (112) (121) (211) �̰Ÿ� ���� (112) ������ count�ϰ� ������������ �����ϵ���
// �ϱ� ���� ���Ƿ� ���������̶�� ������ �߰��ؼ� �����ϸ� �ȴ�. 

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
