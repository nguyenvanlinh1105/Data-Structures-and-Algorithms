#include<stdio.h>
#include<math.h>
//1.1
float DthinhThang(int a, int b, int h){
	float S= 0;
	 S = h * ((float)(a + b) / 2);
	return S;	
}
//1.2 s hinh tron 
float Stron (int r){
	float S =  (float)3.14*r*r;
	return S;
}
// S tam giac khi biet canh day va chieu cao 
float StamgiacCanhDayChieuCao(int a, int h){
	float S = (float)1/2*a*h;
	return S;
}
// dien tich tam gia khi viet chieu dai cua 3 canh

float StamGiac3Canh(int a, int b, int c){
	float p =0;
	p = (float)(a+b+c)/2;
	float S = sqrt(p*(p-a)*(p-b)*(p-c));
	return S;
}
// chu vi hinh tron . tính chu ki con lac
float chuViHinhTron(int r){
	float C = (float)3.14*2*r;
	return C;
}
float chuKiConLac(int l){
	float T =0;
	T = (float)2*3.14*sqrt(l/10);
	return T;
}
main(){
	int a, b, h;
	int r;
	printf("Nhap hai canh day va chieu cao cua hinh thang");
	scanf("%d%d%d",&a, &b, &h);
	printf("dien tich hinh thang la %f",DthinhThang(a, b, h));
	printf("\n");
	printf("Nhap ban kinh");
	scanf("%d",&r);
	printf("dien tich hinh tron la %f",Stron(r));
	printf("\n");
	int e, k;
	printf("Nhap canh day va chieu cao cua tam giac");
	scanf("%d%d",&e, &k);
	printf("dien Tich cua tam giac khi biet canh day và chieu cao la %f",StamgiacCanhDayChieuCao(e,k));
	printf("\n");
	int i, j,t;
	printf("nhap chieu dai ba canh cua tam giac");
	scanf("%d%d%d",&i, &j,&t);
	printf("dien tich cua tam giac khi biet chieu dai ba canh la %f ",StamGiac3Canh(i,j,k));
	printf("\n");
	int d;
	printf("Nhap ban kinh hinh tron");
	scanf("%d",&d);
	printf("Chu vi cua hinh tron la %f",chuViHinhTron(d));
	printf("\n");
	int l;
	printf("Nhap chieu dai con lac");
	scanf("%d",&l);
	printf("Chu ki cua con lac la %f",chuKiConLac(l));

}
