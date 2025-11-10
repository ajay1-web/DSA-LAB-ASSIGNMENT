#include <iostream>
using namespace std;

class TridiagonalMatrix
{
private:
    int *A;
    int n;

public:
    TridiagonalMatrix(int size)
    {
        n = size;
        A = new int[3 * n - 2];
        for (int i = 0; i < 3 * n - 2; ++i)
            A[i] = 0;
    }

    ~TridiagonalMatrix()
    {
        delete[] A;
    }

    void set(int i, int j, int value)
    {
        // i, j are 1-based (for mathematical notation)
        if (i - j == 1)
            A[i - 2] = value; // Lower diagonal: elements a[2][9], a[10][11], ..., a[n][n-1]
        else if (i - j == 0)
            A[n - 1 + i - 1] = value; // Main diagonal: a[9][9], a[11][11], ..., a[n][n]
        else if (i - j == -1)
            A[2 * n - 1 + i - 1] = value; // Upper diagonal: a[9][11], a[11][10], ..., a[n-1][n]
        // otherwise, zero (not stored)
    }

    int get(int i, int j) const
    {
        if (i - j == 1)
            return A[i - 2];
        else if (i - j == 0)
            return A[n - 1 + i - 1];
        else if (i - j == -1)
            return A[2 * n - 1 + i - 1];
        else
            return 0;
    }

    void display() const
    {
        cout << "\nTri-diagonal Matrix:\n";
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;
    TridiagonalMatrix mat(n);

    cout << "Enter the elements of the matrix:\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            mat.set(i, j, x);
        }
    }

    mat.display();

    return 0;
}
