// 주사위에서 나올 수 10개를 미리 알고 있을 때, 얻을 수 있는 점수의 최댓값을 구해보자.

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int pan[10];
int yut[2][43];
int track[2][43];

int mmax = -1;

pair<int, int> horse[4];	// <위치, Special여부(0 or 1)>
bool dead[] = {true, true, true, true};	// false가 죽은 것 의미 

void dfs(int depth, int sofar){
	
	mmax = max(mmax, sofar);
	
	if(depth == 10){
		return;
	}
	
	int jump = pan[depth];
	
	for(int i = 0 ; i < 4 ; ++i){
		
		if(!dead[i])	continue;
		
		int cur = horse[i].first;
		int flag = horse[i].second;
		int next = cur;
		for(int j = 0 ; j < jump ; ++j){
			next = yut[flag][next];
			if(next >= 42)	break;
		}
		int next_flag = flag;
		if(next == 10 || next == 20 || next == 30){
			next_flag = 1;		
		}
		if(next == 40){
			if(track[0][next] >= 1 || track[1][next] >= 1)	continue;
		}
		if(track[next_flag][next] >= 1 && next < 42)	continue;
		
		track[next_flag][next]++;	
		track[flag][cur]--;
		horse[i].first = next;
		horse[i].second = next_flag;
				
		if(next >= 42){
			dead[i] = false;
			dfs(depth + 1, sofar);	
		}
		else{
			if(next == 31)	dfs(depth + 1, sofar + 30);
			else	dfs(depth + 1, sofar + next);
		}
		
		track[next_flag][next]--;
		track[flag][cur]++;
		horse[i].first = cur;
		horse[i].second = flag;
		dead[i] = true;
		
	}
	
	
}

int main(){
	
	for(int i = 0 ; i < 4 ; ++i){
		horse[i].first = 0;	horse[i].second = 0;
	}
	
	memset(yut, -1, sizeof(yut));
	
	for(int i = 0 ; i < 10 ; ++i){
		scanf("%d", &pan[i]);
	}
	
	for(int i = 0 ; i <= 40 ; i = i+2){
		yut[0][i] = i+2;
	}
	
	yut[1][10] = 13;
	yut[1][13] = 16;
	yut[1][16] = 19;
	yut[1][19] = 25;
	
	yut[1][20] = 22;
	yut[1][22] = 24;
	yut[1][24] = 25;
	
	yut[1][30] = 28;
	yut[1][28] = 27;
	yut[1][27] = 26;
	yut[1][26] = 25;
	
	yut[1][25] = 31;
	yut[1][31] = 35;
	yut[1][35] = 40;
	yut[1][40] = 42;
	
	dfs(0, 0);
	
	printf("%d", mmax);
	
	return 0;
}
