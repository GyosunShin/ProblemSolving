
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string all;
int cnt;
int startt;

char M[16] = {'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 
'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p){
    
    // m * t��ŭ �̸� ���س��� 
	while(true){
		if(all.size() > (m*t))	break;
		
		string ret = "";
		
		int start = startt;
		while(true){
			
			if((start / n) < n){
				
				if((start / n) == 0){
					if((start % n) >= 10){
						ret.push_back(M[start % n]);
					}					
					else{
						ret.push_back('0' + (start % n));
					}
				}
				else{
					if((start % n) >= 10){
						ret.push_back(M[start % n]);
					}					
					else{
						ret.push_back('0' + (start % n));
					}
					
					if((start / n) >= 10){
						ret.push_back(M[start / n]);
					}					
					else{
						ret.push_back('0' + (start / n));
					}
				}
				
				break;
			}
			else{
				if((start % n) >= 10){
					ret.push_back(M[start % n]);
				}
				else{
					ret.push_back('0' + (start % n));
				}
				start /= n;
			}
			
		}
		
		reverse(ret.begin(), ret.end());
		
		all += ret;
		startt++;
	}
      
    // ���� n, �̸� ���� ������ ���� t, ���ӿ� �����ϴ� �ο� m, Ʃ���� ���� p
    string answer = "";
    
    for(int i = 0 ; i < all.size() ; ++i){
    	if(i % m == (p-1)){
    		answer.push_back(all[i]);
    	}
    	
    	if(answer.size() >= t)	break;	
    }
    
    return answer;
}




