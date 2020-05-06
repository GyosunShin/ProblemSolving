
// OUTPUT
// 취약 지점을 점검하기 위해 보내야 하는 친구 수의 최소값을 return
// 전부 점검할 수 없는 경우에는 -1을 return

// 1 <= 외벽의 길이 <= 200
// 1 <= weak.size() <= 15
// 1 <= dist.size() <= 8   == 친구의 수 

#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

int humanNum;
int weakNum;
int N;

vector<int> picked;
vector<vector<int>> pan;
vector<vector<int>> allPicked;

bool used[8];

bool comp(vector<int>& a, vector<int>& b){
	return a.size() < b.size();
}

void permutation(){
	
	if(picked.size() > 0)	allPicked.push_back(picked);
	
	if(picked.size() >= humanNum)	return;
	
	
	for(int i = 0 ; i < humanNum ; ++i){
		if(!used[i]){
			used[i] = true;
			picked.push_back(i);
			permutation();
			used[i] = false;
			picked.pop_back();
		}
	}
	
}


void buildPan(vector<int>& weak){
	
	// pan에 집어넣기
	for(int i = 0 ; i < weak.size(); ++i){
		vector<int> tmp;
		for(int j = i ; j < weak.size() ; ++j){
			tmp.push_back(weak[j]);
		}
		for(int j = 0 ; j < i ; ++j){
			tmp.push_back(weak[j] + N);
		}
		pan.push_back(tmp);
	}
	
}

bool check(vector<int>& input, vector<int>& dist){
	
	// vector<vector<int>> pan
	// dist[input[i]] -> 사용할 거리 
	
	int size = input.size();
	
	for(int i = 0 ; i < pan.size() ; ++i){
		int idx = 0;
		int cnt = 1;
		int start = pan[i][0];
		int jmp = dist[input[idx]];
		for(int j = 1 ; j < pan[i].size() ; ++j){
			if(pan[i][j] - start <= jmp){
				cnt++;
			}
			else{
				start = pan[i][j];
				idx++;
				if(idx >= size)	break;
				jmp = dist[input[idx]];
				cnt++;
			}
		}
		
		
		if(cnt >= weakNum)	return true;
	}
	
	return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N = n;
	humanNum = dist.size();
	weakNum = weak.size();
	
	buildPan(weak);
	
	permutation();
	
	sort(allPicked.begin(), allPicked.end(), comp);
	
	int ans = -1;
	for(int i = 0 ; i < allPicked.size() ; ++i){
		if(check(allPicked[i], dist)){
			ans = allPicked[i].size();
			break;
		}
	}

	return ans;
}

//int main(){
//	
//	vector<int> weak{1,5,6,10};
//	vector<int> dist{1,2,3,4};
//	int N = 12;
//	
//	cout << solution(N, weak, dist);
//	
//	
//}
