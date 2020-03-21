
// (실패율) = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

// OUTPUT
// 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return

// 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
// 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다. 

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> answer;

int pan[502];

vector<pair<float, int>> vs;	// (실패율 / 스테이지 번호)

bool comp(const pair<float, int>& a, const pair<float, int>& b){
	
	if(a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    
    for(int i = 0 ; i < stages.size() ; ++i){
    	pan[stages[i]]++;
    }
    
    for(int i = 1 ; i <= N ; ++i){
    	
    	int bunmo = 0;
    	
    	for(int j = i ; j <= N+1 ; ++j)	bunmo += pan[j];	
    	
    	if(bunmo == 0){
    		vs.push_back(make_pair(0, i));	
    		continue;
    	}
    	
    	float ret = (float)pan[i] / (float)bunmo;
    	
    	vs.push_back(make_pair(ret, i));
    }
    
    sort(vs.begin(), vs.end(), comp);
    
    for(int i = 0 ; i < vs.size() ; ++i){
    	answer.push_back(vs[i].second);
    }
    
    return answer;
}






