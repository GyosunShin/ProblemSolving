// (1 ¡Â N ¡Â 20)

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > v;

void Hanoi(int num, int from, int by, int to){
	
	if(num == 1)	v.push_back({from, to});
	else{
		Hanoi(num - 1, from, to, by);
		v.push_back({from, to});
		Hanoi(num - 1, by, from, to);
	}
}

int main(){
	scanf("%d", &N);
	
	Hanoi(N,1,2,3);
	printf("%d\n", v.size());
	
	for(int i = 0 ; i < v.size() ; ++i){
		printf("%d %d\n", v[i].first, v[i].second);
	}
	
	return 0;
}
