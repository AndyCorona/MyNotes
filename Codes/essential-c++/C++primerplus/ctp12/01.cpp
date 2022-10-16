#include <iostream>
#include "01.h"

using namespace std;

Cow::Cow() {
    hobby = new char[1];
    hobby[0] = '\0';
}

Cow::Cow(const char *nm, const char *ho, double wt) {
    strcpy(name, nm);
    int len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::~Cow() {
    delete[] hobby;
}

Cow &Cow::operator=(const Cow &c) {
    if (this == &c) {
        return *this;
    }
    strcpy(name, c.name);
    delete [] hobby;
    int n = strlen(c.hobby);
    hobby = new char[n + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

Cow::Cow(const Cow &c) {
    strncpy(name, c.name, strlen(c.name));
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

void Cow::ShowCow() const {
    cout << "名字：" << name << endl;
    cout << "爱好：" << hobby << endl;
    cout << "体重：" << weight << endl;
}

int main() {
    Cow cow2 = Cow("第一只", "一", 1.0);
    cow2.ShowCow();
    Cow cow3 = cow2;
    cow3.ShowCow();
    Cow cow4 = Cow(cow3);
    cow4.ShowCow();
    Cow cow5;
    cow5 = cow4;
    cow5.ShowCow();
}