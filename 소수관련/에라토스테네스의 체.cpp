// 120�̶� �����غ���
// ���� �ڵ忡 ���� bool map �迭�� �ϼ��� �Ǿ��ٸ�
// ���� 0�� ���� index�� �Ҽ��� ���̴�.(���� : �ٸ� ��鿡 ���� üŷ���� �ʾ����Ƿ�!) 

#include <stdio.h>
#include <cmath>

bool map[121];

int main(){
	
	int sq = (int)sqrt(120);
	
	for(int i = 2 ; i <= sq ; ++i){
		if(map[i])	continue;
		for(int j = i * i ; j <= 120 ; j = j + i){
			map[j] = true;
		}
	}
		
	for(int i = 0 ; i < 12 ; ++i){
		for(int j = 1 ; j <= 10 ; ++j){
			if(map[i*10 + j])	printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}	
	
	return 0;
}
