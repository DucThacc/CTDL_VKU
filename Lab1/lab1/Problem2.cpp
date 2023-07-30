#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
	char name[30];
	char classs[10];
	float mMath;
	float mPhysical; 
}; Student  student[100];

int stt=0;
void add_new_student(){
	Student new_st;
	cout<<"Enter name of student: ";
	cin>>new_st.name;
	cout << "Enter class of student: ";
    cin >> new_st.classs;
    cout << "Enter student's math grade: ";
    cin >> new_st.mMath;
    cout << "Enter student's physical grade: ";
    cin >> new_st.mPhysical;
    
    student[stt] = new_st;
    stt++;
    cout<<"Success !"<<endl;
}


int main(){
	int n;
	cout<<"*************************************************"<<endl;
	cout<<"    	MANAGING LIST OF STUDENTS               "<<endl;
	cout<<endl;
	cout<<"   1.Add a new student                          "<<endl;
	cout<<"   2.Search a student by name       		    "<<endl;
	cout<<"   3.Search and edit class of the student      "<<endl;
	cout<<"**************************************************"<<endl;
	do{
		cout<<"Choose (1,2,3) : ";
		cin>>n;
		  switch (n) {
            case 1:
                add_new_student();
                break;
            case 2:
                break;
            case 3:
            	break;
            	
            default:
				cout<<"Try again"<<endl;
				break;					
	}
	}
	while (n!=4);
	{
		return 0;
	}
}
