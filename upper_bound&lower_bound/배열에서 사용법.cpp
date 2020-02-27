#include <cstdio> 
#include <algorithm>

using namespace std;

int main(){
	
	int pan[] = {1,2,3,4,5,6,6,6,7,8,9};
	
	int ret = (upper_bound(pan, pan + 11, 6) - lower_bound(pan, pan + 11, 6));
	
	printf("<UPPER_BOUND> : %d\n", upper_bound(pan, pan + 11, 6) - pan);
	printf("<LOWER_BOUND> : %d\n", lower_bound(pan, pan + 11, 6) - pan);
	
	printf("%d", ret);
	
	return 0;
}
