 // N(1 �� N �� 200), K(1 �� K �� 200)
 
 #include <stdio.h> 
 #include <vector>
 
 using namespace std;
 
 int N, K;
 
 vector<int> picked;
 
 int ans;
 
 void dfs(){
 	if(picked.size() == K){
// 		for(int i = 0 ; i < picked.size() ; ++i){
// 			printf("%d ", picked[i]);
// 		}
// 		printf("\n");
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += picked[i];
		}
		if(tmp_sum == N){
			++ans;
		}

		return;	
 	}
 	for(int i = 0 ; i <= N ; ++i){
 		picked.push_back(i);
 		dfs();
 		picked.pop_back();
 	}
 	
 }
 
 int main(){
 	scanf("%d %d", &N, &K);
 	//####################
 	
 	//ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.
	dfs();
	printf("%d", ans);
 	
 	return 0;
 }
