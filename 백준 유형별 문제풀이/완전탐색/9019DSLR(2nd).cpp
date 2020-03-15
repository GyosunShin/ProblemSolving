// D : (2n mod 10000)
// S : n-1하고 결과가 0일 경우 -> 9999
// L : d2, d3, d4, d1
// R : d4, d1, d2, d3

//  0 <= A, B < 10,000

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int T;
int src, dst;

bool visited[10000];

queue<pair<int, string> > q;

string solve(){
	q.push(make_pair(src, ""));
	visited[src] = true;
	
	while(!q.empty()){
		int cur = q.front().first; string track = q.front().second;
		q.pop();
		if(cur == dst){
			return track;
		}
		
		// D명령어 
		int next_d = (cur*2) % 10000;
		if(!visited[next_d]){
			visited[next_d] = true;
			q.push(make_pair(next_d, track+"D"));		
		}
		
		// S명령어
		int next_s = cur-1;
		if(next_s+1 == 0)	next_s = 9999;
		if(!visited[next_s]){
			visited[next_s] = true;
			q.push(make_pair(next_s, track+"S"));		
		}		
		
		int one = cur % 10;
		cur /= 10;
		int two = cur % 10;
		cur /= 10;
		int three = cur % 10;
		cur /= 10;
		int four = cur % 10;
		
		// L명령어
		int next_l = (three*1000) + (two*100) + (one*10) + (four);
		if(!visited[next_l]){
			visited[next_l] = true;
			q.push(make_pair(next_l, track+"L"));		
		}
		
		// R명령어
		int next_r = (one*1000) + (four*100) + (three*10) + (two);
		if(!visited[next_r]){
			visited[next_r] = true;
			q.push(make_pair(next_r, track+"R"));		
		}
		
	}
	
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(visited, false, sizeof(visited));
		while(!q.empty())	q.pop();
		scanf("%d %d", &src, &dst);
		
		// A에서 B로 변환하기 위해 필요한 최소한의 명령어 나열을 출력한다.
		cout << solve() << endl;
	}
	
	
	return 0;
}
