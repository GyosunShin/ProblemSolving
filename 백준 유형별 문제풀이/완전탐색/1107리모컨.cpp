#include <stdio.h>
#include <iostream>
#include <math.h>

//--- Case Check! ----
// 1) �ѹ��� ������ ������ �ش� ä�η� �ٷ� �̵�!(diff�� �� ���Ͽ� �� ������ ä��!) 
// 2) �ִ��� ������ ���� �����Ѵ����� +,-�� �������� ����! (diff�� �� ���Ͽ� �� ������ ä��!) 
// 3) �� diff���� ������ ������ ����! 


// diff : ������ +, -�� ���ư� ��쿡 ���� Ƚ��
 

using namespace std;

int buttons[] = {0,1,2,3,4,5,6,7,8,9};

// ���� �ʴ� 100ä�ο� �����ϰ� �ִ�. 
int main(){
	int want;   // ������ �ϴ� ä�� 
	cin >> want;
	if(!(0 <= want && want <= 500000)) return -1;
	
	int diff = abs(want - 100);
	
	// �ڸ��� ���ϱ� 
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

	int broken;  // ������ ��ư �� 
	cin >> broken;
	if(!(0 <= broken && broken <= 10)) return -1;
	int brokenButtons[broken];    // ������ ��ư�� ���� 
	for(int i = 0 ; i < broken; i++){
		cin >> brokenButtons[i];
		buttons[brokenButtons[i]] = -1;
	}
			
	// �ϴ� ���� ��� Ȯ������~ 
	
	// �������1 : ���ϴ� ä���� ���� �ڽ��� �����ϴ� 100ä���� ��� 
	if(want == 100){
		cout << 0 <<endl;
		return 0;
	}
	
	int first = 0;
	for(int i = 0 ; i < cnt ; i++){
		if(buttons[wantChars[i]] == -1){  // ��ư ���� ���ϴ� ����ū �ڸ����� ã�´� 
			first = i;
			break; // ���� ū ù��° �ڸ��� ã�ڸ��� ����������.
		}
	} 
	
	// ���밡���� ��ư �߿�����ū ��, ���� ���� �� ã�ƾ� �Ѵ�.
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
	
	
	// ���� ���� ������ 3���� Case�߿� ��� ���� Ȯ���غ���
	int correct = 0;
	for(int i = 0 ; i < cnt ; i++){
		if(check[i] == 1) correct++;
	}
	
	int tmpChars[7];   // �׳��� ���� ����� ���� �����ϴ°� 
	
	
	if(correct == cnt){  // Case1�� ��� 
		if(correct > diff)	cout << diff << endl;
		else cout << correct << endl;
	}
	else{  // Case2�� ��� 
		for(int i = 0 ; i < cnt ; i++){
			if(i < first){
				tmpChars[i] = wantChars[i];
			}
			else if(i == first){ // i�� �� first�� �� ����! 
//				// ���� �ڸ����� 
//				for(int z = 0 ; z < 10 ; z++){
//					cout << "buttons  " << buttons[z] << endl;
//				}
				
				int remain = (cnt - i);
				// ���� ������ �ڸ��� ���� ��
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
