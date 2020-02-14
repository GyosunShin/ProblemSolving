// r, c, k�� �־�����. (1 �� r, c, k �� 100)
// 1 <= A[i][j] <= 100

// OUTPUT : A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� ������ �ּ� �ð��� ����Ѵ�. �� ���� 100�� �Ѿ�� ��쿡�� -1�� ����Ѵ�.

//  (��, ���� ���� Ƚ��)

#include <stdio.h> 
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int map[100][100];
int size_r = 3;
int size_c = 3;

int ans;

int main(){
	int tmp_r, tmp_c; 
	scanf("%d %d %d", &tmp_r, &tmp_c, &k);
	r = --tmp_r;
	c = --tmp_c;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//##############################
	
	while(1){
		
//		printf("size_r : %d / size_c : %d\n", size_r, size_c);
//		
//		for(int i = 0 ; i < size_r ; ++i) {
//			printf("[");
//			for(int j = 0 ; j < size_c ; ++j){
//				printf("%d ", map[i][j]);
//			}
//			printf("]\n");
//		}
//		printf("\n");
		
		
		// ���� ����! 
		if(map[r][c] == k){
			break;
		}
		
		if(ans > 100){
			ans = -1;
			break;
		}
		
		// �ϴ� R ? C ���� ū�� �����Ѵ�
		int r_c = (size_r >= size_c) ? (1) : (-1);  // 1 : R����, -1 : C���� 
		
		if(r_c == 1){  // R���� 
			int tmp_max = -1 * 0x7fffffff;
			for(int i = 0 ; i < size_r ; ++i){ // �� �ึ�� ���� 
				int cnt[101] = { 0, };  // �� �ึ�� �˾Ƽ� �ʱ�ȭ �Ǿ�.. �� �ึ�� �����ϴ� 100���� �ڿ����� ���� ���� 
				vector<pair<int, int> > v; // <����, ����>
				int tmp_cnt = 0;
				for(int j = 0 ; j < size_c ; ++j){  // ������ ���� ���� count! 
					++cnt[map[i][j]];
				}
				tmp_cnt = 0;
				for(int k = 1 ; k <= 100 ; ++k){
					if(cnt[k] != 0){
						v.push_back(pair<int, int>(cnt[k], k));
						tmp_cnt += 2;
					}	
				}
//				printf("TMP_CNT : %d\n", tmp_cnt);
				sort(v.begin(), v.end());
				if(tmp_max < tmp_cnt)	tmp_max = tmp_cnt;
				
				// ��! ���� map �ٲ����� 
				// �ϴ� �ش� ���� ���� 0���� �ʱ�ȭ
				for(int j = 0 ; j < size_c ; ++j)	map[i][j] = 0;
				for(int j = 0 ; j < v.size() ; ++j){
					map[i][j*2] = v[j].second;	map[i][(j*2) + 1] = v[j].first;
				}
			}
			size_c = tmp_max;
		}
		else if(r_c == -1){  // C���� 
			int tmp_max = -1 * 0x7fffffff;
			for(int i = 0 ; i < size_c ; ++i){ // �� �ึ�� ���� 
				int cnt[101] = { 0, };  // �� �ึ�� �˾Ƽ� �ʱ�ȭ �Ǿ�.. �� �ึ�� �����ϴ� 100���� �ڿ����� ���� ���� 
				vector<pair<int, int> > v; // <����, ����>
				int tmp_cnt = 0;
				for(int j = 0 ; j < size_r ; ++j){  // ������ ���� ���� count! 
					++cnt[map[j][i]];
				}
				tmp_cnt = 0;
				for(int k = 1 ; k <= 100 ; ++k){
					if(cnt[k] != 0){
						v.push_back(pair<int, int>(cnt[k], k));
						tmp_cnt += 2;
					}	
				}
				sort(v.begin(), v.end());
				if(tmp_max < tmp_cnt)	tmp_max = tmp_cnt;
				
				// ��! ���� map �ٲ����� 
				// �ϴ� �ش� ���� ���� 0���� �ʱ�ȭ
				for(int j = 0 ; j < size_r ; ++j)	map[j][i] = 0;
				for(int j = 0 ; j < v.size() ; ++j){
					map[j*2][i] = v[j].second;	map[(j*2) + 1][i] = v[j].first;
				}
			}
			size_r = tmp_max;			
		}
		++ans;
	}
	
	printf("%d", ans);
	return 0;
}

