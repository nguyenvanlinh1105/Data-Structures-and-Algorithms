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

main(){
	node *H=NULL;
	node* DSChan = NULL;
    node* DSLe = NULL;
    int n;
	while(1){
		printf("\n\n-------MENU-------\n");
		printf("\n1. Them vao dau:");
		printf("\n2. Them vao cuoi");
		printf("\n3. Tach Danh sach");
		printf("\n4. Dem so luong node co trong mang");
		printf("\n5. Ban muon tim den vi tri thu k ");
		printf("\n6. Them vao mot node vao sau vi tri thu k nhap vao ban phim");
		printf("\n7 .In ra danh sach goc xem co thay doi sau khi tach hay khong");
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
			printf("\nDanh sach sau khi them phan tu: ");
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
			printf("\nDanh sach sau khi them phan tu: ");
			duyet(H);
		}else if(lc==3){
			DSChan=NULL;
			DSLe=NULL;
			tachDanhSachLK(H, &DSChan, &DSLe);
			printf("Danh sach so chan sau khi tach tu danh sach goc la: ");
			duyet(DSChan);
			printf("\nDanh sach so le sau khi tach tu danh sach goc la: ");
			duyet(DSLe);
		}else if(lc==4){
			printf("\nSo luong node co trong mang la: %d ",count(H));
		}else if(lc==5){
			int k ;
			printf("Ban muon tim den vi tri thu may:");
			scanf("%d",&k);
			node* kthNode = timNodeK(H, k);
		    if (kthNode != NULL) {
				printf("Dia chi cua node co vi tri thu %d tim den la:%p\n", k, kthNode);}
			else{
				printf("Dia chi cua node co vi tri thu %d tim den la: NULL\n", k);
			}
		}
		else if(lc==6){
			int k , x;
			printf("\nNhap vao vi tri k: ");
			scanf("%d",&k);
			printf("\nNhap vao gia tri muon chen sau vi tri thu %d:  ",k);
			scanf("%d",&x);
			insert(&H,k, x );
			printf("\nDanh sach sau khi chen 1 phan tu vao sau vi tri thu %d: ",k);
			duyet(H);
		}else if(lc==7){
			printf("\nDanh sach goc: ");
			duyet(H);
		}else{
			break;
		}
		
	}
}
