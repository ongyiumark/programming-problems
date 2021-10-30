#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6+5;
int d[N];
int n, k;

void sieve() {
  d[0] = 0;
  for (int i = 1; i < n; i++){
    for (int j = i; j < n; j+=i){
      d[j]++;
    }
  }
}

int nextpow2[N][21];
void solve_pows(){
  for (int x = 0; x < n; x++){
    nextpow2[x][0] = (x + d[x])%n;
  }
  for (int i = 1; i < 21; i++){
    for (int x = 0; x < n; x++){
      nextpow2[x][i] = nextpow2[nextpow2[x][i-1]][i-1];
    }
  }
}

ll sumpow2[N][21];
void solve_sums(){
  for (int x = 0; x < n; x++){
    sumpow2[x][0] = x;
  }

  for (int i = 1; i < 21; i++){
    for (int x = 0; x < n; x++){
      sumpow2[x][i] = sumpow2[x][i-1]+sumpow2[nextpow2[x][i-1]][i-1];
    }
  }
}

ll get_sum(int x, int len){
  ll ans = 0;
  int i = 0;
  while(len > 0){
    if (len&1) {
      ans += sumpow2[x][i];
      x = nextpow2[x][i];
    }
    len/=2;
    i++;
  }
  return ans;
}

void print_seq(ll x){
  cout << x;
  for (int i = 0; i < k-1; i++){
    x = nextpow2[x][0];
    cout << " " << x;
  }
  cout << endl;
}

int cycle[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  sieve();
  solve_pows();
  solve_sums();

  // Solve for cycles.
  
  int best = -1;
  ll score = 1e18;
  for (int x = 0; x < n; x++){
    if (cycle[x] < k) continue;
    ll tmp = get_sum(x,k);
    if (score > tmp){
      score = tmp;
      best = x;
    }
  }

  if (best == -1) cout << -1 << endl;
  else print_seq(best);

  print_seq(14);
  return 0;
}
