// �־��� �ڿ��� N�� �̷��� ���������� ������ ǥ���� ���� �� ���� �ּҰ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// INPUT : ù° �ٿ� �ڿ��� N�� �־�����. (1 �� N �� 100,000)

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
            	printf("�ɸ��� ���\n");
            	Dp[i] = Dp[i - j*j] + 1;
            }
            else	printf("��!! ���\n");
            
        }
    }
    
//    for(int i = 0 ; i <= N ; ++i){
//    	printf("%d ", Dp[i]);
//    }
    
    printf("%d\n", Dp[N]);
 
    return 0;
}
