#include <cstdio>
#include <climits>

int main()
{
    char num1 = CHAR_MIN;          // char�� �ּڰ�
    short num2 = SHRT_MIN;         // short�� �ּڰ�
    int num3 = INT_MIN;            // int�� �ּڰ�
    long num4 = LONG_MIN;          // long�� �ּڰ�
    long long num5 = LLONG_MIN;    // long long�� �ּڰ�

    // char, short, int�� %d�� ����ϰ� long�� %ld�� ���, long long�� %lld�� ���
    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
    // -128 -32768 -2147483648 -2147483648 -9223372036854775808
    
    char mnum1 = CHAR_MAX;          // char�� �ּڰ�
    short mnum2 = SHRT_MAX;         // short�� �ּڰ�
    int mnum3 = INT_MAX;            // int�� �ּڰ�
    long mnum4 = LONG_MAX;          // long�� �ּڰ�
    long long mnum5 = LLONG_MAX;    // long long�� �ּڰ�

    // char, short, int�� %d�� ����ϰ� long�� %ld�� ���, long long�� %lld�� ���
    printf("%d %d %d %ld %lld\n", mnum1, mnum2, mnum3, mnum4, mnum5);

    return 0;
}	
