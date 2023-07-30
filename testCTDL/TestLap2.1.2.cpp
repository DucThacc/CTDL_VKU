#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

//---------khai bao CTDL----------

struct SV {
    char name[30];
    int day, month, year;
    float math, physic, language;
    SV *next;  // con tro next
};
SV *L;

//---------Add a student-----------
void Inp(SV *&L)
{
	char ch;
	SV *P, *C;
	//cap' phat' bo. nho' cho P
		
	P=new SV;
		
	//nhap du~ lieu.
		
	//neu' bi. troi du~ lieu. thi` them   fflush(stdin);  tu` chuoi~ qua so'
	fflush(stdin);
	cout<<"Ho Ten= ";
	gets(P->name);	
		
	cout<<"Ngay/Thang/NamSinh: ";
	cin>>P->day>>P->month>>P->year;
		
	cout<<"Diem Toan= ";
	cin>>P->math;
		
	cout<<"Diem Ly= ";
	cin>>P->physic;
		
	cout<<"Diem Van= ";
	cin>>P->language;
		
	//lam` cho con tro? cuoi cung` bang` NULL
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

//-----------Xuat--------------------
void Out(SV *&L)
{
	int dem=1;
	SV *P;
	P=L;
	while(P!=NULL)
	{
		cout<<"--------"<<endl;
		cout<<"STT: "<<dem<<endl;
		cout<<"Ten: "<<P->name<<endl;
		cout<<"Ngay sinh: "<<P->day<<"\\"<<P->month<<"\\"<<P->year<<endl;
		cout<<"Diem Toan: "<<P->math<<endl;
		cout<<"Diem Ly: "<<P->physic<<endl;
		cout<<"Diem Van: "<<P->language<<endl;
		cout<<"---------"<<endl;
		P=P->next;
		dem++;	
	}
}


//----------main--------------------
main()
{
	L=NULL;
	char choice;
        cout << endl << "Menu:" << endl;
        cout <<"---------------------------------------------"<<endl;
        cout << "1. Input n students’ information." << endl;
        cout << "2. Print out the student list." << endl;
        cout << "3. Add a new student to the list." << endl;
        cout << "4. Count the number of students in a given year of birth." << endl;
        cout << "5. Check if a student name x exists in the list or not.";
        cout << "6. Delete a student from the list by a given name x." << endl;
        cout << "7. ind the student(s) having the biggest average of math, physic and language marks." << endl;
        cout << "8. Input n students’ information." << endl;
        cout << "9. Input n students’ information." << endl;
        cout << "10. Exit" <<endl;
        do {
        cout<<"------------------------"<<endl;	
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                
                break;
            case '2':
                Out(L);
                break;
            case '3':
                Inp(L);
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
    
	
	return 1;
}



