#include <stdio.h>

int main() {
    int arr_len = 5;
    int arr[] = {5, 4, 3, 2, 1};

    for (size_t i = 0; i < arr_len; ++i)
        for (size_t j = 0; j < i; ++j)
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    return 0;
}
