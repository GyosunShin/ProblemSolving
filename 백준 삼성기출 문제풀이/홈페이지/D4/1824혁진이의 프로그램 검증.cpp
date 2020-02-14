#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// x좌표(0~19), y좌표(0~19), 방향(0:상, 1:하, 2:좌, 3:우), memory(0 ~ 15)값 
int reg[20][20][4][16];

int mem = 0;
char map[20][20];
int Row,Col;

struct INFO{
	int r;
	int c;	
	int dir;
	int mem;
};

queue<INFO> q;

bool bfs(INFO start){
	
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front(); q.pop(); 
//		cout << "#########################" << endl;
//		cout << "R : " << cur.r << " / C : " << cur.c << endl;
//		cout << "MEM : " << cur.mem << " / DIR : " << cur.dir << endl;
//		cout << endl;
		
		if(reg[cur.r][cur.c][cur.dir][cur.mem] == 1){
			return false;
		}
		else{
			reg[cur.r][cur.c][cur.dir][cur.mem] = 1;
		}
		
		// 이제는 다음방향을 계산
		int next_r, next_c, next_dir, next_mem;
		char tmpchar = map[cur.r][cur.c];
		if(tmpchar == '<'){
			next_r = cur.r;
			next_dir = 2;
			if(cur.c == 0){
				next_c = Col - 1;
			}
			else{
				next_c = cur.c-1;
			}
			next_mem = cur.mem;
		}
		else if(tmpchar == '>'){
			next_r = cur.r;
			next_dir = 3;
			if(cur.c == (Col-1)){
				next_c = 0;
			}
			else{
				next_c = cur.c+1;
			}
			next_mem = cur.mem;
		}	
		else if(tmpchar == '^'){
			next_c = cur.c;
			next_dir = 0;
			if(cur.r == 0){
				next_r = Row - 1;
			}
			else{
				next_r = cur.r-1;
			}
			next_mem = cur.mem;
		}		
		else if(tmpchar == 'v'){
			next_c = cur.c;
			next_dir = 1;
			if(cur.r == (Row - 1)){
				next_r = 0;
			}
			else{
				next_r = cur.r+1;
			}
			next_mem = cur.mem;
		}			
		else if(tmpchar == '_'){
			next_r = cur.r;
			next_mem = cur.mem;
			if(cur.mem == 0){
				next_dir = 3; // 0저장이면 오른쪽으로   
				if(cur.c == (Col-1)){
					next_c = 0;
				}
				else{
					next_c = cur.c+1;
				}
			}
			else{
				next_dir = 2;	// 아니면 왼쪽으로  
				if(cur.c == 0){
					next_c = Col - 1;
				}
				else{
					next_c = cur.c-1;
				}
			}
		}	
		else if(tmpchar == '|'){
			next_c = cur.c;
			next_mem = cur.mem;
			if(cur.mem == 0){
				next_dir = 1; // 0저장이면 아래쪽으로    
				if(cur.r == (Row - 1)){
					next_r = 0;
				}
				else{
					next_r = cur.r+1;
				}
			}
			else{
				next_dir = 0;	// 아니면 위로  
				if(cur.r == 0){
					next_r = Row - 1;
				}
				else{
					next_r = cur.r-1;
				}
			}
		}				
		
		else if(tmpchar == '.'){
			if(cur.dir == 0){
				next_c = cur.c;
				if(cur.r == 0){
					next_r = Row - 1;
				}
				else{
					next_r = cur.r-1;
				}
			}
			else if(cur.dir == 1){
				next_c = cur.c;
				if(cur.r == (Row - 1)){
					next_r = 0;
				}
				else{
					next_r = cur.r+1;
				}
			}
			else if(cur.dir == 2){
				next_r = cur.r;
				if(cur.c == 0){
					next_c = Col - 1;
				}
				else{
					next_c = cur.c-1;
				}
			}
			else if(cur.dir == 3){
				next_r = cur.r;
				if(cur.c == (Col-1)){
					next_c = 0;
				}
				else{
					next_c = cur.c+1;
				}
			}
			next_mem = cur.mem;
			next_dir = cur.dir;
		}
		else if(tmpchar == '0' || tmpchar == '1' || tmpchar == '2' || tmpchar == '3' || tmpchar == '4' || tmpchar == '5' || tmpchar == '6' || tmpchar == '7' || tmpchar == '8' || tmpchar == '9'){
			next_mem = tmpchar - '0';
			next_dir = cur.dir;
			if(cur.dir == 0){
				next_c = cur.c;
				if(cur.r == 0){
					next_r = Row - 1;
				}
				else{
					next_r = cur.r-1;
				}
			}
			else if(cur.dir == 1){
				next_c = cur.c;
				if(cur.r == (Row - 1)){
					next_r = 0;
				}
				else{
					next_r = cur.r+1;
				}
			}
			else if(cur.dir == 2){
				next_r = cur.r;
				if(cur.c == 0){
					next_c = Col - 1;
				}
				else{
					next_c = cur.c-1;
				}
			}
			else if(cur.dir == 3){
				next_r = cur.r;
				if(cur.c == (Col-1)){
					next_c = 0;
				}
				else{
					next_c = cur.c+1;
				}
			}
		}
		
		else if(tmpchar == '-' || tmpchar == '+'){
			next_dir = cur.dir;
			if(tmpchar == '-'){
				if(cur.mem == 0){
					next_mem = 15;
				}
				else{
					next_mem = (cur.mem - 1);
				}
			}
			else if(tmpchar == '+'){
				if(cur.mem == 15){
					next_mem = 0;
				}
				else{
					next_mem = (cur.mem + 1);
				}
			}
			if(cur.dir == 0){
				next_c = cur.c;
				if(cur.r == 0){
					next_r = Row - 1;
				}
				else{
					next_r = cur.r-1;
				}
			}
			else if(cur.dir == 1){
				next_c = cur.c;
				if(cur.r == (Row - 1)){
					next_r = 0;
				}
				else{
					next_r = cur.r+1;
				}
			}
			else if(cur.dir == 2){
				next_r = cur.r;
				if(cur.c == 0){
					next_c = Col - 1;
				}
				else{
					next_c = cur.c-1;
				}
			}
			else if(cur.dir == 3){
				next_r = cur.r;
				if(cur.c == (Col-1)){
					next_c = 0;
				}
				else{
					next_c = cur.c+1;
				}
			}			
		}
		

		else if(tmpchar == '?'){
			int tmpmem = cur.mem; 
			//###################상#
			INFO tmpNode1;
			tmpNode1.mem = tmpmem;
			tmpNode1.c = cur.c;
			tmpNode1.dir = 0;
			int r1;
			if(cur.r == 0){
				r1 = Row - 1;
			}
			else{
				r1 = cur.r-1;
			}
			tmpNode1.r = r1;
			q.push(tmpNode1);
			//###################하#
			INFO tmpNode2;
			tmpNode2.mem = tmpmem;
			tmpNode2.c = cur.c;
			tmpNode2.dir = 1;
			int r2;
			if(cur.r == (Row - 1)){
				r2 = 0;
			}
			else{
				r2 = cur.r+1;
			}
			tmpNode2.r = r2;
			q.push(tmpNode2);			
			//###################좌#
			INFO tmpNode3;
			tmpNode3.mem = tmpmem;
			tmpNode3.r = cur.r;
			tmpNode3.dir = 2;
			int r3;
			if(cur.c == 0){
				r3 = (Col - 1);
			}
			else{
				r3 = cur.c-1;
			}
			tmpNode3.c = r3;
			q.push(tmpNode3);			
			//###################우#
			INFO tmpNode4;
			tmpNode4.mem = tmpmem;
			tmpNode4.r = cur.r;
			tmpNode4.dir = 3;
			int r4;
			if(cur.c == (Col - 1)){
				r4 = 0;
			}
			else{
				r4 = cur.c+1;
			}
			tmpNode4.c = r4;
			q.push(tmpNode4);			
			//####################									
			continue;	
		}
		else if(tmpchar == '@'){
			return true;
		}
		INFO tmpNode;
		tmpNode.r = next_r;
		tmpNode.c = next_c;
		tmpNode.dir = next_dir;
		tmpNode.mem = next_mem;
		q.push(tmpNode);
	}
}




int main(){
	int T;
	scanf("%d", &T);
	
	for(int i = 0 ; i < T ; ++i){
		// 케이스 테스트때마다 queue랑 visited 4차원 배열 초기화! 그리고 map도... 
		while( !q.empty() ) q.pop();
		reg[20][20][4][16] = { 0, };
//		map = { 0, };
		
		//R, C (2 ≤ R, C ≤ 20)
		int R,C;
		scanf("%d %d", &R, &C);
		Row = R;
		Col = C;
		
		for(int j = 0 ; j < R ; ++j){
			getchar();
			for(int k = 0 ; k < C ; ++k){
				scanf("%c", &map[j][k]);
			}
		}
		
		INFO start;
		start.r = 0; start.c = 0; start.dir = 3; start.mem = 0;
		bool ans = bfs(start);
		
		if(ans)
			cout << "#" << (i+1) << " YES";
		else
			cout << "#" << (i+1) << " NO";
	}
}
