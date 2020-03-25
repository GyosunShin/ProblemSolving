// �Էµ� �����̸� �迭�� ������� ó���� ��, �� ����ð��� ����Ѵ�.

// cache hit�� ��� ����ð��� 1�̴�.
// cache miss�� ��� ����ð��� 5�̴�.

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
		
		if(exist){	// �̹� �����ϴ°�� 
			ans += 1;
			m[target] = i;
		}
		else{	// ���� ���� ��� 
			
			if(cur_size >= cacheSize){	// ������ ��ü �ʿ� 
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
			else{	// ���ڸ��� ���� �� 
				ans += 5;
				m[target] = i;
			}
			
		}
		
	}
	
	
    return ans;
}
