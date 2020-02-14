#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> tmp1{0};
    vector<int> tmp2{0, 0, 1};
    
    if(n == 1)	return tmp1;
    if(n == 2)	return tmp2;
    
    vector<int> prev = tmp2;
    for(int j = 3 ; j <= n ; ++j) {
		vector<int> aft;
		
		for(int i = 0 ; i < (prev.size() / 2) ; ++i){
			aft.push_back(prev[i]);
		}
		aft.push_back(0);
		for(int i = (prev.size() / 2) + 1 ; i < prev.size() ; ++i){
			aft.push_back(prev[i]);
		}
		aft.push_back(0);
		for(int i = 0 ; i < (prev.size() / 2) ; ++i){
			aft.push_back(prev[i]);
		}
		aft.push_back(1);
		for(int i = (prev.size() / 2) + 1 ; i < prev.size() ; ++i){
			aft.push_back(prev[i]);
		}
		prev = aft;
    }
    return prev;
}
