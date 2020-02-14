// (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
// -100,000 <=   <= 100,000

// OUTPUT : 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다

#include <stdio.h> 
#include <vector>

using namespace std;

int N, S;
int map[20];
int ans;

vector<int> picked;

void dfs(int start){
	int tmp_sum = 0;
	if(picked.size() > 0){
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += map[picked[i]];
		}
		
		if(tmp_sum == S){
			++ans;
		}	
	}
	
	if(picked.size() == N)	return;
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
}


int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
