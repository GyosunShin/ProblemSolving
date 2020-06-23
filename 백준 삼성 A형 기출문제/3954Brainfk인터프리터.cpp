// 0 < t ≤ 20

// (0 < sm(메모리(배열)의 크기) ≤ 100,000, 0 < sc(프로그램 코드의 크기), si(입력의 크기) < 4096) 

#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int T;
int M, C, I;

char codes[4096];
char inputs[4096];

unsigned char pan[100000];

stack<int> st;

int match[4096];

int ptrChange(int panIdx, char cmd){
	
	if(cmd == '<'){
		panIdx--;
		if(panIdx < 0)	panIdx = M-1;
	}
	else if(cmd == '>'){
		panIdx++;
		if(panIdx >= M)	panIdx = 0;
	}
	
	return panIdx;
}

void solve(){
	
	int cmdPtr = 0;
	int panIdx = 0;
	int inputIdx = 0;	// 0 <= inputIdx <= (I-1)
	
	int lastLoop = -1;
	int maxLoop = 0;
	
	int cnt = 0;
	
	while(true){
		if(cnt > 50000000){			
			printf("Loops %d %d\n", match[maxLoop], maxLoop);
			return;
		}
		cnt++; 	
		
		if(cmdPtr >= C)	break;
		
		char cmd = codes[cmdPtr];
		
		if(cmd == '-'){	
			// 포인터가 가리키는 수를 1 감소시킨다. (modulo 2^8 = 256)
			pan[panIdx]--;
		}
		else if(cmd == '+'){
			// 포인터가 가리키는 수를 1 증가시킨다. (modulo 2^8 = 256)
			pan[panIdx]++;
		}
		else if(cmd == '<'){
			// 포인터를 왼쪽으로 움직인다.(1 감소)
			panIdx = ptrChange(panIdx, cmd);
		}
		else if(cmd == '>'){
			// 포인터를 오른쪽으로 움직인다.(1 증가)			
			panIdx = ptrChange(panIdx, cmd);
		}
		else if(cmd == '['){
			// 만약 포인터가 가리키는 수가 0과 같다면, [와 짝을 이루는 ]로 점프한다.
			if(pan[panIdx] == 0){
				cmdPtr = match[cmdPtr];
				continue;
			}
			
		}
		else if(cmd == ']'){
			// 만약 포인터가 가리키는 수가 0이 아니라면, ]와 짝을 이루는 [로 점프한다.
			if(pan[panIdx] != 0){
				lastLoop = cmdPtr;
				maxLoop = max(maxLoop, lastLoop);
				cmdPtr = match[cmdPtr];
				continue;
			}			
			
		}
		else if(cmd == '.'){
			// 포인터가 가리키는 수를 출력한다.
			
			
		}
		else if(cmd == ','){
			// 문자 하나를 읽고 포인터가 가리키는 곳에 저장한다.
			// 입력의 마지막(EOF)인 경우에는 255를 저장한다.
			if(inputIdx >= I){
				pan[panIdx] = 255;
			}
			else if(inputIdx < I){
				pan[panIdx] = inputs[inputIdx];
				inputIdx++;
			}
		}
		cmdPtr++;
	}
	
	printf("Terminates\n");
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(pan, 0, sizeof(pan));
		scanf("%d %d %d", &M, &C, &I);
		getchar();
		for(int i = 0 ; i < C ; ++i){
			scanf("%1c", &codes[i]);
			if(codes[i] == '['){
				st.push(i);
			}
			else if(codes[i] == ']'){
				int who = st.top();
				st.pop();
				match[who] = i;
				match[i] = who;
			}
		}
		getchar();
		for(int i = 0 ; i < I ; ++i){
			scanf("%1c", &inputs[i]);
		}
		getchar();
		
		solve(); 		
	}
	return 0;
}
