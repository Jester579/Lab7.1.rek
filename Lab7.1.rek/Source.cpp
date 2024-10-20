#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

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
    cout << endl;
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

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0)
{
    if (i >= rowCount) return;

    a[i][j] = Low + rand() % (High - Low + 1);

    if (j + 1 < colCount)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    Create(a, rowCount, colCount, Low, High, 0, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0)
{
    if (i >= rowCount) return;

    cout << setw(4) << a[i][j];

    if (j + 1 < colCount)
        Print(a, rowCount, colCount, i, j + 1);
    else
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    Print(a, rowCount, colCount, 0, 0);
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Sort(int** a, const int rowCount, const int colCount, int i = 0)
{
    if (i >= rowCount - 1) return;  

    for (int j = 0; j < rowCount - i - 1; j++)  
    {
        if (a[j][0] < a[j + 1][0])  
            Change(a, j, j + 1, colCount);
        else if (a[j][0] == a[j + 1][0] && a[j][1] < a[j + 1][1])  
            Change(a, j, j + 1, colCount);
        else if (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][2] > a[j + 1][2]) 
            Change(a, j, j + 1, colCount);
    }

    Sort(a, rowCount, colCount, i + 1);  
}

void Sort(int** a, const int rowCount, const int colCount)
{
    Sort(a, rowCount, colCount, 0);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0)
{
    if (i >= rowCount) return;

    if (a[i][j] > 0 && (a[i][j] % 2 != 0))  
    {
        S += a[i][j];
        k++;
        a[i][j] = 0;  
    }

    if (j + 1 < colCount)
        Calc(a, rowCount, colCount, S, k, i, j + 1);
    else
        Calc(a, rowCount, colCount, S, k, i + 1, 0);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    Calc(a, rowCount, colCount, S, k, 0, 0);
}
