#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int check(int);
int X[10];  // ���ϱ� ó������ �� 0���� �ʱ�ȭ�ǳ�.. 

// N : ����ϴ� ä��
// M : ���峭 ��ư�� ���� 
int ans, N, M;

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0 ; i < M ; ++i){
		int n;
		scanf("%d", &n);
		X[n] = 1; //���峭 �ֵ� 
	}
	ans = abs(100 - N);
	
	for(int i = 0 ; i <= 1000000 ; ++i){
		// check��� �Լ����� �� �ڸ����� �ش��ϴ� ���ڰ�
		// ���峭 �����̸� 0�� return
		// ���峭 ��ư�� �ƴ϶�� i�� ���� length��ȯ 
		int len = check(i);
		
		// i�� ���峭 ��ư�� �ϳ��� ���� �� ��  
		if(len)
			ans = min(abs(N - i) + len, ans);
		cout << "test : "  << ans << endl;
	}
	cout << ans;
}


int check(int num){  // 0 ~ 1�鸸 ���� üũ�Ѵ�. 
	string s = to_string(num);
	int len = s.length();
	for(int i = 0 ; i < len ; ++i){
		if(X[s[i] - '0']) // ���峭 ��ư�̶�� return 0�Ѵ� 
			return 0;
	}
	return len;
	// �ᱹ ���峭 ��ư�� �ϳ��� ���ٸ� �ƿ� length��ȯ! 
}


