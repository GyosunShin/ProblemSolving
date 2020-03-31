//  방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.

// 각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long long> answer;

set<long long> s;

set<long long>::iterator it;

vector<long long> solution(long long k, vector<long long> room_number) {
    // 1 <= k <= 10^12
    // 1 <= room_number.size() <= 200,000
    
    for(int i = 0 ; i < room_number.size() ; ++i){
    	long long target = room_number[i];    	
    	
    	it = s.find(target);
    	if(it == s.end()){
    		answer.push_back(target);
    		s.insert(target);
    	}
    	else{
    		long long start = target+1;
    		while(true){
    			
    			it = s.find(start);
    			if(it == s.end()){
    				answer.push_back(start);
    				s.insert(start);
    				break;
    			}
    			else{
    				start++;
    				continue;
    			}
    			
    		}
    	}
    	
    }
    
    
    return answer;
}
