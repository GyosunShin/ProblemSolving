// B 팀원들이 얻을 수 있는 최대 승점을 return

#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int ans = 0;
	
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int bdex = 0;
    
    for(int i = 0 ; i < A.size() ; ++i){
    	if(bdex >= B.size())	break;
    	if(A[i] < B[bdex]){
    		++ans;
    		++bdex;
    	}
    	else{
    		while(1){
    			++bdex;
    			if(bdex >= B.size())	break;
    			if(A[i] < B[bdex]){
    				++bdex;
    				++ans;
    				break;
    			}		
    		}
    	}
    }
 	return ans;   
}

