// �ʱ� (1��N(R)��50, 1��M(C)��50)
// ���ð� (1��K��300)
// �ٱ⼼�� ����� (1��X��10) 

//  OUTPUT : K�ð� �� ����ִ� �ٱ� ����(��Ȱ�� ���� + Ȱ�� ����)�� �� ������ ���ϴ� ���α׷��� �ۼ��϶�.

#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int T, R, C, K; 

map<pair<int, int>, pair<int, int> > nonactive;   // ���� ��Ȱ��ȭ ������ ���� 
map<pair<int, int>, int> active;	  // Ȱ��ȭ ������ ���� 
set<pair<int, int> > death;   // �̹� ���� ��� 
map<pair<int, int>, int> next_map;  // ���� ���� ���� �ߺ� Ȯ�ο�  

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		nonactive.clear();
		active.clear();
		death.clear();
		next_map.clear();
		
		
		// (1 ~ 10 : �����)  (0 : ��ĭ)
		scanf("%d %d %d", &R, &C, &K);
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				int value;
				scanf("%d", &value);
				if(value > 0)	nonactive[make_pair(i,j)] = make_pair(value, value);
			}
		}
		
		for(int i = 0 ; i < K ; ++i){
			
//			printf("%d�ð�°\n", i);
//			
//			printf("��Ȱ��ȭ��: ");
			map<pair<int, int>, pair<int, int> >::iterator it_nonactive;	
//			for(it_nonactive = nonactive.begin() ; it_nonactive != nonactive.end() ; ++it_nonactive){
//				printf("%d, %d / ", it_nonactive->first.first, it_nonactive->first.second);
//			}
//			printf("\nȰ��ȭ��: ");
			map<pair<int, int>, int>::iterator it_active;	
//			for(it_active = active.begin() ; it_active != active.end() ; ++it_active){
//				printf("%d, %d / ", it_active->first.first, it_active->first.second);
//			}
//			printf("\nDEAATH��: ");
			set<pair<int, int>>::iterator it_death;	
//			for(it_death = death.begin() ; it_death != death.end() ; ++it_death){
//				printf("%d, %d / ", (*it_death).first, (*it_death).second);
//			}
//			printf("\n");
			
			// 1st) Ȱ������ Ȯ�� �� ���� ����
			map<pair<int, int>, int>::iterator it;
			for(it = active.begin() ; it != active.end() ; ++it){
				int cur_r = it->first.first;	int cur_c = it->first.second;	int cur_power = it->second;
				
				for(int dir = 0 ; dir < 4 ; ++dir){
					int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
					// �ϴ� ���� ������ �־����� Ȯ��
					
					// ��Ȱ���� �̹� �ִ��� Ȯ�� 
					map<pair<int, int>, pair<int, int> >::iterator it_nonactive;		 
					it_nonactive = nonactive.find({next_r, next_c});
					if(it_nonactive != nonactive.end()){
						continue;
					}
					
					// Ȱ���� �̹� �ִ��� Ȯ�� 
					map<pair<int, int>, int>::iterator it_active;		 
					it_active = active.find({next_r, next_c});
					if(it_active != active.end()){
						continue;
					}	
					
					// ������ �̹� �ִ��� Ȯ��
					set<pair<int, int> >::iterator it_death;		 
					it_death = death.find({next_r, next_c});
					if(it_death != death.end()){
						continue;
					}	
					
					// ���� �ڸ����� �̹� �������� ������ next_map�� �̹� �ִ��� Ȯ��
					map<pair<int, int>, int>::iterator it_next;
					it_next = next_map.find({next_r, next_c});
					if(it_next != next_map.end()){
						int existed_value = it_next->second;
						if(cur_power > existed_value){
							next_map[{next_r, next_c}] = cur_power;
						}
					}
					else{
						next_map[{next_r, next_c}] = cur_power;
					}
					
				}
			}
			
			// Ȱ��ȭ ��Ͽ��� power �ϳ��� ����� ��
			// �ϳ� ���� 0�Ǵ� ����� active���� erase���ְ� death�� �̰�!
//			map<pair<int, int>, int >::iterator it_active;

			vector<pair<int, int> > erased;
			for(it_active = active.begin() ; it_active != active.end() ; ++it_active){
				int tmp_cur = it_active->second;
				if((tmp_cur - 1) == 0){
					death.insert(make_pair(it_active->first.first, it_active->first.second));
					erased.push_back(make_pair(it_active->first.first, it_active->first.second));
//					active.erase({it_active->first.first, it_active->first.second});
				}
				else{
					active[{it_active->first.first, it_active->first.second}] = tmp_cur - 1;
				}
			}			
			for(int j = 0 ; j < erased.size() ; ++j)	active.erase({erased[j].first, erased[j].second});
			erased.clear();
			
			// ��Ȱ�� ��Ͽ��� -1�� ���־ 0�� �Ǵ� ���� ������ nonactive������ �����ϰ�  active�� �־��ּ� 
//			map<pair<int, int>, pair<int, int> >::iterator it_nonactive;

//			printf("SIZe : %d\n", nonactive.size());
			for(it_nonactive = nonactive.begin() ; it_nonactive != nonactive.end() ; ++it_nonactive){
				int tmp_value = it_nonactive->second.first;
//				printf("R : %d, C : %d / TMP_VALUE  %d\n",it_nonactive->first.first, it_nonactive->first.second , tmp_value);
				if(tmp_value - 1 == 0){
					active[{it_nonactive->first.first, it_nonactive->first.second}] = it_nonactive->second.second;
					erased.push_back(make_pair(it_nonactive->first.first, it_nonactive->first.second));
//					nonactive.erase({it_nonactive->first.first, it_nonactive->first.second});
				}
				else{
					nonactive[{it_nonactive->first.first, it_nonactive->first.second}] = make_pair(tmp_value - 1, it_nonactive->second.second);
				}

			}
			for(int j = 0 ; j < erased.size() ; ++j)	nonactive.erase({erased[j].first, erased[j].second});
			erased.clear();

			// ���� �Ϸ� 
			map<pair<int, int>, int>::iterator it_next;
			for(it_next = next_map.begin() ; it_next != next_map.end() ; ++it_next){
				int cur_r = it_next->first.first;	int cur_c = it_next->first.second;	int cur_power = it_next->second;
				nonactive[{cur_r, cur_c}] = make_pair(cur_power, cur_power);
			}
			next_map.clear();
			
			
		}   // K�ð� �Ϸ� �� 
		
		int ans = 0;
		// Ȱ�� + ��Ȱ�� ������ �ٱ⼼�� �� ���ϱ�
		ans += (nonactive.size() + active.size());
		printf("#%d %d\n", z, ans);
		
	}
	return 0;
}
