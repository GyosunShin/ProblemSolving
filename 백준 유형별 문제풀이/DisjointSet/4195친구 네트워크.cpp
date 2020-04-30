// ģ�� ������ �� F <= 100,000
// �ĺ� �빮�� �Ǵ� �ҹ��ڷθ� �̷���� ���� 20 ������ ���ڿ�

// OUTPUT
// ģ�� ���谡 ���� ������, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

int T, F;
string a, b;

map<string, int> hashlist;
map<string, int>::iterator it;

int parent[100001];
int rrank[100001];
int nums[100001];

int global_idx = 1;

int find(int u){
	if(parent[u] == u)	return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);	v = find(v);
	
	if(u == v)	return;
	
	if(rrank[u] > rrank[v]){
		parent[v] = u;
		nums[u] += nums[v];
	}
	else{
		parent[u] = v;
		nums[v] += nums[u];
		if(rrank[u] == rrank[v])	rrank[v]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	cout.tie(0);
	
	cin >> T;
	
	for(int z = 1 ; z <= T ; ++z){
		cin >> F;	
		hashlist.clear();
		global_idx = 1;
		for(int i = 1 ; i <= 100000 ; ++i){
			parent[i] = i;
			rrank[i] = 1;
			nums[i] = 1;
		}
		
		for(int i = 0 ; i < F ; ++i){
			cin >> a >> b;
			it = hashlist.find(a);
			if(it == hashlist.end()){
				hashlist[a] = global_idx++;
			}
			it = hashlist.find(b);
			if(it == hashlist.end()){
				hashlist[b] = global_idx++;
			}	
			
			merge(hashlist[a], hashlist[b]);
			
//			printf("%d\n", nums[find(hashlist[a])]);
			cout << nums[find(hashlist[a])] << "\n";
		}	
	}
	
	return 0;
}
