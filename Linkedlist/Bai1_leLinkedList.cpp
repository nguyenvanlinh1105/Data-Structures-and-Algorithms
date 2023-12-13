#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *addAft(node *H,node *It){
	if(H==NULL){
		H=It;
	}else{
		node *temp = H;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=It;
	}
	return H;
}
node *addHead(node *H, node*It){
	if(H==NULL){
		H=It;
	}else{
		It->next=H;
		H=It;
	}
	return H;
}
void duyet(node *H){
	if(H==NULL){
		printf("khong co phan tu nao.");
	}else{
		node *temp = H;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int count(node *H) {
    int dem = 0;
    node *temp = H;
    while (temp != NULL) {
        dem++;
        temp = temp->next;
    }
    return dem;
}
// tim kiem thong tin data trong danh sach
int search(node *H,int data){
	node *temp = H;
	while(temp!=NULL){
		if(temp->data ==data)
			return 1;
		temp = temp->next;
	}
	return 0;
}
node *search1(node* H,int data){
	node *temp= H;
	while(temp!=NULL){
		if(temp->data ==data)
			return temp;
		temp=temp->next;	
	}
	return NULL;
}
node *xoa(node *H,int data){
	node *temp ;
	node *p = search1(H,data);
	if(H==p){
		H=H->next;
		p->next=NULL;
	}else{
		temp=H;
		while (temp->next!=p){
			temp = temp->next;
		}
		temp->next = p->next;
		p->next=NULL;
	}
	return H;
}
// cach 1: them theo data truyen vao.
node *insert(node *H, int data){
	node *temp, *p , *t;
	p= new node;
	p->data= data;
	p->next= NULL;
	if(H==NULL){
		H=p;
	}else{
		temp = H;
		while(temp!=NULL&&temp->data<data){
			t=temp;
			temp=temp->next;
		}
		if(data<=H->data){
			// them dau
			p->next=H;
			H=p;
		}else{
			// them sau 
			p->next = t->next;
			t->next=p;		
		}
	}
	return H;
}
// tru?ng h?p 2 là phan tu can chen vao la mot node .
node* insert1(node* H, node *p){
	node *temp, *t;
	if(H==NULL){
		H=p;	
	}else{
		temp =H;
		while(temp!=NULL&&temp->data<p->data){
			t = temp;
			temp= temp->next;
		}
		if(p->data <=H->data){
			p->next=H;
			H= p;
		}else{
			p->next = t->next;
			t->next =p;
		}
	}
	return H ;
}
main(){
	node *H,*It;
	int i,n;
	H=NULL;
	printf("\nNhap bao nhieu so");
	scanf("%d",&n);
	for(i= 1;i<=n;i++){
		It = new node;
		printf("\nNhap so thu %d ",i);
		scanf("%d",&It->data);
		It->next = NULL;
		H = addAft(H,It);
	}
	printf("\nso luong phan tu trong danh sach lien ket: %d\n",count(H));
	duyet(H);
	node *temp = search1(H,3);
	if(temp!=NULL){
		printf("\nPhan tu %d duoc tim thay trong DSLK",temp->data);
		H= xoa(H,3);
		printf("\n Phan tu trong DSLK hien tai:");
		duyet(H);
	}
	else{
		printf("\n Khong tim thay ");
	}
	node *s1 = new node;
	printf("\n Nhap so can chen");
	scanf("%d",&s1->data);
	s1->next=NULL;
	printf("\n sau khi in sert :");
	H=insert1(H, s1);
	duyet(H);
	
	
}
