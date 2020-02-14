// �л��� ���� ���� n (2 �� n �� 100,000)
// ��� �л����� 1���� n���� ��ȣ�� �ο��ȴ� 

// OUTPUT : ������Ʈ ���� ������ ���� �л����� ���� ��Ÿ���� �ȴ�.

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std; 

int T, N;
int map[100001];
int cache[100001];   // (1 : �׷��Ҵ�) (0 : ����) (-1 : �׷� �ȵ�)
int visited[100001];

vector<int> picked;

void dfs(int next){
	
	if(cache[next] != 0){  // �����ϴٰ� �����Ű� �̹� �׷쿡 �ش�Ǵ��� ������ ��� 
		for(int i = 0 ; i < picked.size() ; ++i)	cache[picked[i]] = -1;
		return;
	}
	
	if(visited[next] != 0){
		bool tmp_flag = false;
		for(int i= 0 ; i < picked.size() ; ++i){
			if(tmp_flag){
				cache[picked[i]] = 1;
				continue;
			}
			if(picked[i] == next){
				tmp_flag = true;
				cache[picked[i]] = 1;
				continue;
			}
			cache[picked[i]] = -1;
		}
		return;
	}
	visited[next] = 1;
	picked.push_back(next);
	dfs(map[next]);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(cache, 0, sizeof(cache));
		memset(visited, 0, sizeof(visited));
		picked.clear();
		
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);	
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] != 0)	continue;
			visited[i] = 1;
			picked.clear();
			picked.push_back(i);
			dfs(map[i]);
		}
		
		int ans = N;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == 1)	--ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
