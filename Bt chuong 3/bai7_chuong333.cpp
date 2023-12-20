#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SV {
    char maSV[10];
    char hoTen[20];
    char lop[10];
    float dtb;
};

struct Node {
    struct SV sv;
    struct Node* L;
    struct Node* R;
};

// Function to create a new node with the given student information
struct Node* createNode(struct SV sv) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sv = sv;
    newNode->L = newNode->R = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, struct SV sv) {
    struct Node* p = createNode(sv);
    struct Node* tmp;
    struct Node* TMP;

    if (root == NULL) {
        root = p;
    } else {
        tmp = root;
        while (tmp != NULL) {
            TMP = tmp;
            if (strcmp(sv.maSV, tmp->sv.maSV) < 0)
                tmp = tmp->L;
            else 
                tmp = tmp->R;
        }
        if (strcmp(sv.maSV, TMP->sv.maSV) < 0) {
            TMP->L = p;
        } else {
            TMP->R = p;
        }
    }
    return root;
}

struct Node* insert1(struct Node* root, Node* p) {
    struct Node* tmp,* TMP;

    if (root == NULL) {
        root = p;
    } else {
        tmp = root;
        while (tmp != NULL) {
            TMP = tmp;
            if (strcmp(p->sv.maSV, tmp->sv.maSV) < 0)
                tmp = tmp->L;
            else 
                tmp = tmp->R;
        }
        if (strcmp(p->sv.maSV, TMP->sv.maSV) < 0) {
            TMP->L = p;
        } else {
            TMP->R = p;
        }
    }
    return root;
}

void printStudent(struct SV student) {
    printf("Student ID: %s\n", student.maSV);
    printf("Student Name: %s\n", student.hoTen);
    printf("Student Class: %s\n", student.lop);
    printf("Student GPA: %.2f\n", student.dtb);
}

// Function to print the binary search tree using inorder traversal
void printBST(struct Node* root) {
    if (root != NULL) {
        printBST(root->L);
        printStudent(root->sv);
        printBST(root->R);
    }
}
// Function to create a binary search tree interactively from user input
struct Node* createBST(Node *root) {
    int n;
    printf("Ban muon them bao nhieu sinh vien:");
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        struct SV newStudent;

        printf("Enter student ID: ");
        scanf("%s", &newStudent.maSV);

        printf("Enter student name: ");
        scanf("%s", &newStudent.hoTen);

        printf("Enter student class: ");
        scanf("%s", &newStudent.lop);

        printf("Enter student GPA: ");
        scanf("%f", &newStudent.dtb);

        root = insert(root, newStudent);
    }
    return root;
}
// demsv
int demSV(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + demSV(root->L) + demSV(root->R);
    }
}
// demSV tren 5.5
void DemSV5_5(struct Node* root, int& count) {
    if (root != NULL) {
        DemSV5_5(root->L, count);
        
        if (root->sv.dtb > 5.5) {
            (count)++;
        }
        DemSV5_5(root->R, count);
    }
}
// bài 9:
void printStudentsAbove5_5(struct Node* root) {
    if (root != NULL) {
        printStudentsAbove5_5(root->L);

        if (root->sv.dtb > 5.5) {
            printf("Student ID: %s\n", root->sv.maSV);
            printf("Student Name: %s\n", root->sv.hoTen);
            printf("Student Class: %s\n", root->sv.lop);
            printf("Student GPA: %.2f\n", root->sv.dtb);
            printf("\n");
        }

        printStudentsAbove5_5(root->R);
    }
}
// //bài 10: 

struct Node* TKIEM_2(struct Node* Cay, char maSV[]) {
    struct Node* temp = Cay;
    while (temp != NULL && strcmp(maSV, temp->sv.maSV) != 0) {
        if (strcmp(maSV, temp->sv.maSV) < 0) {
            temp = temp->L;
        } else {
            temp = temp->R;
        }
    }

    if (temp != NULL) {
        return temp;
    } else {
        return NULL;
    }
}
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
		if (strcmp(nut->sv.maSV, tr->sv.maSV)<0)
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
Node *XOA(Node *Cay, SV sv)
{
	Node *tk;
	while (TKIEM_2(Cay, sv.maSV)!=NULL)
	{
		tk = TKIEM_2(Cay, sv.maSV);
		if (tk ==Cay)
			Cay = XOAGOC(Cay);
		else
			if (tk->R==NULL && tk->L == NULL)
				Cay = XOA_LA(Cay, tk);
			else
				if (tk->L!=NULL & tk->R == NULL)
					Cay = XOA_TG_T(Cay, tk);
				else
					if (tk->L==NULL & tk->R != NULL)
						Cay = XOA_TG_P(Cay, tk);
					else
						Cay = XOA_TG(Cay, tk);
							
	}
	return Cay;
}
Node* deleteStudentsBelow5_5GPA(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    root->L = deleteStudentsBelow5_5GPA(root->L);
    root->R = deleteStudentsBelow5_5GPA(root->R);

    if (root->sv.dtb < 5.5) {
        root = XOA(root, root->sv);
    }

    return root;
}


int main() {
    Node* root = NULL;
    root = createBST(root);

    printf("Binary Search Tree:\n");
    printBST(root);

    // Delete students with GPA below 5.5
    root = deleteStudentsBelow5_5GPA(root);

    printf("\nBinary Search Tree after deleting students with GPA below 5.5:\n");
    printBST(root);

    return 0;
}

