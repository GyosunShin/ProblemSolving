#include <cstdio>
#include <climits>

int main()
{
    char num1 = CHAR_MIN;          // char의 최솟값
    short num2 = SHRT_MIN;         // short의 최솟값
    int num3 = INT_MIN;            // int의 최솟값
    long num4 = LONG_MIN;          // long의 최솟값
    long long num5 = LLONG_MIN;    // long long의 최솟값

    // char, short, int는 %d로 출력하고 long은 %ld로 출력, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
    // -128 -32768 -2147483648 -2147483648 -9223372036854775808
    
    char mnum1 = CHAR_MAX;          // char의 최솟값
    short mnum2 = SHRT_MAX;         // short의 최솟값
    int mnum3 = INT_MAX;            // int의 최솟값
    long mnum4 = LONG_MAX;          // long의 최솟값
    long long mnum5 = LLONG_MAX;    // long long의 최솟값

    // char, short, int는 %d로 출력하고 long은 %ld로 출력, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", mnum1, mnum2, mnum3, mnum4, mnum5);

    return 0;
}	
