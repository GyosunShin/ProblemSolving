#include <stdio.h>
#include <vector>

// �� ������ ��ü�� ǥ���ϴ� ���, �ڽ��� �θ��� ��ȣ�� �����ϴ� 1���� �迭������ ǥ�� 

struct NaiveDisjointSet{
	vector<int> parent;
	NaiveDisjointSet(int n): parent(n){
		for(int i = 0 ; i < n ; ++i){
			parent[i] = i;
		}
	}
	
	// u�� ���� Ʈ���� root�� ��ȣ�� ��ȯ�Ѵ�. 
	int find(int u) const{
		if(u == parent[u]) return u;
		return find(parent[u]);
	}
	
	// u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��. 
	void merge(int u, int v){
		u = find(u);	v = find(v);
		// u�� v�� �̹� ���� Ʈ���� ���ϴ� ��츦 �ɷ�����. 
		if(u == v) return;
		parent[u] = v;
	}
};

int main(){
	
}
