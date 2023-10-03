#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll THRESH = 1e6;
const ll INF = 1e18;

struct fort {
    ll a, b, c;
    ll rot;
    fort(ll a, ll b, ll c) : a(a), b(b), c(c), rot(0) {}

    void attack(ll &attacker, ll &left, ll &right, ll &leftTmp, ll &rightTmp) {
        if (attacker > 0) {
            if (left >= right && left > 0) leftTmp--;
            else rightTmp--;
        }
    }
    
    bool step() {
        if ((a > 0) + (b > 0) + (c > 0) <= 1) return false;
        ll na = a, nb = b, nc = c;
        attack(a, b, c, nb, nc);
        attack(b, c, a, nc, na);
        attack(c, a, b, na, nb);
        a = na, b = nb, c = nc;
        return true;
    }

    void rotate() {
        swap(a,b); swap(b,c);
        rot++;
    }

    void reset() {
        while(rot%3 != 0) rotate();
    }

    void rotate_to_max() {
        int to_rot = 0;
        if (a >= b && a >= c) to_rot = 0;
        else if (b >= a && b >= c) to_rot = 1;
        else if (c >= a && c >= b) to_rot = 2;

        while(to_rot--) rotate();
    }

    bool simulate() {
        //cout << a << " " << b << " " << c << endl;
        if ((a > 0) + (b > 0) + (c > 0) <= 1) return false;

        rotate_to_max(); // WLOG max(a,b,c) = a

        // When 2 players are left.
        if (b == 0 || c == 0) {
            a = a - max(b,c);
            b = 0;
            c = 0;
            return false;
        }

        // When a = b = c
        if (a == b && b == c) {
            a = 0; b = 0; c = 0;
            return false;
        }

        if (b == c) {
            // When a = max(b,c)+1
            if (b + 1 == a) {
                ll m = ((a-2)%3);
                a = 0; b = 0; c = 0;
                if (m == 0) c = 1;
                else if (m == 1) b = 1;
                else a = 1;

                return false;
            }
            if (b == 1) {
                a = a-3;
                b = 0; c = 0;
                return false;
            }
            ll k = (1LL<<60);
            while (k > 0) {
                ll na = a-k*2;
                ll nb = b-(k+1)/2;
                ll nc = c-k/2;
                if (nb > 0 && nc >= 0 && na >= nb && na >= nc) {
                    a = na; b = nb; c = nc;
                }
                k >>= 1;
            }
            return true;
        }

        if (b > c) {
            if (a == b) {
                if (a == c+2) {
                    step();
                    return true;
                }
                if (a == c+1) {
                    a = 0; b = 0; c = 0;
                    return false;
                }
                ll k = (1LL<<60);
                while(k > 0) {
                    ll na = a-k*3;
                    ll nb = b-k*3;
                    ll nc = c;
                    if (na >= nc && nb >= nc) {
                        a = na; b = nb; c = nc;
                    }
                    k >>= 1;
                }
                return true;
            }

            ll k = (1LL<<60);
            while(k > 0) {
                ll na = a-k*2;
                ll nb = b-k;
                ll nc = c;
                if (na >= nb && nb >= nc) {
                    a = na; b = nb; c = nc;
                }
                k >>= 1;
            }
            return true;
        }

        if (c > b) {
            if (a == c) {
                if (a == b+2) {
                    step();
                    return true;
                }
                if (a == b+1) {
                    a = 0; b = 0; c = 0;
                    return false;
                }
                ll k = (1LL<<60);
                while(k > 0) {
                    ll na = a-k*3;
                    ll nb = b;
                    ll nc = c-k*3;
                    if (na >= nb && nc >= nb) {
                        a = na; b = nb; c = nc;
                    }
                    k >>= 1;
                }
                return true;
            }

            ll k = (1LL<<60);
            while(k > 0) {
                ll na = a-k*2;
                ll nb = b;
                ll nc = c-k;
                if (na >= nc && nc >= nb) {
                    a = na; b = nb; c = nc;
                }
                k >>= 1;
            }
            return true;
        }

        step();
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c; cin >> a >> b >> c;
    fort f(a,b,c);
    while(f.simulate());
    f.reset();

    if (f.a > 0) cout << "A " << f.a << endl;
    else if (f.b > 0) cout << "B " << f.b << endl;
    else if (f.c > 0) cout << "C " << f.c << endl;
    else cout << "Rubble!" << endl;

    return 0;
}