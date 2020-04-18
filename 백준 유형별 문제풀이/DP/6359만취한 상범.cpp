// 방의 개수 n(5 ≤ n ≤ 100)

#include <cstdio> 
#include <cstring>

int T, N;

bool lock[101];

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(lock, false, sizeof(lock));
		scanf("%d", &N);
		
		for(int i = 2; i <= N ; ++i){
			int start = i;
			
			for(int j = start ; j <= N ; j = j + start){
				if(lock[j])	lock[j] = false;
				else	lock[j] = true;
			}
		}
		
		
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(!lock[i])	++ans;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
