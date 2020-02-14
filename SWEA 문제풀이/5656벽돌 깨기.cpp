// N ���� ������ ����Ʈ�� �ִ��� ���� ������ �����Ϸ��� �Ѵ�.
// ���� ������ ������ ���϶�!  == ��, ���� ������ �ּҿ��� �Ѵ�. 

// 1 �� N �� 4
// 2 �� W(= C) �� 12
// 2 �� H(= R) �� 15 

// 1 <= ���� <= 9 

#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int r, c, value;	
};

int T, N, C, R;
int map[15][12];

int ans = 0x7fffffff;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void solve(int deep, int index, int input[15][12]){   // ���� ������  backup[target_r][index] 
	int backup[15][12];
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			backup[i][j] = input[i][j];
		}
	}	
	
	int target_r;
	for(int i = 0 ; i < R ; ++i){
		if(backup[i][index] > 0){
			target_r = i;	
			break;
		}
	}
	if(target_r >= R)	return;
	
	// BOOM ����!
	queue<INFO> q;
	INFO start;
	start.r = target_r;	start.c = index;	start.value = backup[target_r][index];
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		backup[cur.r][cur.c] = 0;
		
		for(int i = 1 ; i < cur.value ; ++i){  // ������ ó�� 
			int next_r = cur.r;	int next_c = cur.c + i;
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	break;
			if(backup[cur.r][cur.c + i] > 1){
				INFO next;	next.r = cur.r;	next.c = cur.c + i;	next.value = backup[cur.r][cur.c + i];
				q.push(next);
			}
			else	backup[cur.r][cur.c + i] = 0;
		}
		for(int i = 1 ; i < cur.value ; ++i){  // ���� ó�� 
			int next_r = cur.r;	int next_c = cur.c - i;
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	break;
			if(backup[cur.r][cur.c - i] > 1){
				INFO next;	next.r = cur.r;	next.c = cur.c - i;	next.value = backup[cur.r][cur.c - i];
				q.push(next);
			}
			else	backup[cur.r][cur.c - i] = 0;
		}		
		for(int i = 1 ; i < cur.value ; ++i){  // �Ʒ��� ó�� 
			int next_r = cur.r + i;	int next_c = cur.c;
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	break;
			if(backup[cur.r + i][cur.c] > 1){
				INFO next;	next.r = cur.r + i;	next.c = cur.c;	next.value = backup[cur.r + i][cur.c];
				q.push(next);
			}
			else	backup[cur.r + i][cur.c] = 0;
		}		
		for(int i = 1 ; i < cur.value ; ++i){  // ���� ó�� 
			int next_r = cur.r - i;	int next_c = cur.c;
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	break;
			if(backup[cur.r - i][cur.c] > 1){
				INFO next;	next.r = cur.r - i;	next.c = cur.c;	next.value = backup[cur.r - i][cur.c];
				q.push(next);
			}
			else	backup[cur.r - i][cur.c] = 0;
		}				
	}
	
	// ���� ���� count 
	int tmp_ans = 0;
	if(deep == N-1){
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				if(backup[i][j] > 0)	++tmp_ans;
			}
		}
		if(ans > tmp_ans)	ans = tmp_ans;
		return;
	}
	

	// ���� ���ʶ߸���
	for(int i = 0 ; i < C ; ++i){
		vector<int> tmp;
		for(int j = R-1 ; j >= 0 ; --j){
			if(backup[j][i] > 0)	tmp.push_back(backup[j][i]);
		}
		for(int j = 0 ; j < R ; ++j){
			backup[j][i] = 0;
		}
		for(int j = 0 ; j < tmp.size() ; ++j){
			backup[R-1-j][i] = tmp[j];
		}
	}
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(backup[i][j] > 0)	++tmp_ans;
		}
	}
	
	
	if(ans > tmp_ans)	ans = tmp_ans;
	if(ans == 0)	return;
	
	for(int i = 0 ; i < C ; ++i){
		solve(deep + 1, i, backup);
	}
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		ans = 0x7fffffff;
		scanf("%d %d %d", &N, &C, &R);
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		//#################################
		
		for(int i = 0 ; i < C ; ++i){
			solve(0, i, map);
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}

