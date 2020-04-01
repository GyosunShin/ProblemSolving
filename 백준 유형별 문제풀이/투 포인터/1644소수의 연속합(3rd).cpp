// (1 ¡Â N ¡Â 4,000,000)

#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int N, ans;
bool eratos[4000001];
vector<int> sosus;

void era(){
	
	for(int i = 2 ; i <= (int)sqrt(4000000) ; ++i){
		if(eratos[i])	continue;
		for(int j = i*i ; j <= 4000000 ; j = j + i){
			eratos[j] = true;
		}
	}
	
	for(int i = 2 ; i <= 4000000 ; ++i){
		if(!eratos[i])	sosus.push_back(i);
	}
	
}

void solve(){
	
	int left = 0;
	int right = 0;
	int sum = sosus[0];
	
	while(left < sosus.size() && right < sosus.size()){
		
		if(sum >= N){
			if(sum == N)	++ans;
			sum -= sosus[left++];
			
			if(left > right){
				right = left;
				sum = sosus[left];
			}
			
		}
		else{
			sum += sosus[++right];
		}
		
		
	}
	
}

int main(){
	
	scanf("%d", &N);
	
	era();
	
//	printf("SIZE : %d\n", sosus.size());
//	for(int i = 0 ; i < sosus.size() ; ++i)	printf("%d  ", sosus[i]);
//	printf("\n");
//	
//	vector<int>::iterator it;
//	it = sosus.begin();
//	while(it != sosus.end())	{
//		cout << *it << endl;
//		++it;
//	}
	
	solve();
	
	printf("%d", ans);
	
	return 0;
}
