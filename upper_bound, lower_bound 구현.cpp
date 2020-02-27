#include <cstdio> 

int pan[] = {1,2,3,4,5,6,6,6,8,9,11};	// 11개 요소 존재

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

// target값 이상인 것 중 가장 낮은 Index값 반환필요 
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
	
	// upper_bound에 대한 Index 반환
	int upper_idx = upper_bound(6); 
	printf("[UPPER_BOUND] : %d\n", upper_idx);
	
	// lower_bound에 대한 Index 반환
	int lower_idx = lower_bound(6); 
	printf("[LOWER_BOUND] : %d\n", lower_idx);
	
	return 0;
}

