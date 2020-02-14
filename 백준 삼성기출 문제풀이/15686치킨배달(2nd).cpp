// N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13) 

#include <stdio.h>
#include <algorithm>
#include <vector> 

using namespace std;

struct INFO{
	int r;
	int c;
};

int N, M;
int map[50][50];
vector<INFO> homes;  // 집 위치 담은 벡터 
vector<INFO> chickens;  // 치킨 집 위치 담은 벡터 
vector<INFO> picked;  // 치킨집 위치를 담은 구조체들을 PICK할! 
int ans = 0x7fffffff;  // 최소값을 찾으려면 처음 초기화는 최대값으로!! 

void check(){  // '도시의 치킨 거리의 값' 계산 담당 함수 
	 int tmp_min = 0;
	 
	 // 일단 집 하나 잡고 모든 치킨 집 돌아본다
	 for(int i = 0 ; i < homes.size() ; ++i) {
	 	int tmp = 0x7fffffff;
	 	for(int j = 0 ; j < picked.size() ; ++j){
	 		int ttmp = abs(homes[i].r - picked[j].r) + abs(homes[i].c - picked[j].c);
	 		if(tmp > ttmp){
	 			tmp = ttmp;
	 		}
	 	}
	 	tmp_min += tmp;
	 }
	 
	 if(tmp_min < ans){
	 	ans = tmp_min;
	 }
}


void dfs(int count){
	if(picked.size() == M){
		// TODO : '도시의 치킨 거리의 최솟값' 계산		
		check();
		return;
	}
	
	for(int i = count ; i < chickens.size() ; ++i) {
		picked.push_back(chickens[i]);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N; ++i){
		for(int j = 0 ; j < N; ++j){ 
			scanf("%d", &map[i][j]);    // 0 : 빈칸    1 : 집    2 : 치킨집 
			if(map[i][j] == 2){  // 치킨집 
				INFO tmp;
				tmp.r = i;
				tmp.c = j;
				chickens.push_back(tmp);
			}
			else if(map[i][j] == 1){  // 걍 집
				INFO tmp;
				tmp.r = i;
				tmp.c = j;
				homes.push_back(tmp);
			}			
		}
	}
	
	dfs(0);
	printf("%d", ans);
}
