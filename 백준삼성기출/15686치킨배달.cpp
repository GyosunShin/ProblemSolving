//N(2 �� N �� 50)�� M(1 �� M �� 13)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > chicken;
vector<pair<int, int> > home;
vector<pair<int, int> > picked;

int N, M, ans;

int map[50][50];


void dfs(int count){
	if(picked.size() == M){  // chicken�� m�� �� �̾�����.. ����...
		int sum = 0;
		
		for(int i = 0 ; i < home.size() ; ++i){  // �� �������� �ּ� ġŲ�Ÿ� ã�´�.
			int tmpMin = 0x7fffffff;
			for(int j = 0 ; j < picked.size() ; ++j){
				int tmptmpMin = abs(home[i].first - picked[j].first) + abs(home[i].second - picked[j].second);
				if(tmpMin > tmptmpMin){
					tmpMin = tmptmpMin;
				}
			}
			sum += tmpMin;
		}
		if(ans > sum){
			ans = sum;
		}	
		return;
	}
	
	for(int i = count ; i < chicken.size() ; ++i){
		picked.push_back(pair<int, int>(chicken[i].first, chicken[i].second));
		dfs(i + 1);
		picked.pop_back();
	}
}


int main(){
	ans = 0x7fffffff;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			int tmp;
			scanf("%d", &tmp);
			if(tmp == 2){  // CHICKEN
				chicken.push_back(pair<int, int>(i,j));
			} 
			else if(tmp == 1){  // HOME
				home.push_back(pair<int, int>(i,j));
			}
		}
	}
	//-------------- ������� INPUT�޴°�! --------------------
	
	//���� DFS�̿��ؼ� chicken.size()���� M���� ġŲ���� ��󳻾� ��! 
	dfs(0);
	printf("%d", ans);
	
}
