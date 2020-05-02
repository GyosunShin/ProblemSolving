// ���� ����
// 1ST) �� ���� ����Ƚ�� ��������
// 2ND) ������ ũ�� ��������

// ���� ��
// (��, ���� Ƚ��) 

// (1 �� r, c, k �� 100)

// �� �Ǵ� ���� ũ�Ⱑ 100�� �Ѿ�� ��쿡�� ó�� 100���� ������ �������� ������.

// �迭 A�� ����ִ� ���� r, c, k�� �־����� ��, 
// A[r][c] == k�� �Ǳ� ���� �ּ� �ð��� ���غ���. 
// �� ���� 100�� �Ѿ�� ��쿡�� -1�� ����Ѵ�.

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;

int pan[100][100][2];

int rs, cs;

int radix[101];

int solve(){
	int ret = 0;
	int cur_idx = 0;
	int next_idx = 1;
	
	while(true){
		
		if(ret > 100)	break;
		
//		printf("[%d]\n", ret);
//		for(int i = 0 ; i < rs ; ++i){
//			for(int j = 0 ; j < cs ; ++j){
//				printf("%d  ", pan[i][j][cur_idx]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		
		
		if(pan[r][c][cur_idx] == k)	break;
		
		if(rs >= cs){
			int maxsize = 0;
			for(int i = 0 ; i < rs ; ++i){
				memset(radix, 0, sizeof(radix));
				vector<pair<int, int>> tmp;		// <Ƚ��, ����>
				for(int j = 0 ; j < cs ; ++j){
					radix[pan[i][j][cur_idx]]++;
				}
				for(int j = 1 ; j < 101 ; ++j){
					if(radix[j] > 0){
						tmp.push_back(make_pair(radix[j], j));
					}
				}
				sort(tmp.begin(), tmp.end());
				vector<int> ttmp;
				for(int j = 0 ; j < tmp.size() ; ++j){
					if(j >= 100)	break;
					ttmp.push_back(tmp[j].second);
					ttmp.push_back(tmp[j].first);
				}
				int size = (int)ttmp.size();
				if(size >= 100)	size = 100;
				maxsize = max(maxsize, size);
				
				for(int j = 0 ; j < size ; ++j)	pan[i][j][next_idx] = ttmp[j];
			}
			
			cs = maxsize;
		}
		else{
			int maxsize = 0;
			for(int i = 0 ; i < cs ; ++i){
				memset(radix, 0, sizeof(radix));
				vector<pair<int, int>> tmp;		// <Ƚ��, ����>
				for(int j = 0 ; j < rs ; ++j){
					radix[pan[j][i][cur_idx]]++;
				}
				for(int j = 1 ; j < 101 ; ++j){
					if(radix[j] > 0){
						tmp.push_back(make_pair(radix[j], j));
					}
				}
				sort(tmp.begin(), tmp.end());
				vector<int> ttmp;
				for(int j = 0 ; j < tmp.size() ; ++j){
					if(j >= 100)	break;
					ttmp.push_back(tmp[j].second);
					ttmp.push_back(tmp[j].first);
				}
				int size = (int)ttmp.size();
				if(size >= 100)	size = 100;
				maxsize = max(maxsize, size);
				
				for(int j = 0 ; j < size ; ++j)	pan[j][i][next_idx] = ttmp[j];
			}
			
			rs = maxsize;
		}
		
		
		// cur_idx ����
		// About) int pan[100][100][2];
		for(int i = 0 ; i < 100 ; ++i){
			for(int j = 0 ; j < 100 ; ++j){
				pan[i][j][cur_idx] = 0;
			}
		}
		
		int tmp = cur_idx;
		cur_idx = next_idx;
		next_idx = tmp;
		
		ret++;
	}	
	
	return ret;
}

int main(){
	rs = 3;	cs = 3;
	
	scanf("%d %d %d", &r, &c, &k);
	r--;	c--;
	
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			scanf("%d", &pan[i][j][0]);
		}
	}
		
	int ret = solve();
	
	if(ret > 100)	ret = -1;
	printf("%d", ret);

	return 0;	
}





