#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int N = 3e5+5;
struct contestant {
    int a, p, f;
};

contestant arr[N];
vi year(N);

struct segtree {
    int n;
    vector<int> *vals;
    segtree(vi &ar){
        n = ar.size();
        vals = new vector<int>[4*n];
        build(ar,1,0,n-1);
    }

    void build(vi &ar, int p, int i, int j) {
        if (i == j) {
            vals[p].push_back(ar[i]);
        }
        else {
            int k = (i + j)/2;
            build(ar, 2*p, i, k);
            build(ar, 2*p+1, k+1, j);
            pull(p);
        }
    }

    void pull(int p) {
        vector<int> &l = vals[2*p];
        vector<int> &r = vals[2*p+1];

        int lidx, ridx;
        lidx = ridx = 0;
        while(true){
            if (lidx >= l.size() && ridx >= r.size()) break;
            else if (ridx >= r.size()) vals[p].push_back(l[lidx++]);
            else if (lidx >= l.size()) vals[p].push_back(r[ridx++]);
            else {
                if (l[lidx] < r[ridx]) vals[p].push_back(l[lidx++]);
                else vals[p].push_back(r[ridx++]);
            }
        } 
    }

    int query(int _i, int _j, int x, int p, int i, int j) {
        if (_i <= i && j <= _j) {
            int m = vals[p].size();
            int lo = 0;
            int hi = m-1;
            int ans = 0;
            while(lo <= hi) {
                int mid = hi - (hi-lo)/2;
                if (vals[p][mid] >= x) {
                    ans = m-mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            return ans;
        }
        else if (_j < i || j < _i){
            return 0;
        }
        else {
            int k = (i+j)/2;
            return query(_i, _j, x, 2*p, i, k)+query(_i, _j, x, 2*p+1, k+1, j);
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y, n; cin >> y >> n;
    
    for (int i = 0; i < y; i++) {
        cin >> year[i];
    }

    segtree sg(year);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int a, p, f;
        cin >> a >> p >> f;
        a--;
        arr[i] = {a,p,f};
        if (p <= year[a]) {
            cout << 0 << "\n";
            continue;
        }

        cout << sg.query(a+1, a+f, p, 1, 0, sg.n - 1) << "\n";
    }

    return 0;
}