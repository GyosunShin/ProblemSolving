#include <stdio.h> 

int ans;

int main(){
	int map[] = {1,2,3,4,5,6,7,8,9};
	int left = 0;
	int right = 8;
	
	int target;
	scanf("%d", &target);
	
	while(left <= right){
		printf("LEFT : %d / RIGHT : %d\n", left, right);
		int idx = (left + right) / 2;
		printf("IDX : %d\n\n", idx);
		if(map[idx] == target){
			printf("==\n");
			ans = idx;
			break;
		}
		else if(map[idx] > target){
			printf(">\n");
			right = idx -1;
		}
		else{
			printf("<\n");
			left = idx + 1;		
		}
	}
	printf("%d", ans);
	return 0;
}
