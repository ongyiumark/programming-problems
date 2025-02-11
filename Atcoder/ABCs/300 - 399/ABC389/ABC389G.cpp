#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vt;
typedef vector<vt> vvt;
typedef vector<vvt> v3t;
typedef vector<v3t> v4t;
typedef vector<v4t> v5t;

const int MAXN = 30;
const int MAXM = MAXN*(MAXN-1)/2;

const int size_f = (MAXN+1)*(MAXN+1)*(MAXN+1)*(MAXM+1)*2;
ll f[MAXN+1][MAXN+1][MAXM+1][MAXN+1][2];
const int size_g = (MAXN+1)*(MAXN+1)*(MAXM+1);
ll g[MAXN+1][MAXN+1][MAXM+1];
const int size_comb = (MAXN+1)*(MAXN+1);
ll comb[MAXN+1][MAXN+1];


int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    ll N, MOD;
    cin >> N >> MOD;
    int M = N*(N-1)/2;
    
    // initialize combinations
    memset(comb, 0, sizeof(ll)*size_comb);
    for (int i = 0; i <= N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
        }
    }

    // calculate transitions
    

    memset(g, 0, sizeof(ll)*size_g);
    g[0][0][0] = 1;
    for (int x = 1; x < N; x++) {
        g[x][0][0] = 1;
        for (int y = 0; x+y < N; y++) {
            for (int z = y; z < M; z++) {
                for (int dz = 1; dz <= min(x+y, M-z); dz++) {
                    g[x][y+1][z+dz] += g[x][y][z] * (comb[x+y][dz]- comb[y][dz]) % MOD;
                    g[x][y+1][z+dz] %= MOD;
                    if (g[x][y+1][z+dz] < 0) g[x][y+1][z+dz] += MOD;
                }
            }
        }
    }

    
    // <= distance, even, odd, current verts, edges 
    memset(f, 0, sizeof(ll)*size_f);
    f[1][0][0][1][0] = 1;
    for (int even = 1; even <= N; even++) {
        for (int odd = 0; even+odd <= N; odd++) {
            for (int edges = even+odd-1; edges <= (even+odd)*(even+odd-1)/2; edges++) {
                for (int x = 0; x <= max(even, odd); x++) {
                    for (int parity = 0; parity <= 1; parity++) {
                        if (f[even][odd][edges][x][1-parity] == 0) continue;
                
                        // pick y verts and extra edges i
                        for (int y = 0; y <= N-even-odd; y++) {
                            for (int z = y; z <= x*y + y*(y-1)/2; z++) {
                                    int _even = even + (1-parity)*y;
                                    int _odd = odd + parity*y;
                                    int _edges = edges + z;

                                    f[_even][_odd][_edges][y][parity] += f[even][odd][edges][x][1-parity]*g[x][y][z]%MOD*comb[N-even-odd][y]%MOD;
                                    f[_even][_odd][_edges][y][parity] %= MOD;
                            }
                        }
                    } 
                }
            }
        }
    }

    for (int m = N-1; m <= M; m++) {
        ll ans = 0;
        for (int i = 0; i <= N; i++) {
            ans += f[N/2][N/2][m][i][0];
            ans %= MOD;
        }
        cout << ans << " \n"[m==M];
    }
}