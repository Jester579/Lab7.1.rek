#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1.rek/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int** CreateArray(int rowCount, int colCount)
{
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    return a;
}

void DeleteArray(int** a, int rowCount)
{
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int rowCount = 3;
            int colCount = 3;
            int** a = CreateArray(rowCount, colCount);

            a[0][0] = 1; a[0][1] = -2; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 5;  a[1][2] = 6;
            a[2][0] = 7; a[2][1] = -8; a[2][2] = 9;

            int S = 0, k = 0;

            Calc(a, rowCount, colCount, S, k,0);

            int expectedSum = 25;  
            int expectedCount = 5;

            Assert::AreEqual(expectedSum, S);
            Assert::AreEqual(expectedCount, k);

            DeleteArray(a, rowCount);
        }
    };
}
