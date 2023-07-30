#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[30];
    char class_name[10];
    float math_score;
    float physics_score;
};

void add(Student students[], int& numStudents) {
    cout << "Enter student's name: ";
    cin >> students[numStudents].name;
    cout << "Enter student's class: ";
    cin >> students[numStudents].class_name;
    cout << "Enter student's math score: ";
    cin >> students[numStudents].math_score;
    cout << "Enter student's physics score: ";
    cin >> students[numStudents].physics_score;
    numStudents++;
}

void search(Student students[], int numStudents) {
    string nameToSearch;
    bool found = false;
    cout << "Enter name to search: ";
    cin >> nameToSearch;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].name == nameToSearch) {
            cout << "Name: " << students[i].name << endl;
            cout << "Class " << students[i].class_name << endl;
            cout << "Math: " << students[i].math_score << endl;
            cout << "Physics: " << students[i].physics_score << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    }
}

void search_and_edit(Student students[], int numStudents) {
    string nameToSearch;
    bool found = false;
    cout << "Enter name to search: ";
    cin >> nameToSearch;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].name == nameToSearch) {
            cout << "Student found!" << endl;
            cout << "Current class: " << students[i].class_name << endl;
            cout << "Enter new class: ";
            cin >> students[i].class_name;
            cout << "Class updated successfully." << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main(){
	//chèn, sap xep, xoa
	Student students[50];
	int numStudents = 0;
	int n;
	cout<<"*************************************************"<<endl;
	cout<<"    	MANAGING LIST OF STUDENTS               "<<endl;
	cout<<endl;
	cout<<"   1.Add a new student                          "<<endl;
	cout<<"   2.Search a student by name       		    "<<endl;
	cout<<"   3.Search and edit class of the student      "<<endl;
	cout<<"   4.Exit                                        "<<endl;
	cout<<"**************************************************"<<endl;
	do{
		cout<<"--------------------";
		cout<<"Choose (1,2,3) : ";
		cin>>n;
		  switch (n) {
            case 1:
                add(students, numStudents);
                break;
            case 2:
                search(students, numStudents);
                break;
            case 3:
            	search_and_edit(students, numStudents);
            	break;  
			case 4:
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
