#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> m;

int main(){
	
	m["1"] = 1;
	m["2"] = 2;
	m["3"] = 3;
	
	vector<pair<string, int>> v(m.begin(), m.end());
	
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i].first << " : " << v[i].second << endl;
	}
	
	// 이 후 vector와 sort이용 
	
	return 0;
}
