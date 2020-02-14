#include <stdio.h> 
#include <stack>
#include <iostream>

using namespace std;

int N;
int map[500000];
stack<pair<int, int>> s;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	printf("0 ");
	s.push(pair<int, int>(1, map[0]));
	
	for(int i = 1 ; i < N ; ++i){
		while(!s.empty()){
			if(s.top().second < map[i]){
				s.pop();
				continue;
			}
			printf("%d ", s.top().first);
			s.push(pair<int, int>(i+1, map[i]));
			break;
		}
		if(s.empty()){
			printf("0 ");
			s.push(pair<int, int>(i+1, map[i]));
		}
	}	
	
	return 0;
}
