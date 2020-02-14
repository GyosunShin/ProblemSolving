// 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.

//  (1 ≤ r, c, k ≤ 100)
// 배열 A (1 <=   <= 100)  

// OUTPUT : A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다. 이 값이 100을 넘어가는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int A[100][100];

int r_len = 3;
int c_len = 3;

int flag;

int ans;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first)	return a.second < b.second;
	else	return a.first < b.first;
}

int main(){
	scanf("%d %d %d", &r, &c, &k);
	for(int i = 0 ; i < 3 ; ++i){
		for(int j= 0 ; j < 3 ; ++j){
			scanf("%d", &A[i][j]);
		}
	}
	--r;	--c;
	//#################################
	
	// R연산 : # 행 >= # 열 
	// C연산 : # 행 < # 열
	
	while(1){
//		printf("size_r : %d / size_c : %d\n", r_len, c_len);
//		
//		for(int i = 0 ; i < r_len ; ++i) {
//			printf("[");
//			for(int j = 0 ; j < c_len ; ++j){
//				printf("%d ", A[i][j]);
//			}
//			printf("]\n");
//		}
//		printf("\n");		
		
		
		// 기저사례 : 탈출조건!
		if(ans > 100){
			ans = -1;
			break;
		}
		if(A[r][c] == k)	break;
		
		flag = (r_len >= c_len) ? 1 : -1;   // R연산 : 1  ||  C연산 : -1
		
		// R연산인 경우 
		if(flag == 1){
			int new_clen = -1 * 0x7fffffff;
			for(int i = 0 ; i < r_len ; ++i){
				vector<pair<int, int> > v;  // <개수, 숫자>
				int cnt[101] = { 0, };
				
				for(int j = 0 ; j < c_len ; ++j){
					++cnt[A[i][j]];
				}
				for(int z = 1 ; z <= 100 ; ++z){
					if(cnt[z] > 0){
						v.push_back(pair<int, int>(cnt[z], z));
					}
				}
				sort(v.begin(), v.end(), compare);
//				printf("[VVV] new_clen : %d   //   V,SIZE() * 2 : %d\n", new_clen , v.size() * 2);
				if(new_clen < ((int)v.size() * 2)){
//					printf("BYUNGHSIN!@@!!@\n");
					new_clen = (v.size() * 2);
				}	
//				printf("[SSS] NEW_CLEN : %d\n", new_clen);
				
				// 이젠 갱신해줘야 할 듯
				for(int z = 0 ; z < c_len ; ++z) {
					A[i][z] = 0;
				}
				for(int z = 0 ; z < v.size() ; ++z) {
					// <숫자, 개수>
					A[i][z*2] =  v[z].second;	A[i][(z*2)+1] =  v[z].first;
				}
			}
			c_len = new_clen;
			++ans;
//			printf("R]ANS : %d\n", ans);
		}
		else if(flag == -1){	// C연산인 경우
			int new_rlen = -1 * 0x7fffffff;
			for(int i = 0 ; i < c_len ; ++i){
				vector<pair<int, int> > v;  // <개수, 숫자>
				int cnt[101] = { 0, };
				
				for(int j = 0 ; j < r_len ; ++j){
					++cnt[A[j][i]];
				}
				for(int z = 1 ; z <= 100 ; ++z){
					if(cnt[z] > 0){
						v.push_back(pair<int, int>(cnt[z], z));
					}
				}
				sort(v.begin(), v.end(), compare);
				if(new_rlen < ((int)v.size() * 2))	new_rlen = (v.size() * 2);
				
				// 이젠 갱신해줘야 할 듯
				for(int z = 0 ; z < r_len ; ++z) {
					A[z][i] = 0;
				}
				for(int z = 0 ; z < v.size() ; ++z) {
					// <숫자, 개수>
					A[z*2][i] =  v[z].second;	A[(z*2)+1][i] =  v[z].first;
				}
			}
			r_len = new_rlen;
			++ans;
//			printf("C]ANS : %d\n", ans);
		}
		
	}
	
	printf("%d", ans);
	return 0;
}






