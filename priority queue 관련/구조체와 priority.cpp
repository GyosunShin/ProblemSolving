#include <cstdio>
#include <queue>

using namespace std;

struct INFO{
	int r, c, power, left;
};

struct cmp{
    bool operator()(const INFO &a, const INFO &b){
    	
    	if(a.power == b.power)	return a.left > b.left;
    	else	return a.power > b.power;
    	
    	// 기본으로 power가 작은거 부터 나오는 오름차순 
//    	if(a.power == b.power) {
//    		a.left < b.left;  // power값이 같다면 left도 작은거 부터 나오게 하는 오름차순 
//    	}
//        else return a.power < b.power;   
    }
};

int main(){
	
	INFO one;
	one.r = 1;	one.c = 1;	one.power = 1;	one.left = 2;
	INFO two;
	two.r = 2;	two.c = 2;	two.power = 1;	two.left = 1;
	INFO three;
	three.r = 3;	three.c = 3;	three.power = 3;	three.left = 3;
	INFO four;
	four.r = 4;	four.c = 1;	four.power = 4;	four.left = 4;
	
	priority_queue<INFO, vector<INFO>, cmp> pq;
	
	pq.push(one);
	pq.push(two);
	pq.push(three);
	pq.push(four);
	
	while(!pq.empty()){
		
		printf("%d\n", pq.top().r);
		pq.pop();
		
	}
	
	
	
	return 0;
}
