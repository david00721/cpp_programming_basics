#include <iostream>
#include <string>

using namespace std;

struct athletes {
    string licence;
    int scores[3];
    int bestScore;
    int bestRace;
};

// Prototype - implement this function
string raceResult(int* bR);

int main() {
    int b_r = 0;
    string b_s = raceResult(&b_r);
    cout << b_s << "\n" << b_r << endl;
    return 0;
}
