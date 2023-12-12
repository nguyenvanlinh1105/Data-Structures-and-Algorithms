#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *makeNode(int x){
	node * p = new node ;
	p->data= x;
	p->next = NULL;
	return p;
}
node *addAft(node *H, int data){
    node *p, *tmp;
    p = new node;
    p->data = data;
    p->next = NULL;

    if(H == NULL)
        H = p;
    else{
        tmp = H;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = p;
    }
    return H;
}

void duyet(node *H){
	node *tmp = H;
	if(tmp==NULL){
		printf("Danh sach rong ");
	}else{
		while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;	
		}
	}
}

void tachDanhSachLK(node* H, node** DSChan, node** DSLe) {
    node* tmp = H;
    while (tmp != NULL) {
        if (tmp->data % 2 == 0) {
            *DSChan = addAft(*DSChan, tmp->data);
        } else {
            *DSLe = addAft(*DSLe, tmp->data);
        }
        tmp = tmp->next;
    }
}

int count(node *H){
	int dem = 0;
	while(H !=NULL){
		dem++;
		H=H->next;
	}
	return dem;
}

node *addHead(node *H, int data){
	node *p = makeNode(data);
	if(H==NULL){
		H= p;
	}else{
		p->next =H;
		H= p;
	}
	return H;
}

node* timNodeK(node* H, int k) {
    if (k <= 0) {
        return NULL;
    }
    node* tmp = H;
    int count = 1;
    while (tmp != NULL && count < k) {
        tmp = tmp->next;
        count++;
    }
    if (count == k) {
        return tmp;
    } else {
        return NULL;
    }
}

void insert (node **H, int k ,int x){
	int n = count(*H);
	if(k<1 || k >n) {
		printf("Vi tri chen khong hop le ! Tra ve danh sach goc");
		return;
	}
	node * temp = *H;
	for(int i= 1;i<=k-1;i++){
		temp=temp->next;
	}
	node * newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

void tachDoiDanhSach(node* H, int k, node** DS1, node** DS2) {
    node* tmp = H;
    int count = 1;
    while (tmp != NULL && count <= k) {
        *DS1 = addAft(*DS1, tmp->data);
        tmp = tmp->next;
        count++;
    }
    while (tmp != NULL) {
        *DS2 = addAft(*DS2, tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    node *H=NULL;
	node* DSChan = NULL;
    node* DSLe = NULL;
    node* DS1 = NULL;
    node* DS2 = NULL;
    int n;
	while(1){
		printf("\n-------MENU-------\n");
		printf("\n1. Them vao dau:");
		printf("\n2. Them vao cuoi");
		printf("\n3. Tach Danh sach");
		printf("\n4. Dem so luong node co trong mang");
		printf("\n5. Ban muon tim den vi tri thu k ");
		printf("\n6. Them vao mot node vao sau vi tri thu k nhap vao ban phim");
		printf("\n7. Tach danh sach lien ket theo vi tri k nhap vao tu ban phim");
		printf("\n8. In ra danh sach hien tai");
		printf("\n0. Thoat");
		int lc ;
		printf("\n--------------");
		printf("\nNhap su lua chon: ");
		scanf("%d",&lc);
		if(lc==1){
			printf("\nNhap vao bao nhieu phan tu: ");
			scanf("%d",&n);
			for(int i= 1;i<=n;i++){
				printf("Nhap so thu %d ",i);
				int x ;
				scanf("%d",&x);
				H=addHead(H, x);
			}
			printf("Danh sach lien ket sau khi them phan tu: ");
			duyet(H);
		}else if(lc==2){
			printf("\nNhap vao bao nhieu phan tu: ");
			scanf("%d",&n);
			for(int i= 1;i<=n;i++){
				printf("Nhap so thu %d ",i);
				int x ;
				scanf("%d",&x);
				H=addAft(H, x);
			}
			printf("Danh sach lien ket sau khi them phan tu: ");
			duyet(H);
		}else if(lc==3){
			DSChan=NULL;
			DSLe=NULL;
			tachDanhSachLK(H, &DSChan, &DSLe);
			printf("Danh sach so chan sau khi tach:");
			duyet(DSChan);
			printf("\nDanh sach so le sau khi tach:");
			duyet(DSLe);
		}else if(lc==4){
			printf("\nSo luong node co trong mang la: %d ",count(H));
		}else if(lc==5){
			int k ;
			printf("Ban muon tim den vi tri thu may:");
			scanf("%d",&k);
			node* kthNode = timNodeK(H, k);
		    if (kthNode != NULL) {
				printf("Dia chi cua node co vi tri thu %d tim den la:%d\n", k, kthNode->data);
			}
			else{
				printf("Dia chi cua node co vi tri thu %d tim den la: NULL\n", k);
			}
		}
		else if(lc==6){
			int k , x;
			printf("\nNhap vao vi tri k:\n");
			scanf("%d",&k);
			printf("\nNhap vao giá tri muon chen sau vi tri thu %d:  ",k);
			scanf("%d",&x);
			insert(&H,k, x );
			printf("Danh sach lien ket sau khi them phan tu vao sau vi tri thu %d : ",k);
			duyet(H);
		}else if(lc==7){
			int k;
		    printf("Nhap vi tri k de tach danh sach: ");
		    scanf("%d", &k);
		    node* DS1 = NULL;
		    node* DS2 = NULL;
		    tachDoiDanhSach(H, k, &DS1, &DS2);
		    printf("\nDanh sach goc: ");
		    duyet(H);
		    printf("\nDanh sach (DS1) sau khi tach tai vi tri thu %d : ",k);
		    duyet(DS1);
		    printf("\nDanh sach (DS2) sau khi tach tai vi tri thu %d : ",k);
		    duyet(DS2);
		}else if(lc==8){
			printf("In ra danh sach hien tai:");
			duyet(H);
		}else{
			break;
		}
		
	}
}

