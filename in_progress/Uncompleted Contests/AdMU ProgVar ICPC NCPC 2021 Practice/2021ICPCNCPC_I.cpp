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

ll modpow(ll b, ll e, ll m) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1;
  }
  return ans;
}

const int N = 1e6+5;
ll a[N], b[N];

const int M = 2e7;
vector<ll> primes;
bool is_composite[M];

void sieve() {
  memset(is_composite, 0, sizeof is_composite);
  for (ll i = 2; i < M; i++) {
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] < M; j++) {
      is_composite[i*primes[j]] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

int rand(int a, int b) {
  return a+rand()%(b-a+1);
}

const int MOD = 1e9+7;

vector<int> hash_primes;

struct hashes {
  ll val;
  ll p;
  hashes(int i) {
    val = 1;
    p = hash_primes[i];
  }

  void convert(int idxA, int idxB) {
    val *= primes[idxA];
    val %= p;
    val *= modpow(primes[idxB], p-2, p);
    val %= p;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  srand(time(0));
  sieve();

  int n; cin >> n;
  
  hash_primes = {
    1000040641,
    1000040647,
    1000040659,
    1000040663,
    1000040681,
    1000040711,
    1000040791,
    1000040801,
    1000040819,
    1000040831,
    1000040863,
    1000040903,
    1000040917,
    1000040933,
    1000041019,
    1000041037,
    1000041061,
    1000041071,
    1000041083,
    1000041103,
    1000041131,
    1000041151,
    1000041169,
    1000041179,
    1000041181,
    1000041197,
    1000041221,
    1000041233,
    1000041241,
    1000041253
  };
  int m = hash_primes.size();
  int xx = rand(0,m-1);
  int yy = rand(0,m-1);

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  map<ll, int> num2idx;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (num2idx.find(a[i]) != num2idx.end()) continue;
    num2idx[a[i]] = idx;
    idx++;
  }
  for (int i = 0; i < n; i++) {
    if (num2idx.find(b[i]) != num2idx.end()) continue;
    num2idx[b[i]] = idx;
    idx++;
  }

  for (int i = 0; i < n; i++) {
    a[i] = num2idx[a[i]];
    b[i] = num2idx[b[i]];
  }

  map<pair<ll,ll>, int> cnt;
  hashes h1(xx), h2(yy);

  for (int i = 0; i < n; i++) {
    h1.convert(a[i], b[i]);
    h2.convert(a[i], b[i]);
    cnt[{h1.val, h2.val}]++;
  }

  ll total = 0;
  for (auto it : cnt) {
    ll x = it.second;
    total += modpow(2, x, MOD)-x-1;
    total %= MOD;
    if (total < 0) total += MOD;
  }
  cout << total << endl;
  
  return 0;
}
