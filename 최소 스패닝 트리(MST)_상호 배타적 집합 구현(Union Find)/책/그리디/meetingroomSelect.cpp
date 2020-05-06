#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int begin[100], end[100];

// 일찍 끝나는 순서대로 정렬한 
int schedule(){
	// pair(end시간, begin시간) 
	vector<pair<int, int> > order;
	
	for(int i = 0 ; i < n ; i++){
		order.push_back(make_pair(end[i], begin[i]));
	}
	sort(order.begin(), order.end());
	
	// earliest : 다음 회의가 시작할 수 있는 가장 빠른시간
	// selected : 지금까지 선택한 회의의 수
	int earliest = 0;
	int selected = 0;
	
	for(int i = 0 ; i < order.size() ; ++i){
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		if(earliest <= meetingBegin){
			earliest = meetingEnd;
			++selected;
		}
	}
	return selected;
}

int main(){
	int selected = schedule();
	cout << selected << "개" << endl;
}

