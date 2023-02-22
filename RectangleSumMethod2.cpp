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
    if (r1 != 0)
    {
        sum = (Ans[l1][r2] - Ans[l1][r1 - 1]) + (Ans[l2][r2] - Ans[l2][r1 - 1]);
    }
    else
    {
        sum = Ans[l1][r2] + Ans[l2][r2];
    }

    return sum;
}