#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
const ll INFLL = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0;

    string res;
    while(1) {
        if (i < n+1 && a[i+1] < a[i]) {
            res.append(1, 'S');
            swap(a[i+1], a[i]);
        }

        res.append(1,'P');
        i++;
        i%=n;
        if (i == 0) {
            bool val = 1;
            for (int j = 1; j < n; j++) {
                val &= (a[j-1] <= a[j]); 
            }
            if (val) break;
        } 
    }

    cout << (res.size() ? res : "empty") << "\n";
    return 0;
}