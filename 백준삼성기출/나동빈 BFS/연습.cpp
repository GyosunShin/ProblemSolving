#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[7];  // ó���� �� 0���� �ʱ�ȭ �ǰ� 
vector<int> a[8];  // �� �ε����� ��Ҷ� ���� �Ϸ��� a[0]�� �Ⱦ��� 

void bfs(int start){
	queue<int> q;
	// �ϴ� ���۳�带 �־��ְ� �� ������! 
	// �湮ó���� ���ִ°� �翬! 
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


