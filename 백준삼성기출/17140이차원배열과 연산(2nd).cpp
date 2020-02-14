// �� �Ǵ� ���� ũ�Ⱑ 100�� �Ѿ�� ��쿡�� ó�� 100���� ������ �������� ������.

//  (1 �� r, c, k �� 100)
// �迭 A (1 <=   <= 100)  

// OUTPUT : A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� ������ �ּ� �ð��� ����Ѵ�. �� ���� 100�� �Ѿ�� ��쿡�� -1�� ����Ѵ�.

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
	
	// R���� : # �� >= # �� 
	// C���� : # �� < # ��
	
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
		
		
		// ������� : Ż������!
		if(ans > 100){
			ans = -1;
			break;
		}
		if(A[r][c] == k)	break;
		
		flag = (r_len >= c_len) ? 1 : -1;   // R���� : 1  ||  C���� : -1
		
		// R������ ��� 
		if(flag == 1){
			int new_clen = -1 * 0x7fffffff;
			for(int i = 0 ; i < r_len ; ++i){
				vector<pair<int, int> > v;  // <����, ����>
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
				
				// ���� ��������� �� ��
				for(int z = 0 ; z < c_len ; ++z) {
					A[i][z] = 0;
				}
				for(int z = 0 ; z < v.size() ; ++z) {
					// <����, ����>
					A[i][z*2] =  v[z].second;	A[i][(z*2)+1] =  v[z].first;
				}
			}
			c_len = new_clen;
			++ans;
//			printf("R]ANS : %d\n", ans);
		}
		else if(flag == -1){	// C������ ���
			int new_rlen = -1 * 0x7fffffff;
			for(int i = 0 ; i < c_len ; ++i){
				vector<pair<int, int> > v;  // <����, ����>
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
				
				// ���� ��������� �� ��
				for(int z = 0 ; z < r_len ; ++z) {
					A[z][i] = 0;
				}
				for(int z = 0 ; z < v.size() ; ++z) {
					// <����, ����>
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






