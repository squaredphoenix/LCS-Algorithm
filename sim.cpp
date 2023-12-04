#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int LCSLength(string &x, string &y)
{
    //variables
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    // finds the LCS length
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            }
            else
            {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }

    return dp[m % 2][n];
}

char level(int length_LCS, int minLength, int maxLength)
{
    // calculates ratio
    double ratio1 = static_cast<double>(length_LCS) / static_cast<double>(min(minLength, maxLength));
    double ratio2 = static_cast<double>(min(minLength, maxLength)) / static_cast<double>(max(minLength, maxLength));

    // finds the different levels
    if (ratio1 > 0.9 && ratio2 > 0.9)
    {
        return 'H'; // High
    }
    else if (ratio1 > 0.8 && ratio2 > 0.8)
    {
        return 'M'; // Medium
    }
    else if (ratio1 > 0.5 && ratio2 > 0.5)
    {
        return 'L'; // Low
    }
    else
    {
        return 'D'; // Dissimilar
    }
}

int main(int argc, char *argv[])
{
    // checks argcs
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // checks files
    ifstream file("seqs.txt");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file" << endl;
        return 1;
    }

    // variables
    int sequenceCount;
    file >> sequenceCount;

    // inputs into sequences vector
    vector<string> sequences(sequenceCount);
    for (int i = 0; i < sequenceCount; ++i)
    {
        file >> sequences[i];
    }

    // outputs numbers
    cout << " ";
    for (int i = 1; i <= sequenceCount; ++i)
    {
        cout << i << "  ";
    }
    cout << endl;

    // uses the dofferent function to output the right similarities of sequences processed
    for (int i = 0; i < sequenceCount; ++i)
    {
        cout << i + 1;

        for (int j = 0; j < sequenceCount; ++j)
        {
            if (i == j)
            {
                cout << " ";
            }
            else
            {
                string x = sequences[i];
                string y = sequences[j];

                int length_LCS = LCSLength(x, y);
                char similarityLevel = level(length_LCS, sequences[i].length(), sequences[j].length());

                cout << "  ";
                if(i < j)
                {
                    cout << similarityLevel;
                }
                else
                {
                    cout << " ";
                }
            }
        }

        cout << endl;
    }

    return 0;
}