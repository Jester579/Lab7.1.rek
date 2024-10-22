#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** a, const int rowCount, const int colCount, int i = 0, bool swapped = false);
void Change(int** a, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -8;
    int High = 42;
    int rowCount = 8;
    int colCount = 7;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, rowCount, colCount, Low, High, i, j + 1);  
        }
        else {
            Create(a, rowCount, colCount, Low, High, i + 1, 0);  
        }
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << a[i][j];
            Print(a, rowCount, colCount, i, j + 1);  
        }
        else {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);  
        }
    }
    else {
        cout << endl;
    }
}

void Sort(int** a, const int rowCount, const int colCount, int i, bool swapped)
{
    if (i < rowCount - 1) {
        if (!swapped && i == 0) {
            swapped = false;  
        }

        if (a[i][0] < a[i + 1][0]) {
            Change(a, i, i + 1, colCount);
            swapped = true;
        }
        else if (a[i][0] == a[i + 1][0] && a[i][1] < a[i + 1][1]) {
            Change(a, i, i + 1, colCount);
            swapped = true;
        }
        else if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1] && a[i][2] > a[i + 1][2]) {
            Change(a, i, i + 1, colCount);
            swapped = true;
        }

        Sort(a, rowCount, colCount, i + 1, swapped); 
    }
    else if (swapped) {
        Sort(a, rowCount, colCount, 0, false);  
    }
}

void Change(int** a, const int row1, const int row2, const int colCount, int j)
{
    if (j < colCount) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
        Change(a, row1, row2, colCount, j + 1); 
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            if (a[i][j] > 0 && (a[i][j] % 2 != 0)) {
                S += a[i][j];
                k++;
                a[i][j] = 0;  
            }
            Calc(a, rowCount, colCount, S, k, i, j + 1);  
        }
        else {
            Calc(a, rowCount, colCount, S, k, i + 1, 0);  
        }
    }
}
