
// 1 <= k <= 10 ^ 12
// 1<= room_number.size() <= 200,000
// 1 <= 각 원소 <= k 

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<long long, long long>::iterator it;

vector<long long> answer;

struct OptimizedDisjointSet{
	map<long long, long long> parent;
	
	long long find(long long u){	
		// u가 속한 트리의 root번호 반환 
		it = parent.find(u);
		
		if(it == parent.end()){
			parent[u] = u+1;
			return u;
		}
		else{
			return parent[u] = find(parent[u]);
		}
	}	
	
//	void merge(int u, int v){
//		u = 
//		
//	}
	
};


vector<long long> solution(long long k, vector<long long> room_number) {
    // [1,3,4,1,3,1]
    
    OptimizedDisjointSet root;
    
    for(int i = 0 ; i < room_number.size() ; ++i){
    	int now = room_number[i];
    	int ret = root.find(now);
    	answer.push_back(ret);
    }
    
    return answer;
}
