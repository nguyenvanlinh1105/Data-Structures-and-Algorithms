#include <stdio.h>

void insertionSortFromPosition(int arr[], int n) {
    for (int i = 2; i <= n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Di chuy?n các ph?n t? l?n hon key v? sau
        while (j >= 1 && key > arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Chèn key vào dúng v? trí
        arr[j + 1] = key;
    }
}

int main() {
    printf("Nhap bao nhieu so: ");
    int n;
    scanf("%d", &n);

    int a[n];  // M?ng b?t d?u t? v? trí 1
    for (int i = 1; i <= n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }

    insertionSortFromPosition(a, n);

    // In m?ng dã s?p x?p
    printf("Mang da sap xep: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

