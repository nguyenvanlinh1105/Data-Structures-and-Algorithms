#include<stdio.h>
void hamHoanVi(int &a, int &b){
	int temp = a;
	a = b;
	b= temp;
}
void sapXepNoiBot(int a[],int n){
	for(int i =1;i<n;i++){
		for(int j=n;j>1;j--){
			if(a[j]<a[j-1]){
				hamHoanVi(a[j],a[j-1]);
			}
		}
	}
}
void sapXepChen(int a[], int n){
	for(int i=2;i<=n;i++){
		int j=i;
		while(j>1&&a[j]<a[j-1]){
			hamHoanVi(a[j],a[j-1]);
			j--;
		}
	}
}
void sapXepChon(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index!= i) {
            hamHoanVi(a[min_index],a[i]);
        }
    }
}

void inMang(int a[],int n){
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}
main(){
	int a[100];
	int n;
	printf("Ban muon nhap bao nhieu phan tu: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Nhap phan tu thu %d",i);
		scanf("%d",&a[i]);
	}
	printf("Mang sau khi them phan tu:");
	inMang(a,n);
	printf("\n =======Sap xep noi bot");
	sapXepNoiBot(a,n);
	printf("\nMang sau khi sap xep:");
	inMang(a,n);
	printf("\n=======");
	printf("Sap xep chen");
	sapXepChen(a,n);
	printf("\nMang sau khi sap xep:");
	inMang(a,n);
	printf("\n=======");
	printf("Sap xep chon");
	sapXepChon(a,n);
	printf("\nMang sau khi sap xep:");
	inMang(a,n);
	
}
