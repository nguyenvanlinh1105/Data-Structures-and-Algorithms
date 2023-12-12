#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *next;
};
typedef struct node node;
void addHead(node **H , int data){
	node * p = new node;
	p->data = data;
	p->next= NULL;
		p->next = (*H);
		(*H)= p;
		
}
void addAft(node **H, int data) {
    node *p, *tmp;
    p = (node *)malloc(sizeof(node)); 
    p->data = data;
    p->next = NULL; 

    if ((*H) == NULL) {
        (*H) = p;
        return;
    } else {
        tmp = (*H);
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = p;
    }
}

int timKiem(node *H, int x) {
    node *tmp = H;
    while (tmp != NULL) {
        if (tmp->data == x) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void duyet(node *H) {
    node *tmp = H;
    while (tmp != NULL) {
        printf("%d ", tmp->data); 
        tmp = tmp->next;
    }
    printf("\n"); 
}

node * search(node *H, int data) {
    node *tmp = H;
    while (tmp != NULL) {
        if (tmp->data == data) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void chenTangDan(node **H, int data) {
    node *p, *tmp, *t;
    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    p->data = data;
    if ((*H) == NULL) {
        (*H) = p;
    } else {
        tmp = (*H);
        while (tmp != NULL && tmp->data < data) {
            t = tmp;
            tmp = tmp->next;
        }
        if (t == NULL) {
            p->next = (*H);
            (*H) = p;
        } else {
            t->next = p;
            p->next = tmp;
        }
    }
}

void xoa(node **H, int data) {
    node *p, *tmp;
    p = search((*H), data);
    if ((*H) == p) {
        (*H) = (*H)->next;
        free(p); 
    } else {
        tmp = (*H);
        while (tmp != NULL && tmp->next != p) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = p->next;
            free(p); 
        }
    }
}

void sapXep(node **H) {
    int swapped;
    node *ptr1;
    if (*H == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = *H;
  
        while (ptr1->next != NULL){
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

int main() { 
    node *H = NULL; 
    int n, data; 
    int luaChon = 0;
    do {
        printf("\n------MENU------\n");
        printf("1. Nhap vao n so:\n");
        printf("2. Xuat ra n so do\n");
        printf("3. Tim kiem so x co trong mang hay khong\n");
        printf("4. Nhap mot mang tang dan va chen no vao vi tri thich hop\n");
        printf("5. Xoa mot so trong day so\n");
        printf("6. Nhap mot day so bat ki sap xep chung theo thu tu tang dan\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1: {
                printf("Nhap vao bao nhieu so: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    printf("Nhap so thu %d: ", i);
                    scanf("%d", &data);
                    addHead(&H, data);
                }
                break;
            }
            case 2: {
                duyet(H);
                break;
            }
            case 3: {
                printf("Nhap so can tim kiem: ");
                int x;
                scanf("%d", &x);
                int kq = timKiem(H, x);
                if (kq == 1) {
                    printf("Tim thay %d trong danh sach lien ket\n", x);
                } else {
                    printf("Khong tim thay\n");
                }
                break;
            }
            case 4: {
                int t;
                printf("Ban muon chen vao so bao nhieu: ");
                scanf("%d", &t);
                chenTangDan(&H, t);
                break;
            }
            case 5: {
                int k;
                printf("Ban muon xoa so bao nhieu: ");
                scanf("%d", &k);
                xoa(&H, k);
                break;
            }
            case 6: {
            	H = NULL;
            	printf("Nhap vao bao nhieu so: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    printf("Nhap so thu %d: ", i);
                    scanf("%d", &data);
                    addHead(&H, data);
                }
                printf("Day so sau khi sap xep la: ");
                sapXep(&H);
                duyet(H);
                break;
            }
        }
    } while (luaChon != 0);
    return 0;
}

