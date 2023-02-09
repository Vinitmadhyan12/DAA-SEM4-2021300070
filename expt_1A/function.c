#include <stdio.h>
#include <math.h>

int cube(int a)
{
    return a * a * a;
}

float fraction(int a)
{
    int b = 3 * a;
    float c = (float)(b) / (float)(2);
    return c;
}

float logfc(int a)
{
    float c = log10(a);
    return c;
}
float lnfc(int a)
{
    float c = log(a);
    return c;
}

float power(int a)
{
    float b = pow(2, a);
    return b;
}

float expo(int a)
{
    float b = exp(a);
    return b;
}

float logpower(int a)
{
    float b = pow(2, log10(a));
    return b;
}

float func5(int a)
{
    float b = a * (pow(2, a));
    return b;
}

float rootlog(int a)
{
    float b = sqrt(log10(a));
    return b;
}

float powerrootlog(int a)
{
    float b = pow(sqrt(2), log10(a));
    return b;
}

float factorial(int a)
{
    if (a <= 1)
    {
        return 1;
    }
    return a * factorial(a - 1);
}
int main()
{

    int a;
    float b;
    for (int i = 1; i <= 100; i++)
    {
        printf("%d", i);
        a = cube(i);
        printf("  %d", a);
        b = fraction(i);
        printf("  %.2f", b);
        b = logfc(i);
        printf("  %.2f", b);
        b = lnfc(i);
        printf("  %.2f", b);
        b = power(i);
        printf("  %.1f", b);
        b = expo(i);
        printf("  %.2f", b);
        b = logpower(i);
        printf("  %.2f", b);
        b = func5(i);
        printf("  %.1f", b);
        b = rootlog(i);
        printf("  %.2f", b);
        b = powerrootlog(i);
        printf("  %.2f", b);
        if (i <= 20)
        {
            b = factorial(i);
            printf("  %.0f", b);
        }
        printf("\n");
    }

    return 0;
}