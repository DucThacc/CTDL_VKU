#include<iostream>
#include<cstring>

struct Student {
    char id[12];
    char name[30];
    char classs[10];
    float mMath;
    float mPhysical;
};

void inputList(Student* students, int numStudents);
void outputList(Student* students, int numStudents);
void searchById(Student* students, int numStudents, char* id);
void sortList(Student* students, int numStudents);

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cin.ignore(); // ignore the newline character left in the buffer

    Student* students = new Student[numStudents];

    inputList(students, numStudents);
    std::cout << "\nList of students\n";
    outputList(students, numStudents);

    char searchId[12];
    std::cout << "\nEnter an id to search: ";
    std::cin.getline(searchId, 12);
    searchById(students, numStudents, searchId);

    sortList(students, numStudents);
    std::cout << "\nList of students sorted by avg\n";
    outputList(students, numStudents);

    delete[] students;
    return 0;
}

void inputList(Student* students, int numStudents) {
    std::cout << "\nEnter the information of " << numStudents << " students\n";
    for (int i = 0; i < numStudents; i++) {
        std::cout << "\nStudent " << i+1 << ":\n";
        std::cout << "ID: ";
        std::cin.getline(students[i].id, 12);
        std::cout << "Name: ";
        std::cin.getline(students[i].name, 30);
        std::cout << "Class: ";
        std::cin.getline(students[i].classs, 10);
        std::cout << "Math marks: ";
        std::cin >> students[i].mMath;
        std::cout << "Physical marks: ";
        std::cin >> students[i].mPhysical;
        std::cin.ignore(); // ignore the newline character left in the buffer
    }
}

void outputList(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        std::cout << "\nStudent " << i+1 << ":";
        std::cout << "\nID: " << students[i].id;
        std::cout << "\nName: " << students[i].name;
        std::cout << "\nClass: " << students[i].classs;
        std::cout << "\nMath marks: " << students[i].mMath;
        std::cout << "\nPhysical marks: " << students[i].mPhysical << std::endl;
    }
}

void searchById(Student* students, int numStudents, char* id) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            std::cout << "\nStudent found:";
            std::cout << "\nID: " << students[i].id;
            std::cout << "\nName: " << students[i].name;
            std::cout << "\nClass: " << students[i].classs;
            std::cout << "\nMath marks: " << students[i].mMath;
            std::cout << "\nPhysical marks: " << students[i].mPhysical << std::endl;
            return; // return if student found
        }
    }
    std::cout << "\nStudent with ID " << id << " not found." << std::endl; // print if student not found
}

void sortList(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int maxIdx = i;
        float maxAvg = (students[i].mMath + students[i].mPhysical) / 2;
        for (int j = i+1; j < numStudents; j++) {
            float curAvg = (students[j].mMath + students[j].mPhysical) / 2;
            if (curAvg > maxAvg) {
                maxIdx = j;
                maxAvg = curAvg;
            }
        }
        // swap students[i] and students[maxIdx]
        Student temp = students[i];
        students[i] = students[maxIdx];
        students[maxIdx] = temp;
    }
}
