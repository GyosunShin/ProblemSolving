// ���� ������ ä�� 100 ��ġ
// OUTPUT : � ��ư�� ���峵���� �־����� ��,
// ä�� N���� �̵��ϱ� ���ؼ� ��ư�� �ּ� �� �� �������ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.  

// INPUT :  N (0 �� N �� 500,000) --> ��ǥä��
// ���峭 ��ư�� ���� M (0 �� M �� 10)  --> �Ϻ� '����'  ��ư�� ����! 


// (Exhaustive Search = Brute-Force Searching = ����Ž��) ��� �̿� 
#include <stdio.h> 
#include <algorithm>

using namespace std;

int ans = 0x7fffffff;

int N, M;
int map[10];

int check(int n){
	int back_up = n;
	int cnt = 0;
	
	if(back_up / 10 == 0){
		int ttmp = back_up % 10;
		if(map[ttmp] == 1){
			return -1;
		}
		else	return 1;
	}
//	printf("N : %d / CNT : %d\n", n, cnt);
	
	while(back_up > 0){
		int ttmp = back_up % 10;
		if(map[ttmp] == 1){
			cnt = -1;
			break;
		}
		back_up /= 10;
		++cnt;
	}
//	if(map[back_up] == 1)	cnt=-1;
//	printf("N : %d / CNT : %d\n", n, cnt);
	return cnt;
}

int main(){
	scanf("%d", &N);  // ��ǥä�� 
	scanf("%d", &M);  
	for(int i = 0 ; i < M ; ++i){
		int tmp;
		scanf("%d", &tmp);
		map[tmp] = 1;
	}
	//###############################
	
	int first = abs(100 - N);
	if(ans > first)	ans = first;
	
	for(int i = 0 ; i < 1000000 ; ++i){
		int tmp_diff;
		int tmp_chk = check(i); 
		if(tmp_chk != -1){    // -1�ȳ����� ��������� ���� �� �ִ� CASE 
			tmp_diff = abs(i - N);
			tmp_diff += tmp_chk;
			if(tmp_diff < ans)	ans = tmp_diff;
		}
		else	continue;
		
//		if(tmp_diff < ans)	ans = tmp_diff;
	}
	
	printf("%d", ans);
	return 0;
}
