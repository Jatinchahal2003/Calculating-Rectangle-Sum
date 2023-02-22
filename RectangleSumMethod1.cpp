#include <iostream>
#include <vector>

using namespace std;

int RectangleSum(vector<vector<int>> &matrix);
int main()
{
    int n, m, sum = 0;
    cin >> n >> m;

    vector<vector<int>> Matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Matrix[i][j];
        }
    }

    sum = RectangleSum(Matrix);

    cout << "The prefix sum is " << sum;
    return 0;
}
int RectangleSum(vector<vector<int>> &matrix)
{
    int l1, l2, r1, r2;
    cout << "Enter l1 and r1 :";
    cin >> l1 >> r1;
    cout << "Enter l2 and r2 :";
    cin >> l2 >> r2;

    int sum = 0;

    for (int i = l1; i <= l2; i++)
    {
        for (int j = r1; j <= r2; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}