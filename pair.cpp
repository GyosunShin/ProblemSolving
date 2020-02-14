#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	// 단순하게 정렬을 시도하면 앞에있는 int형 기준으로.. 
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "박한울"));
	v.push_back(pair<int, string>(85, "이태일"));
	v.push_back(pair<int, string>(82, "나동빈"));
	v.push_back(pair<int, string>(98, "강종구"));
	v.push_back(pair<int, string>(79, "이상욱"));
	
	sort(v.begin(), v.end());
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i].second << ' ';
	}
}

