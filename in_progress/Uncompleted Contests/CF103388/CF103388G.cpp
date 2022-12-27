#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> fibs;
map<pair<ll,int>, bool> dp;  

bool solve(ll n, int i){
    if (dp.find({n,i}) != dp.end()) return dp[{n,i}];
    bool &pos = dp[{n,i}];
    if (n == 1) return pos = true;
    if (i < 0) return pos = false;

    pos = solve(n, i-1) || (n % fibs[i] == 0 && solve(n/fibs[i], i));
    return pos;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    fibs.push_back(2); fibs.push_back(3);
    while(fibs.back() <= n){
        int m = fibs.size();
        fibs.push_back(fibs[m-1]+fibs[m-2]);
    }

    int m = fibs.size();
    if (!solve(n, m-1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    for (int i = m-1; i >= 0; i--){
        while (n % fibs[i] == 0 && solve(n/fibs[i], i)) {
            ans.push_back(i);
            n /= fibs[i];
        }
    }

    for (int x : ans) {
        for (int i = 0; i < x+1; i++) cout << "A";
        cout << "B";
    }
    cout << "\n";

    return 0;
}