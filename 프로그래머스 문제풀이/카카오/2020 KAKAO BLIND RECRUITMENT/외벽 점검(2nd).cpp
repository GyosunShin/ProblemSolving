// OUTPUT : ��� ������ �����ϱ� ���� ������ �ϴ� ģ�� ���� �ּҰ��� return
// ģ������ ��� �����ص� ��� ������ ���� ������ �� ���� ��쿡�� -1�� return ���ּ���.

// 1  <= �ܺ��� ���� n  <= 200
// 0 <= weak�� ���� <= n-1 

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
