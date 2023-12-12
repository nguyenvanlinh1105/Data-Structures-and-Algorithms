#include<stdio.h>
struct node {
	int data;
	node * L , * R;
};
node *addNode (node *t, int data){
	node * p, * tmp;
	p= new node;
	p->data= data;
	p->L=NULL;
	p->R=NULL;
	if(t==NULL){
		t=p;
	}else{
		tmp = t;
		if(tmp->data>data){
			tmp->L = addNode(t->L, data);
		}else{
			tmp->R= addNode(t->R,data);
		}
	}
	return t;
}
main(){
	
}
