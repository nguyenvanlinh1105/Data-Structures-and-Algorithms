#include <stdio.h>

void selectionSortFromPosition(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (arr[min_index] != arr[i]) {
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    printf("Nhap bao nhieu so: ");
    int n;
    scanf("%d", &n);

    int a[n]; 
    for (int i = 1; i <= n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }

    selectionSortFromPosition(a, n);

    // In m?ng dã s?p x?p
    printf("Mang da sap xep: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

