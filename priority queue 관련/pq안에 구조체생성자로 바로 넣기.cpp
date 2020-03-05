#include <cstdio> 
#include <queue>

using namespace std;

struct INFO{
//	INFO(int R, int C) : r(R), c(C)	{}
	int r, c;
};

struct cmp{
	bool operator()(const INFO& a, const INFO& b){
		return a.r > b.r;
	}
};

priority_queue<INFO, vector<INFO>, cmp> pq;

int main(){
	
//	INFO tmp(1,2);
	INFO tmp = {1,2};
	printf("%d / %d\n", tmp.r, tmp.c);
	
	pq.push(tmp);
	
	return 0;
}



