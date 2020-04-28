// ù° �ٿ� n(1��n��1,000,000), m(1��m��100,000)

// OUTPUT
// 1�� �����ϴ� �Է¿� ���ؼ� �� �ٿ� �ϳ��� YES/NO�� ����� ����Ѵ�. (yes/no �� ����ص� �ȴ�)

// �������� 0 a b

#include <cstdio> 
#include <vector>

using namespace std;

int N, M;

struct DisjointSet{
	vector<int> parent, rank;
	
	DisjointSet(int n) : parent(n), rank(n, 1){
		for(int i = 0 ; i < n ; ++i)	parent[i] = i;
	}
	
	int find(int u){
		if(u == parent[u])	return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		if(u == v)	return;
		
		if(rank[u] > rank[v]){
			parent[v] = u;
		}
		else{
			parent[u] = v;
			if(rank[u] == rank[v])	rank[v]++;
		}
		
	}
	
	
};

int main(){
	scanf("%d %d", &N, &M);
	
	DisjointSet ds(N+1);
	
	int order, a, b;
	
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d", &order, &a, &b);	
		if(order == 0){
			ds.merge(a, b);
		}
		else{
			if(ds.find(a) == ds.find(b))	printf("YES\n");
			else	printf("NO\n");
		}
	}
	return 0;
}
