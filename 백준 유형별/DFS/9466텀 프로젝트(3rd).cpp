// �־��� ������ ����� ���� ��� ������Ʈ ������ ������ �ʴ� �л����� ���� ����ϴ� ���α׷��� �ۼ��϶�.

// �л��� ���� ���� n (2 �� n �� 100,000)
// (��� �л����� 1���� n���� ��ȣ�� �ο��ȴ�.)

#include <stdio.h> 
#include <string.h> 
#include <vector>

using namespace std;

int T, N;
int map[100001];
int visited[100001];
int cache[100001];	// (-1 : ������)  (0 : ����)  (1 : ģ��)
vector<int> track;

void dfs(int start){
	int next = map[start];
	
	if(cache[next] != 0){
		for(int i = 0 ; i < track.size() ; ++i)	cache[track[i]] = -1;
		return;
	}
	
	if(visited[next] != 0){
		bool tmp_flag = false;
		for(int i = 0 ; i < track.size() ; ++i){
			if(track[i] == next)	tmp_flag = true;
			if(tmp_flag){
				cache[track[i]] = 1;
			}
			else{
				cache[track[i]] = -1;
			}
		}
		return;
	}
	
	visited[next] = 1;
	track.push_back(next);
	dfs(next);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(visited, 0, sizeof(visited));
		memset(cache, 0, sizeof(cache));
		scanf("%d", &N);	
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);	
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == 0){
				track.clear();
				visited[i] = 1;
				track.push_back(i);
				dfs(i);
			}
		}
		
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == -1)	++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}


