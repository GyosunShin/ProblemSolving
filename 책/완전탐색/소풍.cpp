#include <stdio.h> 
#include <iostream>

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]){
	int firstFree = -1;
	for(int i = 0 ; i < n ; i++){
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	
	if(firstFree == -1)  return 1;
	int ret = 0;
	
	for(int pairwith = firstFree+1 ; pairwith < n ; pairwith++){
		if(!taken[pairwith] && areFriends[firstFree][pairwith]){
			taken[firstfree] = taken[pairwith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairwith]  = false;
		}
	}
	return ret;
}
