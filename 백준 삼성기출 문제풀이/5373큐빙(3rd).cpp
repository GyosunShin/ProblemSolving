//  가장 윗 면의 색상을 구하는 프로그램을 작성하시오.
#include <stdio.h>
#include <iostream>

using namespace std;

// 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n ≤ 1000)
// 첫 번째 문자는 돌린 면이다. U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면이다
// 두 번째 문자는 돌린 방향이다. + : 시계 방향, - : 반시계 방향이다.

int T;   // <= 100

string map[100];

int main(){
	cin >> T;
	for(int z = 0 ; z < T ; ++z){
		int n;
		cin >> n;
		
		for(int i = 0 ; i < n ; ++i){
			cin >> map[i];
		}	
		
		
		
	}
	
	return 0;
}
