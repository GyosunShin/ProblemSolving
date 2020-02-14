// �־��� ������ ī�带 ����Ͽ� ������ ������� �� �� ����� �ִ밡 �Ǵ� ���İ� �ּҰ� �Ǵ� ������ ã��, �� ���� ���̸� ����Ͻÿ�.

// ������ ���� N �� 3 �̻� 12 ������ �����̴�. ( 3 �� N �� 12 )
 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int opands[12];
int opers[4];
vector<int> picked;
int cnt[4];

int mmax = -1 * 0x7fffffff;
int mmin = 0x7fffffff;

void dfs(){
	if(picked.size() == N-1){
		
		for(int i = 0 ; i < picked.size() ; ++i){
			printf("%d  ", picked[i]);
		}
		printf("\n");				
		
		int start = opands[0];
		
		for(int i = 0 ; i < picked.size() ; ++i){
			if(picked[i] == 0){  // +
				start += opands[i+1];
			}
			else if(picked[i] == 1){	// -
				start -= opands[i+1];
			}
			else if(picked[i] == 2){	// *
				start *= opands[i+1];
			}
			else if(picked[i] == 3){	// /
				start /= opands[i+1];
			}
		}		
		
		mmax = max(mmax, start);
		mmin = min(mmin, start);
		
		return;
	}
		
	for(int i = 0 ; i < 4 ; ++i){
		if(cnt[i] < opers[i]){
			picked.push_back(i);
			cnt[i]++;	
			dfs();
			picked.pop_back();
			cnt[i]--;
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		mmax = -1 * 0x7fffffff;
		mmin = 0x7fffffff;
		scanf("%d", &N);	
		for(int i = 0 ; i < 4 ; ++i){
			scanf("%d", &opers[i]);
		}
		for(int i = 0 ; i < N ; ++i){
			scanf("%d", &opands[i]);	
		}
		
		// �ߺ����� ��� 
		dfs();
		
		int ans = mmax - mmin;
		printf("#%d %d\n", z, ans);	
	}
	return 0;
}
