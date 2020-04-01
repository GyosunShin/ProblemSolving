// 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return

#include <string>
#include <vector>

using namespace std;

int N;
int answer;

vector<int> bucket;
vector<int> machine[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    N = board.size();
    
    for(int i = 0 ; i < N ; ++i){			// C
    	for(int j = N-1 ; j >= 0 ; --j){	// R
    		
    		if(board[j][i] == 0)	break;
    		machine[i].push_back(board[j][i]);
    		
    	}
    }
    
    for(int i = 0 ; i < moves.size() ; ++i){
    	
    	int target = moves[i] - 1;
    	
    	if(machine[target].size() == 0)	continue;
    	
    	int top = machine[target].back();
    	machine[target].pop_back();
    	bucket.push_back(top);
    	
    	if(bucket.size() >= 2){
    		
    		if(bucket[bucket.size() - 1] == bucket[bucket.size() - 2]){
    			answer += 2;
    			bucket.pop_back();	bucket.pop_back();
    		}
    		
    	}
    	
    }
    
	return answer;
	    
}




