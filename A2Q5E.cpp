#include <iostream>
using namespace std;

class SymmetricMatrix
{
private:
    int *A;
    int n;

public:
    SymmetricMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; ++i)
            A[i] = 0;
    }

    ~SymmetricMatrix()
    {
        delete[] A;
    }

    // Set element at (i, j), 1-based indexing
    void set(int i, int j, int x)
    {
        if (i >= j)
        {
            int index = i * (i - 1) / 2 + (j - 1);
            A[index] = x;
        }
        else
        {
            int index = j * (j - 1) / 2 + (i - 1);
            A[index] = x;
        }
    }

    // Get element at (i, j), 1-based indexing
    int get(int i, int j) const
    {
        if (i >= j)
        {
            int index = i * (i - 1) / 2 + (j - 1);
            return A[index];
        }
        else
        {
            int index = j * (j - 1) / 2 + (i - 1);
            return A[index];
        }
    }

    // Display the matrix
    void display() const
    {
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
    cout << "Enter dimension of the symmetric matrix: ";
    cin >> n;

    SymmetricMatrix mat(n);

    cout << "Enter the elements of the symmetric matrix (only lower triangle including diagonal):\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            int x;
            cin >> x;
            mat.set(i, j, x);
        }
    }

    cout << "The symmetric matrix is:\n";
    mat.display();

    return 0;
}
