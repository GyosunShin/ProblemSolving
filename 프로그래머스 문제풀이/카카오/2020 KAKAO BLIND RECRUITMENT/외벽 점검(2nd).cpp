// OUTPUT : 취약 지점을 점검하기 위해 보내야 하는 친구 수의 최소값을 return
// 친구들을 모두 투입해도 취약 지점을 전부 점검할 수 없는 경우에는 -1을 return 해주세요.

// 1  <= 외벽의 길이 n  <= 200
// 0 <= weak의 원소 <= n-1 

#include <string>
#include <vector>

using namespace std;

int N;
answer = 0x7fffffff;

bool pan[200];

int global_cnt;


bool check(){
	bool ret = true;
	for(int i= 0 ; i < N ; ++i){
		if(pan[i]){
			ret = false;
			break;
		}
	}
	return ret;
}

void dfs(){
	
	
	
	
}

bool solve(int cnt){
	global_cnt = cnt;
	
	dfs();
	
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
    
    for(int i = 0 ; i < weak.size() ; ++i){
    	pan[weak[i]] = true;
    }
    
    for(int i = 0 ; i <= dist.size() ; ++i){
    	if(solve(i)){
    		answer = i;
    		break;
    	}
    }
    
    if(answer == 0x7fffffff)	answer = -1;
    
    return answer;
}
