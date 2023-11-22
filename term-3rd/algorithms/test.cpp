#include <iostream>
#include <string>
using namespace std;

int main() {
    string r = "123";
    r = r.substr(0, r.size() - 1);
    cout << r << endl;

    return 0;
}