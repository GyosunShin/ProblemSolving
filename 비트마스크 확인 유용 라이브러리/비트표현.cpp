//bitset<표현할 비트 수>(표현할 수)
#include <bitset>
#include <iostream> 

using namespace std;

int main(){
    for(int i=1;i<=10;i++)
         cout << bitset<6>(i) << "\n";
}
//result
//000001
//000010
//000011
//000100
//000101
//000110
//000111
//001000
//001001
//001010
