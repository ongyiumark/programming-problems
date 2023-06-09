#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
const ll INFLL = 4e18;

string query(vi &L, vi &R) {
    cout << "WEIGH" << endl;
    int kl = L.size();
    cout << kl << endl;
    for (int i = 0; i < kl; i++) {
        cout << L[i];
        if (i+1 < kl) cout << " ";
        else cout << endl;
    }

    int kr = R.size();
    cout << kr << endl;
    for (int i = 0; i < kr; i++) {
        cout << R[i];
        if (i+1 < kr) cout << " ";
        else cout << endl;
    }

    string res; cin >> res;
    return res;
}

vi convert(int mid) {
    vi res(15);
    int i = 0;
    while (mid > 0) {
        res[i++] = mid%3;
        mid /= 3;
    }

    int carry = 0;
    for (int i = 0; i < 15; i++) {
        if ((res[i]+carry)%3 == 2) {
            res[i] = -1;
            carry = 1;
        }
        else {
            int tmp = res[i];
            res[i] = (res[i]+carry)%3;
            carry = (tmp+carry)/3;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n = 15;
    ll pow3[n+1];

    pow3[1] = 2;
    for (int i = 2; i <= n; i++) {
        pow3[i] = 3*pow3[i-1];
    }

    // feathers
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << pow3[i];
        if (i < n) cout << " ";
        else cout << endl;
    }

    // M
    int M = 0;
    for (int i = 1; i <= n; i++) M += pow3[i];
    cout << M << endl;

    int T; cin >> T;
    while (T--) {
        vi L, R;

        int lo = 1;
        int hi = M/2;

        int lb = 0;
        int ub = M+1;
        while(lo <= hi) {
            int mid = hi - (hi-lo)/2;
            vi bt = convert(mid);
            
            L.clear();
            R.clear();
            L.push_back(0);
            for (int i = 0; i < 15; i++) {
                if (bt[i] == -1) L.push_back(i+1);
                else if (bt[i] == 1) R.push_back(i+1);
            }

            string res = query(L, R);
            if (res == ">:(") return 0;

            if (res == "<") {
                ub = mid*2;
                hi = mid-1;
            }
            else if (res == ">") {
                lb = mid*2;
                lo = mid+1;
            }
            else {
                ub = lb = mid*2;
                break;
            }
        }

        cout << "VERDICT" << endl;
        if (ub == M+1) cout << "HEAVY" << endl;
        else {
            cout << "EXACT" << endl;
            cout << (lb==ub ? lb : (lb+1)) << endl;
        }

        string res; cin >> res;
        if (res == ">:(") return 0;
    }

    return 0;
}