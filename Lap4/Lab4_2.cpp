#include<bits/stdc++.h>
using namespace std;
int n;
struct Student{
	char name[30];
	char Class [10];
	float mMath;
	float mPhysical;
	float mAvg;
};

void addstudent(Student (&students)[100]){
	cout << "input n student: "<<endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Name of student " << i+1 << " : "; cin >> students[i].name;
		cout << "Class : "; cin >> students[i].Class;
		cout << "Math grade: "; cin >> students[i].mMath;
		cout << "Physical grade: "; cin >> students[i].mPhysical;
		students[i].mAvg = (students[i].mMath + students[i].mPhysical)/2;
	}	

}
void search_student(Student students[100], char name[30] ){
	for( int i = 0; i < n; i++){
		if( strcmp(students[i].name,name)==0 ){

			cout << "The result:" << endl;
			cout << "\tname: " << students[i].name << endl;
			cout << "\tclass: "<< students[i].Class << endl;
			cout << "\tMath: "<< students[i].mMath << endl;
			cout << "\tPhysical: "<< students[i].mPhysical << endl;
			cout << "\tAverage:" << students[i].mAvg << endl;

			cout << "Edit class of this students to: "; cin >> students[i].Class; 
			cout << "After edit:" << endl;
			cout << "\tname: " << students[i].name << endl;
			cout << "\tclass: "<< students[i].Class << endl;
			cout << "\tMath: "<< students[i].mMath << endl;
			cout << "\tPhysical: "<< students[i].mPhysical << endl;
			cout << "\tAverage:" << students[i].mAvg << endl;
			break;
		}
	}
}
void sort(Student (&students)[100]){
	for(int i = 1;i < n; i++){
		int index = i;
		int j = i - 1;
		while(j >= 0 && students[index].mAvg > students[j].mAvg){
			swap(students[index],students[j]);
			index = j;
			j--;
		}		
	}
}
void display(Student students[100]){
	cout << "The result:" << endl;
		for( int i = 0; i < n; i++){
			cout <<	"Student " << i << " : \n";
			cout << "\tname: " << students[i].name << endl;
			cout << "\tclass: "<< students[i].Class << endl;
			cout << "\tMath: "<< students[i].mMath << endl;
			cout << "\tPhysical: "<< students[i].mPhysical << endl;
			cout << "\tAverage:" << students[i].mAvg << endl;
	}	
}
int main(){
	Student students[100];
	addstudent(students);
	char name[30];
	int n;
	do{
		cout<<	"------------------------";
		cout << "1. Search\n";
		cout << "2. Sort\n";
		cout << "3. Display\n";
		cout << "4. Exit\n";
		cout<<	"------------------------";
		cin >> n;
		switch(n){
			case 1:
				cout << "Name: ";
				cin >> name;
				search_student(students,name);
				break;
			case 2:
				cout <<"Sort!\n";
				sort(students);
				break;
			case 3:
				display(students);
		}
	}while(n != 4);
	return 0;
}
