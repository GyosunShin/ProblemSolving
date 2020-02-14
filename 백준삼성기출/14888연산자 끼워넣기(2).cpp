// ���� ���� N(2 �� N �� 11)
// A1, A2, ..., AN (1 �� Ai �� 100)
// ��° �ٿ��� ���� N-1�� 4���� ������ �־����µ�, ���ʴ�� ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)�� ����

// OUTPUT : �ִ� \n �ּ� 

#include <stdio.h>
#include <vector>

using namespace std;
 
int N;
int map[11];
int opers[4]; // + - * /

int mmin = 0x7fffffff;
int mmax = -1 * mmin;

vector<int> v;


void dfs(){
	if(v.size() == N-1){
		printf("[");
		for(int i = 0 ; i < v.size() ; ++i){
			printf("%d ", v[i]);
		}
		printf("]\n\n");
		int tmp_ret = map[0];
		for(int i = 1 ; i < N ; ++i){
			if(v[i-1] == 0){  // +
				tmp_ret += map[i];
			}
			else if(v[i-1] == 1){  // -
				tmp_ret -= map[i];
			}
			else if(v[i-1] == 2){  // *
				tmp_ret *= map[i];
			}
			else if(v[i-1] == 3){  // /
				tmp_ret /= map[i];
			}									
		}
		
		if(tmp_ret > mmax)	mmax = tmp_ret;
		if(tmp_ret < mmin)	mmin = tmp_ret;
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		if(opers[i] > 0){
			--opers[i];
			v.push_back(i);
			dfs();
			++opers[i];
			v.pop_back();
		}
	}
	
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	for(int i = 0 ; i < 4 ; ++i){
		scanf("%d", &opers[i]);
	}
	//###############################
	
	
	dfs();
	printf("%d\n%d", mmax, mmin);
	return 0;
}


