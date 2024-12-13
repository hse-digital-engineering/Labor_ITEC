#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z)
{
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int editDistance(char* source, char* target, int n, int m)
{
    int dp[n + 1][m + 1];

    if(m == 0){
        return n;
    }

    if(n == 0){
        return m;
    }

    // If second string (target) is empty, only option is to
    // Delete all characters of second string
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }


    // If first string (source) is empty, only option is to
    // insert all characters of second string
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    // Fill dp[][] table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If last characters are same, ignore last char
            // and recur for remaining string
            if (source[i - 1] == target[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Delete
                            dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[n][m];
}
