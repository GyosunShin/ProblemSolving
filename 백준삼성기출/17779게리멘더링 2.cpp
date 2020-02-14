// 선거구를 나누는 방법 중에서, 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 구해보자.

// 5 ≤ N ≤ 20
// 1 ≤ A[r][c] ≤ 100

// d1, d2 ≥ 1
// 1 ≤ x < x+d1+d2 ≤ N
// 1 ≤ y-d1 < y < y+d2 ≤ N

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int map[20][20];
int N;

int check(int r, int c, int d1, int d2){
//	printf("R : %d / C : %d / d1 : %d / d2 : %d\n", r, c, d1, d2);
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	
	int tmp[20][20];
	memset(tmp, 0, sizeof(tmp));
	
	tmp[r][c] = -1;
	int left = 1;
	int right = 1;
	int preL = 1;
	int preR = 1;
	for(int i = 1 ; i <= d1 + d2 ; ++i){
		if(left == d1){
			preL *= -1;
		}
		if(right == d2){
			preR *= -1;
		}
		tmp[r+i][c-left] = -1;
		tmp[r+i][c+right] = -1;
		left = left + preL;
		right= right + preR;
	}
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d  ", tmp[i][j]);
//		}
//		printf("\n");
//	}	

	for(int i = 0 ; i < c ; ++i){
		one += map[r][i];
	}
	for(int i = c+1 ; i < N ; ++i)	two += map[r][i];
	for(int i = 0 ; i < c-d1+d2 ; ++i)	three += map[r+d1+d2][i];
	for(int i = c-d1+d2+1 ; i < N ; ++i)	four += map[r+d1+d2][i];

	bool flag = false;
	for(int i = r+1 ; i < r+d1+d2 ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(flag && tmp[i][j] == -1){
				five += map[i][j];
				flag = false;
				break;
			}
			if(flag){
				five += map[i][j];
			}	
			if(tmp[i][j] == -1){
				flag = true;
				five += map[i][j];
			}
		}
	}
	five += map[r][c];
	five += map[r+d1+d2][c-d1+d2];
	
	for(int i = 0 ; i < r ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(j <= c){
				one += map[i][j];
			}	
			else	two += map[i][j];
		}
	}
	
	for(int i = r+d1+d2+1 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(j < c-d1+d2)	three += map[i][j];
			else	four += map[i][j];
		}
	}
	
	
	for(int i = r+1 ; i < r + d1 + d2 ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(tmp[i][j] == -1)		break;
			if(i < r+d1){
				one += map[i][j];
			}	
			else if(i >= r+d1)	three += map[i][j];
		}
	}
	for(int i = r+1 ; i < r + d1 + d2 ; ++i){
		for(int j = N-1 ; j >= 0 ; --j){
			if(tmp[i][j] == -1)		break;
			if(i <= r+d2)	two += map[i][j];
			else if(i > r+d2)	four += map[i][j];
		}
	}	
	
//	printf("ONE : %d\n",one);
//	printf("two : %d\n",two);
//	printf("three : %d\n",three);
//	printf("four : %d\n",four);
//	printf("five : %d\n",five);

	vector<int> v;
	v.push_back(one);
	v.push_back(two);
	v.push_back(three);
	v.push_back(four);
	v.push_back(five);
	sort(v.begin(), v.end());
	int ret = v[4] - v[0];
//	printf("<%d>\n\n", ret);
	return ret;
}

int solve(int r, int c){
	// 1 <= d1, d2
	// 0 ≤ r < r+d1+d2 ≤ N-1
	// 0 ≤ c-d1 < c < c+d2 ≤ N-1
	int tmp_ret =  0x7fffffff;
	
	for(int d1 = 1 ; 0 <= c-d1 ; ++d1){
		for(int d2 = 1 ; c+d2 <= N-1 ; ++d2){
			if(r + d1 + d2 >= N)	continue;
			tmp_ret = min(tmp_ret, check(r,c,d1,d2));
		}
	}
	return tmp_ret;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	
	int ans = 0x7fffffff;
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			ans = min(ans, solve(i,j));
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

