#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
	int x,y;
};

bool compare(Point p1, Point p2){
	if(p1.x == p2.x){
		return p1.y > p2.y;
	}
	else{
		return p1.x > p2.x;
	}
}

int main(){
	Point p[4];
	Point p1;
	p1.x = 1;	p1.y = 5;
	
	Point p2;
	p2.x = 4;	p2.y = 3;
	
	Point p3;
	p3.x = 10;	p3.y = 2;
	
	Point p4;
	p4.x = 4;	p4.y = 5;
	
	p[0] = p1;
	p[1] = p2;
	p[2] = p3;
	p[3] = p4;
	
	for(int i = 0 ; i < 4 ; ++i){
		printf("x : %d / y : %d\n", p[i].x, p[i].y);
	}
	
	sort(p, p+4, compare);
	printf("##############################################\n");
	
	for(int i = 0 ; i < 4 ; ++i){
		printf("x : %d / y : %d\n", p[i].x, p[i].y);
	}
	
	return 0;
}
