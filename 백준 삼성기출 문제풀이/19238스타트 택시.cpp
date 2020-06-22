// �մ� Pick �켱����
// 1st) �ý� ���� ��ġ���� ���� ����� �°� 
// 2nd) �� ��ȣ�� ���� ���� �°�
// 3rd) �� ��ȣ�� ���� ���� �°�

// INPUT
// 2 �� N �� 20		 1 �� M �� N^2		 1 �� �ʱ� ���� �� 500,000

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct GUEST{
	int sr, sc, er, ec;
	int dis;
	bool alive;
};

GUEST guests[400];

int N, M, K;
int pan[20][20];
bool visited[20][20];
int start_r, start_c;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, pair<int, int>>> q;

vector<pair<pair<int, int>, pair<int, int>>> v;

bool comp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b){
	if(a.first.first == b.first.first && a.second.first == b.second.first)	return a.second.second < b.second.second;
	if(a.first.first == b.first.first)	return a.second.first < b.second.first;
	return a.first.first < b.first.first;
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= N || 0 > c || c >= N)	return false;
	return true;
}

int disCal(int sr, int sc, int er, int ec){
	memset(visited, false, sizeof(visited));
	while(!q.empty())	q.pop();
	
	visited[sr][sc] = true;
	q.push(make_pair(0, make_pair(sr, sc)));
	
	int ret = 0;
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;
		int sofar = q.front().first;	q.pop();
		
		if(cur_r == er && cur_c == ec)	return sofar;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			int next_sofar = sofar + 1;
			if(!rangeCheck(next_r, next_c))	continue;
			if(pan[next_r][next_c] == 1 || visited[next_r][next_c])	continue;
			
			visited[next_r][next_c] = true;
			q.push(make_pair(next_sofar, make_pair(next_r, next_c)));
		}
	}
	
	return 0x7fffffff;
}

int solve(){
	
	while(true){
		
		// �ý� ��ġ ~~ �� �°��� ��ġ dis ���
		for(int i = 0 ; i < M ; ++i){
			guests[i].dis = disCal(start_r, start_c, guests[i].sr, guests[i].sc);
		}
		
		v.clear();
		for(int i = 0 ; i < M ; ++i){
			if(guests[i].alive){
				v.push_back(make_pair(make_pair(guests[i].dis, i), make_pair(guests[i].sr, guests[i].sc)));
			}
		}
		
		if(v.empty())	return K;
		
		sort(v.begin(), v.end(), comp);
		
		int targetIdx = v[0].first.second;
		int howlong = v[0].first.first;
		guests[targetIdx].alive = false;
		
		// ��� �°����� �̵� 
		K -= howlong;
		if(K < 0)	return -1;
		
		// �°� �¿�� ���������� �̵�����
		int take = disCal(guests[targetIdx].sr, guests[targetIdx].sc, guests[targetIdx].er, guests[targetIdx].ec);
		K -= take;
		if(K < 0)	return -1;
		
		// ������ ���� ��, ���� ���� 
		K += (take * 2);
		
		// �ý� ���� ��ġ ����
		start_r = guests[targetIdx].er;	start_c = guests[targetIdx].ec;
	}
	
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	// (0 : ��ĭ) 	(1 : ��)
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	// �ý� �ʱ� ��ġ
	scanf("%d %d", &start_r, &start_c);
	start_r--; 	start_c--;
	
	// �� �°��� ������� ��� �� ��ȣ, �׸��� �������� ��� �� ��ȣ
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d %d", &guests[i].sr, &guests[i].sc, &guests[i].er, &guests[i].ec);
		guests[i].sr--;	guests[i].sc--;	guests[i].er--;	guests[i].ec--;
		guests[i].alive = true;
	}
	
	int ret = solve();
	
	// OUTPUT
	// ��� �մ��� �̵���Ű�� ���Ḧ �������� �� ���� ������ ���� ����Ѵ�
	// ��, �̵� ���߿� ���ᰡ �ٴڳ��� ���� ������� �������� �̵��� �� ������ -1�� ���
	// ��� �մ��� �̵���ų �� ���� ��쿡�� -1�� ����Ѵ�.
	printf("%d", ret);
	
	return 0;
}
