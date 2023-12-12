#include<stdio.h>
struct node {
	int data;
	node *L, *R;
};
node * addNode(node * t, int d){
	node * p = new node ;
	p->data = d;
	p->L =NULL;
	p->R=NULL;
	if(t==NULL){
		t=p;
	}else{
		if(t->data>d){
			t ->L = addNode(t->L,d);
		}else{
			t ->R=addNode(t->R,d);
		}
	}
	return t;
}

void duyetNLR(node *t){
	if(t!=NULL){
		printf("%d ",t->data);
		duyetNLR(t->L);
		duyetNLR(t->R);
	}
}
void duyetNRL(node *t){
	if(t!=NULL){
		printf("%d ",t->data);
		duyetNRL(t->R);
		duyetNRL(t->L);
		
	}
}
void duyetLNR(node *t){
	if(t!=NULL){
	
		duyetLNR(t->L);
		printf("%d ",t->data);
		duyetLNR(t->R);
	}
}
void duyetRNL(node *t){
	if(t!=NULL){
		duyetRNL(t->R);
		printf("%d ",t->data);
		duyetRNL(t->L);
	
	}
}
void duyetLRN(node *t){
	if(t!=NULL){
		
		duyetLRN(t->L);
		duyetLRN(t->R);
		printf("%d ",t->data);
	}
}
void duyetRLN(node *t){
	if(t!=NULL){
		
		duyetRLN(t->R);
		duyetRLN(t->L);
		printf("%d ",t->data);
		
	}
}
int timkiem(node *t, int x) {
    if (t == NULL) {
        return 0;
    } else {
        if (t->data == x) {
            return 1;
        } else {
            if (t->data > x) {
                return timkiem(t->L, x); 
            } else {
                return timkiem(t->R, x); 
            }
        }
    }
}
node *SEARCH(node *t, int x) {
    if (t == NULL) {
        return NULL;
    } else {
        if (t->data == x) {
            return t;
        } else {
            if (t->data > x) {
                return SEARCH(t->L, x); 
            } else {
                return SEARCH(t->R, x); 
            }
        }
    }
}
int timMin(node *t){
	node *tmp =t;
	if(tmp->L==NULL)
		return tmp->data;
	else
		return  timMin(t->L);
}
int timMax(node * t){
	node *tmp = t;
	if(tmp ->R==NULL){
		return tmp->data;
	}else{
		return timMax(tmp->R);
	}
}
int Max(int a, int b) {
   if(a>b)
      return a;
   else
      return b;
}
//chieu cao cay
int HeightTree(node *T) {
   if( T == NULL)
      return 0;
   else
      return Max(HeightTree(T->L),HeightTree(T->R)) + 1;
}


//node *delete (node *t, int d){
//	node * tmp ,*R,*L;
//	while(SEARCH(t, d)){
//		tmp = SEARCH(t,d) ;
//		if(tmp==t){
//			if(tmp->L!=NULL){
//				R= t->R;
//				
//			}
//		}
//	}
//	return t;
//}

void duyetdep(node *t){
	if(t==NULL){
		printf("Cay trong");
	}else{
		printf("%d ",t->data);
		if(t->R!=NULL){
			printf("\\n%d",t->R->data);
		}
		if(t->L!=NULL){
			printf("/\n%d",t->L->data);
		}
		duyetdep(t->R);
		duyetdep(t->L);
	}
}

main(){
	node * t= NULL;
	int n,x;
	printf("Them bao nhieu so");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Nhap so thu %d",i);
		scanf("%d",&x);
		t= addNode(t,x);
	}
	printf("Duyet Dau: ");
	duyetNLR(t);
	printf("\n");
	printf("Duyet Giua: ");
	duyetLNR(t);
	printf("\n");
	printf("Duyet Cuoi: ");
	duyetLRN(t);
	printf("\nNhap so muon tim kiem ");
	scanf("%d",&x);
	int kq= timkiem(t,x);
	if(kq==1)
		printf("Tim thay");
	else
		printf("khong tim thay");
		
	printf("\nGia tri nho nhat tim thay trong cay la: %d",timMin(t));
	printf("\nGia tri lon nhat tim thay trong cay la : %d",timMax(t));
	printf("\nChieu cao cua cay la: %d",HeightTree(t));
	printf("\n");
	printf("duyet dep");
	duyetdep(t);
}
