#include <iostream>
#include <string>
using namespace std;

struct SV {
    string name;
    int day, month, year;
    double math, physic, language;
    SV *next;
};

void inputSV(SV*& L) {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        SV *P = new SV;
        cout << "\nEnter name of student " << i << ": ";
        cin.ignore();
        getline(cin, P->name);
        cout << "Enter date of birth (day month year): ";
        cin >> P->day >> P->month >> P->year;
        cout << "Enter math mark: ";
        cin >> P->math;
        cout << "Enter physic mark: ";
        cin >> P->physic;
        cout << "Enter language mark: ";
        cin >> P->language;
        P->next = L;
        L = P;
    }
}

void OutpSV(SV* L) {
    cout << "List of students:\n";
    while (L != NULL) {
        cout << L->name << "\t" << L->day << "/" << L->month << "/" << L->year 
             << "\t Math: " << L->math << "\t Physic: " << L->physic << "\t Language: " << L->language << "\n";
        L = L->next;
    }
}

void addSV(SV*& L) {
    SV *P = new SV;
    cout << "\nEnter name of new student: ";
    cin.ignore();
    getline(cin, P->name);
    cout << "Enter date of birth (day month year): ";
    cin >> P->day >> P->month >> P->year;
    cout << "Enter math mark: ";
    cin >> P->math;
    cout << "Enter physic mark: ";
    cin >> P->physic;
    cout << "Enter language mark: ";
    cin >> P->language;
    P->next = L;
    L = P;
}

void countSVbyYear(SV *L){
	int count=0;
	int c_year;
	cout << "Enter year of birth: ";
	cin>>c_year;
	while (L!=NULL)
	{
		if (L->year==c_year)
		{
			count++;
		}
		L=L->next;
	}
	cout<<"Number of student born in "<<c_year<<" is "<<count<<endl;
}

bool checkSV(SV *L){
	string c_name;
	cout << "Enter student name to search: ";
	cin.ignore();
    getline(cin, c_name);
    while (L!=NULL)
    {
    	if (L->name == c_name)
    	{
    		return true;
		}
		L=L->next;
	}
	return false;
}

void deleteSV(SV*&L){
	SV *P=NULL;
	SV *C=L;
	string d_name;
	cout << "Enter student name to delete: ";
	cin>>d_name;
	
	while (C!=NULL and C->name!=d_name)
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
		cout << "Student "<<d_name<<" has been deleted.\n";
	}
	else {
		cout << "Student "<<d_name<<" is not found.\n";
	}
	
}

void findSV(SV*&L){
	
}

void printSV(SV*L){
	SV*P;
	P=L;
	int count=0;
	while (P!=NULL)
	{
		if(P->math<5){
			 cout << P->name << "\t Math: " << P->math
                 << "\t Physic: " << P->physic << "\t Language: " << P->language << "\n";
			count++;
		}
		P=P->next;
	}
	if (count == 0) {
        cout << "No students found with math marks less than 5.\n";
    }
}

SV *newSVien(string name, int day, int month, int year, double math, double physic, double language){
	SV *newSV = new SV;
    newSV->name=name;
    newSV->day=day;
	newSV->month=month;
	newSV->year=year;
	newSV->math=math;
	newSV->physic=physic;
	newSV->language=language;
	newSV->next=NULL;
	return newSV;
}


void chen(SV**head,int pos, string name, int day, int month, int year, double math, double physic, double language){
	SV *newSV= newSVien(name,day,month,year,math,physic,language);
	SV *current=*head;
	for (int i=0; i<pos-1&& current!=NULL; i++){
		current=current->next;
	} 
	
	newSV->next=current->next;
	current->next=newSV;
	
	
}

int main() {
    SV* L = NULL;
    SV *head=NULL;
    int choice;
        cout << "\n------- MENU -------\n";
        cout << "1. Input students' information\n";
        cout << "2. Print students' information\n";
        cout << "3. Add a new student\n";
        cout << "4. Count students by year of birth\n";
        cout << "5. Check if a student name x exists in the list or not.\n";
        cout << "6. Delete a student from the list by a given name x.\n";
        cout << "7. Find the student(s) having the biggest average of math, physic and language marks.\n";
        cout << "8. Print the list of students whose math mark is less than 5\n";
        cout << "9. Insert";
        cout << "10. Exit program\n";
    do {    
    	cout << "--------------------------------\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputSV(L);
                OutpSV(L);
                break;
            case 2:
                OutpSV(L);
                break;
            case 3:
                addSV(L);
                OutpSV(L);
                break;
            case 4:
                countSVbyYear(L);
                break;
            case 5:
				if (checkSV(L)){
					cout << "Name exists in the list.\n";
				}
				else{
					cout << "Name doesn't exists in the list.\n";
				}
				break;  
			case 6:
				deleteSV(L);
				break;
			case 7:
				int pos;
				string name;
    			int day, month, year;
    			double math, physic, language; 
    			cout<<"\nVi tri can chen: ";
    			cin>>pos;
    			cout << "\nEnter name of new student: ";
				cin>>name;
				cout << "Enter date of birth (day month year): ";
				cin>>day;
				cin>>month;
				cin>>year;
				cout << "Enter math mark: ";
				cin>>math;
				cout << "Enter physic mark: ";
				cin>>physic;
				cout << "Enter language mark: ";
				cin>>language;	
				chen(&head,pos,name,day,month,year,math,physic,language);
				OutpSV(L);
				break;
			case 8:
				printSV(L);
				break;
			
			case 9:
				cout << "Exiting program\n";
				break;	  
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}

