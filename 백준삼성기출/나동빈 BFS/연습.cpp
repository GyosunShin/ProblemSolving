#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];  // 처음엔 다 0으로 초기화 되겠 
vector<int> a[8];  // 걍 인덱스랑 요소랑 같게 하려고 a[0]은 안쓰네 

void bfs(int start){
	queue<int> q;
	// 일단 시작노드를 넣어주고 그 다음에! 
	// 방문처리를 해주는게 당연! 
	q.push(start);   
	c[start] = true;
	
	while(!(q.empty())){
		int x = q.front();
		q.pop();
		cout << x << endl;
		for(int i = 0 ; i < a[x].size() ; i++){
			if(!(c[a[x][i]])){
				q.push(a[x][i]);
				c[a[x][i]] = true;
			}
		}
		
	}

}

int main(){
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
	
	a[3].push_back(2);
	a[7].push_back(3);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
}


