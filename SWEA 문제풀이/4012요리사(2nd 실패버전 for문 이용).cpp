// 식재료의 수 (4 ≤ N ≤ 16)
// 시너지 Sij는 1이상 20,000이하의 정수이다. (1 ≤ Sij ≤ 20,000, i ≠ j)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int map[16][16];

vector<int> picked;
vector<int> unpicked;
bool used[16];

int ans = 0x7fffffff;

int solve(){
	int sumA = 0;
	int sumB = 0;
	
	// 순열 이용  
	for(int i = 0 ; i < picked.size() ; ++i){
		for(int j = i+1 ; j < picked.size() ; ++j) {
			sumA += (map[picked[i]][picked[j]] + map[picked[j]][picked[i]]);
		}
	}
	
	for(int i = 0 ; i < unpicked.size() ; ++i){
		for(int j = i+1 ; j < unpicked.size() ; ++j) {
			sumB += (map[unpicked[i]][unpicked[j]] + map[unpicked[j]][unpicked[i]]);
		}
	}
//	printf("sumA : %d / sumB : %d\n", sumA, sumB);
	return abs(sumA - sumB);
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0x7fffffff;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		
		// 조합이용
		for(int i = 0 ; i < N ; ++i){
			picked.push_back(i);
			used[i] = true;
			for(int j = i + 1 ; j < N ; ++j){
				picked.push_back(j);
				used[j] = true;
				
				if(picked.size() == (N/2)){
				
					for(int k = 0 ; k < N ; ++k){
						if(!used[k])	unpicked.push_back(k);
					}
					
					// 작업시작 
					ans = min(ans, solve());
					
					
					for(int k = 0 ; k < picked.size() ; ++k){
						printf("(%d) ", picked[k]);
					}
					printf("\n");
					for(int k = 0 ; k < unpicked.size() ; ++k){
						printf("<%d> ", unpicked[k]);
					}
					printf("\n");
					
					unpicked.clear();
					
					used[j] = false;
					picked.pop_back();
				}
			}
			picked.pop_back();
			used[i] = false;
		}
		
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}


