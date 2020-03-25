// 입력된 도시이름 배열을 순서대로 처리할 때, 총 실행시간을 출력한다.

// cache hit일 경우 실행시간은 1이다.
// cache miss일 경우 실행시간은 5이다.

#include <string>
#include <map> 
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

map<string, int> m;

int ans; 

int solution(int cacheSize, vector<string> cities) {
	
	for(int i = 0 ; i < cities.size() ; ++i){
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
	}
	
	if(cacheSize == 0){
		return 5 * (cities.size());
	}
	
	for(int i = 0 ; i < cities.size() ; ++i){
		
		string target = cities[i];
		int cur_size = m.size();
		bool exist = false;
		
		map<string, int>::iterator it;
		it = m.find(target);
		if(it != m.end()){
			exist = true;
		}
		
		if(exist){	// 이미 존재하는경우 
			ans += 1;
			m[target] = i;
		}
		else{	// 현재 없는 경우 
			
			if(cur_size >= cacheSize){	// 페이지 교체 필요 
				string key;
				int tmp_min = 0x7fffffff;
				
				for(it = m.begin() ; it != m.end() ; ++it){
					if(tmp_min > (it->second)){
						tmp_min = (it->second);
						key = (it->first);
					}
				}
				
				ans += 5;
				m.erase(key);
				m[target] = i;
				
			}
			else{	// 빈자리에 들어가면 됨 
				ans += 5;
				m[target] = i;
			}
			
		}
		
	}
	
	
    return ans;
}
