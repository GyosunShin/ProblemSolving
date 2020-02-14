// T(-1,000,000,000 ≤ T ≤ 1,000,000,000) 
// n(1 ≤ n ≤ 1,000)
// A[1], …, A[n]
// m(1≤m≤1,000)
// B[1], …, B[m]

//  OUTPUT : 첫째 줄에 답을 출력한다. 가능한 경우가 한 가지도 없을 경우에는 0을 출력한다.

#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int T, n, m;

int nmap[1000];
int mmap[1000];

vector<int> npicked;
vector<int> mpicked;

vector<int> nsum;
vector<int> msum;

int ans;


void ndfs(int start){
	int tmp_sum = 0;
	for(int i = start ; i < n ; ++i){
		tmp_sum += nmap[i];
//		printf("[N] TMP_SUM : %d\n",tmp_sum);
		nsum.push_back(tmp_sum);
	}
}

void mdfs(int start){
	int tmp_sum = 0;
	for(int i = start ; i < m ; ++i){
		tmp_sum += mmap[i];
//		printf("[M] TMP_SUM : %d\n",tmp_sum);
		msum.push_back(tmp_sum);
	}	
}

int main(){
	scanf("%d", &T);
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d", &nmap[i]);
	}
	scanf("%d", &m);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d", &mmap[i]);
	}	
	//##################################
	
	for(int i = 0 ; i < n ; ++i){
//		printf("I : %d\n", i);
		ndfs(i);	
	}
	for(int i = 0 ; i < m ; ++i){
//		printf("I : %d\n", i);
		mdfs(i);	
	}
	
	
//	for(int i = 0 ; i < nsum.size() ; ++i){
//		for(int j = 0 ; j < msum.size() ; ++j){
////			printf("nsum : %d / msum : %d\n", nsum[i], msum[j]);
//			if(nsum[i] + msum[j] == T){
//				printf("== T\n");
//				++ans;
//			}
//		}
//	}

	sort(nsum.begin(), nsum.end());
	sort(msum.begin(), msum.end());

	for(int i = 0 ; i < nsum.size() ; ++i){
		int low = lower_bound(msum.begin(), msum.end(), T - nsum[i]) - msum.begin();
		int high = upper_bound(msum.begin(), msum.end(), T - nsum[i]) - msum.begin();
		ans += high - low;
	}
	
	printf("%d", ans);
	
	return 0;
}
