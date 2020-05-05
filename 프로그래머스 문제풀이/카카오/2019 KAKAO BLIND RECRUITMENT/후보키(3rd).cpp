
// OUTPUT
// 후보 키의 개수를 return

#include <string>
#include <vector>
#include <cmath>
#include <set>
//#include <bitset>
#include <iostream>

using namespace std;

int R, C;

set<vector<string>> s;
set<vector<string>>::iterator it;

vector<int> track;

bool check(int input, vector<vector<string>>& pan){
	
//	cout << bitset<4>(input) << "\n";
	s.clear();
	
	for(int i = 0 ; i < pan.size() ; ++i){
		vector<string> tmp;
		
		for(int j = 0 ; j < C ; ++j){
			if((input & (int)pow(2, j)) != 0){
				tmp.push_back(pan[i][C-1-j]);
			}
		}
		
		it = s.find(tmp);
		if(it != s.end())	return false;
		
		s.insert(tmp);	// 유일성 만족 
		
	}
	
	// 최소성 확인 
	for(int i = 0 ; i < track.size() ; ++i){
		int cur = track[i];
		if((cur & input) == cur)	return false;
	}
	 
	track.push_back(input);
	return true;
}

int solution(vector<vector<string>> relation) {
    R = relation.size();
    C = relation[0].size();
    
    int answer = 0;
    
    for(int i = 1 ; i <= ((int)pow(2, C) - 1) ; ++i){
    	if(check(i, relation)){
//    		cout << "++++" << "\n";
			answer++;
		}
    }
    
    return answer;
}
