#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[15] = {1, 3, 4, 6, 12, 34, 56, 78, 122, 3434, 5657, 12123, 456323, 1233331, 2321233};
    printf("%d\n", binsearch(10, v, 15));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[low] == x)
        return low;
    if (v[high] == x)
        return high;

    printf("%d %d\n", low, high);
    return -1;
}
