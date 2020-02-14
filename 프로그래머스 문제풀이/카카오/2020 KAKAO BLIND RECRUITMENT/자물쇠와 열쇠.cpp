// 0 : 홈 / 1 : 돌기 
// key는 M x M(3 ≤ M ≤ 20
// lock은 N x N(3 ≤ N ≤ 20

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int klen, llen;
vector<vector<int>> global_key;
vector<vector<int>> global_lock;
vector<pair<int, int>> home;

bool ans = false;

vector<vector<int>> clockwise(vector<vector<int>> input){
	vector<vector<int>> ret;
	for(int i = 0 ; i < input.size() ; ++i){
		vector<int> ttmp;
		for(int j = 0 ; j < input[i].size() ; ++j){
			ttmp.push_back(input[(klen-1)- j][i]);
		}
		ret.push_back(ttmp);
	}
	return ret;
}	

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	global_key = key;
	global_lock = lock;
	klen = key.size();
    llen = lock.size();
	
	for(int i = 0 ; i < lock.size() ; ++i){
		for(int j = 0 ; j < lock[i].size() ; ++j){
			if(lock[i][j] == 0){
				home.push_back(pair<int, int>(i, j));	
			}
		}
	}
    
    for(int i = -klen ; i <= llen + klen ; ++i){
    	for(int j = -klen ; j <= llen + klen ; ++j){
    		// [r][c] --> [r+i][c+j]
    		for(int k = 0 ; k < 4 ; ++k){
    			vector<vector<int>> tmp = global_key;
    			for(int z = 0 ;  z < k ; ++z){
    				tmp = clockwise(tmp);
    			}
    			int cnt = 0;
    			int f_cnt = 0;
    			for(int r = 0 ; r < tmp.size() ; ++r){
    				for(int c ; c < tmp[r].size() ; ++c){
    					if(0 <= r+i && r+i < llen && 0 <= c+j && c+j < llen){
    						if(tmp[r+i][c+j] == 1 && lock[r+i][c+j] == 0)	++cnt;
    						if(tmp[r+i][c+j] == 1 && lock[r+i][c+j] == 1)	++f_cnt;
    					}
    				}
    			}
    			if(cnt == home.size() && f_cnt == 0){
    				ans = true;
    				break;	
    			}
    			
    		}
    	}
    }
    
    
    return ans;
}
