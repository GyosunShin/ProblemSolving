// �־��� ������ ī�带 ����Ͽ� ������ ������� �� �� ����� �ִ밡 �Ǵ� ���İ� �ּҰ� �Ǵ� ������ ã��, �� ���� ���̸� ����Ͻÿ�.

// ������ ���� N �� 3 �̻� 12 ������ �����̴�. ( 3 �� N �� 12 )
 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int opands[12];
vector<int> opers;
bool visited[11];
vector<int> picked;

int mmax = -1 * 0x7fffffff;
int mmin = 0x7fffffff;

void dfs(){
	
	if(picked.size() == opers.size()){
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d  ", picked[i]);
//		}
//		printf("\n");		
		
		int start = opands[0];
		for(int i = 0 ; i < picked.size() ; ++i){
			if(opers[picked[i]] == 0){  // +
				start += opands[i+1];
			}
			else if(opers[picked[i]] == 1){	// -
				start -= opands[i+1];
			}
			else if(opers[picked[i]] == 2){	// *
				start *= opands[i+1];
			}
			else if(opers[picked[i]] == 3){	// /
				start /= opands[i+1];
			}
		}
		
		mmax = max(mmax, start);
		mmin = min(mmin, start);
//		printf("START : %d / MAX : %d / MIN : %d\n", start, mmax, mmin);
		
		return;
	}
	
	
	for(int i = 0 ; i < opers.size() ; ++i){
		if(!visited[i]){
			picked.push_back(i);
			visited[i] = true;
			dfs();
			picked.pop_back();
			visited[i] = false;
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		mmax = -1 * 0x7fffffff;
		mmin = 0x7fffffff;
		memset(visited, false, sizeof(visited));
		opers.clear();
		scanf("%d", &N);	
		for(int i = 0 ; i < 4 ; ++i){
			int tmp;
			scanf("%d", &tmp);
			for(int j = 0 ; j < tmp ; ++j)	opers.push_back(i);
		}
		for(int i = 0 ; i < N ; ++i){
			scanf("%d", &opands[i]);	
		}
		
		dfs();
		
		int ans = mmax - mmin;
		printf("#%d %d\n", z, ans);	
	}
	return 0;
}
