#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];

    cout << "Adj meg " << N << " egesz szamot:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int osszeg = 0, maxVal = arr[0], minVal = arr[0];
    for (int i = 0; i < N; i++) {
        osszeg += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    double atlag = static_cast<double>(osszeg) / N;

    int nagyobb = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > atlag) nagyobb++;
    }

    cout << "\nOsszeg: " << osszeg
         << "\nAtlag: " << atlag
         << "\nLegnagyobb: " << maxVal
         << "\nLegkisebb: " << minVal
         << "\nAtlagnal nagyobbak: " << nagyobb << endl;

    return 0;
}