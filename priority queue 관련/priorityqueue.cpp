#include <cstdio>
#include <queue>
using namespace std;
 
// ���� greater�� ���������̶�µ� �� pq�� ���̸� Min Heap�� ������ִ°���
// �״ϱ� greater ���� ��������(���� �� ����) 
priority_queue<int, vector<int>, greater<int>> pq;  
//priority_queue<int, vector<int>, less<int>> pq;    // less���� ��������(ū�ź��� top() pop())

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
        printf("%d\n",pq.top());
        pq.pop();
    }
}


