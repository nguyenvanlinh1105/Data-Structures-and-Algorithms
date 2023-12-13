#include<stdio.h>

#define MAX_STACK_SIZE 10001

int n = 1, stack[MAX_STACK_SIZE];  // Initialize n to 0, as the stack is empty.

void push(int x) {
    if (n < MAX_STACK_SIZE) {
        stack[n] = x;
        ++n;
    } else {
        printf("Stack overflow\n");
    }
}

int pop() {
    if (n > 0) {
        --n;
        return stack[n];
    } else {
        printf("Stack underflow\n");
        return -1;  // Indicate an error
    }
}

int top() {
    if (n > 0) {
        return stack[n - 1];
    } else {
        printf("Stack is empty\n");
        return -1;  // Indicate an error
    }
}

int size() {
    return --n;
}
void in (){
	for(int i = 1;i<=n-1;i++){
		printf("%d ",stack[i]);
	}
}
int main() {
    int lc;
    while (1) {
        printf("\n----------------\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. top\n");
        printf("4. size\n");
        printf("----------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lc);

        switch (lc) {
            case 1: {
                int x;
                printf("Nhap gia tri muon them: ");
                scanf("%d", &x);
                push(x);
                break;
            }
            case 2: {
                int popped_value = pop();
                if (popped_value != -1) {
                    printf("Phan tu duoc lay ra: %d\n", popped_value);
                }
                break;
            }
            case 3: {
                int top_value = top();
                if (top_value != -1) {
                    printf("Phan tu o dinh ngan xep: %d\n", top_value);
                }
                break;
            }
            case 4: {
            	in();
                printf("Kich thuoc cua ngan xep: %d\n", size());
                break;
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    }

    return 0;
}

