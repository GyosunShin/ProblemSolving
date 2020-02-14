#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int flag = 0;

int N;   // 보드 판 크기 
int K;   // 사과 개수 
vector<pair<int, int> > apple;
deque<pair<int, char> > change;
int L;   // 뱀의 방향 변환 횟수 

deque<pair<int, int> > location; // 뱀의 차지하는 지역 

int dr[] = {-1, 1, 0, 0};  // 상, 하, 좌, 우 
int dc[] = {0, 0, -1, 1};
int dirIndex;

int main(){
	dirIndex = 3; // 처음엔 오른쪽으로 설정 
	location.push_back(pair<int, int>(1,1));
	scanf("%d", &N);
	scanf("%d", &K);
	
	for(int i = 0 ; i < K ; ++i){  // 각 사과의 '행, 열'
		int r, c;
		scanf("%d %d", &r, &c);
		apple.push_back(pair<int, int>(r, c));
	}
	
	scanf("%d", &L);
	for(int i = 0 ; i < L ; ++i){  // 정수 X초 이후, 왼쪽'L' (or) 오른쪽'D' 
		int X;
		char C;
		scanf("%d %c", &X, &C);
		change.push_back(pair<int, char>(X, C));
	}
	//######################################################################################
	
	int count = 0;  
	
	while(1){		
		
		// 대가리 정보는 마지막 
		int head_r = location.back().first;
		int head_c = location.back().second;
		
		// 기저 사례1 : 벽만나면 끝!
		if(head_r == 0 || head_c == 0  || head_r == (N+1)  || head_c == (N+1)){
			break; 
		}
		
		
		// 기저 사례2 : 자기 대가리가 자기 몸뚱아리에 닿으면 끝! 
		int flag2 = 0;
		for(int  i = 0 ; i < location.size()-1 ; ++i){
			if(head_r == location.at(i).first && head_c == location.at(i).second){
				flag2 = 1;
			}
			
		}
		if(flag2){
			break;
		}
		if(!flag && count != 0){ // 사과가 존재하지 않았을 경우에는 가장 예전에 집어넣었던 값을 뺀다. 
			location.pop_front(); 
		}
		flag = 0;
		
		
		// 0 : 상 | 1 : 하 | 2 : 좌 | 3 : 우 
		// 방향 바꿈 Check 
		for(int i = 0 ; i < change.size() ; ++i){
			if((count)== change.at(i).first){
				if(change.at(i).second == 'L'){
					if(dirIndex == 3)  dirIndex = 0;
					else if(dirIndex == 0)  dirIndex = 2;
					else if(dirIndex == 1)  dirIndex = 3;
					else if(dirIndex == 2)  dirIndex = 0;
				}
				else if(change.at(i).second == 'D'){
					if(dirIndex == 3)  dirIndex = 1;
					else if(dirIndex == 0)  dirIndex = 3;
					else if(dirIndex == 1)  dirIndex = 2;
					else if(dirIndex == 2)  dirIndex = 0;
				}
				change.at(i).first = -1;
			}
		}
		
		// 이제 다음 위치로
		int next_r =  head_r + dr[dirIndex];
		int next_c =  head_c + dc[dirIndex];
		
		location.push_back(pair<int, int>(next_r, next_c));
		count++;
		
		// 다음 위치에 사과 존재하는지 Check!
		for(int i = 0 ; i < apple.size() ; ++i)	{
			if((apple[i].first == next_r && apple[i].second == next_c)){
				flag = 1;	
			}	

		}
		
	} // End of while(1)
	
	printf("%d", count);
	return 0;
}
