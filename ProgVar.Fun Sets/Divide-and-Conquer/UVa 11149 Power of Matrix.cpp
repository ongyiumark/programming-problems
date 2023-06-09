#include <bits/stdc++.h>
using namespace std;

const int MOD = 10;
struct matrix {
    vector<vector<int>> A;

    matrix(int n)  {
        vector<vector<int>>(n, vector<int>(n, 0)).swap(A);
    }
    matrix(vector<vector<int>> _A) : A(_A) {}

    matrix operator+(const matrix &B) const {
        int n = A.size();
        matrix C(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C.A[i][j] = A[i][j] + B.A[i][j];
                C.A[i][j] %= MOD;
            }
        }
        return C;
    }

    matrix operator*(const matrix &B) const {
        int n = A.size();
        matrix C(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C.A[i][j] += A[i][k]*B.A[k][j];
                }
                C.A[i][j] %= MOD;
            }
        }
        return C;
    }

    matrix operator^(int n) const {
        matrix tmp(A);
        int sz = tmp.A.size();
        matrix ans(sz);
        for (int i = 0; i < sz; i++) ans.A[i][i] = 1;

        while (n > 0) {
            if (n&1) ans = ans*tmp;
            tmp = tmp*tmp;
            n >>= 1;
        }
        return ans;
    } 

    friend ostream& operator<<(ostream& os, const matrix &B);
};

ostream& operator<<(ostream& os, const matrix &B) {
    int n = B.A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os << B.A[i][j];
            if (j+1 < n) cout << " ";
            else os << "\n";
        }
    }
    return os;
} 

matrix eye(int n) {
    matrix res(n);
    for (int i = 0; i < n; i++) res.A[i][i] = 1;
    return res;
}

matrix solve(matrix A, int k) {
    int n = A.A.size();
    if (k == 0) return eye(n);
    if (k == 1) return A;

    matrix tmp1 = solve(A, k/2);
    matrix tmp2 = (A^(k/2)) + eye(n);
    if (k&1) return ((A^k) + tmp1*tmp2);
    
    else return tmp1*tmp2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while(cin >> n >> k) {
        if (n == 0) break;
        matrix A(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A.A[i][j];
                A.A[i][j] %= MOD;
            }
        }

        cout << solve(A, k) << "\n";
    }

    return 0;
}