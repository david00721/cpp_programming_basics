#include <iostream>
#include <string>
using namespace std;

string screaming(string* szavak, int n) {
    string result = "";

    for (int i = 0; i < n; ++i) {
        string word = szavak[i];

        // minden karaktert nagybetűssé alakítunk
        for (int j = 0; j < (int)word.size(); ++j) {
            word[j] = toupper(word[j]);
        }

        if (!result.empty()) {
            result += "_";   // elválasztó csak nem első elem elé
        }

        result += word;
    }

    return result;
}

int main() {
    string s[] = {"I", "love", "C++", "programming"};
    int n = sizeof(s) / sizeof(s[0]);

    cout << screaming(s, n) << endl;   // I_LOVE_C++_PROGRAMMING

    return 0;
}