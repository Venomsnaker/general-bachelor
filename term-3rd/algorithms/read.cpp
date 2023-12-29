#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool isFloat(const string& myString) {
    istringstream iss(myString);
    float f;
    iss >> noskipws >> f; 
    return iss.eof() && !iss.fail();
}

int main() {
    fstream infile("sample.txt");

    if (infile.is_open()) {
        string line;
        while(getline(infile, line)) {
            if (line.empty()) continue;
            istringstream iss(line);
            string word;
            string name = "", code = "";
            float score1, score2;

            while (iss >> word) {
                bool flag = isFloat(word);

                if (flag && code != "") {
                    float val = stof(word);
                    score2 = val;
                }else {
                    if (word[word.size() - 1] == ',') {
                        float val = stof(word.substr(0, 3));
                        score1 = val;
                    }else {
                        if (code == "") {
                            code += word;
                        } else {
                            name += word + " ";
                        }
                    }
                }
            }
            name.pop_back();
            cout << code << " " << name << " " << score1 << " " << score2 << endl;
        }
        infile.close();
    }
    return 0;
}