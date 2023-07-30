#include <iostream>
#include <string>
using namespace std;

struct SV {
    string name;
    int day, month, year;
    double math, physic, language;
    SV *next;
};
SV*L;

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

void countSVbyYear(SV *L){
	int count=0;
	int year;
	cout << "year: ";
	cin>>year;
	while (L!=NULL)
	{
		if (L->year==year)
		{
			count++;
		}
		L=L->next;
	}
	cout<<count<<endl;
}

void deleteSV(SV*&L){
	SV *P=NULL;
	SV *C=L;
	string name;
	cout << "Enter name to delete: ";
	cin>>name;
	
	while (C!=NULL and C->name!=name)
	{
		P=C;
		C=C->next;
	}
	
	if (C!=NULL){
		if (P==NULL){
			L=C->next;
		}
		else{
			P->next=C->next;
		}
		delete C;
		cout << "Student "<<name<<" deleted.\n";
	}
	else {
		cout << "Student "<<name<<" is not found.\n";
	}
	
}



main(){
	L=NULL;
}

