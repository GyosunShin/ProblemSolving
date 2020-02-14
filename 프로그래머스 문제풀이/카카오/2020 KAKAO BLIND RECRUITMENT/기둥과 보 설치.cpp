// 5 <= N <= 100 

// ��� ��ɾ ������ �� �������� ���¸� return �ϵ��� solution �Լ��� �ϼ����ּ���.

// INPUT
// [x, y, a, b]
// a : (0 ���) (1 ��)
// b : (0 ����) (1 ��ġ)

// OUTPUT
// [x, y, a]
// x��ǥ �������� �������� �����ϸ�, x��ǥ�� ���� ��� y��ǥ �������� �������� �������ּ���.
// x, y��ǥ�� ��� ���� ��� ����� ������ �տ� ���� �˴ϴ�. 

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
		
		if(a == 0){   // ����� ��� 
			if(b == 1){  // ��ġ�ϴ�  ���  
			
				// ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
			
				if(y == 0){  // �ٴڿ� ��ġ�� ��� 
					kidong[x][y] = 1; 
				}
				else{  // �ٴں��� ���� ��ġ�� ��� 
					
					if(kidong[x][y-1] == 1 || bo[x-1][y] == 1 || bo[x][y] == 1){
						kidong[x][y] = 1;
					}
					else	continue;
				}
			}
			else{  	// �����ϴ� ��� 
				
				if(kidong[x][y+1] == 1 && bo[x-1][y+1] == 0 && bo[x][y+1] == 0)	continue;
				if(bo[x-1][y+1] == 1 && bo[x-2][y+1] == 0 && kidong[x-1][y] == 0)	continue;
				if(bo[x][y+1] == 1 && bo[x+1][y+1] == 0 && kidong[x+1][y] == 0)	continue;
				
				kidong[x][y] = 0; 
			}
		}
		else{  // ���� ��� 
			if(b == 1){  // ��ġ�ϴ�  ���  
				
				// ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
				if(kidong[x][y-1] == 1 || kidong[x+1][y-1] == 1 || (bo[x-1][y] == 1 && bo[x+1][y] == 1)){
					bo[x][y] = 1;
				}
				else	continue;
				
			}	
			else{ // �����ϴ� ��� 
			
				if(kidong[x][y] == 1 && bo[x-1][y] == 0 && kidong[x][y-1] == 0)	continue;
				if(kidong[x+1][y] == 1 && bo[x+1][y] == 0 && kidong[x+1][y-1] == 0)	continue;
				if(bo[x-1][y] == 1 && kidong[x-1][y-1] == 0 && kidong[x][y-1] == 0)	continue;
				if(bo[x+1][y] == 1 && kidong[x+1][y-1] == 0 && kidong[x][y-1] == 0)	continue;
				
				bo[x][y] = 0; 
				
			}
		}
		
	}
	
	// ���� kidong[][]�� bo[][]�� ���� answer 2���� vector�� ������ 
	
	//  [x, y, a]
	// 0�� ���, 1�� ��
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





