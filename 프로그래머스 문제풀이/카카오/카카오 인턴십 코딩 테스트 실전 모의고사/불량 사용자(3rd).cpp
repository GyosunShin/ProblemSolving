
//������ ����� ���̵���� ���� �ߺ����� �ʽ��ϴ�.
//������ ����� ���̵�� (���ĺ� �ҹ���)�� (����)�θ����� �����Ǿ� �ֽ��ϴ�.

// OUTPUT
// ��÷���� ���ܵǾ�� �� ���� ���̵� ����� ��� ����� ���� ������ �� return 

// user_id �迭�� ũ��� 1 �̻� 8 �����Դϴ�.

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

vector<vector<vector<int>>> ffinal;
vector<vector<int>> final;
vector<int> tmp;
vector<int> picked;
int CNT;
int N;
int answer;

bool cache[8];

bool check(string& id, string& tem){
	bool ret = true;
	
	for(int i = 0 ; i < id.size() ; ++i){
		if(tem[i] == '*')	continue;
		if(tem[i] != id[i]){
			ret = false;
			break;
		}
	}
	
	return ret;
}

void dfs(int start){
	
	if(picked.size() == CNT){
		final.push_back(picked);
		return;
	}
	
	for(int i = start ; i < tmp.size() ; ++i){
		picked.push_back(tmp[i]);
		dfs(i+1);
		picked.pop_back();
	}
	
}

bool solve(vector<string>& user, string tem, int cnt){
	
//	cout << tem << " : " << cnt << endl;
	
	final.clear();
	tmp.clear();
	CNT = cnt;
	
	for(int i = 0 ; i < user.size() ; ++i){
		if(user[i].size() == tem.size()){		
			bool ret = check(user[i], tem);
			if(ret){
				tmp.push_back(i);
			}
		}
	}	
	
	if(tmp.size() < cnt)	return false;
	
	dfs(0);
	
//	for(int i = 0 ; i < final.size() ; ++i){
//		for(int j = 0 ; j < final[i].size() ; ++j){	
//			cout << final[i][j] << ", ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	
	ffinal.push_back(final);	
	
	return true;
}

void ddfs(int start){
	
//	cout << "START : " << start << endl;
	
//	for(int i = 0 ; i < picked.size() ; ++i)	cout << picked[i];
//	cout << endl;
	
	if(start >= N){
		++answer;
		return;
	}
	
	for(int j = 0 ; j < ffinal[start].size() ; ++j){
		bool flag = true;
		for(int k = 0 ; k < ffinal[start][j].size() ; ++k){
			if(cache[ffinal[start][j][k]]){
				flag = false;
				break;
			}
		}
		if(flag){
			for(int k = 0 ; k < ffinal[start][j].size() ; ++k){
				cache[ffinal[start][j][k]] = true;
				picked.push_back(ffinal[start][j][k]);
			}
			
			ddfs(start+1);
			
			for(int k = 0 ; k < ffinal[start][j].size() ; ++k){
				cache[ffinal[start][j][k]] = false;
				picked.pop_back();
			}
		}
		
	}
	
}

int solution(vector<string> user_id, vector<string> banned_id) {
	
	for(int i = 0 ; i < banned_id.size() ; ++i){
		m[banned_id[i]]++;
	}
	
	N = m.size();
	
	map<string, int>::iterator it;
	for(it = m.begin() ; it != m.end() ; ++it){
		bool ret = solve(user_id, it->first, it->second);
		if(!ret)	return 0;
	}	
	
//	cout << ffinal.size() << endl;
//	cout << ffinal[0].size() << endl;
//	cout << ffinal[0][0].size() << endl;
//	
//	for(int i = 0 ; i < ffinal.size() ; ++i){
//		for(int j = 0 ; j < ffinal[i].size() ; ++j){
//			for(int k = 0 ; k < ffinal[i][j].size() ; ++k){
//				cout << ffinal[i][j][k] << ", ";
//			}	
//			cout << " / ";
//		}
//		cout << endl;
//	}	


	// ffinal������ ����Ǯ�� ����
	ddfs(0);
	
	return answer;
}

//int main(){
////	["frodo", "fradi", "crodo", "abc123", "frodoc"]
////	["*rodo", "*rodo", "******"]
//	vector<string> user_	id({"frodo", "fradi", "crodo", "abc123", "frodoc"});
//	vector<string> banned_id({"*rodo", "*rodo", "******"});
//	solution(user_id, banned_id);
//	
//	return 0;	
//}



