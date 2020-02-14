#include <stdio.h>
#include <algorithm>

using namespace std;

struct TREE{
	int y, x, age;
}

bool cmp(TREE& a, TREE& b){
	return (a.age < b.age);  // ���̰� � �������! 
}

struct QUEUE{
	int f, b;  // front, back 
	TREE tree[684000];  // ȯ�� queue�� �ϸ� �ð� �����ɸ��� ������ �׳� �̷��� �ϼ� 
	
	QUEUE(){
		init();
	}
	
	void init(){
		f = 0, b = 0;
	}
	
	bool isempty(){
		return (f == b);
	}
	
	void push(TREE val){
		tree[b++] = val;
	}
	
	void pop(){
		++f;
	}
	
	TREE front(){
		return tree[f];
	}
	
	int size(){
		return (b - f);
	}
};

int n, m, k;
QUEUE tree[2];
QUEUE new_tree;
QUEUE dead_tree, birth_of_child_tree;

TREE init_tree[100];

int map[10][10], add[10][10];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int y = 0 ; y < n ; ++y){
		for(int x = 0 ; x < n ; ++x){
			scanf("%d", &add[y][x]);
			map[y][x] = 5;
		}
	}
	
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d", &init_tree[i].y)
	}
}
