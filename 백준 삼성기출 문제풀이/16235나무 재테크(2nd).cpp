#include <stdio.h> 
#include <queue>
#include <algorithm>

using namespace std;

struct TREE{
	int y, x, age;
};

bool operator<(TREE a, TREE b){  // < : less operator�ΰ� ����! 
	return (a.age > b.age);
}

priority_queue<TREE> pq[2];  // ���̰� � ���� ���� pop�Ǿ�� �Ѵ�. 
int n, m, k;
int map[10][10];  // ���� ����� ǥ���ϴ� �� 
int add[10][10];  // 

const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int cur = 0;
	int next;
	scanf("%d %d %d", &n, &m, &k);
	for(int y = 0 ; y < n ; ++y){
		for(int x = 0 ; x < n ; ++x){
			scanf("%d", &add[y][x]);
			map[y][x] = 5;
		}
	}
	
	for(int i = 0 ; i < m ; ++i){
		TREE tree;
		scanf("%d %d %d", &tree.y, &tree.x, &tree.age);
		--tree.y;	--tree.x;
		pq[cur].push(tree);
	}
	
	for(int i = 0 ; i < k ; ++i){  // k�� ����... 
		next = (cur + 1) % 2;  // 0 (or) 1
		
		queue<TREE> life_tree;
		queue<TREE> dead_tree;
		
		while(!pq[cur].empty()){
			TREE cur_tree = pq[cur].top();	pq[cur].pop();
			
			if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){   // "��" : � ������ ���̺��� ���� ������ �׿� 
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;
				TREE next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;  // �ڱ� ���̸�ŭ ��и������� ���� ++1 �Ǵ� �κ� 
				
				life_tree.push(next_tree);  // ��Ƴ��� ���� ����ִ� queue 
				pq[next].push(next_tree);   // ���� ���� Priority Queue�� ����ִ´�. 
			}
			else{   // �׾�� �Ǵ� ���̽� 
				dead_tree.push(cur_tree);
			}
		}
		
		while(!dead_tree.empty()){   // "����" �ش� ���̽� : ���� ���� ������ 1/2�� �ش��ϴ� ����� ���� �ڸ��� ++..... 
			TREE cur_tree = dead_tree.front();	dead_tree.pop();
			map[cur_tree.y][cur_tree.x] += cur_tree.age / 2;
		}
		
		while(!life_tree.empty()){  // "����" : ���� --> ���̰� 5�� ����� ������ ��� �ֺ� 8�ڸ��� ���� 1�� ���� �ɾ�����! 
			TREE cur_tree = life_tree.front();	
			life_tree.pop();
			if(cur_tree.age % 5 == 0){  // ���İ����� ���� 
				for(int dir = 0 ; dir < 8 ; ++dir){
					TREE next_tree;
					next_tree.y = cur_tree.y + dy[dir];
					next_tree.x = cur_tree.x + dx[dir];
					next_tree.age = 1;
					
					// �ؿ�ó�� ���� ����� �׻� ����� �ϴ� ���̴�! 
					if(next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n){
						continue;
					}
					
					pq[next].push(next_tree);
				}
			}
		}
		
		for(int y = 0 ; y < n ; ++y){   // "�ܿ�" : �� �� ������� ��� �����ּ�! 
			for(int x = 0 ; x < n ; ++x){
				map[y][x] += add[y][x];	
			}
		}
		
		cur = next;
		
	}  // The End of k�� ���� ��! 
	
	
	printf("%d\n", pq[next].size());
	return 0;
}
	
