// R, C�� ����� �� M�� �־�����. (2 �� R, C �� 100, 0 �� M �� R��C)
//  r, c, s, d, z (1 �� r �� R, 1 �� c �� C, 0 �� s �� 1000, 1 �� d �� 4, 1 �� z �� 10000)
//  (r, c) : ��� ��ġ
//  s : �ӷ�
//  d : �̵� ����   --> (1 : ��) (2 : �Ʒ�) (3 : ������) (4 : ����)
//  z : ũ�� 
//  
//  OUTPUT : ���ÿ��� ���� ��� ũ���� ���� ����Ѵ�.

#include <stdio.h>
#include <queue>

using namespace std;

struct SHARK{
	int speed, dir, size;
};
 
int R, C, M;
int visited[100][100];
SHARK sharks[100][100];

queue<pair<int, int> > q;

int ans;

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int i = 0 ; i < M ; ++i){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		q.push(pair<int, int>((r-1), (c-1)));
		SHARK tmp;
		tmp.speed = s;	tmp.dir = d;	tmp.size = z;
		sharks[r-1][c-1] = tmp;
		visited[r-1][c-1] = 1;
	}
	
	// �ùķ��̼� ����!
	for(int i = 0 ; i < C ; ++i){
		
		for(int j = 0 ; j < R ; ++j){   // ������ ���� �Դ´�.
			if(visited[j][i] == 1){
				ans += sharks[j][i].size;
				visited[j][i] = 0;
			}
		}
		
		int visited_new[100][100] = { 0, };
		// ���� ��� �̵� ����
		// queue���� �ϳ��� ���鼭 visited�� ���� ������ ��Ƹ������� Ȯ���Ѵ�.
		// �׸��� �� ��Ƹ������� ���� ��ġ�� ����Ѵ�
		// �ٵ� ������ġ�� ���� �̹� ������ size �� �� ���Դ´�.
		while(!q.empty()){
	}
	
	
}
