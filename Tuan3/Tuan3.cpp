#include<stdio.h>
void Nhap(int a[],int&n){
	printf("Nhap so luong phan tu");
	scanf("%d",&n);
	for(int i = 0 ;i<n;i++){
		printf("Nhap phan tu thu %d, a[%d]: ",i,i);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n){
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int TongAm(int a[], int n){
	int S=0;
	for(int i = 0;i<n;i++){
		if(a[i]<0){
			S+=a[i];
		}
	}
	return S;
}
int TongDuong(int a[], int n){
	int S=0;
	for(int i = 0;i<n;i++){
		if(a[i]>0){
			S+=a[i];
		}
	}
	return S;
}
int Tongchia5(int a[],int n){
	int S=0;
	for(int i = 0;i<n;i++){
		if(a[i]%5==0){
			S+=a[i];
		}
	}
	return S;
}
int max(int a[],int n){
	int max = a[0];
	for(int i = 1;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int min (int a[], int n){
	int min= a[0];
		for(int i = 1;i<n;i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	return min;
	
}
int chanmax(int a[],int n){
	int chanmax= 0;
	for(int i= 0;i<n;i++){
		if(a[i]%2==0){
			if(a[i]>chanmax){
				chanmax = a[i];
			}
		}
	}
	return chanmax;
}

int lemin(int a[],int n){
	int lemin= 0;
	for(int i= 0;i<n;i++){
		if(a[i]%2!=0){
			if(a[i]<lemin){
				lemin = a[i];
			}
		}
	}
	return lemin;
}

int main(){
	int a[100];
	int n;
	Nhap(a,n);
	Xuat(a,n);
	printf("\n");
	printf("Tong cac so am la: %d ",TongAm(a,n));
	printf("\n");
	printf("Tong cac so duong la: %d ",TongDuong(a, n));
	printf("\n");
	printf("Tong cac so chi het cho 5 la: %d ",Tongchia5(a,n));
	printf("\n");
	printf("So lon nhat trong mang la %d: ", max(a,n));
	printf("\n");
	printf("So be nhat trong mang la %d: ", min(a,n));
	printf("\n");
	printf("So chan lon nhat trong mang la %d: ", chanmax(a,n));
	printf("\n");
	printf("So le lon nhat trong mang la %d:  ",lemin(a,n));
}
