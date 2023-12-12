#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node node;
node * AddHead(node *H, int data){
	node *p = new node;
	p->data = data;
	p->next = NULL;
	if(H==NULL){
		H= p;
	}else{
		p->next = H;
		H=p;
	}
	return H;
}
node * AddAft(node *H, int data){
	node *p, *tmp;
	p= new node;
	p->data = data;
	p->next = NULL;
	if(H==NULL){
		H= p;
	}else{
		tmp = H;
		while(tmp->next !=NULL)
			tmp= tmp->next;
		tmp->next = p;
	}
	return H;
}
node *Chen(node *H, int data){
	node *p, *tmp;
	p= new node ;
	p->data;
	p->next= NULL;
	if(H==NULL)
		H= p;
	else{
		if(H==p){
			p->next=H;
			H=p;
		}else{
			tmp= H;
			while(tmp->next !=NULL&&tmp->next->data<data)
				tmp= tmp->next;
			p->next = tmp->next;
			tmp->next = p;
		}		
	}
	return H;
}
void duyet(node *H) {
    node *tmp = H;
    while (tmp != NULL) {
        printf("%d ", tmp->data); 
        tmp = tmp->next;
    }
    printf("\n"); 
}
int search(node *H, int data){
	node *tmp=H;
	while(tmp!=NULL){
		if(tmp->data==data){
			return 1;
		}
		tmp = tmp ->next;
	}
	return 0;
}

void sapXep(node **H){
	node *ptr1;
	int lap;
	if((*H)==NULL)
		return;
	do{
		lap = 0;
		ptr1 = (*H);
		while (ptr1->next != NULL){
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                lap = 1;
            }
            ptr1 = ptr1->next;
        }
	}while(lap==1);
}
node *ghepHaiNode(node *H, node *T){
	if(H==NULL){
		return T;
	}else if(T==NULL)
		return H;
	node *tmp = H;
	node *TMP =T;
	while(tmp->next !=NULL)
		tmp = tmp->next;
	tmp->next = TMP;
	return H;
}
int main() { 
    node *L = NULL; node *F=NULL;
    int n, data; 
    int luaChon = 0;
    do {
        printf("\n------MENU------\n");
        printf("1. Nhap vao n so dang LIFO :\n");
        printf("2. Nhap vao n so dang FIFO :\n");
        printf("3. Xuat ra n so trong day LIFO: \n");
        printf("4. Xuat ra n so trong day FIFO: \n");
        printf("5. Tim kiem so x co trong mang hay khong\n");
        printf("6. Ghep hai day so vua tao thanh 1 day tang dan ");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1: {
            	printf("\nNhap day so duoi dang LIFO\n");
                printf("Nhap vao bao nhieu so: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    printf("Nhap so thu %d: ", i);
                    scanf("%d", &data);
                    L=AddHead(L, data);
                }
                break;
            }
            case 2: {
            	printf("\nNhap day sao duoi dang FIFO\n");
                printf("Nhap vao bao nhieu so: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    printf("Nhap so thu %d: ", i);
                    scanf("%d", &data);
                    F=AddAft(F, data);
                }
                break;
            }
            case 3: {
                duyet(L);
                break;
            }
        	case 4: {
                duyet(F);
                break;
            }
            case 5: {
                printf("Nhap so can tim kiem trong day LIFO: ");
                int x;
                scanf("%d", &x);
                int kq = search(L, x);
                if (kq == 1) {
                    printf("Tim thay %d trong danh sach lien ket\n", x);
                } else {
                    printf("Khong tim thay\n");
                }
                break;
            }
            case 6: {
            	L= ghepHaiNode(L, F);
            	sapXep(&L);
            	printf("Day so sau khi ghep va sap xep theo day tang dan la:");
            	duyet(L);
            }
        }
    } while (luaChon != 0);
    return 0;
}

