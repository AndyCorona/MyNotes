#include <iostream>
#include "studenti.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student &stu, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    int i;
    for (i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }
    cout << "\nResult:";
    for (i = 0; i < pupils; i++) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }

    return 0;
}