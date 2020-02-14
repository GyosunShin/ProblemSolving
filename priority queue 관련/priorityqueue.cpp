#include <cstdio>
#include <queue>
using namespace std;
 
// 씨발 원래 greater는 내림차순이라는데 왜 pq에 쓰이면 Min Heap을 만들어주는거지.... 씨발... 
// 그니까 greater 쓰면 오름차순(작은 것 부터) 
priority_queue<int, vector<int>, greater<int>> pq;  

// 밑에 처럼 쓰면 내림차순 
//priority_queue<int> pq;  
 

//bool operator<(int a, int b){
//	return (a > b);
//}
 
int main(){
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(9);
    while (!pq.empty()) {
        printf("%d",pq.top());
        pq.pop();
    }
}


