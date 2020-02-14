// N(1≤N≤100,000)
// M(1≤M≤100,000)

// OUTPUT : M개의 줄에 답을 출력한다. 
// 존재하면 1을, 존재하지 않으면 0을 출력한다.

#include <stdio.h> 
#include <algorithm>

using namespace std;

int N, M;

int map[100000];
int map2[100000];

void solve(int target){
	int left = 0;
	int right = N-1;
	bool flag = false;
	
	while(left <= right){
		int mid = (left + right) / 2;
		if(map[mid] == target){
			printf("1\n");
			flag = true;
			break;
		}
		else if(map[mid] < target){
			left = mid + 1;
			continue;
		}
		else{
			right = mid - 1;
			continue;
		}
	}
	
	if(!flag){
		printf("0\n");
	}
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	sort(map, map+N);
	
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &map2[i]);
		solve(map2[i]);
	}	
	//###############################	
	
	return 0;	
}



