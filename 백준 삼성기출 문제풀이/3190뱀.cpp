#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int flag = 0;

int N;   // ���� �� ũ�� 
int K;   // ��� ���� 
vector<pair<int, int> > apple;
deque<pair<int, char> > change;
int L;   // ���� ���� ��ȯ Ƚ�� 

deque<pair<int, int> > location; // ���� �����ϴ� ���� 

int dr[] = {-1, 1, 0, 0};  // ��, ��, ��, �� 
int dc[] = {0, 0, -1, 1};
int dirIndex;

int main(){
	dirIndex = 3; // ó���� ���������� ���� 
	location.push_back(pair<int, int>(1,1));
	scanf("%d", &N);
	scanf("%d", &K);
	
	for(int i = 0 ; i < K ; ++i){  // �� ����� '��, ��'
		int r, c;
		scanf("%d %d", &r, &c);
		apple.push_back(pair<int, int>(r, c));
	}
	
	scanf("%d", &L);
	for(int i = 0 ; i < L ; ++i){  // ���� X�� ����, ����'L' (or) ������'D' 
		int X;
		char C;
		scanf("%d %c", &X, &C);
		change.push_back(pair<int, char>(X, C));
	}
	//######################################################################################
	
	int count = 0;  
	
	while(1){		
		
		// �밡�� ������ ������ 
		int head_r = location.back().first;
		int head_c = location.back().second;
		
		// ���� ���1 : �������� ��!
		if(head_r == 0 || head_c == 0  || head_r == (N+1)  || head_c == (N+1)){
			break; 
		}
		
		
		// ���� ���2 : �ڱ� �밡���� �ڱ� ���׾Ƹ��� ������ ��! 
		int flag2 = 0;
		for(int  i = 0 ; i < location.size()-1 ; ++i){
			if(head_r == location.at(i).first && head_c == location.at(i).second){
				flag2 = 1;
			}
			
		}
		if(flag2){
			break;
		}
		if(!flag && count != 0){ // ����� �������� �ʾ��� ��쿡�� ���� ������ ����־��� ���� ����. 
			location.pop_front(); 
		}
		flag = 0;
		
		
		// 0 : �� | 1 : �� | 2 : �� | 3 : �� 
		// ���� �ٲ� Check 
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
		
		// ���� ���� ��ġ��
		int next_r =  head_r + dr[dirIndex];
		int next_c =  head_c + dc[dirIndex];
		
		location.push_back(pair<int, int>(next_r, next_c));
		count++;
		
		// ���� ��ġ�� ��� �����ϴ��� Check!
		for(int i = 0 ; i < apple.size() ; ++i)	{
			if((apple[i].first == next_r && apple[i].second == next_c)){
				flag = 1;	
			}	

		}
		
	} // End of while(1)
	
	printf("%d", count);
	return 0;
}
