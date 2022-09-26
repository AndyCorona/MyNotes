#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person() { lname = "", fname[0] = '\0'; }

    Person(const string &ln, const char *fn = "Heyyou") {
        this->lname = ln;
        strncpy(this->fname, fn, LIMIT);
    }

    void Show() const {
        cout << "last name: " << this->lname << ", ";
        cout << "first name: " << this->fname << endl;
    }

    void FormatShow() const {
        cout << "format last name: " << this->lname << ", ";
        cout << "format first name: " << this->fname << endl;
    }
};

int main() {
    Person one;
    Person two("Smythecraft");
    Person three("DImwiddy", "Sam");
    one.Show();
    one.FormatShow();
    two.Show();
    two.FormatShow();
    three.Show();
    three.FormatShow();
    return 0;
}