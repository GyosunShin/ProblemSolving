// OUTPUT
// 현재 주어진 상황에서 몇연쇄가 되는지 출력하라. (하나도 터지지 않는다면 0을 출력하면 된다.)

// (. : 빈 공간)
// R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.(모두 대문자로 주어진다.)

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char pan[12][6];
bool visited[12][6];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, int> > q;
vector<pair<int, int> > v;

void pr(){
	printf("\n");
	for(int i = 0 ; i < 12 ; ++i){
		for(int j = 0 ; j < 6 ; ++j){
			printf("%c ", pan[i][j]);
		}
		printf("\n");
	}	
}

void bfs(int start_r, int start_c){
	v.clear();
	while(!q.empty())	q.pop();
	v.push_back(make_pair(start_r, start_c));
	
	q.push(make_pair(start_r, start_c));
	visited[start_r][start_c] = true;
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			
			if(0 > next_r || next_r >= 12 || 0 > next_c || next_c >= 6
			|| visited[next_r][next_c] || pan[cur_r][cur_c] != pan[next_r][next_c])	continue;
			
			q.push(make_pair(next_r, next_c));
			visited[next_r][next_c] = true;
			v.push_back(make_pair(next_r, next_c));
		}
		
	}
	
}

void rebuild(){
	
	for(int i = 0 ; i < 6 ; ++i){
		vector<char> tmp;
		for(int j = 11 ; j >= 0 ; --j){
			if(pan[j][i] != '.')	tmp.push_back(pan[j][i]);
		}
		
		for(int k = 0 ; k < tmp.size() ; ++k){
			pan[11-k][i] = tmp[k];
		}
		for(int k = 11 - (int)tmp.size() ; k >= 0 ; --k){
			pan[k][i] = '.';
		}
	}
	
	
}

int solve(){
	
	int ans = 0;

	while(true){
		memset(visited, false, sizeof(visited));
		int cnt = 0;
	
		for(int i = 0 ; i < 12 ; ++i){
			for(int j = 0 ; j < 6 ; ++j){
				if(pan[i][j] != '.' && !visited[i][j]){
					bfs(i, j);
					if(v.size() < 4){
						continue;
					}
					for(int k = 0 ; k < v.size() ; ++k)	pan[v[k].first][v[k].second] = '.';
					cnt++;
				}
			}
		}
		
		if(cnt == 0)	break;
		ans++;
		rebuild();
//		pr();
	}
	
	return ans;
}

int main(){
	
	for(int i = 0 ; i < 12 ; ++i){
		for(int j = 0 ; j < 6 ; ++j){
			scanf("%1c", &pan[i][j]);
		}
		getchar();
	}
	
//	pr();

	int ret = solve();
	
	printf("%d", ret);
	
	return 0;
}
	
