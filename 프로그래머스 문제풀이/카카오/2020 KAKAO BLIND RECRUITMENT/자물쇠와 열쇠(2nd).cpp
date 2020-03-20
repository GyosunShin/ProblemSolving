// ����� �ڹ��踦 ���� ������ true��, �� �� ������ false�� return 

// key�� M x M(3 �� M �� 20)
// lock�� N x N(3 �� N �� 20)
// M <= N
// (0 : Ȩ �κ�) (1 : ���� �κ�)

// �ڹ��� ���� �������� ������ ���� �κ�(1)�� �ڹ����� Ȩ �κ�(0)�� ��Ȯ�� ��ġ�ؾ� �ϸ� 
// ������ ����� �ڹ����� ���Ⱑ �������� �ȵ˴ϴ�. 

#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int target_num;

// (M : KEY) (N : LOCK)
int M, N;

int pan[20][20][4];

bool check(int dr, int dc, int k, vector<vector<int>>& key, vector<vector<int>>& lock){
	
	int cnt = 0;
	bool flag = true;
	
	for(int i = 0 ; i < key.size() ; ++i){
		if(!flag)	break;
		for(int j = 0 ; j < key[i].size() ; ++j){
			// !! ������ ����(1)�� �ڹ����� ����(1)�� �������� �ȵȴ� !!
			int tr = i + dr;	int tc = j + dc;
			if(0 <= tr && tr < N && 0 <= tc && tc < N){
				if(pan[i][j][k] == 1 && lock[tr][tc] == 0)	++cnt;
				if(pan[i][j][k] == 1 && lock[tr][tc] == 1){
					flag = false;
					break;
				}
			}
		}
	}
		
	if(!flag)	return false;
	if(cnt == target_num){
		return true;
	}
	return false;
	
}


bool solve(vector<vector<int>>& key, vector<vector<int>>& lock){
	
	bool ret = false;	
		
	for(int i = (-1 * (M-1)) ; i < N ; ++i){
		if(ret)	break;
		for(int j = (-1 * (M-1)) ; j < N ; ++j){
			if(ret)	break;
			for(int k = 0 ; k < 4 ; ++k){
				if(check(i, j, k, key, lock)){
					ret = true;
					break;
				}
			}
		}
	}
	
	return ret;
	
}

void rotate(vector<vector<int>>& key){
	
	for(int z = 0 ; z < 4 ; ++z){
		
		if(z == 0){
			for(int i = 0 ; i < M ; ++i){
				for(int j = 0 ; j < M ; ++j){
					pan[i][j][z] = key[i][j];
				}
			}
		}
		else{
			for(int i = 0 ; i < M ; ++i){
				for(int j = 0 ; j < M ; ++j){
					pan[i][j][z] = pan[M-j-1][i][z-1];
				}
			}
		}
		
	}
	
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	
    M = key.size();	N = lock.size();
    
    rotate(key);
    
//    for(int z = 0 ; z < 4 ; ++z){
//	    for(int i = 0 ; i < key.size() ; ++i){
//	    	for(int j = 0 ; j < key[i].size() ; ++j){
//	    		printf("%d ", pan[i][j][z]);
//	    	}
//	    	printf("\n");
//	    }
//	    printf("\n");
//	    printf("\n");
//	}
//    printf("\n");
    
    for(int i = 0 ; i < lock.size() ; ++i){
    	for(int j = 0 ; j < lock[i].size() ; ++j){
    		if(lock[i][j] == 0)	++target_num;
    	}
    }
    
    return solve(key, lock);
    
}

//int main(){
//	vector<vector<int>> key({
//		vector<int>({0,0,0}),
//		vector<int>({1,0,0}),
//		vector<int>({0,1,1})
//		}
//	);
//	
//	vector<vector<int>> lock({
//		vector<int>({1,1,1}),
//		vector<int>({1,1,0}),
//		vector<int>({1,0,1})
//		}
//	);
//	
//	solution(key, lock);
//}


