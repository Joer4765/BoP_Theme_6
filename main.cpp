#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

int pres(long double p, int n) {
    n = pow(10, n);
    p *= n;
    int k = int(p);
    p = double(k) / n;
    return p;
}

int main() {
    srand(time(NULL));
    int n;
    cout << "n:\n";
    cin >> n;
    long double matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    long double coeff;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++){
            coeff = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
                matrix[j][k] = matrix[j][k] - matrix[i][k] * coeff;
        }
    }
    long double det = 1;
    int maximum, digs = 7;
    for (int i = 0; i < n; i++) {
//
//        maximum = 0;
//        for (int i = 0; i < n; i++) {
//            if (fabs(matrix[i][j]) > maximum)
//                maximum = fabs(matrix[i][j]);
//        }
//
//        digs = 0;
//        while(maximum > 0) {
//            maximum /= 10;
//            digs++;
//        }
//

        for (int j = 0; j < n; j++) {
            cout << fixed << setprecision(1) << setw(digs + 1) << matrix[i][j];
            if (i == j)
                det *= matrix[i][j];
        }
        cout << endl;
    }
    cout << endl << det;
    return 0;
}
