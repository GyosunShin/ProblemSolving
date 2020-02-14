//11
//1 4
//3 5
//0 6
//5 7
//3 8
//5 9
//6 10
//8 11
//8 12
//2 13
//12 14

// ù° �ٿ� �ִ� ����� �� �ִ� ȸ�� ���� ����Ͽ���.

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > schedules;
	
	for(int i = 0 ; i < n ; i++){
		int start, end;
		cin >> start >> end;
		schedules.push_back(pair<int,int>(end, start));
	}
	
	sort(schedules.begin(), schedules.end());
	
	int earliest = 0;  // ���� ������ �ð� 
	int selected = 0;
	for(int i = 0 ; i < schedules.size() ; i++){
		int begin = schedules[i].second;
		int end = schedules[i].first;
		if(earliest <= begin){  // �߸��� ��� �׳� �Ѿ�� �Ѵ� 
			selected++;
			earliest = end;
		}
		
	}
	
	cout << selected << endl;
}



