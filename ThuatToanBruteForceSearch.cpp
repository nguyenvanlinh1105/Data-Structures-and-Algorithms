#include <stdio.h>
#include <string.h>


int bruteForceSearch(char text[], char pattern[]) {
    int m = strlen(text);
    int n = strlen(pattern);

    for (int i = 0; i <= m - n; i++) {
        int j;

        // Kiem tra tung ki tu trong mau 
        for (j = 0; j < n; j++)
            if (text[i + j] != pattern[j])
                break;

        // Neu tim thay tra ve vi tri dau tien 
        if (j == n)
            return i;
    }

    // neu khong tim thay tra ve -1
    return -1;
}

int main() {
    char text[] = "Ðây la mot mau co san";
    char pattern[] = "mau";

    int result = bruteForceSearch(text, pattern);

    if (result != -1) {
        printf("Mau dc tim thay tai vi tri: %d\n", result);
    } else {
        printf("Không tim thay mau trong van ban.\n");
    }

    return 0;
}

