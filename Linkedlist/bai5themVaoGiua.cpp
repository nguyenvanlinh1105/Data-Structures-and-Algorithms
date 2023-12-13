#include<stdio.h>
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
main(){
	node *head=NULL;

	while(1){
		
	}


}
