// 주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

// INPUT : 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

#include <stdio.h>
 
int main(void){
    
    int N;
    int Dp[100001] = {};
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++)
    {
    	printf("I : %d\n", i); 
        for (int j = 1; j*j <= i; j++){
        	printf("J : %d\n", j);	
            if ((Dp[i] > Dp[i - j*j] + 1) || Dp[i] == 0){
            	printf("걸리는 경우\n");
            	Dp[i] = Dp[i - j*j] + 1;
            }
            else	printf("안!! 경우\n");
            
        }
    }
    
//    for(int i = 0 ; i <= N ; ++i){
//    	printf("%d ", Dp[i]);
//    }
    
    printf("%d\n", Dp[N]);
 
    return 0;
}
