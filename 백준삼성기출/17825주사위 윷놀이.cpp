// 2초 512MB

// 말 4개

// INPUT : 첫째 줄에 주사위에서 나올 수 10개가 순서대로 주어진다.
// OUTPUT : 얻을 수 있는 점수의 최댓값을 출력한다.

#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;

struct node{
	int value;
	node* normal;
	node* special;
};
node nodes[43];
node bluenodes[31];

struct INFO{
	int sum;
	node* cur;
	bool flag;
};

vector<int> test{0,1,1,0,0,0,0,1,0,1};

int map[10];
 
vector<int> picked;

int ans = -1 * 0x7fffffff; 

node* go(node* start, int jmp){
	node* next;
	
	if(start->special == NULL){
		next = start->normal;
	}
	else{
		next = start->special;
	}
	if(next->value == 0)	return next;
	if(jmp == 1)	return next;
	else{
		for(int i = 0 ; i < jmp-1 ; ++i){
			next = next->normal;
			if(next->value == 0)	return next;
		}
		return next;
	}
}


int solve(){
	INFO infos[4];
	for(int i = 0 ; i < 4 ; ++i){
		infos[i].sum = 0;
		infos[i].cur = &nodes[0];
		infos[i].flag = true;
	}
	
	
	// picked <-> map 이용
	for(int i = 0 ; i < picked.size() ; ++i){
		int jmp = map[i];
		int who = picked[i];
		
		if(!infos[who].flag)	continue;
		
		node* next = go(infos[who].cur, jmp);
		if(next->value == 0){
			infos[who].flag = false;
			infos[who].cur = next;
			continue;
		}
		
		bool tmp_flag = false;
		for(int j = 0 ; j < 4 ; ++j){	// 이미 존재하는 경우 
			if(infos[j].cur == next){
				tmp_flag = true;
				break;			  
			}
		}
		if(tmp_flag){
			return -1 * 0x7fffffff;
		}	
		
		infos[who].cur = next;
		infos[who].sum += next->value;
	}
	
	int ret = 0;
	for(int i = 0 ; i < 4 ; ++i){
		ret += infos[i].sum;
	}
	return ret;
}

void dfs(){
	if(picked.size() == 10){
		int ret = solve();
		ans = max(ans, ret);
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
}

void draw(){
	for(int i = 0 ; i < 44 ; ++i){
		nodes[i].value = i;  // 0 ~ 43
	}
	for(int i = 0 ; i < 32 ; ++i){
		bluenodes[i].value = i;  // 0 ~ 43
	}	
	nodes[0].value = -1;
	nodes[42].value = 0;
	
	for(int i = 0 ; i < 8 ; i += 2){
		nodes[i].special = NULL;
		nodes[i].normal = &nodes[i+2];
	}
	nodes[8].normal = &bluenodes[10];
	nodes[8].special = NULL;
	bluenodes[10].special = &bluenodes[13];
	bluenodes[10].normal = &nodes[12];
	for(int i = 12 ; i < 18 ; i += 2){
		nodes[i].special = NULL;
		nodes[i].normal = &nodes[i+2];
	}	
	nodes[18].normal = &bluenodes[20];
	nodes[18].special = NULL;
	
	bluenodes[20].special = &bluenodes[22];
	bluenodes[20].normal = &nodes[22];	
	
	bluenodes[13].special = NULL;
	bluenodes[13].normal = &bluenodes[16];
	bluenodes[16].special = NULL;
	bluenodes[16].normal = &bluenodes[19];
	bluenodes[19].special = NULL;
	bluenodes[19].normal = &bluenodes[25];
	
	bluenodes[22].special = NULL;
	bluenodes[22].normal = &bluenodes[24];
	bluenodes[24].special = NULL;
	bluenodes[24].normal = &bluenodes[25];		
	
	bluenodes[25].special = NULL;
	bluenodes[25].normal = &nodes[30];	
	
	nodes[30].special = NULL;
	nodes[30].normal = &nodes[35];	
	nodes[35].special = NULL;
	nodes[35].normal = &nodes[40];			
	
	for(int i = 22 ; i < 28 ; i += 2){
		nodes[i].special = NULL;
		nodes[i].normal = &nodes[i+2];
	}		
	nodes[28].special = NULL;
	nodes[28].normal = &bluenodes[30];				
	
	bluenodes[30].special = &bluenodes[28];
	bluenodes[30].normal = &nodes[32];	
	
	for(int i = 32 ; i < 39 ; i += 2){
		nodes[i].special = NULL;
		nodes[i].normal = &nodes[i+2];
	}			
	
	bluenodes[28].special = NULL;
	bluenodes[28].normal = &bluenodes[27];
	bluenodes[27].special = NULL;
	bluenodes[27].normal = &bluenodes[26];
	bluenodes[26].special = NULL;
	bluenodes[26].normal = &bluenodes[25];
	
	nodes[40].special = NULL;
	nodes[40].normal = &nodes[42];						
}

int main(){
	for(int i = 0 ; i < 10 ; ++i){
		scanf("%d", &map[i]);
	}
	
	draw();
	dfs();
	printf("%d", ans);
	
	return 0;
}

