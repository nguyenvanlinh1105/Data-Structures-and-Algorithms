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
main(){
	node *head=NULL;
	for(int i= 1;i<=5;i++){
		pushBack(&head,i);// truyen dia chi cua con tro , vi da khai bao là *head roi hì ban chat no la con tro gio mình chi can truyen dia chi cua con tro vao la xong
		} 
	duyet(head);
	printf("so luong phan tu: %d ", count(head));
	
}
