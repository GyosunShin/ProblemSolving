#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

vector<int> a[8];  // graph(V, E) 정의용도!
int c[7]; // 걍 방문 Check용 
 


// 걍 재귀적으로 함수 정의만 하면 따로 Stack 안써도 된다능!
void dfs(int src) {
	if(c[src]){ // 이미 방문한 것이면.. 
		return;
	}
	c[src] = true;
	cout << src << ' ';
	
	for(int i = 0 ; i < a[src].size() ; i++){
		dfs(a[src][i]);
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
	
	dfs(1);
	return 0;
}
