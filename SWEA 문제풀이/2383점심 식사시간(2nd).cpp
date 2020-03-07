// ��� �Ա� ���� �� 1�� �� �Ʒ�ĭ���� �������� ���� ����
// ��� �� �ִ� 3�������

// OUTPUT : ��� ������� ����� ������ �̵��� �Ϸ�Ǵ� �ð��� �ּҰ� �Ǵ� ��츦 ã��,
// �� ���� �ҿ�ð��� ����ϴ� ���α׷��� �ۼ��϶�. 

// INPUT
// ��� �Ա��� ������ 2�� 
// (4 �� N �� 10)	(1 �� ����� �� �� 10)	(2 �� ����� ���� �� 10)
// (1 : ���), (2 �̻� : ����� �Ա�)

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

vector<int> mapping;	// mapping[��� �ε���] = ���(0 (or) 1)

priority_queue<int, vector<int>, greater<int>> pq0;
priority_queue<int, vector<int>, greater<int>> pq1;

int first_cal(){
	// pq0 ������ ��� 
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
	// pq1 ������ ���
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
	
	// ��� <-> ��� Mapping �۾�
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

