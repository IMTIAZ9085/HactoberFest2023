#include <iostream>
#include <climits>
using namespace std;

// Matrix Chain Multiplication function
int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // cost is 0 when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length.
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // Return the minimum number of multiplications needed.
}

// Example usage
int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, size) << endl;
    return 0;
}
