#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+5;
priority_queue<int, vector<int>, greater<int>> arr[N];
int C[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x, c; cin >> x >> c;
        c--;
        C[i] = c;
        arr[c].push(x);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(arr[C[i]].top());
        arr[C[i]].pop();
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i-1] != i) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "Y" << endl;
    return 0;
}