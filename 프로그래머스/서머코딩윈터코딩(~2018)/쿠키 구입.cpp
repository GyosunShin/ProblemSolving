// A[l]+..+A[m] = A[m+1]+..+A[r]
// (1 <= l <= m, m+1 <= r <= N)
	
// OUTPUT : �� ���� �Ƶ鿡�� �� �� �ִ� ���� ���� ���� ���� return
// (��, ���ǿ� �°� ���ڸ� ������ �� ���ٸ� 0�� return �մϴ�) 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cache[2001];   // 0 ~ i������ �� 

int ans = -1 * 0x7fffffff;

int solution(vector<int> cookie) {
	int len = cookie.size();
	
	for(int i = 1 ; i <= len ; ++i){
		cache[i] = cache[i-1] + cookie[i-1];
	}
	
	for(int i = 1 ; i < len ; ++i){
		int first = cache[i];
//		cout << "FIRST : " << first << endl;
		
		for(int j = 0 ; j < i ; ++j){
			int first_tmp = first - cache[j];
//			cout << "FIRST_TMP : " << first_tmp << endl;
			if(first_tmp < ans)	continue;
			
			for(int k = i+1 ; k <= len ; ++k){
				int second = cache[k] - first;
//				cout << "SECOND : " << second << endl;
				if(first_tmp == second){
//					cout << "SUCCEED!!!!" << endl;
					if(second < ans)	continue;
					ans = second;
				}
			}
		}
	}
	if(ans == (-1 * 0x7fffffff))	return 0;
	return ans;
}




