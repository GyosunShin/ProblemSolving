#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];  //�湮�ߴٴ°� Check ���ε�.... 
vector<int> a[8]; // �� �����ϴٴ°� ���� �� ǥ���ϴ� �κ��ΰ� ����... 

void bfs(int start){
	queue<int> q;  // ������ ��� �� ����ִ� �뵵�ε� 
	q.push(start);
	c[start] = true;  // �湮 ó��! 
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d", x);
		for(int i = 0 ; i < a[x].size() ; i++){
			int y = a[x][i];  // ���� ����� ������ ��带 ���δ� ã�´� 
			if(!c[y]){   // �̹� �湮�� ��尡 �ƴ϶��... 
				q.push(y);
				c[y] = true;  // ���� �湮�ߴٰ� ǥ���Ѵ�! 
			}
		}
	}
}

int main(){
	//1�� 2�� �����մϴ�. 
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	return 0;
}
