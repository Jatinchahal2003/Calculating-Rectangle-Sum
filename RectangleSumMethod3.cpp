#include <iostream>
#include <vector>
using namespace std;
int RectangleSum(vector<vector<int>> &matrix, int n, int m);
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> Matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = RectangleSum(Matrix, n, m);

    cout << "The Rectangle sum of given matrix is " << sum;
    return 0;
}
int RectangleSum(vector<vector<int>> &matrix, int n, int m)
{
    int l1, r1, l2, r2;
    cout << "Enter l1 and r1 :";
    cin >> l1 >> r1;
    cout << "Enter l2 and r2 :";
    cin >> l2 >> r2;
    int sum = 0;
    vector<vector<int>> Ans(n, vector<int>(m));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j == 0)
            {
                sum = matrix[i][j];
                Ans[i][j] = sum;
            }
            else
            {
                sum += matrix[i][j];
                Ans[i][j] += sum;
            }
        }
    }
    // vector<vector<int>> Ans2(n,vector<int> (m));

    for (int i = 1; i < Ans.size(); i++)
    {
        for (int j = 0; j < Ans[i].size(); j++)
        {
            Ans[i][j] += Ans[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }

    if (r1 != 0 && l1 != 0)
    {
        sum = Ans[l2][r2] - Ans[l2][r1 - 1] - Ans[l1 - 1][r2] + Ans[l1 - 1][r1 - 1];
    }
    else if (r1 == 0)
    {
        sum = Ans[l2][r2] - Ans[l1 - 1][r2];
    }
    else if (l1 == 0)
    {
        sum = Ans[l2][r2] - Ans[l2][r1 - 1];
    }

    return sum;
}