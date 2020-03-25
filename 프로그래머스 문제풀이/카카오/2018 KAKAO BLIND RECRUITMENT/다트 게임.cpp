

// Single(S), Double(D), Triple(T) =  1제곱, 2제곱, 3제곱 
// 스타상(*) , 아차상(#) = 
// 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다
// 아차상(#) 당첨 시 해당 점수는 마이너스된다.

#include <string>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> idxes;
vector<string> strs;
vector<int> score;
vector<int> opts;

// 3번의 기회에서 얻은 점수 합계에 해당하는 정수값을 출력한다.
int solve(){
	
	for(int i = 0 ; i < opts.size() ; ++i){
		
		if(opts[i] == 0){
			continue;
		}
		else if(opts[i] == 1){	// 스타상 
			if(i == 0){
				score[0] *= 2;
			}
			else{
				score[i] *= 2;
				score[i-1] *= 2;
			}
		}
		else if(opts[i] == 2){	// 아차상 
			
			score[i] *= -1;
			
		}
		
	}
	
	int ret = 0;
	for(int i = 0 ; i < score.size() ; ++i)	ret += score[i];
	return ret;	
}


int solution(string dartResult) {
	
	for(int i = 0 ; i < dartResult.size() ; ++i){
		if('0' <= dartResult[i] && dartResult[i] <= '9'){			
			if(dartResult[i] == '1' && dartResult[i+1] == '0'){
				idxes.push_back(i);
				++i;
			}
			else{
				idxes.push_back(i);
			}
			
		}
	}
	idxes.push_back(dartResult.size());
	
	for(int i= 0 ; i < idxes.size()-1 ; ++i){
		strs.push_back(dartResult.substr(idxes[i], idxes[i+1] - idxes[i]));
	}
	
	for(int i= 0 ; i < strs.size() ; ++i){
		int cnt;
		char se;
		int p;
		bool flag = false;
		char opt;
		if(strs[i][0] == '1' && strs[i][1] == '0'){
			cnt = 10;
			se = strs[i][2];
			if(strs[i].size() == 4){
				flag = true;
				opt = strs[i][3];
			}
		}
		else{
			cnt = strs[i][0] - '0';
			se = strs[i][1];
			if(strs[i].size() == 3){
				flag = true;
				opt = strs[i][2];
			}
		}
		
		if(se == 'S'){
			p = 1;
		}
		else if(se == 'D'){
			p = 2;
		}
		else if(se == 'T'){
			p = 3;
		}
		
		score.push_back((int)pow(cnt, p));
		
		if(flag){
			if(opt == '*')	opts.push_back(1);
			else if(opt == '#')	opts.push_back(2);
		}
		else{
			opts.push_back(0);
		}
		
	}
	
	// 3번의 기회에서 얻은 점수 합계에 해당하는 정수값을 출력한다.
    return solve();
}
