// N(1��N��100,000)
// M(1��M��100,000)

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, tmp;
int pan[100000];

bool check(int target){
	
	if(binary_search(pan, pan+N, target))	return true;
	return false;

}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
	}
	sort(pan, pan+N);
	
	scanf("%d", &M);
	
	for(int i = 0 ; i < M ; ++i){	// �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
		scanf("%d", &tmp);
		
		if(check(tmp))	printf("1\n");
		else	printf("0\n");
	}	

	return 0;
}
