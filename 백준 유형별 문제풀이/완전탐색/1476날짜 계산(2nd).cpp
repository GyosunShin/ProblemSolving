// E  S  M
//  (1 ¡Â E ¡Â 15, 1 ¡Â S ¡Â 28, 1 ¡Â M ¡Â 19)

#include <cstdio>

int E, S, M;

int main(){
	
	scanf("%d %d %d", &E, &S, &M);
	
	int e = 1;
	int s = 1;
	int m = 1;
	
	int ans = 1;
	
	while(true){
		
		if(e == E && s == S && m == M)	break;
		
		e++;	s++;	m++;
		if(e > 15)	e = 1;
		if(s > 28)	s = 1;
		if(m > 19)	m = 1;
		++ans;
	}
	
	printf("%d", ans);
	
	return 0;
}
