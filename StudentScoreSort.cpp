// 학생 성적순 정렬..?
// 임의대로 객체를 정의해서 객체의 특정변수에  기반하여 정렬을 구현할 수 있어야 한다 

#include <iostream>
#include <algorithm>

using namespace std;

class Student{
	public:
		string name;
		int score;
		Student(string name, int score){
			this->name = name;
			this->score = score;
		}
		
	// 정렬 기준은 '점수가 작은 순서'
	bool operator <(Student &student){
		return this->score < student.score;
	}
};

int main(){
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5);
	
	for(int i = 0 ; i < sizeof(students) / sizeof(Student) ; i++){
		cout << students[i].name << ' ';
	}
}
