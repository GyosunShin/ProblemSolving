#include <iostream> 
#include <set>

using namespace std;

int main(){
	set<int> s;
	
	for(int i = 1 ; i <= 100 ; ++i){
		s.insert(i);
	}
	
	auto it = s.find(50);
	
	if(it != s.end()){
		cout << "EXIST!" << endl;
	}
	else{
		cout << "NOT EXIST!" << endl;
	}
	
	for(auto iit = s.begin() ; iit != it ; ++iit){
		cout << *iit << endl;
	}
	printf("------------------------\n");
	for(it ; it != s.end() ; ++it){
		cout << *it << endl;
	}	
	
	return 0;
}
