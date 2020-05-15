// ���ڰ��Կ��� �մ��� ���ϴ� ũ���� ���ڸ� �Ǹ��ϴ� ��� ����� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

///  ( 3��m, n��1000).

// OUTPUT 
// ù° �ٿ��� ���ڸ� �Ǹ��ϴ� ����� ���� ���� ��Ÿ���� ������ ����Ѵ�. ���ڸ� �Ǹ��ϴ� ����� ���� ��쿡�� ���� 0�� ����Ѵ�.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int H, M, N;
int panA[1000];
int panB[1000];

vector<int> a;
vector<int> b;

int ans;

void solve(){
	
	for(int i = 0 ; i < M ; ++i){	// start
		int start_idx = i;
		int sum = 0;
		int cnt = 0;
		while(true){
			if(cnt >= M-1)	break;
			if(start_idx >= M)	start_idx -= M;
			sum += panA[start_idx];
			if(sum < H)	a.push_back(sum);
			else if(sum == H)	++ans;
			else	break;
			++start_idx;
			++cnt;
		}
	}
	
	for(int i = 0 ; i < N ; ++i){	// start
		int start_idx = i;
		int sum = 0;
		int cnt = 0;
		while(true){
			if(cnt >= N-1)	break;
			if(start_idx >= N)	start_idx -= N;
			sum += panB[start_idx];
			if(sum < H)	b.push_back(sum);
			else if(sum == H)	++ans;
			else	break;
			++start_idx;
			++cnt;
		}
	}	
	
	sort(a.begin(), a.end());	sort(b.begin(), b.end());
	
	for(int i = 0 ; i < a.size() ; ++i){
		int cur = a[i];
		int rem = H - a[i];
			
		vector<int>::iterator hi;
		hi = upper_bound(b.begin(), b.end(), rem);
		vector<int>::iterator lo;
		lo = lower_bound(b.begin(), b.end(), rem);
		ans += (hi-lo);
	}
	
}

int main(){
	scanf("%d", &H);
	scanf("%d %d", &M, &N);
	int sumA = 0;	int sumB = 0;
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &panA[i]);
		sumA += panA[i];
	}
	if(sumA == H)	++ans;
	else if(sumA < H)	a.push_back(sumA);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &panB[i]);
		sumB += panB[i];
	}
	if(sumB == H)	++ans;
	else if(sumB < H)	b.push_back(sumB);
	
	solve();	
	
	printf("%d", ans);
	
	return 0;
}
