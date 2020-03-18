// 1<= N(R)과 M(C) <= 2,000,000,000

// OUTPUT : 병든 나이트가 여행에서 방문할 수 있는 칸의 개수중 최댓값을 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int R, C, start_r, start_c;

const int dr[] = {-2, -1, 2, 1};
const int dc[] = {1, 2, 1, 2};

int ans = -1;

int three(int r, int c, int cnt){
	
	
	
}

int main(){
	scanf("%d %d", &R, &C);
	start_r = R-1;	start_c = 0;
	
	ans = max(ans, three(start_r, start_c, 0));
	
	return 0;
}
