// N(4 ≤ N ≤ 20, N은 짝수)
// 
// OUTPUT : 첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[20][20];

vector<int> picked;

int ans = 0x7fffffff;

void dfs(int cnt, int start){
	if(cnt == (N/2)){
		vector<int> unpicked;
		int pick_index = 0;
		for(int i = 0 ; i < N ; ++i){
			if(picked[pick_index] == i && pick_index < picked.size()){ // 이미 picked에 있을 경우
				++pick_index; 
				continue;
			}
			unpicked.push_back(i);
		}
		
//		printf("PICKED[");
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d ", picked[i]);
//		}
//		printf("]\n");
//		printf("UNPICKED<");
//		for(int i = 0 ; i < Unpicked.size() ; ++i){
//			printf("%d ", Unpicked[i]);
//		}
//		printf(">\n\n");	
		
		int pick_sum = 0;
		int unpick_sum = 0;
		for(int i = 0 ; i < picked.size() - 1 ; ++i)	{
			for(int j = i + 1 ;  j < picked.size() ; ++j){
				pick_sum += map[picked[i]][picked[j]];
				pick_sum += map[picked[j]][picked[i]];
				unpick_sum += map[unpicked[i]][unpicked[j]];
				unpick_sum += map[unpicked[j]][unpicked[i]];				
			}
		}
		
		int tmp_dif = abs(pick_sum - unpick_sum);
		
		if(ans  > tmp_dif)	ans = tmp_dif;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfs(cnt+1, i + 1);
		picked.pop_back();
	}
	
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){	
			scanf("%d", &map[i][j]);
		}
	}
	//###########################
	
	dfs(0, 0);
	printf("%d", ans);
	
}

 
