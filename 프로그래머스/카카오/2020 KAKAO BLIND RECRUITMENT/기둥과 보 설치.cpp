// 5 <= N <= 100 

// 모든 명령어를 수행한 후 구조물의 상태를 return 하도록 solution 함수를 완성해주세요.

// INPUT
// [x, y, a, b]
// a : (0 기둥) (1 보)
// b : (0 삭제) (1 설치)

// OUTPUT
// [x, y, a]
// x좌표 기준으로 오름차순 정렬하며, x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬해주세요.
// x, y좌표가 모두 같은 경우 기둥이 보보다 앞에 오면 됩니다. 

#include <string>
#include <vector>
#include <iostream>	

using namespace std;

vector<vector<int>> answer;
int kidong[101][101];
int bo[100][101];

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	
	int len = build_frame.size();
	for(int i = 0 ; i < len ; ++i){
		int x,y,a,b;
		x = build_frame[i][0];	y = build_frame[i][1];	a = build_frame[i][2];	b = build_frame[i][3];
		
		if(a == 0){   // 기둥인 경우 
			if(b == 1){  // 설치하는  경우  
			
				// 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
			
				if(y == 0){  // 바닥에 설치할 경우 
					kidong[x][y] = 1; 
				}
				else{  // 바닥보다 위에 설치할 경우 
					
					if(kidong[x][y-1] == 1 || bo[x-1][y] == 1 || bo[x][y] == 1){
						kidong[x][y] = 1;
					}
					else	continue;
				}
			}
			else{  	// 삭제하는 경우 
				
				if(kidong[x][y+1] == 1 && bo[x-1][y+1] == 0 && bo[x][y+1] == 0)	continue;
				if(bo[x-1][y+1] == 1 && bo[x-2][y+1] == 0 && kidong[x-1][y] == 0)	continue;
				if(bo[x][y+1] == 1 && bo[x+1][y+1] == 0 && kidong[x+1][y] == 0)	continue;
				
				kidong[x][y] = 0; 
			}
		}
		else{  // 보인 경우 
			if(b == 1){  // 설치하는  경우  
				
				// 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
				if(kidong[x][y-1] == 1 || kidong[x+1][y-1] == 1 || (bo[x-1][y] == 1 && bo[x+1][y] == 1)){
					bo[x][y] = 1;
				}
				else	continue;
				
			}	
			else{ // 삭제하는 경우 
			
				if(kidong[x][y] == 1 && bo[x-1][y] == 0 && kidong[x][y-1] == 0)	continue;
				if(kidong[x+1][y] == 1 && bo[x+1][y] == 0 && kidong[x+1][y-1] == 0)	continue;
				if(bo[x-1][y] == 1 && kidong[x-1][y-1] == 0 && kidong[x][y-1] == 0)	continue;
				if(bo[x+1][y] == 1 && kidong[x+1][y-1] == 0 && kidong[x][y-1] == 0)	continue;
				
				bo[x][y] = 0; 
				
			}
		}
		
	}
	
	// 이제 kidong[][]과 bo[][]를 보고 answer 2차원 vector를 만들자 
	
	//  [x, y, a]
	// 0은 기둥, 1은 보
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j <= n ; ++j){
			vector<int> tmp1;
			vector<int> tmp2;
			if(kidong[i][j] == 1){
				tmp1.push_back(i);
				tmp1.push_back(j);
				tmp1.push_back(0);
				answer.push_back(tmp1);
			}
			if(bo[i][j] == 1){
				tmp2.push_back(i);
				tmp2.push_back(j);
				tmp2.push_back(1);
				answer.push_back(tmp2);
			}
		}
	}
	
    return answer;
}





