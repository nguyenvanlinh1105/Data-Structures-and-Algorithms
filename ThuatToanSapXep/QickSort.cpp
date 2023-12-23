#include <stdio.h>

// Ham hoan vi
void hoanVi(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Ham phan doan trong quick sort
int part(int a[], int l, int r) {
    int ls, t, k;
    k = (l + r) / 2;
    hoanVi(&a[l], &a[k]);
    ls = l;
    while ((a[ls + 1] <= a[l]) && (ls < r)) {
        ls++;
    }
    t = ls + 1;
    while ((a[l] < a[t]) && (t < r)) {
        t++;
    }
    while (t <= r) {
        if (a[t] < a[l]) {
            hoanVi(&a[ls + 1], &a[t]);
            ls++;
        }
        t++;
    }
    hoanVi(&a[l], &a[ls]);
    k = ls;
    return k;
}

// Ham sap xep quick sort
void quick_sort(int a[], int l, int r) {
    if (r > l) {
        int k;
        k = part(a, l, r);
        quick_sort(a, l, k - 1);
        quick_sort(a, k + 1, r);
    }
}

// Ham nhap mang
void nhapMang(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Ham in mang
void inMang(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int main() {
    int a[20], r;

    printf("Nhap so phan tu cua mang a: n = ");
    scanf("%d", &r);

    nhapMang(a, r);

    quick_sort(a, 1, r);

    printf("Cac phan tu cua mang a sau khi sap xep:\n");
    inMang(a, r);

    return 0;
}

