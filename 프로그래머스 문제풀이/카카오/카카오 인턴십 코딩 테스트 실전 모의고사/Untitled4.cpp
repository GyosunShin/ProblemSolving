//  ���� �̹� �����Ǿ� ������ ���ϴ� �溸�� ��ȣ�� ũ�鼭 ����ִ� �� �� ���� ��ȣ�� ���� ���� �����մϴ�.

// �� ������ �����Ǵ� �� ��ȣ�� ������� �迭�� ��� return

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
