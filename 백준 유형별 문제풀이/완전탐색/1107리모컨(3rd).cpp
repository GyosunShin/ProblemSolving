// (0 ≤ N ≤ 500,000)
// (0 ≤ M ≤ 10)
// 수빈이가 지금 보고 있는 채널은 100번이다.

#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int N, M, tmp;
int can[10];
int ans = 0x7fffffff;
string ttmp;

void check(){
	
	for(int i = 0 ; i <= 1000000 ; ++i){
		ttmp = to_string(i);
		bool tmp_flag = true;
		for(int j = 0 ; j < ttmp.size() ; ++j){
			if(can[ttmp[j] - '0'] == -1){
				tmp_flag = false;	
				break;
			}
		}
		if(tmp_flag){
			int t = ttmp.size();
			ans = min(ans, abs(N - i) + t);
		}
		
	}
	
}

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &tmp);	
		can[tmp] = -1;
	}
	
	int bigo = abs(100 - N);
	
	check();
	
	printf("%d", min(ans, bigo));
	
	return 0;
}
