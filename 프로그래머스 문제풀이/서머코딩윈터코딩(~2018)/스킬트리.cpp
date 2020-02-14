		
// 가능한 스킬트리 개수를 return

#include <string>
#include <vector>

using namespace std;

int alpa[26];

int ans;

int solution(string skill, vector<string> skill_trees) {
	
	for(int i = 0 ; i < skill.size() ; ++i){
		alpa[skill[i] - 'A'] = 1;
	}
	
	for(int i = 0 ; i < skill_trees.size() ; ++i){
		bool tmp_flag = true;
		int idx = 0;
		for(int j = 0 ; j < skill_trees[i].size() ; ++j){
			if(alpa[skill_trees[i][j] - 'A'] == 0)	continue;
			if(skill_trees[i][j] != skill[idx]){
				tmp_flag = false;
				break;
			}
			idx++;
		}
		if(tmp_flag)	++ans;
	}
	
	return ans;   
}
