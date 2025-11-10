#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int *arr;
    int n;

public:
    DiagonalMatrix(int size)
    {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = 0;
    }

    ~DiagonalMatrix()
    {
        delete[] arr;
    }

    // Set value at (i, j) -- only for diagonal elements
    void set(int i, int j, int value)
    {
        if (i == j && i >= 0 && i < n)
            arr[i] = value;
        // Else do nothing (non-diagonal elements remain zero)
    }

    // Get value at (i, j)
    int get(int i, int j) const
    {
        if (i == j && i >= 0 && i < n)
            return arr[i];
        else
            return 0;
    }

    // Display the matrix
    void display() const
    {
        cout << "\nMatrix is:\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    cout << arr[i] << " ";
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
    cout << "Enter matrix dimension: ";
    cin >> n;
    DiagonalMatrix mat(n);

    cout << "Enter the diagonal elements:\n";
    for (int i = 0; i < n; ++i)
    {
        int val;
        cout << "Element (" << i << "," << i << "): ";
        cin >> val;
        mat.set(i, i, val);
    }

    mat.display();

    return 0;
}
