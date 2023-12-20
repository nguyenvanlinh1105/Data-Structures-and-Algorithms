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
            (*count)++;
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
// bài 10: 

// Function to print the tree using inorder traversal
//void inorderTraversal(struct Node* root) {
//    if (root != NULL) {
//        inorderTraversal(root->L);
//        printf("%s ", root->sv.maSV);
//        inorderTraversal(root->R);
//    }
//}

int main() {
	Node * root = NULL;
    root=createBST(root);
	printBST(root);
    return 0;
}

