#include <stdio.h>

#define N_MAX 100000

void arr_sort(int *a, int left, int right);
void arr_print(int *a, int len_a);

int main() {
    int t, n;

    scanf("%d", &t);
    scanf("%d", &n);

    for (int i = 0; i < t; ++i) {
        int a[n];

        for (int j = 0; j < n; ++j)
            if (scanf("%d", &a[j]) != 1) {
                printf("Error.");
                return 1;
            }

        arr_sort(a, 0, n - 1);
        arr_print(a, n);
        printf("\n");
    }

    return 0;
}

void arr_sort(int *a, int left, int right) {
    int i, last;
    void swap(int *a, int val0, int val1);

    if (left > right)
        return;

    swap(a, left, (left + right) / 2);

    last = left;
    for (i = left + 1; i <= right; i++) {
        if (a[i] < a[left])
            swap(a, ++last, i);
    }

    swap(a, left, last);
    arr_sort(a, left, last - 1);
    arr_sort(a, last + 1, right);
}

void arr_print(int *a, int len_a) {
    for (int i = 0; i < len_a; ++i)
        printf("%d ", a[i]);
}

void swap(int *a, int val0, int val1) {
    int tmp = a[val0];
    a[val0] = a[val1];
    a[val1] = tmp;
}
