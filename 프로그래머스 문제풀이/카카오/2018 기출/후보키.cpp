#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countBits(int n){
	int ret = 0;
	while(n){
		if(n & 1)	++ret;
		n = n >> 1;
	}
	return ret;
}

bool comp(int a, int b){  // 더 긴 비트열을 앞쪽으로(길이 기준 : 내림 차순) 
	int x = countBits(a); int y = countBits(b);
	return x > y;
}

bool check(vector<vector<string> > relation, int rowsize, int colsize, int subset){
	for(int a = 0 ; a < rowsize - 1 ; ++a){
		for(int b = a + 1 ; b < rowsize ; ++b){
			bool isSame = true;
			for(int k = 0 ; k < colsize ; ++k){
				if((subset & 1 << k) == 0)	continue;
				if(relation[a][k] != relation[b][k]){
					isSame = false;
					break;
				}
			}
			if(isSame)	return false;
		}
	}
	return true;
}

int solution(vector<vector<string> > relation){
	int answer = 0;
	int rowsize = relation.size();
	int colsize = relation[0].size();
	vector<int> candidates;
	
	for(int i = 1 ; i< (1 << colsize) ; ++i){
		if(check(relation, rowsize, colsize, i)){
			candidates.push_back(i);
		}
	}
	
	sort(candidates.begin(), candidates.end(), comp);  // (길이 기준 : 내림 차순) 
	
	while(!candidates.empty()){
		int n = candidates.back();  // 가장 적은 속성을 가지는것을 꺼내온다 
		candidates.pop_back();
		++answer; 
		
		for(vector<int>::iterator it = candidates.begin() ; it != candidates.end();){
			if((n & *it) == n){   // 적은 속성을 가진놈이랑 AND 연산해서 적은 속성이랑 똑같은 값 나오면 최소성 만족 못하는거임! 
				it = candidates.erase(it);   
			}
			else{
				++it;	
			}
		}
		
	}
	
	return answer;
}
