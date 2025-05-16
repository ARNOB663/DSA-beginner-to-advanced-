#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

vector<string> keywords = {"int", "float", "char", "double", "if", "return", "true", "false"};

bool isKeyword(const string &word) {
    for (const string &kw : keywords) {
        if (word == kw)
            return true;
    }
    return false;
}

void parseFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    string word;
    while (file >> word) {
        // Removing special characters from the word
        string token;
        for (char ch : word) {
            if (isalnum(ch) || ch == '_') {
                token += ch;
            }
        }

        if (!token.empty()) {
            if (isKeyword(token))
                cout << "Keyword: " << token << endl;
            else
                cout << "Identifier: " << token << endl;
        }
    }

    file.close();
}

int main() {
    parseFile("input.txt");
    return 0;
}
