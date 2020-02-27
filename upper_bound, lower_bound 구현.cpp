#include <cstdio> 

int pan[] = {1,2,3,4,5,6,6,6,8,9,11};	// 11�� ��� ����

int upper_bound(int target){
	
	int left = 0;
	int right = 10;
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		if(pan[mid] > target)	right = mid - 1;
		else	left = mid + 1;
	}
	
	return left;
	
}

// target�� �̻��� �� �� ���� ���� Index�� ��ȯ�ʿ� 
int lower_bound(int target){
	
	int left = 0;
	int right = 10;
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		if(pan[mid] >= target)	right = mid - 1;
		else	left = mid + 1;
	}
	
	return left;
	
}

int main(){
	
	// upper_bound�� ���� Index ��ȯ
	int upper_idx = upper_bound(6); 
	printf("[UPPER_BOUND] : %d\n", upper_idx);
	
	// lower_bound�� ���� Index ��ȯ
	int lower_idx = lower_bound(6); 
	printf("[LOWER_BOUND] : %d\n", lower_idx);
	
	return 0;
}

