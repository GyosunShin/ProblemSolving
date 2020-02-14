// 초기 (1≤N(R)≤50, 1≤M(C)≤50)
// 배양시간 (1≤K≤300)
// 줄기세포 생명력 (1≤X≤10) 

//  OUTPUT : K시간 후 살아있는 줄기 세포(비활성 상태 + 활성 상태)의 총 개수를 구하는 프로그램을 작성하라.

#include <cstdio>
#include <cstring>
#include <queue> 
#include <vector>
#include <algorithm>

using namespace std;
ㄱ 
struct INFO{
	int r, c, power, left;
};
struct cmp{
    bool operator()(const INFO &a, const INFO &b) {
    	// left기준으로 내림차순 정렬 
        return a.power < b.power;  
    }
};

int T, R, C, K; 
int pan[650][650];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

priority_queue<INFO, vector<INFO>, cmp> active[2];
queue<INFO> nonactive[2];

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(pan, 0, sizeof(pan));
		while(!nonactive[0].empty())	nonactive[0].pop();
		while(!nonactive[1].empty())	nonactive[1].pop();
		while(!active[0].empty())	active[0].pop();
		while(!active[1].empty())	active[1].pop();
	
		// (1 ~ 10 : 생명력)  (0 : 빈칸)
		scanf("%d %d %d", &R, &C, &K);
		for(int i = 300 ; i < 300 + R ; ++i){
			for(int j = 300 ; j < 300 + C ; ++j){
				scanf("%d", &pan[i][j]);
				if(pan[i][j] > 0){
					INFO tmp;
					tmp.r = i;	tmp.c = j;	tmp.power = pan[i][j];	tmp.left = pan[i][j];
					nonactive[0].push(tmp);
				}
			}
		}
		
		for(int i = 0 ; i < K ; ++i){
			int now = i % 2;
			int next = (i + 1) % 2;
			
			// active에서 번식 
			while(!active[now].empty()){
				INFO cur = active[now].top();	active[now].pop();
				
				for(int dir = 0 ; dir < 4 ; ++dir){
					int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
					if(pan[next_r][next_c] == 0){
						pan[next_r][next_c] = cur.power;	
						INFO nxt;
						nxt.r = next_r;	nxt.c = next_c;	nxt.left = cur.power;	nxt.power = cur.power;
						nonactive[next].push(nxt);						
					}
				}
				if(cur.left - 1 == 0){   // active --> dead
					pan[cur.r][cur.c] = -1;
				}
				else{
					INFO nxt;
					nxt.r = cur.r;	nxt.c = cur.c;	nxt.left = cur.left - 1;	nxt.power = cur.power;
					active[next].push(nxt);		
				}				
			}
			
			// nonactive에서 active 변이 확인
			while(!nonactive[now].empty()){
				
				INFO cur = nonactive[now].front();	nonactive[now].pop();
								
				if(cur.left - 1 == 0){    // nonactive --> active
					INFO nxt;
					nxt.r = cur.r;	nxt.c = cur.c;	nxt.left = cur.power;	nxt.power = cur.power;
					active[next].push(nxt);
				}
				else{
					INFO nxt;
					nxt.r = cur.r;	nxt.c = cur.c;	nxt.left = cur.left - 1;	nxt.power = cur.power;
					nonactive[next].push(nxt);
				}
			}
			
		}   // K시간 완료 후 
		
		int ans = 0;
		
		for(int i = 0 ; i < 650 ; ++i){
			for(int j = 0 ; j < 650 ; ++j){
				if(pan[i][j] != 0 && pan[i][j] != -1)	++ans;
			}
		}
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
