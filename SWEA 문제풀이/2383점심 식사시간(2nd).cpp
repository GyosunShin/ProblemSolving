// 계단 입구 도착 후 1분 후 아래칸으로 내려가기 시작 가능
// 계단 위 최대 3명까지만

// OUTPUT : 모든 사람들이 계단을 내려가 이동이 완료되는 시간이 최소가 되는 경우를 찾고,
// 그 때의 소요시간을 출력하는 프로그램을 작성하라. 

// INPUT
// 계단 입구는 무조건 2개 
// (4 ≤ N ≤ 10)	(1 ≤ 사람의 수 ≤ 10)	(2 ≤ 계단의 길이 ≤ 10)
// (1 : 사람), (2 이상 : 계단의 입구)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N;
int pan[10][10];

int ans = 0x7fffffff;

vector<pair<int, int> > people;
vector<pair<int, int> > stairs;

vector<int> mapping;	// mapping[사람 인덱스] = 계단(0 (or) 1)

priority_queue<int, vector<int>, greater<int>> pq0;
priority_queue<int, vector<int>, greater<int>> pq1;

int first_cal(){
	// pq0 가지고 놀기 
	int ret = -1 * 0x7fffffff;
	
	if(pq0.size() == 0)	return 0;
	
	int tmp_ret = 0;
	int tick = 0; 
	int spot[3] = { 0, };
	int prev = pq0.top();
	
	
	while(!pq0.empty()){
		int cur = pq0.top();	pq0.pop();
		tmp_ret = cur;
		int diff = cur - prev;
		diff -= tick;
		for(int i = 0 ; i < 3 ; ++i)	spot[i] = spot[i] - diff;
		prev = cur;
		tick = 0; 
		
		while(true){
			
			bool escape_flag = true;
			for(int i = 0 ; i < 3 ; ++i){
				if(spot[i] <= 0){
					if(tick == 0){
						spot[i] = pan[stairs[0].first][stairs[0].second] + 1;
						tmp_ret++;
					}
					else	spot[i] = pan[stairs[0].first][stairs[0].second];
					escape_flag = false;
					break;
				}
			}
			if(!escape_flag){
				ret = max(ret, tmp_ret);
				break;
			}
			
			for(int i = 0 ; i < 3 ; ++i){
				spot[i]--;
			}
			tmp_ret++;
			tick++;
			
		}
	}
	
//	printf("FIRST : %d\n", tmp_ret + pan[stairs[0].first][stairs[0].second]);
//	ret = max(ret, tmp_ret + pan[stairs[0].first][stairs[0].second]);
	return (ret + pan[stairs[0].first][stairs[0].second]);
	
}

int second_cal(){
	int ret = -1 * 0x7fffffff;
	// pq1 가지고 놀기
	if(pq1.size() == 0)	return 0;
	
	int tmp_ret = 0;
	int tick = 0; 
	int spot[3] = { 0, };
	int prev = pq1.top();
	
	while(!pq1.empty()){
		int cur = pq1.top();	pq1.pop();
		tmp_ret = cur;
		int diff = cur - prev;
		diff -= tick;
		for(int i = 0 ; i < 3 ; ++i)	spot[i] = spot[i] - diff;
		prev = cur;
		tick = 0; 
		while(true){
			bool escape_flag = true;
			for(int i = 0 ; i < 3 ; ++i){
				if(spot[i] <= 0){
					if(tick == 0){
						spot[i] = pan[stairs[1].first][stairs[1].second] + 1;
						tmp_ret++;
					}
					else	spot[i] = pan[stairs[1].first][stairs[1].second];
					escape_flag = false;
					break;
				}
			}
			if(!escape_flag){
				ret = max(ret, tmp_ret);
				break;
			}
			
			for(int i = 0 ; i < 3 ; ++i){
				spot[i]--;
			}
			tmp_ret++;
			tick++;
		}
	}
	
//	printf("SECOND : %d\n", tmp_ret + pan[stairs[1].first][stairs[1].second]);
	return (ret + pan[stairs[1].first][stairs[1].second]);	
	
}

void check(){
	
	int tmp = max(first_cal(), second_cal());
	ans = min(ans, tmp);
//	printf("TMP : %d / ANS : %d\n", tmp, ans);
	
}

void divide(){
	
	if(mapping.size() == people.size()){
		
		for(int i = 0 ; i < mapping.size() ; ++i){
//			printf("%d  ", mapping[i]);
			int dis = abs(stairs[mapping[i]].first - people[i].first) + abs(stairs[mapping[i]].second - people[i].second);
			
			if(mapping[i] == 0){
				pq0.push(dis);
			}
			else if(mapping[i] == 1){
				pq1.push(dis);
			}
			
		}
//		printf("\n");
		
		check();
				
		return;
	}
	
	for(int i = 0 ; i <= 1 ; ++i){
		mapping.push_back(i);
		divide();
		mapping.pop_back();
	}
	
}

void solve(){
	
	// 사람 <-> 계단 Mapping 작업
	divide();
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		people.clear();
		stairs.clear();
		ans = 0x7fffffff;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);	
				if(pan[i][j] == 1)	people.push_back(make_pair(i, j));
				else if(pan[i][j] > 1)	stairs.push_back(make_pair(i, j));
			}
		}
		
		solve();
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}

