// �л��� ���� ���� n (2 �� n �� 100,000)
// ��� �л����� 1���� n���� ��ȣ�� �ο��ȴ�

// OUTPUT : ������Ʈ ���� ������ ���� �л����� ���� ��Ÿ���� �ȴ�.

#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>

using namespace std; 

int T, N;
int map[100001];
int cache[100001];   // (1 : �׷��Ҵ�) (0 : ����) (-1 : �׷� �ȵ�)

set<int> s;
vector<int> picked;

void dfs(int next){
	
	if(cache[next] != 0){  // �����ϴٰ� �����Ű� �̹� �׷쿡 �ش�Ǵ��� ������ ��� 
		for(int i = 0 ; i < picked.size() ; ++i)	cache[picked[i]] = -1;
//		for(auto it = s.begin() ; it != s.end() ; ++it){
//			cache[*it] = -1;
//		}
		return;
	}
	
	// set �����̳ʸ� �̿��ؼ� �׷쿡 ������ ���������� �Ѳ����� ó������!
	auto it = s.find(next);
	if(it != s.end()){   // �����ϴ� ���! 
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
	s.insert(next);
	picked.push_back(next);
	dfs(map[next]);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(cache, 0, sizeof(cache));
		s.clear();
		picked.clear();
		
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);	
		}
		//###########################
		
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] != 0)	continue;
			s.clear();
			picked.clear();
			s.insert(i);
			picked.push_back(i);
			dfs(map[i]);
//			printf("[%d]\n", i);
//			for(int j = 1 ; j <= N ; ++j)	printf("%d ", cache[j]);
//			printf("\n");
		}
		
		int ans = N;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == 1)	--ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
