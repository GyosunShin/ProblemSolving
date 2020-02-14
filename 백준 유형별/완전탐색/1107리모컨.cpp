#include <stdio.h>
#include <iostream>
#include <math.h>

//--- Case Check! ----
// 1) 한번에 리모컨 눌러서 해당 채널로 바로 이동!(diff와 값 비교하여 더 작은것 채택!) 
// 2) 최대한 가까운곳 까지 도달한다음에 +,-로 수동으로 도달! (diff와 값 비교하여 더 작은것 채택!) 
// 3) 걍 diff값만 가지고 일일이 도달! 


// diff : 일일이 +, -로 나아갈 경우에 대한 횟수
 

using namespace std;

int buttons[] = {0,1,2,3,4,5,6,7,8,9};

// 현재 너는 100채널에 존재하고 있다. 
int main(){
	int want;   // 가고자 하는 채널 
	cin >> want;
	if(!(0 <= want && want <= 500000)) return -1;
	
	int diff = abs(want - 100);
	
	// 자릿수 구하기 
	int ttmp = want;
	int cnt = 0;
	do{
		ttmp = ttmp / 10;
		cnt ++;
	}while(ttmp != 0);
	
	int check[cnt] = {0,};
	
	int wantChars[7];
	int ztmp = want;
	for(int i = (cnt - 1) ; i >= 0 ; i--){
		wantChars[(cnt-1) - i] = (ztmp / pow(10, i));
		ztmp = ztmp - (wantChars[(cnt-1) - i] * pow(10, i));
	}
//	itoa(want, wantChars, 10);

	int broken;  // 망가진 버튼 수 
	cin >> broken;
	if(!(0 <= broken && broken <= 10)) return -1;
	int brokenButtons[broken];    // 망가진 버튼의 조합 
	for(int i = 0 ; i < broken; i++){
		cin >> brokenButtons[i];
		buttons[brokenButtons[i]] = -1;
	}
			
	// 일단 기저 사례 확인하자~ 
	
	// 기저사례1 : 원하는 채널이 지금 자신이 존재하는 100채널일 경우 
	if(want == 100){
		cout << 0 <<endl;
		return 0;
	}
	
	int first = 0;
	for(int i = 0 ; i < cnt ; i++){
		if(buttons[wantChars[i]] == -1){  // 버튼 존재 안하는 가장큰 자릿수를 찾는다 
			first = i;
			break; // 가장 큰 첫번째 자릿수 찾자마자 나가버린다.
		}
	} 
	
	// 가용가능한 버튼 중에가장큰 값, 가장 작은 값 찾아야 한다.
	int min, max;
	for(int i = 0 ; i < 10 ; i++){
		if(buttons[i] != -1){
			min = buttons[i];
			break;
		} 
	}
	for(int i = 9 ; i >= 0 ; i--){
		if(buttons[i] != -1){
			max = buttons[i];
			break;
		} 		
	}
	
	
	// 제일 위에 정리한 3가지 Case중에 어떤거 인지 확인해보자
	int correct = 0;
	for(int i = 0 ; i < cnt ; i++){
		if(check[i] == 1) correct++;
	}
	
	int tmpChars[7];   // 그나마 제일 가까운 숫자 저장하는곳 
	
	
	if(correct == cnt){  // Case1일 경우 
		if(correct > diff)	cout << diff << endl;
		else cout << correct << endl;
	}
	else{  // Case2일 경우 
		for(int i = 0 ; i < cnt ; i++){
			if(i < first){
				tmpChars[i] = wantChars[i];
			}
			else if(i == first){ // i가 딱 first가 된 시점! 
//				// 남은 자릿수들 
//				for(int z = 0 ; z < 10 ; z++){
//					cout << "buttons  " << buttons[z] << endl;
//				}
				
				int remain = (cnt - i);
				// 현재 오류난 자리의 원래 값
				int origin = wantChars[i];
//				cout << "origin : " << origin << endl;
				
				int tmpmin, tmpmax;
				
				//-----------------------------------------
				for(int z = (origin + 1) ; z < 10 ; z++){
					if(buttons[z] != -1){
						tmpmin = buttons[z];
						break;
					}
				}				
//				cout << "tmpmin : " << tmpmin << endl;

				int ver = 0;
				for(int z = (origin - 1) ; z >= 0 ; z--){
					ver++;
//					cout << "TEST : " << z << endl;
					if(buttons[z] != -1){
						tmpmax = buttons[z];
						break;
					}
				}
				
//				cout << "tmpmax : " << tmpmax << endl;
				//-----------------------------------------
				
				int finalmin = 0;
				int finalmax = 0;
				int realremain = 0;
				for(int k = (remain-1) ; k >= 0 ; k--){
					if(k == remain - 1)
						finalmin += tmpmin * pow(10, k);
					else
						finalmin += min * pow(10, k);
				}
//				cout << "finalmin : " << finalmin << endl;
				for(int k = (remain-1) ; k >= 0 ; k--){
					if(k == remain - 1)
						finalmax += tmpmax * pow(10, k);
					else
						finalmax += max * pow(10, k);
				}				
//				cout << "finalmax : " << finalmax << endl;
				
				int tttmp = cnt - 1;
				for(int k = 0 ; k < remain ; k++){
					realremain += (wantChars[tttmp]) * pow(10, k);
					tttmp -= 1;
				}
//				cout << "realremain : " << realremain << endl;
				

				int diff1 = abs(realremain - finalmin);
//				cout << "diff1 : " << diff1 << endl;
				int diff2 = abs(realremain - finalmax);
//				cout << "diff2 : " << diff2 << endl;
				
				if(ver == 0){
					cout << diff1 + cnt<<endl;
					return 0;
				}
				
				int realans = 0;
				
				if(diff1 < diff2){
					realans = (diff1 + cnt);
				}
				else{
					realans = (diff2 + cnt);
				}
				
				cout << realans << endl;
				break;
			}
		}
	}
//	for( int i = 0 ; i < cnt ; i++){
//		cout << i << " : " << tmpChars[i] << endl;
//	}
}
