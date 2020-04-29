#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> parent;
map<long long, long long>::iterator it;

vector<long long> answer;
long long K;

long long find(long long u){
	it = parent.find(u);
	
	if(it == parent.end()){
		answer.push_back(u);
		parent[u] = u+1;
		return u+1;
	}
	
	return parent[u] = find(parent[u]);
}

vector<long long> solution(long long k, vector<long long> room_number){
    K = k;
    
    for(int i = 0 ; i < room_number.size() ; ++i){
    	
    	long long cur = room_number[i];
    	it = parent.find(cur);
    	if(it == parent.end()){
    		answer.push_back(cur);
    		parent[cur] = cur+1;
    		continue;
    	}
    	find(cur);
    	
    }
    
    return answer;
}
