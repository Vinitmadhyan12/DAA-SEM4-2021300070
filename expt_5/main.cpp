#include <iostream>
using namespace std;

float knapsack(int n, int c, int we[], int pr[])
{
    int curwe = 0;
    int curr = 0;
    float curpr = 0;
    float frac[n];

    for (int i = 0; i < n; i++)
    {
        frac[i] = ((float)pr[i] / (float)we[i]);
    }
    cout << "input data" << endl;
    cout << "sr.\tweight\tprofit\tfraction" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << we[i] << "\t" << pr[i] << "\t" << frac[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int m = i;
        float temp;
        int k;
        for (int j = i + 1; j < n; j++)
        {
            if (frac[j] > frac[m])
            {
                m = j;
            }
        }
        temp = frac[i];
        frac[i] = frac[m];
        frac[m] = temp;

        k = we[i];
        we[i] = we[m];
        we[m] = k;

        k = pr[i];
        pr[i] = pr[m];
        pr[m] = k;
    }

    cout << "data after sorting" << endl;
    cout << "sr.\tweight\tprofit\tfraction" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << we[i] << "\t" << pr[i] << "\t" << frac[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        curr = curr + we[i];
        // cout << "main ";
        if (curr <= c)
        {
            // cout << "if ";
            curwe = curwe + we[i];
            curpr = curpr + (float)pr[i];
        }
        else
        {
            // cout << "else ";
            int w = c - curwe;
            // cout << w;
            float z = ((float)w * frac[i]);
            // cout << z;
            curpr = curpr + z;
            return curpr;
        }
    }
    return curpr;
}

int main()
{

    int n, capacity;
    cout << "enter no of iteration : ";
    cin >> n;
    cout << "enter capacity : ";
    cin >> capacity;
    int we[n];
    int pr[n];
    cout << "enter weights for " << n << " iteration : ";
    for (int i = 0; i < n; i++)
    {
        cin >> we[i];
    }
    cout << "enter profits for " << n << " iterations : ";
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i];
    }
    float ans = knapsack(n, capacity, we, pr);
    cout << "ans is " << ans;
}