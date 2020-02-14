#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    
    vector<pair<int, int> > newv;
    for(int i = 0 ; i < size ; ++i){
        newv.push_back(pair<int, int>(food_times[i], i+1));
    }
    
    sort(newv.begin(), newv.end());
    
    int pretime = 0;
    for(vector<pair<int, int>>::iterator it = newv.begin() ; it != newv.end() ; ++it, --size){
        long long spend = (long long)(it->first - pretime) * size;
        if(spend == 0)  continue;
        if(spend <= k){
            k -= spend;
            pretime = it->first;
        }
        else{
            k %= size;
            sort(it, newv.end(), comp);
            return (it+k)->second;
        }    	
    }
    
    return -1;
}
