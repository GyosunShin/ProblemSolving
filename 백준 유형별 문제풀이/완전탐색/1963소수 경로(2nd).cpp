// OUTPUT
// �� test case�� ���� �� �Ҽ� ������ ��ȯ�� �ʿ��� �ּ� ȸ���� ����Ѵ�. �Ұ����� ��� Impossible�� ����Ѵ�.

#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int a, b;

bool era[10000];
bool visited[10000];

queue<pair<int, int> > q;

void check(){
	for(int i = 2 ; i <= (int)sqrt(9999) ; ++i){
		if(era[i])	continue;
		
		for(int j = i*i ; j < 10000 ; j = j+i){
			era[j] = true;
		}
	}
}

int solve(){
	
	q.push(make_pair(a, 0));
	visited[a] = true;
	
	while(!q.empty()){
		int cur = q.front().first;	int cnt = q.front().second;
		q.pop();
		
		if(cur == b){
			return cnt;
		}
		
		int one = cur % 10;	// ���� �ڸ� 
		cur /= 10;
		int two = cur % 10;
		cur /= 10;
		int three = cur % 10;
		cur /= 10;
		int four = cur;	// õ�� �ڸ�
		
		for(int i = 0 ; i < 10 ; ++i){
			if(i != one){
				int tmp = (four * 1000) + (three * 100) + (two * 10) + (i);
				if(visited[tmp] || era[tmp])	continue;
				visited[tmp] = true;
				q.push(make_pair(tmp, cnt+1));
			}
		}
		for(int i = 0 ; i < 10 ; ++i){
			if(i != two){
				int tmp = (four * 1000) + (three * 100) + (i * 10) + (one);
				if(visited[tmp] || era[tmp])	continue;
				visited[tmp] = true;
				q.push(make_pair(tmp, cnt+1));
			}
		}
		for(int i = 0 ; i < 10 ; ++i){
			if(i != three){
				int tmp = (four * 1000) + (i * 100) + (two * 10) + (one);
				if(visited[tmp] || era[tmp])	continue;
				visited[tmp] = true;
				q.push(make_pair(tmp, cnt+1));
			}
		}
		for(int i = 1 ; i < 10 ; ++i){
			if(i != four){
				int tmp = (i * 1000) + (three * 100) + (two * 10) + (one);
				if(visited[tmp] || era[tmp])	continue;
				visited[tmp] = true;
				q.push(make_pair(tmp, cnt+1));
			}
		}						
		
	}
	
	return -1;
	
}

int main(){
	check();
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		while(!q.empty())	q.pop();
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &a, &b);
		int ans = solve();
		if(ans == -1){
			printf("Impossible\n");
		}
		else	printf("%d\n", ans);
	}
	
	return 0;
}
