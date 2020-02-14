// 노드의 개수 N(1≤N≤26)
// 노드   왼쪽자식    오른쪽자식

// OUTPUT
// 전위 순회  preorder
// 중위 순회  inorder
// 후위 순회  postorder

#include <stdio.h> 
#include <vector>

using namespace std;

int N;
int map[26][2]; 

void inorder(int start){  // l R r

	if(map[start][0] != -1){
		inorder(map[start][0]);
	}
	printf("%c", 'A' + start);	
	if(map[start][1] != -1){
		inorder(map[start][1]);
	}
	
}

void postorder(int start){ // l r R
	if(map[start][0] != -1){
		postorder(map[start][0]);
	}
	if(map[start][1] != -1){
		postorder(map[start][1]);
	}
	printf("%c", 'A' + start);	
}

void preorder(int start){  // R l r 
	printf("%c", 'A' + start);
	for(int i = 0 ; i < 2 ; ++i){
		if(map[start][i] == -1){
			continue;
		}
		preorder(map[start][i]);
	}
}

int main(){
	scanf("%d", &N);
	getchar();
	for(int i = 0 ; i < N ; ++i){
//		printf("[%d]\n", i);
		int real_me, real_left, real_right;
		char me, left, right;
		scanf("%c %c %c", &me, &left, &right);
//		printf("ME : %c / LEFT : %c / RIGHT : %c\n", me, left, right);
		getchar();
		if(left == '.'){
			real_left = -1;		
		}
		else{
			real_left = left - 'A';		
		}
		if(right == '.'){
			real_right = -1;		
		}
		else{
			real_right = right - 'A';		
		}		
		real_me = me - 'A';
//		printf("REAL_ME : %d / REAL_LEFT : %d / REAL_RIGHT : %d\n", real_me, real_left, real_right);
		map[real_me][0] = real_left;
		map[real_me][1] = real_right;
		
	}
	
	// 전위 순회
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	
	return 0;
}
