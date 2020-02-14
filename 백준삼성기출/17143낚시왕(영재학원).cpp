#include <stdio.h> 
#include <string.h>

struct shark{
	int s, d, z;
};

int r, c, m, sum = 0;
shark a[100][100];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve(){
	for(int t = 0 ; t < c ; ++t){
		shark b[100][100] = {0};
		
		for(int i = 0 ; i < r ; ++i){
			if(a[i][t].z){  // ¹¹... °Á 0ÀÌ ¾Æ´Ï¶ó¸é... 
				sim += a[i][t].z;
				a[i][t] = {0,0,0};
				break;
			}
		}
		
		for(int i = 0 ; i < r ; ++i){
			for(int j = 0 ; j < c ; ++j){
				if(a[i][j].z){
					if(a[i][j].d < 2){
						int s = a[i][j].s % ((r-1) * 2);
						int d = a[i][j].d;
						int ni = i;
						while(s--){
							
						}
					}
				}
			}
		}
	}
	
	
}

int main(){
	scanf("%d %d %d", &r, &c, &m);
	for(int i = 0 ; i < m ; ++i){
		int x, y, s, d, z;
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		a[x-1][y-1] = {s, d-1, z};
	}
	solve();
	printf("%d\n", sum);
	return 0;
}
