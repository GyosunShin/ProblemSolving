// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
// 1 <= N <= 10

#include <cstdio>
#include <vector>

using namespace std;

int T, N;

vector<int> picked;

int ans;

void dfs(){
	
	int tmp_sum = 0;
	for(int i = 0 ; i < picked.size() ; ++i)	tmp_sum += picked[i];
	if(tmp_sum == N)	++ans;
	
	
	if(picked.size() == N)	return;
	
	for(int i = 1 ; i <= 3 ; ++i){
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
	
}
 
int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0;
		scanf("%d", &N);
		
		// 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
		
		// 중복 순열로 풀어보자
		// 최대 N개 뽑기
		dfs(); 
		printf("%d\n", ans);
	}
	
	return 0;
}
