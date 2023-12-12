#include<stdio.h>
int Tong(int n){
	if(n==1){
		return 1;
	}else 
	return Tong(n-1)+n;
};

int Tong2(int n){
	if(n==1){
		return 1;
	}
	if(n%2==0){
		return -n+Tong2(n-1);
	}else {
		return n+Tong2(n-1);
	}
}
int Tong3(int n){
	if(n==1){
		return -1;
	}
	if(n%2==0){
		return n+Tong3(n-1);
	}else {
		return -n+Tong3(n-1);
	}
}
float Tong4(int n){
	if(n==1){
		return 1;
	}
	return (1.0/n)+Tong4(n-1);
}
float Tong5(int n){
	if(n==1){
		return 1;
	}
	if(n%2==0){
		return -(1.0/n)+Tong5(n-1);
	}else {
		return (1.0/n)+Tong5(n-1);
	}
}
float Tong6(int n){
	if(n==1){
		return -1;
	}
	if(n%2==0){
		return (1.0/n)+Tong5(n-1); 
	}else {
		return -(1.0/n)+Tong5(n-1);
	}
}
int Giaithua(int n){
	if(n==1){
		return 1;
	}else if(n>1){
		return n*Giaithua(n-1);
	}
}
float Tong8(int n){
	if(n==1){
		return 1;
	}else
	  return 1.0/Giaithua(n)+ Tong8(n-1);
}
float Tong9(int n){
	if(n==1){
		return 1;
	}
	if(n%2==0){
	 	return -1.0/Giaithua(n)+ Tong8(n-1);
	}else {
		return 1.0/Giaithua(n)+ Tong8(n-1);
	}
}
float Tong10(int n){
	if(n==1){
		return 1;
	}
	if(n%2==0){
	 	return 1.0/Giaithua(n)+ Tong8(n-1);
	}else {
		return -1.0/Giaithua(n)+ Tong8(n-1);
	}
}
main(){
	int n;
	printf("Nhap n ");
	scanf("%d",&n);
	printf("tong la %d",Tong(n));
	printf("\n");
	//bai2
	printf("tong S2:%d",Tong2(n));
	printf("\n");
	//bai3
	printf("tong S3: %d",Tong3(n));
	// bai4
	printf("Tong S4:%f",Tong4(n));
	printf("\n");
	//bai5
	printf("Tong S5 %f",Tong5(n));
	printf("\n");
	//bai6
	printf("Tong S6 %f",Tong6(n));
	printf("\n");
	// bai7
	printf("Giaithua %d",Giaithua(n));
	printf("\n");
	//bai8
	printf("Tong S8 %f",Tong8(n));
	printf("\n");
	//bai9
	printf("Tong S9 %f",Tong9(n));
	printf("\n");
	// bai10
	printf("Tong S10 %f",Tong10(n));
	printf("\n");
}
