#include <stdio.h>
#include <stdlib.h>

// Hàm in day so 
void hienThi(int arr[], int n) {
    printf("Danh sach sau khi sap xep: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm hoán vi
void HoanVi(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sap xep Quick Sort theo gia tri tuyet doi 
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (abs(arr[j]) < abs(pivot)) {
                i++;
                HoanVi(&arr[i], &arr[j]);
            }
        }

        HoanVi(&arr[i + 1], &arr[high]);
        int viTriPhanDoan = i + 1;

        quickSort(arr, low, viTriPhanDoan - 1);
        quickSort(arr, viTriPhanDoan + 1, high);
    }
}

// Hàm sap xep ShellSort voi buoc nhay nhap vao ban phim. 
void shellSort(int arr[], int n, int buocNhay) {
    for (int gap = buocNhay; gap > 0; gap /= 2) {
        for (int i = gap; i <= n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// hàm sx ho tro cho ham heapsort 
void hamSXheapsortGiam(int arr[], int n, int i) {
  int viTriNhoNhat = i;
  int trai = 2 * i;
  int phai = 2 * i + 1;

  if (trai <= n && arr[trai] < arr[viTriNhoNhat]) {
    viTriNhoNhat = trai;
  }

  if (phai <= n && arr[phai] < arr[viTriNhoNhat]) {
    viTriNhoNhat = phai;
  }

  if (viTriNhoNhat != i) {
    HoanVi(&arr[i], &arr[viTriNhoNhat]);
    hamSXheapsortGiam(arr, n, viTriNhoNhat);
  }
}

void heapSortGiam(int arr[], int n) {
  for (int i = n / 2; i >= 1; i--) {
    hamSXheapsortGiam(arr, n, i);
  }

  for (int i = n; i >= 1; i--) {
    HoanVi(&arr[1], &arr[i]);
    hamSXheapsortGiam(arr, i - 1, 1);
  }
}

int main() {
    int luaChon;
    int soPhanTu;

    do {
        printf("\nMenu:\n");
        printf("1. Quick Sort\n");
        printf("2. Shell Sort\n");
        printf("3. Heap Sort\n");
        printf("4. Thoat\n");
        printf("Chon lua cua ban: ");
        scanf("%d", &luaChon);

        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &soPhanTu);

        int mang[soPhanTu + 1]; // M?ng b?t d?u t? index 1

        printf("Nhap cac phan tu cua mang:\n");
        for (int i = 1; i <= soPhanTu; i++) {
            printf("mang[%d] = ", i);
            scanf("%d", &mang[i]);
        }

        switch (luaChon) {
            case 1:
                quickSort(mang, 1, soPhanTu);
                hienThi(mang, soPhanTu);
                break;
            case 2:
                int buocChay; // Buoc chay
                printf("Nhap buoc chay cho Shell Sort: ");
                scanf("%d", &buocChay);
                shellSort(mang, soPhanTu, buocChay);
                hienThi(mang, soPhanTu);
                break;
            case 3:
                heapSortGiam(mang, soPhanTu);
                hienThi(mang, soPhanTu);
                break;
            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 4);

}

