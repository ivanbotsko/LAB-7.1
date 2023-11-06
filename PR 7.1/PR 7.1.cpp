// Lab_7_1.cpp
// Боцко Іван Віталійович
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 4

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** s , const int rowCount, const int colCount, const int Low, const int High);
void Print(int** s , const int rowCount, const int colCount);
void Sort(int** s , const int rowCount, const int colCount);
void Change(int** s , const int row1, const int row2, const int colCount);
void Calc(int** s , const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = 9;
    const int High = 61;

    const int rowCount = 7;
    const int colCount = 6;

    int **s = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        s[i] = new int[colCount];

    Create(s, rowCount, colCount, Low, High);
    Print(s, rowCount, colCount);
    Sort(s, rowCount, colCount);
    Print(s, rowCount, colCount);

    int S = 0;
    int k = 0;

    Calc(s, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(s, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] s[i];
    delete[] s;
    return 0;

}

void Create(int** s, const int rowCount, const int colCount, const int Low, const int High)

{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            s[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** s, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << s[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** s, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((s[i1][0] < s[i1 + 1][0])
                || (s[i1][0] == s[i1 + 1][0] &&
                    s[i1][1] < s[i1 + 1][1])
                || (s[i1][0] == s[i1 + 1][0] &&
                    s[i1][1] == s[i1 + 1][1] &&
                    s[i1][3] > s[i1 + 1][3]))
                Change(s, i1, i1 + 1, colCount);
}

void Change(int** s, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j = 0; j < colCount; j++)
    {
        tmp = s[row1][j];
        s[row1][j] = s[row2][j];
        s[row2][j] = tmp;
    }
}

void Calc(int** s, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(s[i][j] % 2 == 1 && i + j % 7 != 0))
            {
                S += s[i][j];
                k++;
                s[i][j] = 0;
            }
}
