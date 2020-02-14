// ���� <= 1000     ���� <= 255
// ���� �� 2 ��� X
#include <iostream> 
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	for(int i = 0 ; i < 10 ; ++i){
		int world[1000][255] = { 0, };
		int width;
		scanf("%d", &width);  // ���������� wi 
		
		int ans = 0;
		
		int highest = 0;
		// ������ �Ǽ��� 
		for(int j = 0 ; j < width ; ++j){
			int height;
			scanf("%d", &height);	
			if(highest < height) highest = height; // ���� ���� �ǹ��� ���̸� ���� 
			
			if(height != 0){  // 1�� �̻��� �ǹ��� ������ ��� 
				for(int k = 0 ; k < height ; ++k){
					world[j][k] = 1;
				}
			}
		}
		
		for(int j = 0 ; j < width ; ++j){
			for(int k = 0 ; k < highest ; ++k){
				if(world[j][k] == 1){  // ���밡 �����ϴ� ����̶��!  ������ ���� Ȯ��! 
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
 
