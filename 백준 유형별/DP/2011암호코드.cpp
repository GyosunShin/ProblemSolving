// � ��ȣ�� �־����� ��, �� ��ȣ�� �ؼ��� �� ������ ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// input : 5000�ڸ� ������ ��ȣ�� �־�����
// output : 1000000���� ���� �������� ����Ѵ�. 
// ��ȣ�� �߸��Ǿ� ��ȣ�� �ؼ��� �� ���� ��쿡�� 0�� ����Ѵ�.

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
