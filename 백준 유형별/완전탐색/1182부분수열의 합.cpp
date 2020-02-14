#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

// (1 �� N �� 20, |S| �� 1,000,000) 
// �־����� ������ ������ 100,000�� ���� �ʴ´�.

using namespace std;
vector<int> vecs;

int main(){
	
	int N;
	cin >> N;
	int S;
	cin >> S;
	for(int i = 0 ; i < N ; ++i){
		int tmp;
		cin >> tmp;
		vecs.push_back(tmp);
	}

	int cnt = 0;
	int sum = 0;
	
	for(int i = 1 ; i < (1 << N) ; ++i){   // i�� vecs�ε����� ��,���� ���� �����ϰ� ���ִ� ����! 
		sum = 0;
		for(int j = 0 ; j < vecs.size() ; ++j){
			if(i & (1 << j)){
				sum += vecs[j];
			}
		}
		if(sum == S)	cnt+=1;
	}

	cout << cnt;
	
}
