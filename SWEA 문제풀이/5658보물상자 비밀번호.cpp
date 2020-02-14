// (8 ≤ N ≤ 28)
// 0 ~ 9 || A ~ F
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int T;

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		vector<long long> v[4];
		int N, K; //숫자의 개수,N 순서 K 
		scanf("%d %d", &N, &K);
		getchar();
		string str;
		cin >> str;
		
		int leng = str.size();
		int one_len = leng / 4;
		for(int i = 0 ; i < leng ; ++i){
			char tmp = str[i];
			int cur;
			if('0' <= tmp && tmp <= '9'){
				cur = tmp - '0';
			}
			else{
				if(tmp == 'A'){
					cur = 10;
				}
				else if(tmp == 'B'){
					cur = 11;
				}
				else if(tmp == 'C'){
					cur = 12;
				}
				else if(tmp == 'D'){
					cur = 13;
				}
				else if(tmp == 'E'){
					cur = 14;
				}
				else if(tmp == 'F'){
					cur = 15;
				}																
			}
			v[i / one_len].push_back(cur);
		}
		
		set<long long, greater<long long> > s;
		
		// 0 <=    < one_len 만큼만 회전가능
		for(int i = 0 ; i < one_len ; ++i){
			if(i > 0){
				long long backup = v[0][v[0].size() - 1];
				for(int j = v[0].size() - 2 ; j >= 0 ; --j){
					v[0][j+1] = v[0][j];
				}
				v[0][0] = v[3][v[3].size() - 1];
				for(int j = v[3].size() - 2 ; j >= 0 ; --j){
					v[3][j+1] = v[3][j];
				}
				v[3][0] = v[2][v[2].size() - 1];
				for(int j = v[2].size() - 2 ; j >= 0 ; --j){
					v[2][j+1] = v[2][j];
				}
				v[2][0] = v[1][v[1].size() - 1];
				for(int j = v[1].size() - 2 ; j >= 0 ; --j){
					v[1][j+1] = v[1][j];
				}
				v[1][0] = backup;
			}
		
			
			for(int j = 0 ; j < 4 ; ++j){
				long long tttmp = 0;
				for(int k = 0 ; k < v[j].size() ; ++k){
					long long tmp = pow(16, (one_len - 1 - k));
					long long ttmp = v[j][k] * tmp;
					tttmp += ttmp;
				}
				s.insert(tttmp);
			}
			set<long long>::iterator itit;	
//			for(itit = s.begin() ; itit != s.end() ; ++itit)	printf("%lld ", *itit);
//			printf("\n");

		}
		set<long long>::iterator it;
		it = s.begin();
		for(int q = 0 ; q < K-1 ; ++q){
			++it;
		}
		long long tmp_ans = *it;
		
		printf("#%d %lld\n", z, tmp_ans);
	}
	
	return 0;
}

