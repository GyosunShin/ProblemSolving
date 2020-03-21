
// (������) = ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��

// OUTPUT
// �������� ���� ������������ ������������ ���������� ��ȣ�� ����ִ� �迭�� return

// ���� �������� ���� ���������� �ִٸ� ���� ��ȣ�� ���������� ���� ������ �ϸ� �ȴ�.
// ���������� ������ ������ ���� ��� �ش� ���������� �������� 0 ���� �����Ѵ�. 

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> answer;

int pan[502];

vector<pair<float, int>> vs;	// (������ / �������� ��ȣ)

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






