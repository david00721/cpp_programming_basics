#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct athletes {
    string licence;
    int scores[3];
    int bestScore;
    int bestRace;
};

string raceResult(const string& filename, int* bR) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Hiba: a fajl nem nyithato meg!" << endl;
        return "";
    }

    int n;
    fin >> n;

    athletes* arr = new athletes[n];

    for (int i = 0; i < n; ++i) {
        fin >> arr[i].licence
            >> arr[i].scores[0]
            >> arr[i].scores[1]
            >> arr[i].scores[2];

        arr[i].bestScore = arr[i].scores[0];
        arr[i].bestRace = 1;

        for (int j = 1; j < 3; ++j) {
            if (arr[i].scores[j] > arr[i].bestScore) {
                arr[i].bestScore = arr[i].scores[j];
                arr[i].bestRace = j + 1;
            }
        }
    }

    int bestIndex = 0;
    int globalBest = arr[0].bestScore;

    for (int i = 1; i < n; ++i) {
        if (arr[i].bestScore > globalBest) {
            globalBest = arr[i].bestScore;
            bestIndex = i;
        }
    }

    *bR = arr[bestIndex].bestRace;
    string bestLicence = arr[bestIndex].licence;

    delete[] arr;
    fin.close();

    return bestLicence;
}

int main() {
    int b_r = 0;
    string best = raceResult("input.txt", &b_r);

    if (!best.empty()) {
        cout << best << "\n" << b_r << endl;
    }

    return 0;
}
