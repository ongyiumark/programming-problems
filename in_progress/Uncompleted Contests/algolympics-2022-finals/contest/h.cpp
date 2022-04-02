#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<int>;

const int N = 5e3+5;
ll W[N], V[N];
ll diff[N];

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void testcase(){
    int n;
    ll d; cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> W[i] >> V[i];
        V[i] *= d;
        diff[i] = W[i]-V[i];
    }
    //sort(diff, diff+n);
    /*
    for (int i = 0; i < n; i++){
        cout << diff[i] << " ";
    }
    cout << endl;
    */

    vector<ll> neg, pos;
    for (int i = 0; i < n; i++) {
        if (diff[i] < 0) neg.push_back(-diff[i]);
        else if (diff[i] > 0) pos.push_back(diff[i]);
        else {
            cout << "BLAST OFF\n";
            return;
        }
    }
    if ((int)neg.size() > 0 && (int)pos.size() > 0) {
        cout << "BLAST OFF\n";
        return;
    }
    
    cout << "CURSE YOU NEWTON\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int T; cin >> T;
    while (T--){
        testcase();
    }
    return 0;
}
