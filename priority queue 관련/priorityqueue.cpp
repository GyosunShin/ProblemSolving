#include <cstdio>
#include <queue>
using namespace std;
 
// ���� ���� greater�� ���������̶�µ� �� pq�� ���̸� Min Heap�� ������ִ°���.... ����... 
// �״ϱ� greater ���� ��������(���� �� ����) 
priority_queue<int, vector<int>, greater<int>> pq;  

// �ؿ� ó�� ���� �������� 
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


