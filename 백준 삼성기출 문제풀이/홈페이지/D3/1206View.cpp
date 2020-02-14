// 가로 <= 1000     세로 <= 255
// 양쪽 끝 2 사용 X
#include <iostream> 
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	for(int i = 0 ; i < 10 ; ++i){
		int world[1000][255] = { 0, };
		int width;
		scanf("%d", &width);  // 실질적으로 wi 
		
		int ans = 0;
		
		int highest = 0;
		// 세대주 건설중 
		for(int j = 0 ; j < width ; ++j){
			int height;
			scanf("%d", &height);	
			if(highest < height) highest = height; // 가장 높은 건물의 높이를 저장 
			
			if(height != 0){  // 1층 이상의 건물이 존재할 경우 
				for(int k = 0 ; k < height ; ++k){
					world[j][k] = 1;
				}
			}
		}
		
		for(int j = 0 ; j < width ; ++j){
			for(int k = 0 ; k < highest ; ++k){
				if(world[j][k] == 1){  // 세대가 존재하는 블록이라면!  조망권 조건 확인! 
					int flag = 0;
					if(world[j-1][k] == 0 && world[j-2][k] == 0 && world[j+1][k] == 0 && world[j+2][k] == 0) {
						ans += 1;
					}
				}
			}
		}
		
		cout << "#" << (i+1) << " " << ans << endl;
	}	
}
 
