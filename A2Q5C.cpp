#include <iostream>
using namespace std;

class LowerTriangularMatrix
{
private:
    int *A;
    int n;

public:
    LowerTriangularMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; ++i)
            A[i] = 0;
    }

    ~LowerTriangularMatrix()
    {
        delete[] A;
    }

    // Set element at (i, j), 1-based indexing
    void set(int i, int j, int x)
    {
        if (i >= j)
        {
            int index = n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j);
            A[index] = x;
        }
    }

    // Get element at (i, j), 1-based indexing
    int get(int i, int j) const
    {
        if (i >= j)
        {
            int index = n * (j - 1) - ((j - 2) * (j - 1)) / 2 + (i - j);
            return A[index];
        }
        else
        {
            return 0;
        }
    }

    // Display the full matrix
    void display() const
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i >= j)
                    cout << get(i, j) << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the dimension of the lower triangular matrix: ";
    cin >> n;

    LowerTriangularMatrix mat(n);

    cout << "Enter the elements (only lower triangular including diagonal):\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            mat.set(i, j, x);
        }
    }

    cout << "The matrix is:\n";
    mat.display();

    return 0;
}
