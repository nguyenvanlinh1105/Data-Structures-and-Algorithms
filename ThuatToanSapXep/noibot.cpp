#include <stdio.h>

//void bubbleSort(int arr[], int n) {
//    for (int i = n; i > 1; i--) {
//        for (int j = 1; j < i; j++) {
//            // So s�nh v� trao d?i ph?n t? n?u c?n
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//void bubbleSort(int arr[], int n) {
//    for (int i = 1; i <n; i++) {
//        for (int j = i; j >1; j--) {
//            // So s�nh v� trao d?i ph?n t? n?u c?n
//            if (arr[j] < arr[j - 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j - 1];
//                arr[j - 1] = temp;
//            }
//        }
//    }
//}

void bubbleSort(int arr[], int n) {
    for (int i = 1; i <n; i++) {
        for (int j = i+1; j<=n;j++) {
            
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


int main() {
    printf("Nhap bao nhieu so: ");
    int n;
    scanf("%d", &n);

    int a[n + 1];  // M?ng b?t d?u t? v? tr� 1
    for (int i = 1; i <= n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    // In m?ng d� s?p x?p
    printf("Mang da sap xep: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

