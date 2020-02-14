#include <cmath> 
#include <iostream>

using namespace std;

long long solve(int r, int c){
	long long min = r < c ? r : c;
	for(int i = r ; 1 <= i ; --i){
		if(r % i == 0 && c % i == 0){
			return i;
		}
	}
}

long long solution(int w,int h)
{
	long long answer = 1;		
	
	int gcd = solve(w,h);
	
	answer = ((long long)w*(long long)h) - (gcd * ((w/gcd) + (h/gcd) - 1));
	
	return answer;
}
