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

string raceResult(int *bR) {
    int n;
    cin >> n;

    athletes* arr = new athletes[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].licence
            >> arr[i].scores[0]
            >> arr[i].scores[1]
            >> arr[i].scores[2];

        // legjobb részpont és annak versenye (1–3)
        arr[i].bestScore = arr[i].scores[0];
        arr[i].bestRace = 1;

        for (int j = 1; j < 3; ++j) {
            if (arr[i].scores[j] > arr[i].bestScore) {
                arr[i].bestScore = arr[i].scores[j];
                arr[i].bestRace = j + 1;
            }
        }
    }

    // globális legjobb keresése
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

    return bestLicence;
}

int main() {
    int b_r = 0;
    string b_s = raceResult(&b_r);
    cout << b_s << "\n" << b_r << endl;
    return 0;
}
