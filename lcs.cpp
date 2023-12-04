#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // checks argcs
    if (argc != 3)
    {
        cout << argc << "Usage: " << argv[0] << " <gene sequences> <gene sequences>" << endl;
        return 1;
    }

    // variables
    string x = argv[1];
    string y = argv[2];

    int m = x.length();
    int n = y.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = 0;
    }

    // LCS Length finder
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length_LCS = dp[m][n];

    // variables
    string LCS = "";
    int i = m, j = n;

    // finds the LCS
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            LCS = x[i - 1] + LCS;
            i = i - 1;
            j = j - 1;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i = i - 1;
        }
        else
        {
            j = j - 1;
        }
    }

    // outputs the info
    cout << "LCS: " << length_LCS << " " << LCS << endl;

    return 0;
}