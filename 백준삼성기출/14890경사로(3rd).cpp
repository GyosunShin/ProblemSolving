// N (2 �� N �� 100)�� L (1 �� L �� N)
// �� ĭ�� ���� <= 10 

// OUTPUT : ù° �ٿ� ������ �� �ִ� ���� ������ ����Ѵ�.

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int map[100][100];

int ans;

bool garo(int r){
	// (r, 0)  ~  (r, N-1)
	
	// ���� �Ȱ�����
	bool flag = true;
	for(int i = 0 ; i < N-1 ; ++i){
		if(map[r][i] != map[r][i+1]){
			flag = false;
			break;
		}
	}
	if(flag){
		return true;
	}	
	
	if(map[r][0] == map[r][N-1]){
		for(int i = 1 ; i < N-1 ; ++i){
			if(map[r][i] < map[r][0])	return false;
		}
		
		int cnt = 0;
		
		
		for()
		
	}
	
	
	
	// ����� �ִ���
	int tmp = map[r][0] > map[r][N-1] ? 1 : -1;
	if(tmp == 1){  // ������ �� ū ��� 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[r][i] < map[r][i+1]){
				return false;
			}
		}
	}
	else if(tmp == -1){  // �������� �� ū ��� 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[r][i] > map[r][i+1]){
				return false;
			}
		}		
	}
	 
	
	// ����� ���� �Ϸķ� ���������̰ų� ���������� ���
	if(tmp == -1){  // �������� �� ū ��� 
		vector<int> diff;
		int start = map[r][N-1];
		int cnt = 0;
		for(int i = N-2 ; i >= 0 ; --i){
			if(map[r][i] == map[r][N-1]){
				continue;
			}
			else{
				if(map[r][i] != start && start == map[r][N-1]){
					if(abs(map[r][i] - start) > 1)	return false;
					start = map[r][i];
					cnt++;
				}
				else if(map[r][i] != start && start != map[r][N-1]){
					if(abs(map[r][i] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[r][i];
					cnt = 1;
				}
				else if(map[r][i] == start && start != map[r][N-1]){
					cnt++;
				}
			}
			if(i == 0)	diff.push_back(cnt);
		}
		
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}
	else if(tmp == 1){  // ������ �� ū ��� 
		vector<int> diff;
		int start = map[r][0];
		int cnt = 0;
		for(int i = 1 ; i < N ; ++i){
			if(map[r][i] == map[r][0]){
				continue;
			}
			else{
				if(map[r][i] != start && start == map[r][0]){
					if(abs(map[r][i] - start) > 1)	return false;
					start = map[r][i];
					cnt++;
				}
				else if(map[r][i] != start && start != map[r][0]){
					if(abs(map[r][i] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[r][i];
					cnt = 1;
				}
				else if(map[r][i] == start && start != map[r][0]){
					cnt++;
				}
			}
			if(i == N-1)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}	 
}

bool sero(int c){
	// (0, c)  ~  (N-1, c)
	
	// ���� �Ȱ�����
	bool flag = true;
	for(int i = 0 ; i < N-1 ; ++i){
		if(map[i][c] != map[i+1][c]){
			flag = false;
			break;
		}
	}
	if(flag){
		return true;
	}	
	
	// ����� �ִ���
	int tmp = map[0][c] > map[N-1][c] ? 1 : -1;
	if(tmp == 1){  // ������ �� ū ��� 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[i][c] < map[i+1][c]){
				return false;
			}
		}
	}
	else if(tmp == -1){  // �Ʒ����� �� ū ��� 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[i][c] > map[i+1][c]){
				return false;
			}
		}		
	}
	 
	
	// ����� ���� �Ϸķ� ���������̰ų� ���������� ���
	if(tmp == -1){  // �Ʒ����� �� ū ��� 
		vector<int> diff;
		int start = map[N-1][c];
		int cnt = 0;
		for(int i = N-2 ; i >= 0 ; --i){
			if(map[i][c] == map[N-1][c]){
				continue;
			}
			else{
				if(map[i][c] != start && start == map[N-1][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					start = map[i][c];
					cnt++;
				}
				else if(map[i][c] != start && start != map[N-1][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[i][c];
					cnt = 1;
				}
				else if(map[i][c] == start && start != map[N-1][c]){
					cnt++;
				}
			}
			if(i == 0)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}
	else if(tmp == 1){  // ������ �� ū ��� 
		vector<int> diff;
		int start = map[0][c];
		int cnt = 0;
		for(int i = 1 ; i < N ; ++i){
			if(map[i][c] == map[0][c]){
				continue;
			}
			else{
				if(map[i][c] != start && start == map[0][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					start = map[i][c];
					cnt++;
				}
				else if(map[i][c] != start && start != map[0][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[i][c];
					cnt = 1;
				}
				else if(map[i][c] == start && start != map[0][c]){
					cnt++;
				}
			}
			if(i == N-1)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}	 
}

int main(){
	scanf("%d %d", &N, &L);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		if(garo(i)){
			printf("%d��° ROW ����1\n", i);
			++ans;
			continue;
		}	
		printf("%d��° ROW �ȉ褱!!!1\n", i);
	}
	for(int i = 0 ; i < N ; ++i){
		if(sero(i)){
			printf("%d��° COL ����1\n", i);
			++ans;
			continue;
		}	
		printf("%d��° COL �ȉ褱!!!1\n", i);
	}	
	
	printf("%d", ans);
	
	return 0;
}
