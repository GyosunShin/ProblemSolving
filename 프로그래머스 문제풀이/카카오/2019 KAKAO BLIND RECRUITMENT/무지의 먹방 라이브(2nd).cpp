
// OUTPUT
// �� �� ���ĺ��� �ٽ� �����ϸ� �Ǵ��� return 
// ���� �� �����ؾ� �� ������ ���ٸ� -1�� ��ȯ�ϸ� �ȴ�.

#include <string>
#include <vector>

using namespace std;

int answer;
int N;

bool check(vector<int>& input){
	bool ret = true;
	
	for(int i = 0 ; i < input.size() ; ++i){
		if(input[i] > 0){
			ret = false;
			break;
		}
	}
	
	return ret;
}

int solution(vector<int> food_times, long long k) {
    N = food_times.size();
    
    int start = 0;
    
    for(long long i = 0 ; i < k ; ++i){
    	
//    	if(check(food_times))	return -1;
    	
//    	printf("%d : %d\n", i, start);
    	
    	if(food_times[start] == 0){
    		
    		bool tmp_flag = false;
    		int next;
    		for(int j = 1 ; j < N ; ++j){
    			next = (start + j) % N;
    			if(food_times[next] > 0){
    				tmp_flag = true;
    				break;
    			}
    		}
    		if(!tmp_flag){
//    			printf("��Ż\n");
    			return -1;
    		}
    		food_times[next]--;
//    		printf("���� : %d\n", next);
    		start = (next + 1) % N;
    		continue;
    		
		}
		
    	food_times[start]--;
    	start = (start + 1) % N;		
    	
    }
    
	bool tmp_flag = false;
	if(food_times[start] == 0){
		
		int next;    
		for(int j = 1 ; j < N ; ++j){
			next = (start + j) % N;
			if(food_times[next] > 0){
				tmp_flag = true;
				break;
			}
		}
		if(!tmp_flag)	return -1;
		start = next % N;
	}
    
    
    return start+1;
}



