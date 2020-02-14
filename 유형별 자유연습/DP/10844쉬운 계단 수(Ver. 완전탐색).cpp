#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// �ϴ��� (Ver.����Ž��)

//  OUTPUT : ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.

int N; // 1 <= N <= 100
vector<int> picked;

int ans;

void dfs(){
	if(picked.size() == N){
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d  ", picked[i]);
//		}
//		printf("\n");
		bool tmp_flag = true;
		for(int i = 0 ; i < picked.size() - 1 ; ++i){
			if(abs(picked[i+1] - picked[i]) != 1){
				tmp_flag = false;
				break;
			}
		}
		
		if(tmp_flag)	++ans;

		return;
	}
	
	for(int i = 0 ; i < 10 ; ++i){
		if(picked.size() == 0 && i == 0)	continue;
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
}

int main(){
	scanf("%d", &N);
	
	dfs();
	ans %= 1000000000;
	printf("%d", ans);
	return 0;
}
