/*
    Prime factorize. Take the first k-1 primes and multiply the rest.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> facts;
    int n, k; cin >> n >> k;
    for (int d = 2; d*d <= n; d++) {
        while(n%d==0) {
            facts.push_back(d);
            n /= d;
        }
    }
    if (n>1) facts.push_back(n);
    for (int i = k; i < facts.size(); i++) {
        facts[k-1] *= facts[i];
    }
    if (facts.size() < k) cout << -1 << endl;
    else {
        int sz = facts.size();
        for (int i = 0; i < k; i++) {
            cout << facts[i];
            if (i == sz-1) cout << endl;
            else cout << " ";
        }
    } 
}