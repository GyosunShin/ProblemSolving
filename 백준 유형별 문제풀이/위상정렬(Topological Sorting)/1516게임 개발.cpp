// �ǹ��� ���� �� N(1 �� N �� 500)

// �� �ǹ��� ���µ� �ɸ��� �ð� <= 100,000

// !!  ���� ���� �ǹ��� ���ÿ� ���� �� �ִ�. !!

#include <cstdio> 
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int inDegree[501];
int time[501];
int cache[501];

vector<int> graph[501];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0){
			int cur_time = time[i];
			pq.push(make_pair(cur_time, i));
			cache[i] = cur_time;
		}
	}
	
	while(!pq.empty()){
		
		int sofar = pq.top().first;	int curV = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < graph[curV].size() ; ++i){
			int nextV = graph[curV][i];
			int nextSofar = sofar + time[nextV];
			
			if(cache[nextV] != -1 && cache[nextV] <= nextSofar)	continue;
			
			inDegree[nextV]--;
			
			if(inDegree[nextV] == 0){
				pq.push(make_pair(nextSofar, nextV));
				cache[nextV] = nextSofar;
			}	
		}
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &time[i]);
		int tmp;
		while(true){
			scanf("%d", &tmp);
			if(tmp == -1)	break;
			graph[tmp].push_back(i);
			inDegree[i]++;
		}
	}
	
	solve();
	// OUTPUT : N���� �� �ǹ��� �ϼ��Ǳ���� �ɸ��� �ּ� �ð��� ����Ѵ�.
	int answer = -1 * 0x7fffffff;
	for(int i = 1 ; i <= N ; ++i){
		printf("%d\n", cache[i]);
	}
	
	return 0;
}
