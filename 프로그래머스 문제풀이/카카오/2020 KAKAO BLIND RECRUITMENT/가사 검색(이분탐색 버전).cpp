#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> answer;
vector<string> revs;

int solve(string input, vector<string>& queries){
	
	int ret = 0;
	
	for(int i = 0 ; i < input.size() ; ++i){
		char target = input[i]
		if(target == '?'){
			break;
		}
		
		
	}
	
	return ret;
	
}

vector<int> solution(vector<string> words, vector<string> queries) {
    
    for(int i = 0 ; i < words.size() ; ++i){
    	string tmp = words[i];
    	reverse(tmp.begin(), tmp.end());
    	revs.push_back(tmp);
    }
    
    sort(queries.begin(), queries.end());	sort(revs.begin(), revs.end());
    
    for(int i = 0 ; i < queries.size() ; ++i){
    	
    	if(queries[i].back() == '?'){
    		answer.push_back(solve(queries[i], queries));
    	}
    	else{
    		string ttmp = queries[i];
    		reverse(ttmp.begin(), ttmp.end());	
    		answer.push_back(solve(ttmp, revs));
    	}
    	
    }
    
    return answer;
}
