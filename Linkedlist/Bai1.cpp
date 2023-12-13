#include<stdio.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node* makeNode(int x){
//	node* newNode = (node*)malloc(sizeof(node));
	node *newNode = new node;
	newNode->data= x;
	newNode->next= NULL;
	return newNode;
}
void duyet(node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;	
	}
}
int count(node * head){
	int dem = 0;
	while(head !=NULL){
		dem++;
		head=head->next;
	}
	return dem;
}
void pushFront(node **head, int x){
	node *newNode = makeNode(x);
	//B1:phan next cua newNode = dia chi cua con tro head.
	newNode->next = (*head);// *head toán tu dai tham chieu. luu dia chi cua node head dau tien. Hay nói cách khác là dia chi cua node head.
	// B2 cap nhat node head=>newNode
	*head = newNode;
}

main(){
	node *head=NULL;
	for(int i= 1;i<=5;i++){
		pushFront(&head,i);// truyen dia chi cua con tro , vi da khai bao là *head roi hì ban chat no la con tro gio mình chi can truyen dia chi cua con tro vao la xong
		} 
	duyet(head);
	printf("so luong phan tu: %d ", count(head));
	
}
