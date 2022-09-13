#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cal_elements(vector<int> &vec, int pos);

void display_elems(vector<int> &vec, const string &title, ostream &os = cout);

int main() {
    vector<int> pent;
    const string title("Pentagonal Numeric Series");
    //测试
    if (cal_elements(pent, 0)) {
        display_elems(pent, title);
    }
    if (cal_elements(pent, 8)) {
        display_elems(pent, title);
    }
    if (cal_elements(pent, 14)) {
        display_elems(pent, title);
    }
    if (cal_elements(pent, 138)) {
        display_elems(pent, title);
    }
}

bool cal_elements(vector<int> &vec, int pos) {
    if (pos <= 0 || pos > 64) {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }
    for (int ix = vec.size() + 1; ix <= pos; ++ix) {
        vec.push_back(ix * (ix * 3 - 1) / 2);
    }
    return true;
}

void display_elems(vector<int> &vec, const string &title, ostream &os) {
    os << "\n" << title << "\n\t";
    for (int ix = 0; ix < vec.size(); ++ix) {
        os << vec[ix] << " ";
    }
    os << endl;
}