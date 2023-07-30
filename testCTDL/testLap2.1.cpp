#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

//---------khai bao CTDL----------

struct Student {
    char name[30];
    int day, month, year;
    double math, physic, language;
    Student *next;  // con tro next
};
Student *L;

//----------ham` nhap case 1--------------

void inputStudent(Student *&L)
{
	Student *P, *C;
	int n;
	cout<<"Enter number of students: ";
	cin>>n;
	for (int i = 1; i <= n; i++){
		P= new Student;
	
	//---Nhap. du~ lieu.---
	//neu' bi. troi du~ lieu. thi` them   fflush(stdin);  tu` chuoi~ qua so'
	fflush(stdin);  
	cout<<"Name: ";
	get(P->name);
	
	cout<<"Day-Month-Year: ";
	cin>>P->day>>P->month>>P->year;
	
	cout<<"Math: ";
	cin>>P->math;
	
	cout<<"Physic: ";
	cin<<P->physic;
	
	cout<<"Language: ";
	cin>>P->language;
	
	//chuyen? con tro? cuoi' bang` NULL;
	P->next=NULL;
	if(L==NULL)
		{
			L=P;
			C=P;
		}
	else
		{
			//them vao` cuoi' dsach
			C->next=P;
			C=P;
		}
	}
}





//----------ham` xuat case 2-------------

void printStudent(Student *&L)
{
	int dem=1;
	Student *P;
	P=L;
	while(P!=NULL)
	{
		cout<<dem<<"     "<<P->name<<"\t"<<P->day<<"\ "<<P->month<<"\ "<<P->year<<"\t"<<P->math<<"\t"<<P->physic<<"\t"<<P->language<<"\n";
		P=P->next;
		dem++;
	}
}


//----------ham` nhap case 3-------------

void addStudent(Student *&L)
{
	Student *P, *C;
	
	//cap' phat' bo. nho' cho P
	P= new Student;
	
	//---Nhap. du~ lieu.---
	//neu' bi. troi du~ lieu. thi` them   fflush(stdin);  tu` chuoi~ qua so'
	fflush(stdin);  
	cout<<"Name: ";
	get(P->name);
	
	cout<<"Day-Month-Year: ";
	cin>>P->day>>P->month>>P->year;
	
	cout<<"Math: ";
	cin>>P->math;
	
	cout<<"Physic: ";
	cin<<P->physic;
	
	cout<<"Language: ";
	cin>>P->language;
	
	//chuyen? con tro? cuoi' bang` NULL;
	P->next=NULL;
	if(L==NULL)
		{
			L=P;
			C=P;
		}
	else
		{
			//them vao` cuoi' dsach
			C->next=P;
			C=P;
		}
	
}





//----------Ham` Main-------------

main()
{
	L=NULL;
	char choice;
    do {
        cout << endl << "Menu:" << endl;
        cout <<"---------------------------------------------";
        cout << "1. Input n students’ information." << endl;
        cout << "2. Print out the student list." << endl;
        cout << "3. Add a new student to the list." << endl;
        cout << "4. Count the number of students in a given year of birth." << endl;
        cout << "5. Check if a student name x exists in the list or not."
        cout << "6. Delete a student from the list by a given name x." << endl;
        cout << "7. ind the student(s) having the biggest average of math, physic and language marks." << endl;
        cout << "8. Input n students’ information." << endl;
        cout << "9. Input n students’ information." << endl;
        cout << "10. Exit" <<endl;
        cout <<"----------------------------------------------";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                
                break;
            case '2':
                
                break;
            case '3':
                
                break;
            case '4':
                
                break;
            case '5':
                
                break; 
			case '6':
                
                break;	
			case '7':
                
                break;
			case '8':
                
                break;
			case '9':
                
                break;			   
            case '10':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Nhap so sai! Vui long nhap lai: " << endl;
        }
    } while (choice != '10');
    return 0;
}
}

