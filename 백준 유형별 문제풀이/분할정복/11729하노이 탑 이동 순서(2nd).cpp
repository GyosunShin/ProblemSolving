//  (1 ¡Â N ¡Â 20)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int> > ans;

void solve(int howmany, int src, int mid, int dst){
	if(howmany == 1){
		ans.push_back(make_pair(src, dst));
		return;
	}
	
	solve(howmany-1, src, dst, mid);
	ans.push_back(make_pair(src, dst));
	solve(howmany-1, mid, src, dst);
	
}

int main(){
	scanf("%d", &N);
	
	solve(N, 1,2,3);
	
	printf("%d\n", ans.size());
	for(int i = 0 ; i < ans.size() ; ++i)	printf("%d %d\n", ans[i].first, ans[i].second);
	
	return 0;
}
