#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> fibs = {2LL,3LL};

vector<int> ans;
bool found = false;
void solve(ll n, int i){
    if (found) return;
    if (n == 1) {
        for (int x : ans) {
            for (int j = 0; j < x+1; j++) cout << "A";
            cout << "B"; 
        }
        found = true;
        return;
    }

    for (int j = i; j >= 0 && !found; j--) {
        if (n % fibs[j] == 0) {
            ans.push_back(j);
            solve(n/fibs[j], j);
            ans.pop_back();
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    while(fibs.back() <= n) {
        int m = fibs.size();
        fibs.push_back(fibs[m-1]+fibs[m-2]);
    }

    int m = fibs.size();

    solve(n, m-1);
    if (!found) cout << "IMPOSSIBLE";

    return 0;
}