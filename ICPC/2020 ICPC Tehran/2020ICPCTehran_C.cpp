#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6+3;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int sz = (1<<n);
    vector<int> a(sz);
    vector<bool> has(N);
    unordered_map<int,int> idx;
    for (int i = 0; i < sz; i++) {
        cin >> a[i];
        has[a[i]] = true;
        idx[a[i]] = i;
    }

    vector<pair<int,int>> ans;
    int t = 0;
    for (int i = 0; i < N; i++) {
        if (!has[i]) continue;
        int s = idx[i];
        
        for (int j = 0; j < n; j++) {
            if ((t&(1<<j)) == (s&(1<<j))) continue;
            
            int v = s^(1<<j);
            idx[a[s]] = v;
            idx[a[v]] = s;
            swap(a[s], a[v]);

            ans.push_back({s, v});

            s = v;
        }

        t++;
    }

    int ressz = ans.size();
    cout << ressz << "\n";
    for (int i = 0; i < ressz; i++) {
        auto [a, b] = ans[i];
        cout << a << " "  << b << "\n";
    }


    return 0;
}