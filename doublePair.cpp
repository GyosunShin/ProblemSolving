#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> >a , pair<string, pair<int, int> >b){
	if(a.second.first == b.second.first){
		return a.second.second > b.second.second;		
	}
	else{
		return a.second.first > b.second.first;
	}
}

int main(){
	// 단순하게 정렬을 시도하면 앞에있는 int형 기준으로.. 
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> > ("나동빈", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int> > ("이태일", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int> > ("박한울", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int> > ("이상욱", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int> > ("강종구", pair<int, int>(88, 19900302)));
	
	sort(v.begin(), v.end(), compare);
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i].first << ' ';
	}
}

