#include <iostream>
#include <iomanip>

using namespace std;

// Prototype - implement this function
int **szorzat(int *oszlop, int no, int *sor, int ns);

void nyomtat(int *oszlop, int no, int *sor, int ns, int **mtx)
{
    cout << setw(4) << " ";
    for (int j = 0; j < ns; j++)
        cout << setw(4) << sor[j];
    cout << "\n";

    cout << setw(4) << " ";
    for (int j = 0; j < ns; j++)
        cout << "----";
    cout << "\n";

    for (int i = 0; i < no; i++)
    {
        cout << setw(3) << oszlop[i] << "|";
        for (int j = 0; j < ns; j++)
            cout << setw(4) << mtx[i][j];
        cout << "\n";
    }
}

void felszabadit(int **mtx, int no)
{
    for (int i = 0; i < no; i++)
        delete[] mtx[i];
    delete[] mtx;
}

int main()
{
    int oszlop[] = {1, 2, 3};
    int no = sizeof(oszlop) / sizeof(oszlop[0]);

    int sor[] = {4, 5};
    int ns = sizeof(sor) / sizeof(sor[0]);

    int **mtx = szorzat(oszlop, no, sor, ns);

    nyomtat(oszlop, no, sor, ns, mtx);

    felszabadit(mtx, no);

    cout << "\n--- Nagyobb pelda ---\n\n";

    int oszlop2[] = {2, 4, 6, 8, 10};
    int no2 = sizeof(oszlop2) / sizeof(oszlop2[0]);

    int sor2[] = {1, 3, 5, 7};
    int ns2 = sizeof(sor2) / sizeof(sor2[0]);

    int **mtx2 = szorzat(oszlop2, no2, sor2, ns2);

    nyomtat(oszlop2, no2, sor2, ns2, mtx2);

    felszabadit(mtx2, no2);

    return 0;
}