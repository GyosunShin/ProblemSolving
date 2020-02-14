#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];  //방문했다는거 Check 용인듯.... 
vector<int> a[8]; // 걍 인접하다는거 전부 다 표시하는 부분인가 보네... 

void bfs(int start){
	queue<int> q;  // 인접한 노드 쳐 집어넣는 용도인듯 
	q.push(start);
	c[start] = true;  // 방문 처리! 
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d", x);
		for(int i = 0 ; i < a[x].size() ; i++){
			int y = a[x][i];  // 현재 노드의 인접한 노드를 전부다 찾는다 
			if(!c[y]){   // 이미 방문한 노드가 아니라면... 
				q.push(y);
				c[y] = true;  // 이젠 방문했다고 표기한다! 
			}
		}
	}
}

int main(){
	//1과 2를 연결합니다. 
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
