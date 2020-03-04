// ���� â�� (1 ~ N) 
// ���� â�� (1 ~ M) 

//���� â���� �켱������ �Ʒ��� ����.
//   �� ���� ���� ��ٸ��� �ִ� ��� ����ȣ�� ���� ������� �켱 �����Ѵ�.
//   �� �� â���� ���� ���� ��� ���� â����ȣ�� ���� ������ ����.

//���� â���� �켱������ �Ʒ��� ����.
//   �� ���� ��ٸ��� ���� �켱�Ѵ�.  
//   �� �� �� �̻��� ������ ���� â������ ���ÿ� ������ �Ϸ��ϰ� ���� â���� �̵��� ���, �̿��ߴ� ���� â����ȣ�� ���� ���� �켱�Ѵ�.
// (priority_queue) �̿��ߴ� â����ȣ �������� 
//   �� �� â���� ���� ���� ��� ���� â����ȣ�� ���� ������ ����.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M, K, A, B;
int recep[10];
int repair[10];
int arrive[1001];

int recep_write[1001];
int repair_write[1001];

int recep_empty[10];
int repair_empty[10];

int recep_who[10];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq_one;	// (tick, ����ȣ)
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, greater<pair<pair<int, int>, int> > > pq_two;

//priority_queue<INFO, vector<INFO>, cmp> pq_two;	// (tick, ���� â����ȣ)

void solve(){
	
	int tick = 0;
	
	while(true){
		
		bool break_flag = true;
		for(int i = 1 ; i <= K ; ++i){
			if(recep_write[i] == -1 || repair_write[i] == -1){
				break_flag = false;
				break;
			}
		}
		if(break_flag)	break;
		
		
		// ���� â�� N�� ��� 
		for(int i = 1 ; i <= K ; ++i){
			if(arrive[i] == 0)	pq_one.push(make_pair(tick, i));
			arrive[i]--;
		}
			
		for(int i = 1 ; i <= N ; ++i){
			if(recep_empty[i] < 1){
				if(pq_one.size() > 0){
					int cur = pq_one.top().second;// ����ȣ
					pq_one.pop();
					recep_empty[i] = recep[i];
					recep_write[cur] = i;
					recep_who[i] = cur;
//					printf("����ȣ : %d --> ����â����ȣ : %d\n", cur, i);
				}
			}
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(--recep_empty[i] == 0){
				pq_two.push(make_pair(make_pair(tick, i), recep_who[i]));
			}
		}
		
		for(int i = 1 ; i <= M ; ++i){
			if(repair_empty[i] < 1){
				if(pq_two.size() > 0){
					int cur = pq_two.top().second;		pq_two.pop();
					repair_empty[i] = repair[i];
					repair_write[cur] = i;	
//					printf("����ȣ : %d --> ���� â����ȣ : %d\n", cur, i);
				}
			}
		}
		
		for(int i = 1 ; i <= M ; ++i){
			--repair_empty[i];
		}
		
		tick++;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(recep_write, -1, sizeof(recep_write));
		memset(repair_write, -1, sizeof(repair_write));
		memset(recep_empty, 0, sizeof(recep_empty));
		memset(repair_empty, 0, sizeof(repair_empty));
//		while(pq_one.empty())	pq_one.pop();
//		while(pq_two.empty())	pq_two.pop();
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);	
		for(int i = 1 ; i <= N ; ++i)	scanf("%d", &recep[i]);
		for(int i = 1 ; i <= M ; ++i)	scanf("%d", &repair[i]);
		for(int i = 1 ; i <= K ; ++i){
			scanf("%d", &arrive[i]);
		}
		
		solve();
		
		// OUTPUT 
		//������ �н��� ���� ���� ���� â���� ���� ���� â���� �̿��� ���� ����ȣ���� ã�� �� ���� ���
		//����, �׷� ���� ���� ��� -1�� ����Ѵ�. 
		int ans = 0;
		for(int i = 1 ; i <= K ; ++i){
			if(recep_write[i] == A && repair_write[i] == B){
				ans += i;	
			}
		}
		if(ans == 0)	ans = -1;
		printf("#%d %d\n", z, ans);
	}	
	return 0;
}

