#include<stdio.h>
#include <stdlib.h>  
struct node {
	int data;
	struct node *next;
};
typedef struct node node;
node* makeNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    // node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **top,int x){
	node* newNode = makeNode(x);
	if(*top == NULL){
		*top = newNode;
	}else{
		newNode->next = (*top);
		(*top)= newNode;
	}
}
void pop(node **top){
	if(*top !=NULL){
		node *temp = *top;
		(*top)= (*top)->next;
		free(temp);
	}
}
int Top (node *top){
	if(top !=NULL){
		return top->data;
	}
}
int size(node *top){
	int ans = 0;
	while (top!=NULL){
		ans++;
		top=top->next;
	}
	return ans;
}
main(){
	node *top;
    while (1) {
        printf("\n----------------\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. top\n");
        printf("4. size\n");
        printf("----------------\n");
        printf("Nhap lua chon: ");
        int lc;
        scanf("%d", &lc);
        switch (lc) {
            case 1: {
                int x;
                printf("Nhap gia tri muon them: ");
                scanf("%d", &x);
                push(&top,x);
                break;
            }
            case 2: {
               	pop(&top);
               	break;
            }
            case 3: {
                int top_value = Top(top);
                if (top_value != -1) {
                    printf("Phan tu o dinh ngan xep: %d\n", top_value);
                }
                break;
            }
            case 4: {
                printf("Kich thuoc cua ngan xep: %d\n", size(top));
                break;
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    }

}
