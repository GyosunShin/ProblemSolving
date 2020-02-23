// N은 항상 3의 제곱꼴인 수이다 (3, 9, 27, ...) 
// 3 ^ 8 = 6561

#include <cstdio>

int N;
char ans[6561][6561];

int main(){
	scanf("%d", &N);
	
	ans[0][0] = '*';	ans[0][1] = '*';	ans[0][2] = '*';
	ans[1][0] = '*';	ans[1][1] = ' ';	ans[1][2] = '*';
	ans[2][0] = '*';	ans[2][1] = '*';	ans[2][2] = '*';
	
	
	for(int z = 3 ; z < N ; z *= 3){
		
		// 나머지 7군데 채색 
		for(int i = 0 ; i < z ; ++i){
			for(int j = 0 ; j < z ; ++j){
				
				ans[i][j+z] = ans[i][j];
				ans[i][j+z+z] = ans[i][j];
				ans[i+z][j] = ans[i][j];
				ans[i+z][j+z+z] = ans[i][j];
				ans[i+z+z][j] = ans[i][j];
				ans[i+z+z][j+z] = ans[i][j];
				ans[i+z+z][j+z+z] = ans[i][j];
				
			}
		}
		
	}
	
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(ans[i][j] == '*')	printf("*");
			else	printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
