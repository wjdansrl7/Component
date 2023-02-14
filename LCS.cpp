// LCS(Longest Common Subsequence) or (Longest Common Substring)
// 최장 공통 부분 수열: 주어진 여러 개의 수열 모두의 부분수열이 되는 수열들 중에 가장 긴 것을 찾는 문제

/*
앞으로 채워야할 칸을 (i, j)라고 하고, 첫 번째 문자열을 arr1[], 두 번째 문자열을 arr2[] 라고 하자.
그리고 해당 테이블을 저장할 배열을 dp[][]라고 한다.

(1,1)부터 채우게 될텐데 여기서 두 가지 경우

1. arr1[j] = arr2[i]인 경우
이 경우 왼쪽 대각선 위칸(dp[i-1][j-1])의 값에 1을 더하면 된다.
이유는 해당 문자를 제외하고 지금까지 최대값이 dp[i-1][j-1]인데 공통인 문자가 하나 추가되었으니
지금까지의 최대값에 1을 더해주는 것이다.

2. arr1[j] != arr2[i]인 경우
이 경우는 새로 추가된 문자를 써도 추가되는 공통부분이 없으므로 현재까지의 최대를 가져와야 한다.
이경우 바로위칸(dp[i-1][j]) 또는 바로왼쪽칸(dp[i][j-1] 중 큰 값을 가져오면 된다.

*/
#include <iostream>
#include <stdio.h>

char arr[1001];
char arr2[1001];
int dp[1002][1002];

int max(int a, int b);
int main(int argc, char const *argv[])
{
    scanf("%s", arr);
    scanf("%s", arr2);
    int i, j;
    for (i = 0; i < 1002 + 1; i++)
    {
        for (j = 0; j < 1002; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[i - 1] == arr2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[1001][1001]);

    return 0;
}

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}