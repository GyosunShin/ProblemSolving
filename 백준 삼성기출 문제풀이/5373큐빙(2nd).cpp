// 윗 면의 색상을 출력한다. 
//  흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.

#include <stdio.h>

int main(){
	int tc;
	scanf("%d", &tc);
	for(int t = 0 ; t < tc ; ++t){
		
		// 초기 큐브 초기화 
		char up[3][3] = { 'w', };
		char down[3][3] = { 'y', };
		char forward[3][3] = { 'r', };
		char backward[3][3] = { 'o', };
		char left[3][3] = { 'g', };
		char right[3][3] = { 'b', };
		
		// 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n ≤ 1000)
		int n;
		scanf("%d", &n);  
		char m[1000];
		char d[1000];
		
		for(int i = 0 ; i < n ; ++i){  // 큐브를 돌린 횟수만큼 
		// U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
		// +인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준), -인 경우에는 반시계 방향이다.
			char tmp[2];
			scanf("%s", &tmp);
			m[i] = tmp[0];	d[i] = tmp[1];
			if(m[i] == 'U' && d[i] == '+') {
				char tmp_right00 = right[0][0];
				char tmp_right01 = right[0][1];
				char tmp_right02 = right[0][2];
				right[0][0] = backward[0][2];
				right[0][1] = backward[0][1];
				right[0][2] = backward[0][0];
				backward[0][0] = left[0][0];
				backward[0][1] = left[0][1];
				backward[0][2] = left[0][2];
				left[0][0] = forward[0][2];
				left[0][1] = forward[0][1];
				left[0][2] = forward[0][0];
				forward[0][0] = tmp_right00;
				forward[0][1] = tmp_right01;
				forward[0][2] = tmp_right02;
				
				char backup00 = up[0][0];
				char backup01 = up[0][1];
				char backup02 = up[0][2];
				char backup10 = up[1][0];
				char backup11 = up[1][1];
				char backup12 = up[1][2];
				char backup20 = up[2][0];
				char backup21 = up[2][1];
				char backup22 = up[2][2];
				up[0][0] = backup20;
				up[0][1] = backup10;
				up[0][2] = backup00;
				up[1][0] = backup21;
				up[1][1] = backup11;
				up[1][2] = backup01;
				up[2][0] = backup22;
				up[2][1] = backup12;
				up[2][2] = backup02;
			}
			else if(m[i] == 'U' && d[i] == '-') {
				char for00 = forward[0][0];
				char for01 = forward[0][1];
				char for02 = forward[0][2];
				forward[0][0] = left[0][2];
				forward[0][1] = left[0][1];
				forward[0][2] = left[0][0];
				left[0][0] = backward[0][0];
				left[0][1] = backward[0][1];
				left[0][2] = backward[0][2];
				backward[0][0] = right[0][2];
				backward[0][1] = right[0][1];
				backward[0][2] = right[0][0];
				right[0][0] = for00;
				right[0][1] = for01;
				right[0][2] = for02;
				
				char backup00 = up[0][0];
				char backup01 = up[0][1];
				char backup02 = up[0][2];
				char backup10 = up[1][0];
				char backup11 = up[1][1];
				char backup12 = up[1][2];
				char backup20 = up[2][0];
				char backup21 = up[2][1];
				char backup22 = up[2][2];
				up[0][0] = backup02;
				up[0][1] = backup12;
				up[0][2] = backup22;
				up[1][0] = backup01;
				up[1][1] = backup11;
				up[1][2] = backup21;
				up[2][0] = backup00;
				up[2][1] = backup10;
				up[2][2] = backup20;
			}			
			
			else if(m[i] == 'D' && d[i] == '+') {
				
				
				char backup00 = down[0][0];
				char backup01 = down[0][1];
				char backup02 = down[0][2];
				char backup10 = down[1][0];
				char backup11 = down[1][1];
				char backup12 = down[1][2];
				char backup20 = down[2][0];
				char backup21 = down[2][1];
				char backup22 = down[2][2];
				down[0][0] = backup20;
				down[0][1] = backup10;
				down[0][2] = backup00;
				down[1][0] = backup21;
				down[1][1] = backup11;
				down[1][2] = backup01;
				down[2][0] = backup22;
				down[2][1] = backup12;
				down[2][2] = backup02;				
			}			
			else if(m[i] == 'D' && d[i] == '-') {
				
				
				char backup00 = down[0][0];
				char backup01 = down[0][1];
				char backup02 = down[0][2];
				char backup10 = down[1][0];
				char backup11 = down[1][1];
				char backup12 = down[1][2];
				char backup20 = down[2][0];
				char backup21 = down[2][1];
				char backup22 = down[2][2];
				down[0][0] = backup02;
				down[0][1] = backup12;
				down[0][2] = backup22;
				down[1][0] = backup01;
				down[1][1] = backup11;
				down[1][2] = backup21;
				dpwn[2][0] = backup00;
				down[2][1] = backup10;
				down[2][2] = backup20;				
			}						
			
			else if(m[i] == 'F' && d[i] == '+') {
				
			}			
			else if(m[i] == 'F' && d[i] == '-') {
				
			}			

			else if(m[i] == 'B' && d[i] == '+') {
				
			}			
			else if(m[i] == 'B' && d[i] == '-') {
				
			}	
			
			else if(m[i] == 'L' && d[i] == '+') {
				
			}			
			else if(m[i] == 'L' && d[i] == '-') {
				
			}			
			
			else if(m[i] == 'R' && d[i] == '+') {
				
			}			
			else if(m[i] == 'R' && d[i] == '-') {
				
			}																	
						
		}
		//##############################################################################
		
		 
		
		
		// 정답 뿌리는 중 
		printf("%c%c%c\n", up[0][0]m up[0][1], up[0][2]);
		printf("%c%c%c\n", up[1][0]m up[1][1], up[1][2]);
		printf("%c%c%c\n", up[2][0]m up[2][1], up[2][2]);	
	}
	return 0;
}

