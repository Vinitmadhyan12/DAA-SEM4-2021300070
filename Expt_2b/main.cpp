#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
int SWAP = 0;
int list[100000];

void read()
{
    ifstream fin("values.txt", ios::binary);
    for (long i = 0; i < 100000; i++)
    {
        fin.read((char *)&list[i], sizeof(int));
    }
    fin.close();
}

long partition(long left, long right)
{
    long rd = (rand() % (right - left + 1)) + left;
    int pivot_element = list[rd];
    int lb = left, ub = right;
    int temp;

    while (left < right)
    {
        while (list[left] <= pivot_element)
            left++;
        while (list[right] > pivot_element)
            right--;
        if (left < right)
        {
            temp = list[left];
            list[left] = list[right];
            list[right] = temp;
            SWAP++;
        }
    }
    list[lb] = list[right];
    list[right] = pivot_element;
    SWAP++;
    return right;
}

void quickSort(long left, long right)
{
    if (left < right)
    {
        long pivot = partition(left, right);
        quickSort(left, pivot - 1);
        quickSort(pivot + 1, right);
    }
}

int main()
{
    clock_t t1, t2, t3, t4;
    read();

    int num = 10;
    for (int i = 0; i < 1000; i++)
    {

        t3 = clock();
        quickSort(0, num - 1);
        t4 = clock();
        double quicktime = double(t4 - t3) / double(CLOCKS_PER_SEC);
        cout << endl;
        cout << " " << fixed << quicktime << "  " << SWAP;
        num += 100;
    }

    return 0;
}