#include "Headerfile.h"

bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    int i = 0, j = n - 1;

    while ((i < m - 1) && (j > 0))
    {
        if (target == mat[i][j])
            return true;

        else if (target > mat[i][n - 1])
            i++;

        else
            j--;
    }

    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 1}, {4, 8}};
    int m = 2, n = 2, target = 8;

    cout << findTargetInMatrix(mat, m, n, target);

    return 0;
}