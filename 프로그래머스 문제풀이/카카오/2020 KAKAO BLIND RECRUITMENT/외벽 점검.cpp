// INPUT : (1 <= N(�ܺ��� ����) <= 200)  (1 <= weak(������� �迭) <= 15)  (1 <= dist(1 <= <= 100) <= 8)

// OUTPUT : ��� ������ �����ϱ� ���� ������ �ϴ� ģ�� ���� �ּҰ��� return 
// ģ������ ��� �����ص� ��� ������ ���� ������ �� ���� ��쿡�� -1�� return ���ּ���.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct INFO{
	int start, len, clock;  
};

int N;
int weak_len, dist_len;

vector<INFO> picked;
int visited[8];

vector<int> global_dist;
vector<int> global_weak;

int ans = 0x7fffffff;

void dfs(){
	int target = 0;
	vector<int> tmp;
	for(int i = 0 ; i < N ; ++i)	tmp.push_back(0);
	for(int i = 0 ; i < global_weak.size() ; ++i){
		tmp[global_weak[i]] = 1;
	}
	
	for(int i = 0 ; i < picked.size() ; ++i){
//		cout << picked[i].start << " / " << picked[i].len << " / " << picked[i].clock << endl;
		int start = picked[i].start;
		int len = picked[i].len;
		int clock = picked[i].clock;  // (0 : �ð����) (1 : �ݽð� ����)
		
		for(int j = 0 ; j <= len ; ++j){
			if(clock == 0){  
				int ttmp = (start + j) % N;
				if(tmp[ttmp] == 1){
					tmp[ttmp] = 0;
					++target;
				}
			}
			else if(clock == 1){
				int ttmp = N + ((start - j) % N);
				if(tmp[ttmp] == 1){
					tmp[ttmp] = 0;
					++target;
				}
			}
		}
	}
	if(target == weak_len){
		if(ans < picked.size())	ans = target;
	}
	
	for(int i = 0 ; i < dist_len ; ++i){
		INFO next;
		// start --> 0 <= start <= (N-1)
		for(int s = 0 ; s < N ; ++s){
			for(int d = 0 ; d < dist_len ; ++d){
				if(visited[d] != 0)	continue;
				for(int clock = 0 ; clock < 2 ; ++clock){
					next.start = s;	next.len = global_dist[d];	next.clock = clock;
					picked.push_back(next);
					visited[d] = 1;
					dfs();
					picked.pop_back();
					visited[d] = 0;
				}
			}
		}
	}
	
}

int solution(int n, vector<int> weak, vector<int> dist) {
	global_dist = dist;
	global_weak = weak;
    N = n;
    weak_len = weak.size();
	dist_len = dist.size();
	
	dfs();
	
	if(ans < 0x7fffffff){
		return ans;
	}
	else	return -1;
}
