#include <iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    float a[20][20];
    float ratio;
    int i, j, k;
    cout << "Enter no of unknowns? ";
    cin >> n;

    // Data entry
    cout << "\nEnter the element of augmented matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++) {
            cout << "A(" << i << "," << j << ") = ";
            cin >> a[i][j];
        }

    // Gauss Elimination method
    for (j = 0; j < n - 1; j++) {
        if (abs(a[j][j]) <= 0.0005) {
            cout << "Error: Pivot element is zero";
            return 0;
        }
        for (i = j + 1; i < n; i++) {
            ratio = a[i][j] / a[j][j];
            for (k = j; k <= n; k++)
                a[i][k] -= ratio * a[j][k];
        }
    }

    // Solutions by Backward Substitution
    cout << "\nThe solution is:\n";
    float x[n], sum;
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += a[i][j] * x[j];
        x[i] = (a[i][n] - sum) / a[i][i];
        cout << char('z'-(n-1)+i) << " = " << x[i] << endl;
    }   
    return 0;
}
