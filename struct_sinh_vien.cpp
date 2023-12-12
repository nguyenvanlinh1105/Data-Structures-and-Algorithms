#include<stdio.h>
#include<string.h>

struct diem{
	float Dtoan;
	float Dli;
	float Dhoa;
};
typedef struct diem diem;
struct SinhVien {
	char ten[20];
	char ngaySinh[15];
	char gioiTinh[1];
	diem diemTLH;
	float dtb;
};
typedef struct SinhVien SV;

void nhap(SV list[], int &n){
	printf("Nhap bao nhieu sinh vien ");
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		SV sv;
		printf("Nhap thong tin cua sinh vien thu %d: \n",i);
		printf("Nhap ten sinh vien: ");
		fflush(stdin);
		gets(sv.ten);
		printf("Nhap ngay sinh cua sinh vien: ");
		gets(sv.ngaySinh);
		printf("Nhap gioi tinh cua sinh vien: ");
		gets(sv.gioiTinh);
		diem diem = sv.diemTLH;
		printf("Nhap diem toan cua sinh vien: ");
		scanf("%f",&diem.Dtoan);
		printf("Nhap diem li cua sinh vien: ");
		scanf("%f",&diem.Dli);
		printf("Nhap diem hoa cua sinh vien: ");
		scanf("%f",&diem.Dhoa);
		sv.dtb = (diem.Dtoan+diem.Dli+diem.Dhoa)*1.0/3;
		list[i] = sv;
	}
}
void inSinhVien(SV list[], int n){
	printf("DANH SACH SINH VIEN	: \n");
	printf("%10s \t %15s \t %10s \t %4s\n", "TEN", "NGAY SINH","GIOI TINH","DTB");
	for(int i= 1;i<=n;i++){
		printf("%10s \t %15s \t %10s \t %4.2f\n", list[i].ten, list[i].ngaySinh, list[i].gioiTinh, list[i].dtb);
	}
}
void xepLoai(SV list[],int n){
	for(int i= 1;i<=n;i++){
		if(list[i].dtb < 10 && list[i].dtb>=9){
			printf(" Sinh vien thu i Xep loai: GIOI",i);
		}else if(list[i].dtb>=7){
			printf(" Sinh vien thu i Xep loai: KHA",i);
		}else if(list[i].dtb>=5){
			printf(" Sinh vien thu i Xep loai: TB",i);
		}else{
			printf(" Sinh vien thu i Xep loai: YEU",i);
		}
	}
}
void sapXep(SV list[], int n){
	for(int i = 1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(list[i].dtb>list[j].dtb){
				SV temp = list[i];
				list[i]= list[j];
				list[j]= temp;
			}
		}
	}
}
int search(SV List[],int n, char ten[20]){
	for(int i =1;i<=n;i++){
		if(strcmp(List[i].ten,ten)==0){
			return i;
		}
	}
	return 0;
	
}
void chenSV(SV List[], int&n, int k, SV sv){
	if(k<0||k>n){
		printf("\nVi tri nhap vao khong hop le!");
		return;
	}
	for(int i=n;i>=k;i--){
		List[i+1]= List[i];
	}
	List[k]= sv;
	n++;
}
main(){
	SV list[100];
	char timTen[20];
	int n;
	nhap(list, n);
	inSinhVien(list,n);
	xepLoai(list, n);
	sapXep(list,n);
	printf("\n");
	inSinhVien(list ,n);
	printf("\nNhap ten muon tim: ");
	fflush(stdin);
	gets(timTen);
	int kq;
	kq= search(list,n, timTen);
	if(kq!=0){
		printf("Tim thay sinh vien");
	}else{
		printf("Khong tim thay sinh vien");
	}
	SV sv;
	printf("Nhap thong tin cua sinh vien can chen: \n");
	printf("Nhap ten sinh vien:");
	fflush(stdin);
	gets(sv.ten);
	printf("Nhap ngay sinh cua sinh vien: ");
	gets(sv.ngaySinh);
	printf("Nhap gioi tinh cua sinh vien: ");
	gets(sv.gioiTinh);
	diem diem = sv.diemTLH;
	printf("Nhap diem toan cua sinh vien: ");
	scanf("%f",&diem.Dtoan);
	printf("Nhap diem li cua sinh vien: ");
	scanf("%f",&diem.Dli);
	printf("Nhap diem hoa cua sinh vien: ");
	scanf("%f",&diem.Dhoa);
	sv.dtb = (diem.Dtoan+diem.Dli+diem.Dhoa)*1.0/3;
	printf("Nhap vi tri can chen: ");
	int k;
	scanf("%d",&k);
	chenSV(list,n,k,sv);
	inSinhVien(list, n);
}
