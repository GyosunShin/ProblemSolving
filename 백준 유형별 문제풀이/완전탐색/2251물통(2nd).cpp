// 첫 번째 물통(용량이 A인)이 비어 있을 때, 
// 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

// (1≤A, B, C≤200)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

int A, B, C;
bool cache[201][201][201];

void dfs(int a, int b, int c){
//	printf("%d  /  %d  /  %d\n", a,b,c);
	
	if(a == 0)	ans.push_back(c);
	
	// c --> a
	int aa, bb ,cc;
	if(c > 0){
		int tmp = (A-a) - c;
		bb = b;
		if(tmp < 0){
			aa = A;
			cc = c - (A-a);
		}
		else{
			aa = a+c;
			cc = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}
	
	// c --> b
	if(c > 0){
		int tmp = (B-b) - c;
		aa = a;
		if(tmp < 0){
			bb = B;
			cc = c - (B-b);
		}
		else{
			bb = b+c;
			cc = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}	
	
	// b --> a
	if(b > 0){
		int tmp = (A-a) - b;
		cc = c;
		if(tmp < 0){
			aa = A;
			bb = b - (A-a);
		}
		else{
			aa = a+b;
			bb = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}		
	
	// b --> c
	if(b > 0){
		int tmp = (C-c) - b;
		aa = a;
		if(tmp < 0){
			cc = C;
			bb = b - (C-c);
		}
		else{
			cc = c+b;
			bb = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}		
	
	// a --> b
	if(a > 0){
		int tmp = (B-b) - a;
		cc = c;
		if(tmp < 0){
			bb = B;
			aa = a - (B-b);
		}
		else{
			bb = b+a;
			aa = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}	
	
	// a --> c
	if(a > 0){
		int tmp = (C-c) - a;	
		bb = b;
		if(tmp < 0){
			cc = C;
			aa = a - (C-c);
		}
		else{
			cc = c+a;
			aa = 0;
		}
		if(!cache[aa][bb][cc]){
			cache[aa][bb][cc] = true;
			dfs(aa,bb,cc);
		}
	}	
	
}

void solve(){
	int a = 0;	int b = 0;	int c = C;
	
	cache[a][b][c] = true;
	dfs(a,b,c);
	
}


int main(){
	scanf("%d %d %d", &A, &B, &C);
	
	solve();
	
	// OUTPUT : 각 용량은 오름차순으로 정렬한다.	
	sort(ans.begin(), ans.end());
	for(int i =0 ; i < ans.size() ; ++i)	printf("%d ", ans[i]);
	
	return 0;
}
