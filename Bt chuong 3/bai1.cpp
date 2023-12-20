#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//Ð?nh nghia c?u trúc c?a m?t nút trong cây
struct SV {
	char maSV[10];
	char hoTen[20]
};
struct Node {
    char name[50];
    struct Node* L;
    struct Node* R;
};

// Hàm d? t?o m?t nút m?i

struct Node* createNode(char name[]) {
    struct Node* newNode = new Node;
    strcpy(newNode->name, name);
    newNode->L = newNode->R = NULL;
    return newNode;
}

// Hàm d? thêm m?t nút m?i vào cây
struct Node* insert1(struct Node* root, Node *p) {
	
    if (root == NULL) {
        root=p;
    }

    if (strcmp(p->name, root->name) < 0) {
        root->L = insert1(root->L, p);
    } else {
        root->R = insert1(root->R, p);
    }

    return root;
}
Node *insert(Node* root, char name[]) {
    struct Node* p = createNode(name);
    struct Node* tmp;
    struct Node* TMP;
    if (root == NULL) {
        root = p;
    } else {
        tmp = root;
        while (tmp != NULL) {
            TMP = tmp;
            if (strcmp(name, tmp->name) < 0)
                tmp = tmp->L;
            else 
                tmp = tmp->R;
        }
        if (strcmp(name, TMP->name) < 0) {
            TMP->L = p;
        } else {
            TMP->R = p;
        }
    }
    return root;
}
// câu 1:
struct Node* TaoCay(char names[][50], int count) {
    struct Node* root = NULL;

    for (int i = 0; i < count; ++i) {
        root = insert(root, names[i]);
    }

    return root;
}
// câu 2-3
void printTree(struct Node* root) {
    if (root != NULL) {
        // In nút hi?n t?i
        printf("%s ", root->name);
        
        // Duy?t sang cây con bên trái
        printTree(root->L);
        
        // Duy?t sang cây con bên ph?i
        printTree(root->R);
    }
}
// câu 4:
int countStudents(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countStudents(root->L) + countStudents(root->R);
}
// câu 5:
//int countStudentsWithGivenName(struct Node* root, char targetName[]) {
//	int count = 0;
//    if (root == NULL) {
//        return 0;
//    }
//
//    
//    if (strcmp(targetName, root->name) == 0) {
//        count += 1;
//    }
//
//    count += countStudentsWithGivenName(root->left, targetName);
//    count += countStudentsWithGivenName(root->right, targetName);
//
//    return count;
//}

int countStudentsWithGivenName(struct Node* root, char targetName[]) {
    int count = 0;

    while (root != NULL) {
        int cmp = strcmp(targetName, root->name);
        if (cmp == 0) {
            count++;
            root = root->R; // Ki?m tra các nút có cùng tên bên ph?i
        } else if (cmp < 0) {
            root = root->L;
        } else {
            root = root->R;
        }
    }

    return count;
}
// hàm tìm
struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->L, name);
    }

    return search(root->R, name);
}
// câu 6: 

Node *XOAGOC(Node *Cay)
{
	Node *tg, *CayL, *CayR;
	
	if (Cay->L == NULL & Cay->R == NULL)
		Cay = NULL;
	else
		if (Cay->L != NULL & Cay->R == NULL)//Cay lech trai
		{
			tg = Cay;
			Cay = Cay->L;
			tg->L = NULL;	
		}
		else
			if (Cay->L == NULL & Cay->R != NULL)//Cay lech phai
			{
				tg = Cay;
				Cay = Cay->R;
				tg->R = NULL;	
			}
			else // cay can bàng
			{				
				tg = Cay;
				CayR = Cay->R;
				Cay = Cay->L ;
				Cay = insert1(Cay, CayR);
			}		
	return Cay;	 
}
Node *TRUOC(Node *Cay, Node *nut)
{
	Node *tr;
	tr = Cay;
	while (tr->L!=nut && tr->R!= nut)
		if (strcmp(nut->name,Cay->name)<0)
			tr = tr->L;
		else
			tr = tr->R;
	return tr;			
}
Node *XOA_LA(Node *Cay, Node *nut)
{
	Node *tr;
	tr = TRUOC(Cay, nut);
	if (tr->R==nut)
		tr->R=NULL;
	else
		tr->L =NULL;
	return Cay;				
}
Node *XOA_TG_T(Node *Cay, Node *nut)
{
	Node *tr;
	tr = TRUOC(Cay, nut);
	if (tr->R == nut)
	{
		tr->R = nut->L;
		nut->L = NULL;
	}
	else
	{
		tr->L = nut->L;
		nut->L = NULL;
	}
	return Cay;			
}
Node *XOA_TG_P(Node *Cay, Node *nut)
{
	Node *tr;
	tr = TRUOC(Cay, nut);
	if (tr->L ==nut)
	{
		tr->L = nut->R;
		nut->R = NULL;
	}
	else
	{
		tr->R = nut->R;
		nut->R = NULL;	
	}
	return Cay;
}
Node *XOA_TG(Node *Cay, Node *nut)
{
	Node *tr, *CayR;
	tr = TRUOC(Cay, nut);
	if (tr->L ==nut)
	{
		tr->L = nut->L;
		nut->L = NULL;
		CayR= nut->R;
		nut->R = NULL;
		Cay = insert1(Cay, CayR);			
	}
	else
	{
		tr->R = nut->L;
		nut->L =NULL;
		CayR= nut->R;
		nut->R = NULL;
		Cay = insert1(Cay, CayR);			
	}
	return Cay;
}
Node *XOA(Node *Cay, char name[])
{
	Node *tk;
	while (search(Cay, name)!=NULL)
	{
		tk = search(Cay, name);
		if (tk ==Cay)
			Cay = XOAGOC(Cay);
		else
			if (tk->R==NULL && tk->L == NULL)
				Cay = XOA_LA(Cay, tk);
			else
				if (tk->L!=NULL && tk->R == NULL)
					Cay = XOA_TG_T(Cay, tk);
				else
					if (tk->L==NULL && tk->R != NULL)
						Cay = XOA_TG_P(Cay, tk);
					else
						Cay = XOA_TG(Cay, tk);
							
	}
	return Cay;
}


int main() {
    struct Node* root = NULL;

    // Thêm các tên sinh viên vào cây
    root = insert(root, "Alice");
    insert(root, "Bob");
    insert(root, "Charlie");
    insert(root, "David");
    insert(root, "Bob");

    // Tìm ki?m tên trong cây
    char searchName[50];
    printf("Enter a name to search: ");
    scanf("%s", searchName);

    struct Node* result = search(root, searchName);

    if (result != NULL) {
        printf("Name found in the tree: %s\n", result->name);
    } else {
        printf("Name not found in the tree.\n");
    }
    char targetName[50];
    printf("Enter the name to count: ");
    scanf("%s", targetName);

 	int studentCount = countStudentsWithGivenName(root, targetName);
    printf("Number of students with the name '%s': %d\n", targetName, studentCount);
	printf("%d",countStudents(root));
	printf("Enter the name to count: ");
    scanf("%s", targetName);
    XOA(root,targetName);
    printTree(root);
    return 0;
}

