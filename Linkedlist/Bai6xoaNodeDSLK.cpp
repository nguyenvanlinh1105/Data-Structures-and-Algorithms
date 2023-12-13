#include<stdio.h>
#include<stdlib.h>
// a <=> *ptr;
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node* makeNode(int x){
//	node* newNode = (node*)malloc(sizeof(node));
	node *newNode = new node;
	newNode->data= x;
	newNode->next= NULL; // moi lan cap phat node moi thi hãy de gia tri next = NULL,
	return newNode;
}
void duyet(node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;	
	}
}
int count(node *head){
	int dem = 0;

	while(head !=NULL){
		dem++;
			printf("Gia tri cua head: %p\n", (void *)head);
		head=head->next;
	}
	
	return dem;
}
void pushFront(node **head,int x){
	node *newNode = makeNode(x);
	newNode-> next = (*head);///=> dia chi. // truy cap den dia chi ma con tro dang tro 
	(*head)= newNode;
}
void pushBack(node **head, int x){
	node *newNode = makeNode(x);
	if(*head == NULL){
		// neu con tro truyen vao có dia chi == NULL thì gán con tro dau tien truyen vao= newNode dc tao o tren.
		*head = newNode; 
		return ;	
	}
	node *tmp = *head;// dia chi// **head là con tro den con tro => * là con tro và * head là mot dia chi
	// neu su dung head o trong nay se lam thay doi DSLK nen phai tao bien trung gian 
	while(tmp->next!=NULL){
		tmp= tmp->next; 
	}
	tmp->next = newNode;
	// dat bien trung gian de khi di chuyen tu dau DSLK den cuoi thi head khog thay doi vi nó luon tro den vi tri dau tien . còn  temp thi tro di tu dau den cuoi DSLK
}
void insert (node **head, int k ,int x){
	int n = count(*head);// truyen vao con tro cua head dang tro toi 
	if(k<1 || k >n+1) return ;
	if(k==1){
		pushFront(head, x); return; // head trong truong hop nay chinh la dia chi.
				// vì *head chính là con tro duoc tro den .=> head là mot dia chi.
	}
	node * temp = *head;
	for(int i= 1;i<=k-2;i++){
		temp=temp->next;
	}
	node * newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}
void popFront (node **head){
	if(*head == NULL) return ;
	node *temp  = *head;// nut dau tien ; // de lat con xóa. free bo nho
	// B1: cho node head luu node thu 2 
	*head = (*head)->next;
	// B2: Giai phong bo nho thu nhat.
	free(temp);
	// o day su d?ng *head de thuc hien thay doi *head dàu 
}
void popBack(node **head){
	if(*head ==NULL) return ;
	node *temp = *head;
	if(temp->next==NULL){
		*head =NULL;
		free(temp);// free temp trong if này .
		return ;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	node *last = temp-> next; // node cuoi
	temp->next = NULL;
	free(last);
}
main(){
	node *head=NULL;// khi head mang giá tri thi no luon quan li node dau tien.
	while(1){
		printf("-------MENU-------\n");
		printf("\n1. Them vao dau:");
		printf("\n2. Them vao cuoi");
		printf("\n3. Them vao giua");
		printf("\n4. Xoa node dau tien");
		printf("\n5. Xoa node cuoi cung");
		printf("\n6. Duyet");
		printf("\n0. Thoat");
		int lc ;
		printf("\n--------------");
		printf("\nNhap su lua chon: ");
		scanf("%d",&lc);
		if(lc==1){
			printf("\nNhap gia tri muon them");
			int x ;
			scanf("%d",&x);
			pushFront(&head, x);
		}else if(lc==2){
			printf("\nNhap gia tri muon them");
			int x ;
			scanf("%d",&x);
			pushBack(&head, x);
		}else if(lc==3){
			int k , x;
			printf("\nNhap vao vi tri muon chen\n");
			scanf("%d",&k);
			printf("\nNhap vao giá tri muon chen");
			scanf("%d",&x);
			insert(&head,k, x );
		}else if(lc==4){
			popFront(&head);
		}else if(lc==5){
			popBack(&head);
		}else if(lc==6){
			duyet(head);
			printf("\n");
		}else{
			break;
		}
		
	}
}
