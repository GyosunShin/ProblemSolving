// ���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 1 <= N <= 10

#include <cstdio>
#include <vector>

using namespace std;

int T, N;

vector<int> picked;

int ans;

void dfs(){
	
	int tmp_sum = 0;
	for(int i = 0 ; i < picked.size() ; ++i)	tmp_sum += picked[i];
	if(tmp_sum == N)	++ans;
	
	
	if(picked.size() == N)	return;
	
	for(int i = 1 ; i <= 3 ; ++i){
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
	
}
 
int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0;
		scanf("%d", &N);
		
		// �� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ����Ѵ�.
		
		// �ߺ� ������ Ǯ���
		// �ִ� N�� �̱�
		dfs(); 
		printf("%d\n", ans);
	}
	
	return 0;
}
