#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
vector<bool> isc(N);
vector<int> mobius(N);
vector<int> lpf(N, 1);
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!isc[i]) {
      mobius[i] = -1;
      lpf[i] = i;
    }
    for (int j = 2*i; j < N; j += i) {
      isc[j] = true;
      if (j/i % i == 0) mobius[j] = 0;
      else mobius[j] = mobius[j/i]*mobius[i];
      if (lpf[j] == 1) lpf[j] = i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<ll> A(n, 0LL);
  for (ll &x : A) cin >> x;
  vector<int> c(q, 0);
  vector<ll> d(q, 0LL);
  for (int i = 0; i < q; i++) {
    cin >> c[i] >> d[i];
  }

  sieve();
  function<vector<ll>(int)> factorize = [&](int x) {
    map<ll,int> factors;
    while(x > 1) {
      factors[lpf[x]]++;
      x /= lpf[x];
    }
    vector<ll> prime_factors;
    for (auto [p, cnt] : factors) prime_factors.push_back(p);
    return prime_factors;
  };

  // compute all divisors
  vector divisors(N, vector<int>());
  for (int i = 1; i < N; i++) {
    auto factors = factorize(i);
    int sz = factors.size();
    for (int mask = 1; mask < (1<<sz); mask++) {
      ll d = 1;
      for (int j = 0; j < sz; j++) {
        if ((mask>>j)&1) d *= factors[j];
      }
      divisors[i].push_back(d);
    }
  }

  vector regress(N, vector<int>());
  for (int i = 0; i < q; i++) {
    for (int d : divisors[c[i]]) {
      regress[d].push_back(i);
    }
  }

  vector regress_prefix(N, vector<ll>());
  for (int i = 0; i < N; i++) {
    int sz = regress[i].size();
    if (sz == 0) continue;
    regress_prefix[i].assign(sz, 0);
    regress_prefix[i][0] = d[regress[i][0]];
    for (int j = 1; j < sz; j++) regress_prefix[i][j] = regress_prefix[i][j-1] + d[regress[i][j]];
  }

  function<int(int, int)> find_idx = [&](int i, int x) {
    // find largest j s.t. regress[i][j] <= x
    int lo = 0;
    int hi = (int)regress[i].size()-1;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (regress[i][mid] <= x) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    return ans;
  };

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    int lo = 0;
    int hi = q-1;
    int ans = -1;
    
    while (lo <= hi) {
      int mid = hi - (hi - lo)/2;
      
      ll val = A[i];
      for (int d : divisors[i+1]) {
        int idx = find_idx(d, mid);
        if (idx != -1) val += mobius[d]*regress_prefix[d][idx];
      }
  
      if (val <= 0) {
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    result[i] = (ans == -1 ? -1 : ans+1);
  }
  for (int i = 0; i < n; i++) {
    cout << result[i] << "\n";
  }

  return 0;
}