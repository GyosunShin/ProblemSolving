// (2 ¡Â N ¡Â 11)	
// (1 ¡Â Ai ¡Â 100)
// µ¡¼À(+)ÀÇ °³¼ö, »¬¼À(-)ÀÇ °³¼ö, °ö¼À(¡¿)ÀÇ °³¼ö, ³ª´°¼À(¡À)
#include <stdio.h>

using namespace std;

int N;
int nums[11];
int opers[4];  // + - * /
int max,min;

// ¸ðµç °æ¿ìÀÇ ¼ö¸¦ µûÁ®¾ß ÇÏ¹Ç·Î dfs()
void dfs(int count, int ret){
//	printf("TEST!!! %d / %d   <ret : %d>\n",max, min, ret);
	if(count == (N-1)){
		if(ret < min){
			min = ret;
		}
		if(ret > max){
			max = ret;
		}
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		if(opers[i] != 0){
			--opers[i];
			if(i == 0){  // +
				dfs(count+1, ret + nums[count + 1]);
			}
			else if(i == 1){  // - 
				dfs(count+1, ret - nums[count + 1]);
			}
			else if(i == 2){   // *
				dfs(count+1, ret * nums[count + 1]);			
			}
			else if(i == 3){   // /
				dfs(count+1, ret / nums[count + 1]);
			}						
			++opers[i];
		}
	}
}

int main(){
	min = 0x7fffffff;
	max = min * -1;
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &nums[i]);	
	}
	for(int i = 0 ; i < 4 ; ++i){
		scanf("%d", &opers[i]);	
	}
	// ###########################
	
	dfs(0, nums[0]);
	
	printf("%d\n%d", max, min);
	
}
  
