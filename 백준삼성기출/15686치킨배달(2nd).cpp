// N(2 �� N �� 50)�� M(1 �� M �� 13) 

#include <stdio.h>
#include <algorithm>
#include <vector> 

using namespace std;

struct INFO{
	int r;
	int c;
};

int N, M;
int map[50][50];
vector<INFO> homes;  // �� ��ġ ���� ���� 
vector<INFO> chickens;  // ġŲ �� ��ġ ���� ���� 
vector<INFO> picked;  // ġŲ�� ��ġ�� ���� ����ü���� PICK��! 
int ans = 0x7fffffff;  // �ּҰ��� ã������ ó�� �ʱ�ȭ�� �ִ밪����!! 

void check(){  // '������ ġŲ �Ÿ��� ��' ��� ��� �Լ� 
	 int tmp_min = 0;
	 
	 // �ϴ� �� �ϳ� ��� ��� ġŲ �� ���ƺ���
	 for(int i = 0 ; i < homes.size() ; ++i) {
	 	int tmp = 0x7fffffff;
	 	for(int j = 0 ; j < picked.size() ; ++j){
	 		int ttmp = abs(homes[i].r - picked[j].r) + abs(homes[i].c - picked[j].c);
	 		if(tmp > ttmp){
	 			tmp = ttmp;
	 		}
	 	}
	 	tmp_min += tmp;
	 }
	 
	 if(tmp_min < ans){
	 	ans = tmp_min;
	 }
}


void dfs(int count){
	if(picked.size() == M){
		// TODO : '������ ġŲ �Ÿ��� �ּڰ�' ���		
		check();
		return;
	}
	
	for(int i = count ; i < chickens.size() ; ++i) {
		picked.push_back(chickens[i]);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N; ++i){
		for(int j = 0 ; j < N; ++j){ 
			scanf("%d", &map[i][j]);    // 0 : ��ĭ    1 : ��    2 : ġŲ�� 
			if(map[i][j] == 2){  // ġŲ�� 
				INFO tmp;
				tmp.r = i;
				tmp.c = j;
				chickens.push_back(tmp);
			}
			else if(map[i][j] == 1){  // �� ��
				INFO tmp;
				tmp.r = i;
				tmp.c = j;
				homes.push_back(tmp);
			}			
		}
	}
	
	dfs(0);
	printf("%d", ans);
}
