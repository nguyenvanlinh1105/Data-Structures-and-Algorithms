#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    int maSV;
    char tenSV[50];
    float diemCC;
    float diemGK;
    float diemCK;
    float diemTB;
    struct SinhVien* next;
};

typedef struct SinhVien SinhVien;

SinhVien* makeNode(int maSV, const char* tenSV, float diemCC, float diemGK, float diemCK) {
    SinhVien* p = new SinhVien;
    p->maSV = maSV;
    strcpy(p->tenSV, tenSV);
    p->diemCC = diemCC;
    p->diemGK = diemGK;
    p->diemCK = diemCK;
    p->diemTB = 0; 
    p->next = NULL;
    return p;
}
// ham them sinh vien
SinhVien* addAft(SinhVien* H, int maSV, const char* tenSV, float diemCC, float diemGK, float diemCK) {
    SinhVien* p = makeNode(maSV, tenSV, diemCC, diemGK, diemCK);

    if (H == NULL)
        H = p;
    else {
        SinhVien* tmp = H;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
    return H;
}
// ham in danh sach sinh vien 
void duyet(SinhVien* H) {
    SinhVien* tmp = H;
    printf("%8s \t %25s \t %10s \t %10s \t %10s \t %10s\n", "MaSV", "Ten SV", "CC", "GK", "CK", "DTB");
    while (tmp != NULL) {
        printf("%8d \t %25s \t %10.2f \t %10.2f \t %10.2f \t %10.2f\n", 
		tmp->maSV, tmp->tenSV, tmp->diemCC, tmp->diemGK, tmp->diemCK, tmp->diemTB);
        tmp = tmp->next;
    }
}
// tinh diem trung binh
void tinhDiemTB(SinhVien* sv) {
    sv->diemTB = (sv->diemCC * 2 + sv->diemGK * 2 + sv->diemCK * 6) / 10;
}

void tinhDiemTrungBinh(SinhVien* danhSachSV) {
    SinhVien* tmp = danhSachSV;
    while (tmp != NULL) {
        tinhDiemTB(tmp);
        tmp = tmp->next;
    }
    printf("Da tinh diem trung binh cho tat ca sinh vien.\n");
}

// them sinh vien moi theo ma sinh vien 
SinhVien* themSinhVienTheoMaSV(SinhVien* danhSachSV, int maSV) {
    SinhVien* svMoi = new SinhVien;
    svMoi->maSV = maSV;
	strcpy(svMoi->tenSV, " ");

	// Cap nhat cac cot diem bang 0 
    svMoi->diemCC = 0.0;
    svMoi->diemGK = 0.0;
    svMoi->diemCK = 0.0;
    svMoi->diemTB = 0.0;

    svMoi->next = danhSachSV;
    danhSachSV = svMoi;

    printf("Da them sinh vien voi ma %d vao danh sach.\n", maSV);

    return danhSachSV;
}

// hàm tìm kiem sinh vien theo ma sinh vien de cho ham xoa su dung
SinhVien* timSinhVienTheoMaSV(SinhVien* danhSachSV, int maSV) {
    SinhVien* sv = danhSachSV;
    while (sv != NULL) {
        if (sv->maSV == maSV) {
            return sv;  // Tra ve con tro den sinh vien neu tim thay
        }
        sv = sv->next;
    }
    // Tra ve NULL neu không tìm thay sinh viên có mã tuong ung
    return NULL;
}

// ham xoa sinh vien theo ma sinh vien. 
SinhVien *xoaMaSV(SinhVien *H, int maSV){
	SinhVien *newSv, *temp;
	while(timSinhVienTheoMaSV(H, maSV)!=NULL){
		newSv= timSinhVienTheoMaSV(H, maSV);
		if(H==newSv){
			H=H->next;
		}else{
			temp =H;
			while(temp->next != newSv)
				temp = temp->next;
			temp->next = newSv->next;	
		}
		newSv->next = NULL;
	}
	return H;
}

// sua sinh vien theo ma sinh vien 
void suaSinhVien(SinhVien* danhSachSV, int maSV, const char* tenSV, float diemCC, float diemGK, float diemCK) {
    SinhVien* tmp = danhSachSV;
    while (tmp != NULL && tmp->maSV != maSV) {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        printf("Khong tim thay sinh vien co maSV = %d\n", maSV);
        return;
    }

    // Cap nhat thong tin 
    strcpy(tmp->tenSV, tenSV);
    tmp->diemCC = diemCC;
    tmp->diemGK = diemGK;
    tmp->diemCK = diemCK;
//    tinhDiemTB(tmp);// ban co the them dong nay neu ban muon cap nhat luon DTB

    printf("Da sua thong tin cho sinh vien co maSV = %d\n", maSV);
}

// ham tim vi tri max cua sinh vien có diem TB Cao nhat 
int timViTriMax(SinhVien* danhSachSV) {
    SinhVien* tmp = danhSachSV;
    int viTri = 1;
    float maxDiemTB = tmp->diemTB;

    for (int i = 1; tmp != NULL; ++i) {
        if (tmp->diemTB > maxDiemTB) {
            maxDiemTB = tmp->diemTB;
            viTri = i;
        }
        tmp = tmp->next;
    }

    return viTri;
}
// ham sap xep sinh vien 
SinhVien* sapXepDanhSach(SinhVien* danhSachSV) {
    SinhVien* tmp = danhSachSV;
    SinhVien* sortedList = NULL;// danh sach sinh vien sau khi sap xep

    while (tmp != NULL) {
        SinhVien* current = tmp;
        tmp = tmp->next;

        // Chèn nút hien tai vào danh sách dã sap xep
        if (sortedList == NULL || current->diemTB <= sortedList->diemTB) {
            current->next = sortedList;
            sortedList = current;
        } else {
            SinhVien* prev = NULL;
            SinhVien* nextNode = sortedList;
            while (nextNode != NULL && current->diemTB > nextNode->diemTB) {
                prev = nextNode;
                nextNode = nextNode->next;
            }
            current->next = nextNode;
            
            // Cap nhat các con tro truoc dó
            if (prev != NULL) {
                prev->next = current;
            } else {
                sortedList = current;
            }
        }
    }

    return sortedList;
}

int main() {
    SinhVien* danhSachSV = NULL; 
    int choice;
    do {
        printf("\n-------MENU-------\n");
        printf("1. Them sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("3. Them sinh vien voi ma sinh vien\n");
        printf("4. Tinh diem trung binh cho sinh vien\n");
        printf("5. Sua sinh vien theo maSV\n");
        printf("6. Xoa sinh vien theo maSV\n");
        printf("7. Tim vi tri sinh vien co diem trung binh cao nhat\n");
        printf("8. Sap xep danh sach sinh vien tang theo diem trung binh\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
        	// Them sinh vien voi tat ca thong tin 
            case 1: {
                int maSV;
                char tenSV[50];
                float diemCC, diemGK, diemCK;

                printf("Nhap ma sinh vien: ");
                scanf("%d", &maSV);
                printf("Nhap ten sinh vien: ");
                scanf(" %[^\n]s", tenSV);
                printf("Nhap diem chuyen can: ");
                scanf("%f", &diemCC);
                printf("Nhap diem giua ky: ");
                scanf("%f", &diemGK);
                printf("Nhap diem cuoi ky: ");
                scanf("%f", &diemCK);

                // Kiem tra diem nhap vào co >=0 hay khong
                if (diemCC < 0 || diemGK < 0 || diemCK < 0) {
                    printf("Diem khong hop le. Vui long nhap lai.\n");
                    break;
                }
				danhSachSV=addAft(danhSachSV,maSV, tenSV, diemCC, diemGK, diemCK);
                printf("Da them sinh vien moi.\n");
                break;
            }
            // in Danh sach sinh vien có trong danh sách
            case 2:
            	printf("Danh sach sinh vien:\n");
                duyet(danhSachSV);
                break;
            case 3:
            	// Them sinh vien chi voi ma sinh vien.
            	int maSV ;
            	printf("Nhap maSV sinh vien Can them: ");
            	scanf("%d",&maSV);
            	danhSachSV=themSinhVienTheoMaSV(danhSachSV,maSV);
				break;
                
            case 4: {
            	// tinh diem trung binh cho cac sinh vien 
            	tinhDiemTrungBinh(danhSachSV);
                duyet(danhSachSV);
                break;
            }
            case 5:{
            	// Sua thong tin sinh vien theo ma Sinh vien 
            	int maSV;
                char tenSV[50];
                float diemCC, diemGK, diemCK;
                printf("Nhap ma sinh vien muon sua: ");
                scanf("%d", &maSV);
                printf("Nhap ten sinh vien: ");
                scanf(" %[^\n]s", tenSV);
                printf("Nhap diem chuyen can: ");
                scanf("%f", &diemCC);
                printf("Nhap diem giua ky: ");
                scanf("%f", &diemGK);
                printf("Nhap diem cuoi ky: ");
                scanf("%f", &diemCK);

                // Kiem tra diem nhap vao có hop le >=0 ?
                if (diemCC < 0 || diemGK < 0 || diemCK < 0) {
                    printf("Diem khong hop le. Vui long nhap lai.\n");
                    break;
                }

                suaSinhVien(danhSachSV, maSV, tenSV, diemCC, diemGK, diemCK);
                duyet(danhSachSV);
				break;
			}
            case 6: {
            	// Xóa sinh vien theo ma sinh vien 
                int maSV;
                printf("Nhap ma sinh vien muon xoa: ");
                scanf("%d", &maSV);
                danhSachSV=xoaMaSV(danhSachSV, maSV);
                printf("Danh sach sinh vien sau khi xoa :\n ");
                duyet(danhSachSV);
                break;
            }
            case 7: {
            	//Tim vi tri cua sinh vien có diem TB max.
            	if (danhSachSV == NULL) {
                    printf("Danh sach rong.\n");
                } else {
                    int viTriMax = timViTriMax(danhSachSV);
                    printf("Sinh vien co diem trung binh cao nhat o vi tri %d\n", viTriMax);
                }
                break;
                
            }
			case 8:{
				// Sap xep sinh vien.
            	danhSachSV = sapXepDanhSach(danhSachSV);
                printf("Da sap xep tang dan danh sach sinh vien theo diem trung binh.\n");
                duyet(danhSachSV);
                break;
			}
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
