#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void solution(int A[][2], int B[][2])
{
    int c[2][2];
    int s1 = B[0][1] - B[1][1];
    int s2 = A[0][0] + A[0][1];
    int s3 = A[1][0] + A[1][1];
    int s4 = B[1][0] - B[0][0];
    int s5 = A[0][0] + A[1][1];
    int s6 = B[0][0] + B[1][1];
    int s7 = A[0][1] - A[1][1];
    int s8 = B[1][0] + B[1][1];
    int s9 = A[0][0] - A[1][0];
    int s10 = B[0][0] + B[0][1];

    int p1 = A[0][0] * s1;
    int p2 = s2 * B[1][1];
    int p3 = s3 * B[0][0];
    int p4 = A[1][1] * s4;
    int p5 = s5 * s6;
    int p6 = s7 * s8;
    int p7 = s9 * s10;

    c[0][0] = p5 + p4 - p2 + p6;
    c[0][1] = p1 + p2;
    c[1][0] = p3 + p4;
    c[1][1] = p5 + p1 - p3 - p7;

    cout << "Matrix Multiplication of Aand B is  " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    clock_t t1, t2;
    int A[2][2], B[2][2];
    cout << "enter elements of matrix A  ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "enter elements of matrix B  ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << "Matrix A  " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix B  " << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    t1 = clock();
    solution(A, B);
    t2 = clock();
    double time = double(t2 - t1) / double(CLOCKS_PER_SEC);
    cout << endl;
    cout << " time requried is " << fixed << time;

    return 0;
}