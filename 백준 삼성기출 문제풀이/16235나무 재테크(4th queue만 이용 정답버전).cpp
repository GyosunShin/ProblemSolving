// OUTPUT : K년이 지난 후 상도의 땅에 살아있는 나무의 개수

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int A[10][10];
int pan[10][10];

queue<pair<int, pair<int, int> > > pq[2];
queue<pair<int, pair<int, int> > > death;
queue<pair<int, pair<int, int> > > birth;

vector<pair<int, pair<int, int> > > tmp_vec;

const int dr[] = {-1, 1, 0 ,0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

int year, next_year;

void ss(){

	next_year = (year+1) % 2;
	
	// 봄 
	while(!birth.empty()){
		int cur_r = birth.front().second.first;	int cur_c = birth.front().second.second;
		birth.pop();
		if(pan[cur_r][cur_c] < 1){
			death.push(make_pair(1/2, make_pair(cur_r, cur_c)));
			continue;
		}
		pan[cur_r][cur_c] -= 1;
		pq[next_year].push(make_pair(2, make_pair(cur_r, cur_c)));
	}
	while(!pq[year].empty()){
		int cur_r = pq[year].front().second.first;	int cur_c = pq[year].front().second.second;	
		int age = pq[year].front().first;
		
		pq[year].pop();
		if(pan[cur_r][cur_c] < age){
			death.push(make_pair(age/2, make_pair(cur_r, cur_c)));
			continue;
		}
		
		pan[cur_r][cur_c] -= age;
		pq[next_year].push(make_pair(age+1, make_pair(cur_r, cur_c)));
	}
	
	// 여름 
	while(!death.empty()){
		int cur_r = death.front().second.first;	int cur_c = death.front().second.second;	int howmany = death.front().first;
		death.pop();
		pan[cur_r][cur_c] += howmany;
	}
	
	year = next_year;
	
}

void fw(){
	
	next_year = (year + 1) % 2;
	
	// 번식
	while(!pq[year].empty()){
		int cur_r = pq[year].front().second.first;	int cur_c = pq[year].front().second.second;	
		int age = pq[year].front().first;
		pq[year].pop();
		
		pq[next_year].push(make_pair(age, make_pair(cur_r, cur_c)));
		
		if(age % 5 != 0)	continue;
		
		for(int dir = 0 ; dir < 8 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(!(0 > next_r || next_r >= N || 0 > next_c || next_c >= N)){
				birth.push(make_pair(1, make_pair(next_r, next_c)));
			}
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			pan[i][j] += A[i][j];
		}
	}
	
	year = next_year;
	
}

void solve(){
	
	// 봄, 여름 
	ss();
	
	// 가을, 겨울 
	fw();
		
}

int main(){
	
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &A[i][j]);
			pan[i][j] = 5;
		}
	}
	int x, y, z;
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d", &x, &y, &z);
		tmp_vec.push_back(make_pair(z, make_pair(x-1,y-1)));
	}
	sort(tmp_vec.begin(), tmp_vec.end());
	for(int i = 0 ; i < tmp_vec.size() ; ++i)	pq[year].push(make_pair(tmp_vec[i].first, 
	make_pair(tmp_vec[i].second.first, tmp_vec[i].second.second)));
	
	tmp_vec.clear();
	
	for(int z = 1 ; z <= K ; ++z){
		solve();
	}
	
	// ANS : 살아있는 나무의 개수
	int ans = pq[year].size() + birth.size();
	printf("%d", ans);
	
	return 0;
}


