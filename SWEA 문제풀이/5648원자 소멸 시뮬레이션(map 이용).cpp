// N ���� ���ڵ��� [x, y] ��ġ, �̵� ����, ���� �������� �־��� �� ���ڵ��� �Ҹ�Ǹ鼭 �����ϴ� �������� ������ ���ϴ� ���α׷��� �ۼ��϶�.

// ������ �� (1��N��1,000) 
// �� ������ ���� ������ (1��K��100) 
// ó�� ��ġ (-1,000��x,y��1,000)
// ��ǥ�� ������ ������ ����.
// ��(0), ��(1), ��(2), ��(3)

#include <cstdio> 
#include <map>	
#include <vector>

using namespace std;

struct INFO{
	float x, y;
	int dir, energy;
};

int T, N;

//  �� �� �� �� 
const float dx[] = {0, 0, -0.5, 0.5};
const float dy[] = {0.5, -0.5, 0, 0};

int ans;

map<int, INFO> pan;

bool check(){
	vector<INFO> v;
	
	bool ret = true;
	
	map<int, INFO>::iterator it;
	for(it = pan.begin() ; it != pan.end() ; ++it){
		INFO cur = it->second;
		v.push_back(cur);
	}
	
	int tmp_size = v.size();
	// ���� nCr
	for(int i = 0 ; i < tmp_size ; ++i){
		for(int j = i+1 ; j < tmp_size ; ++j){
			// ���� ���ɼ��� �� �����̶� ������ return false�ع�����. 
			if(v[i].dir == 0){
				if(v[j].dir == 1){
					if(v[i].y < v[j].y && v[i].x == v[j].x)	return false;
				}
				else if(v[j].dir == 2){
					if(v[i].y < v[j].y && v[i].x < v[j].x)	return false;	
				}
				else if(v[j].dir == 3){
					if(v[i].y < v[j].y && v[i].x > v[j].x)	return false;	
				}
			}
			else if(v[i].dir == 1){
				if(v[j].dir == 0){
					if(v[i].y > v[j].y && v[i].x == v[j].x)	return false;
				}
				else if(v[j].dir == 2){
					if(v[i].y > v[j].y && v[i].x < v[j].x)	return false;	
				}
				else if(v[j].dir == 3){
					if(v[i].y > v[j].y &&v[i].x > v[j].x)	return false;	
				}
			}
			else if(v[i].dir == 2){
				if(v[j].dir == 0){
					if(v[i].y > v[j].y && v[i].x < v[j].x)	return false;	
				}
				else if(v[j].dir == 1){
					if(v[i].y < v[j].y && v[i].x < v[j].x)	return false;	
				}
				else if(v[j].dir == 3){
					if(v[i].y == v[j].y && v[i].x > v[j].x)	return false;	
				}
			}			
			else if(v[i].dir == 3){
				if(v[j].dir == 0){
					if(v[i].y > v[j].y && v[i].x > v[j].x)	return false;	
				}
				else if(v[j].dir == 1){
					if(v[i].y < v[j].y && v[i].x < v[j].x)	return false;	
				}
				else if(v[j].dir == 2){
					if(v[i].y == v[j].y && v[i].x < v[j].x)	return false;	
				}
			}
		}
	}
	
	return ret;
}

void walk(){  // 0.5ĭ�� ����!

	map<pair<float, float>, vector<int> > next_pan;
	
	map<int, INFO>::iterator it;
	for(it = pan.begin() ; it != pan.end() ; ++it){
		int key = it->first;
		INFO cur = it->second;
		float next_x = cur.x + dx[cur.dir];	float next_y = cur.y + dy[cur.dir];
		map<pair<float, float>, vector<int> >::iterator itt;
		itt = next_pan.find({next_x, next_y});
		if(itt == next_pan.end()){
			vector<int> tmp;
			tmp.push_back(key);
			next_pan[{next_x, next_y}] = tmp;
		}
		else{
			vector<int> tmp = itt->second;
			tmp.push_back(key);
			next_pan[{next_x, next_y}] = tmp;
		}
		it->second.x = next_x;	it->second.y = next_y;
	}
	
	// next_pan���� ������ 2 �̻��� �͵� �� ���̱�
	map<pair<float, float>, vector<int> >::iterator itt;
	for(itt = next_pan.begin() ; itt != next_pan.end() ; ++itt){
		if(itt->second.size() > 1){
			for(int i = 0 ; i < itt->second.size() ; ++i){
				ans += pan[itt->second[i]].energy;
				pan.erase(itt->second[i]);
			}
		}
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		pan.clear();
		ans = 0;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			int x, y, dir, k;
			scanf("%d %d %d %d", &x, &y, &dir, &k);	// ��(0), ��(1), ��(2), ��(3)
			float xf = (float)x;	float yf = (float)y;
			INFO tmp = {xf, yf, dir, k};
			pan[i] = tmp;
		}
		while(true){  // �� �Ͽ� 0.5�� �����ϰ� �Ѵ�. 
			if(check()){
				break;
			}
			walk();
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



