#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

vector<int> a[8];  // graph(V, E) ���ǿ뵵!
int c[7]; // �� �湮 Check�� 
 


// �� ��������� �Լ� ���Ǹ� �ϸ� ���� Stack �Ƚᵵ �ȴٴ�!
void dfs(int src) {
	if(c[src]){ // �̹� �湮�� ���̸�.. 
		return;
	}
	c[src] = true;
	cout << src << ' ';
	
	for(int i = 0 ; i < a[src].size() ; i++){
		dfs(a[src][i]);
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
	
	dfs(1);
	return 0;
}
