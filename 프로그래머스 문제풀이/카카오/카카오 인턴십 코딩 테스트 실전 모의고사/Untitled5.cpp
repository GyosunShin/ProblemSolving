
// 최대 몇 명까지 징검다리를 건널 수 있는지 return 


// 1 <= stones.size() <= 200,000
// 1 <= stones[i] <= 200,000,000

#include <string>
#include <vector>

using namespace std;

int answer;

int solution(vector<int> stones, int k) {
    
    while(true){
    	
    	bool flag = true;
    	
    	for(int i = 0 ; i < stones.size() ; ++i){
    		
    		int cnt = 1;
    		if(stones[i] == 0){
    			for(int j = i+1 ; j < stones.size(); ++j){
    				if(stones[j] > 0){
    					break;
    				}
    				cnt++;
    			}
    		}
    		
    		if(cnt >= 3){
    			flag = false;
    			break;
    		}
    		
    		i += cnt-1;
    		
    	}
    	
    	if(!flag)	break;
    	
    	for(int i = 0 ; i < stones.size() ; ++i){
    		stones[i]--;	
    	}
    	
    	answer++;
    }
    
    
    return answer;
}
