#include "Headerfile.h"

using namespace std;

void Bankers_Algo()
{
    cout << endl
         << "\t\t\tBamker's Algorithm" << endl
         << endl;
    int n, m, i, j, k;
    cout << "Enter Value of M and N" << endl;
    cin >> n >> m;
    int alloc[100][100];
    int max[100][100];

    cout << "Enter the Allocation Matrix\n ";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> alloc[n][m];
        }
    }

    cout << endl;
    cout << "Enter the Max Matrix\n ";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> max[n][m];
        }
    }

    int avail[100];
    int p;
    cout << "Enter the value for no of resource " << endl;
    cin >> p;
    cout << "Enter Available array" << endl;
    for (int i = 0; i < p; i++)
    {
        cin >> avail[i];
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }

    return;
    
}

int main()
{
    system("cls");

    cout << "\t\tTHIS CODE BELONGS TO BHASKAR ANAND 2K20/CO/121" << endl;

    cout << endl
         << "\t\t\tBamker's Algorithm" << endl
         << endl;

    cout << "Press Enter To Continue!!!!" << endl;
    getch();
    system("cls");
    Bankers_Algo();

    

    return 0;
}
