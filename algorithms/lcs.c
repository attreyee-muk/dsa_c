// A Naive recursive implementation of LCS problem

#include <stdio.h>
#include <string.h>
int max(int a, int b);
char sequence[10];

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(char* X, char* Y, int m, int n)
{
	if (m == strlen(X) || n == strlen(Y))
		return 0;
	if (X[m] == Y[n]){
        sequence[m]=X[m];
		return 1 + lcs(X, Y, m +1, n+1);

    }
        
    else{
        return max(lcs(X, Y, m, n + 1),
				lcs(X, Y, m + 1, n));
    }
		
}

// Utility function to get max of 2 integers
int max(int a, int b) { return (a > b) ? a : b; }

// Driver code
int main()
{
	char S1[] = "GGTAB";
	char S2[] = "GXTXAYB";
	int m = 0;
	int n = 0;

	printf("Length of LCS is %d\n", lcs(S1, S2, m, n));
    for(int i=0;i<10;i++){
        printf("%c",sequence[i]);
    }
    printf("\n");
	return 0;
}
