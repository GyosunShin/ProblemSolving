#include <stdio.h>
#include <vector>

using namespace std;

struct OptimizedDisjointSet{
	vector<int> parent, rank;
	
	// rank[] : �ش� ��尡 �� Ʈ���� root ������ ����ϴ� ��쿡�� �ش� Ʈ���� ���̸� ���� 
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1){	
		for(int i = 0 ; i < n ; ++i){
			parent[i] = i;
		}
	}
	
	// u�� ���� Ʈ���� root�� ��ȣ�� ��ȯ�Ѵ�. 
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);		// ��� ���� ����ȭ(Path Compression) 
	}
	
	// �׻� ���̰� �� ���� Ʈ���� �� ���� Ʈ�� �ؿ� ����������ν� Ʈ���� ���̰� �������� ��Ȳ�� �����Ѵ�. 
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		// u�� v�� �̹� ���� Ʈ���� ���ϴ� ��츦 �ɷ�����. 
		if(u == v)	return;
		
		if(rank[u] > rank[v]) swap(u, v);
		
		parent[u] = v;
		// �� Ʈ���� ���̰� ���� ��쿡�� +1 ���ش�. 
		if(rank[u] == rank[v]) ++rank[v];
	}
};

int main(){
	
	return 0;
}
