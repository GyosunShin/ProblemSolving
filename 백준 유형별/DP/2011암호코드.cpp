// 어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.
// input : 5000자리 이하의 암호가 주어진다
// output : 1000000으로 나눈 나머지를 출력한다. 
// 암호가 잘못되어 암호를 해석할 수 없는 경우에는 0을 출력한다.

#include <stdio.h> 
#include <iostream>

using namespace std;

string input;
int map[5000], cache[5000];
int len;

int main(){
	cin >> input;
	int len = input.size();
	for(int i = 0 ; i < len ; ++i){
		map[i] = input[i] - '0';
	}
	
	if(map[0] == 0){
		printf("0");
		return 0;
	}
	
	for(int i = 0 ; i < len ; ++i){
		if(i == 0){
			cache[0] = 1;
			continue;
		}
		
		if(map[i] != 0){
			cache[i] = cache[i-1] % 1000000;
		}
		
		int tmp = (map[i-1] * 10) + map[i];
		if(10 <= tmp && tmp <= 26){
			if(i == 1){
				cache[i] = (cache[i] + 1);
			}
			else	cache[i] = (cache[i] + cache[i-2]) % 1000000;	
		}
	}
//	for (int i = 0; i < len; i++){
//        cout << "DP[" << i << "] = " << cache[i] << endl;
//    }
	printf("%d", cache[len-1]);
	
	return 0;
}
