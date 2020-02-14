// N 개의 원자들의 [x, y] 위치, 이동 방향, 보유 에너지가 주어질 때 원자들이 소멸되면서 방출하는 에너지의 총합을 구하는 프로그램을 작성하라.

// 원자의 수 (1≤N≤1,000) 
// 각 원자의 보유 에너지 (1≤K≤100) 
// 처음 위치 (-1,000≤x,y≤1,000)
// 좌표의 범위에 제한은 없다.
// 상(0), 하(1), 좌(2), 우(3)

#include <cstdio> 
#include <map>	
#include <vector>

using namespace std;

struct INFO{
	float x, y;
	int dir, energy;
};

int T, N;

//  상 하 좌 우 
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
	// 조합 nCr
	for(int i = 0 ; i < tmp_size ; ++i){
		for(int j = i+1 ; j < tmp_size ; ++j){
			// 만날 가능성이 한 조합이라도 있으면 return false해버린다. 
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

void walk(){  // 0.5칸씩 전진!

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
	
	// next_pan에서 사이즈 2 이상인 것들 다 죽이기
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
			scanf("%d %d %d %d", &x, &y, &dir, &k);	// 상(0), 하(1), 좌(2), 우(3)
			float xf = (float)x;	float yf = (float)y;
			INFO tmp = {xf, yf, dir, k};
			pan[i] = tmp;
		}
		while(true){  // 한 턴에 0.5씩 전진하게 한다. 
			if(check()){
				break;
			}
			walk();
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



