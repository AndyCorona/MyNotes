#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");
    if (!in_file || !out_file) {
        cerr << "Unable to open the necessary file.\n";
        return -1;
    }
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    vector<string> text;
    copy(is, eof, back_inserter(text));
    sort(text.begin(), text.end());
    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);
    return 0;
}
