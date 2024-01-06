#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMPSearch(char text[], char pattern[]) {
	    int n = strlen(text);
	    int m = strlen(pattern);
	    int lps[m + 1];
	    int len = 0;
	    int i = 1;
	    lps[0] = 0;
	
	    while (i < m) {
		        if (pattern[i] == pattern[len]) {
			            len++;
			            lps[i + 1] = len; 
			            i++;
		        } else {
			            if (len != 0) {
			                	len = lps[len];
			            } else {
				                lps[i + 1] = 0; 
				                i++;
			            }
		        }
	    }
	
	    // Thuc hien tim kiem 
	    for (int i = 1, j = 0; i <= n; ) {
	        if (pattern[j] == text[i - 1]) {
		            j++;
		            i++;
	        }
	        if (j == m) {
		            // Mau duoc tim thay tai trí i - j
		            return i - j;
	        } else if (i <= n && pattern[j] != text[i - 1]) {
		            if (j != 0) {
		                	j = lps[j];
		            } else {
		                	i++;
		            }
	        }
	    }
	
	   	return -1;
}

int main() {
    char text[] = "xin va chao moi nguoi";
    char pattern[] = "chao";
    
    int result = KMPSearch(text, pattern);

    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}

