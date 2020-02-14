// ���� ���� ����� ���̴� ���ǿ��� ��ȸ ���� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// (2 �� N �� 16)
// 1 <= �� ����� ���� <= 1,000,000
// �� �� ���� ���� 0�� �־�����.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[16][16];
int cache[16][1 << 16];

int dfs(int start, int track){
	
	if(track == ((1 << N) - 1)){   // ��� city�� �湮���� �� 
		if(map[start][0] == 0)	return 0x7fffffff;
		else	return  map[start][0];
	}
	
	int& ret = cache[start][track];
	if(ret != -1)	return ret;
	
	int tmp = 0x7fffffff;
	
	for(int i = 0 ; i < N ; ++i){
		if(map[start][i] == 0 || (track & (1 << i))){
			continue;
		}
		
		int ttmp = dfs(i, track | (1 << i));
//		printf("START : %d / next : %d / dfsnext : %d\n", start, i, ttmp);
		if(ttmp == 0x7fffffff){
			ttmp = 0x7fffffff;
		}
		else{
			ttmp += map[start][i];
		}
		tmp = min(tmp, ttmp);
	}
	return ret = tmp;
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	
	memset(cache, -1, sizeof(cache));
	
	int ans = dfs(0, 1);
	
	printf("%d", ans);
	
	return 0;
}
