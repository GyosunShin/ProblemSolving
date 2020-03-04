// 접수 창구 (1 ~ N) 
// 정비 창구 (1 ~ M) 

//접수 창구의 우선순위는 아래와 같다.
//   ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
//   ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.

//정비 창구의 우선순위는 아래와 같다.
//   ① 먼저 기다리는 고객이 우선한다.  
//   ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
// (priority_queue) 이용했던 창구번호 오름차순 
//   ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M, K, A, B;
int recep[10];
int repair[10];
int arrive[1001];

int recep_write[1001];
int repair_write[1001];

int recep_empty[10];
int repair_empty[10];

int recep_who[10];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq_one;	// (tick, 고객번호)
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, greater<pair<pair<int, int>, int> > > pq_two;

//priority_queue<INFO, vector<INFO>, cmp> pq_two;	// (tick, 접수 창구번호)

void solve(){
	
	int tick = 0;
	
	while(true){
		
		bool break_flag = true;
		for(int i = 1 ; i <= K ; ++i){
			if(recep_write[i] == -1 || repair_write[i] == -1){
				break_flag = false;
				break;
			}
		}
		if(break_flag)	break;
		
		
		// 접수 창고 N개 사용 
		for(int i = 1 ; i <= K ; ++i){
			if(arrive[i] == 0)	pq_one.push(make_pair(tick, i));
			arrive[i]--;
		}
			
		for(int i = 1 ; i <= N ; ++i){
			if(recep_empty[i] < 1){
				if(pq_one.size() > 0){
					int cur = pq_one.top().second;// 고객번호
					pq_one.pop();
					recep_empty[i] = recep[i];
					recep_write[cur] = i;
					recep_who[i] = cur;
//					printf("고객번호 : %d --> 접수창구번호 : %d\n", cur, i);
				}
			}
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(--recep_empty[i] == 0){
				pq_two.push(make_pair(make_pair(tick, i), recep_who[i]));
			}
		}
		
		for(int i = 1 ; i <= M ; ++i){
			if(repair_empty[i] < 1){
				if(pq_two.size() > 0){
					int cur = pq_two.top().second;		pq_two.pop();
					repair_empty[i] = repair[i];
					repair_write[cur] = i;	
//					printf("고객번호 : %d --> 수리 창구번호 : %d\n", cur, i);
				}
			}
		}
		
		for(int i = 1 ; i <= M ; ++i){
			--repair_empty[i];
		}
		
		tick++;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(recep_write, -1, sizeof(recep_write));
		memset(repair_write, -1, sizeof(repair_write));
		memset(recep_empty, 0, sizeof(recep_empty));
		memset(repair_empty, 0, sizeof(repair_empty));
//		while(pq_one.empty())	pq_one.pop();
//		while(pq_two.empty())	pq_two.pop();
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);	
		for(int i = 1 ; i <= N ; ++i)	scanf("%d", &recep[i]);
		for(int i = 1 ; i <= M ; ++i)	scanf("%d", &repair[i]);
		for(int i = 1 ; i <= K ; ++i){
			scanf("%d", &arrive[i]);
		}
		
		solve();
		
		// OUTPUT 
		//지갑을 분실한 고객과 같은 접수 창구와 같은 정비 창구를 이용한 고객의 고객번호들을 찾아 그 합을 출력
		//만약, 그런 고객이 없는 경우 -1을 출력한다. 
		int ans = 0;
		for(int i = 1 ; i <= K ; ++i){
			if(recep_write[i] == A && repair_write[i] == B){
				ans += i;	
			}
		}
		if(ans == 0)	ans = -1;
		printf("#%d %d\n", z, ans);
	}	
	return 0;
}

