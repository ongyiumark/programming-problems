#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int F_MAX = 2e6+5;
ll fact[F_MAX];
ll ifact[F_MAX];

const ll MOD = 1e9+7;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll perm(ll n, ll k) {
  return fact[n] * ifact[n-k] % MOD;
}

ll comb(ll n, ll k) {
  return perm(n, k) * ifact[k] %MOD;
}

ll inv(ll x) {
  return modpow(x, MOD-2);
}

void compute_fact() {
  fact[0] = 1;
  for (int i = 1; i < F_MAX; i++) {
    fact[i] = i*fact[i-1]%MOD;
  }

  ifact[F_MAX-1] = inv(fact[F_MAX-1]);
  for (int i = F_MAX-2; i >= 0; i--) {
    ifact[i] = (i+1)*ifact[i+1]%MOD;
  } 
}

ll solve(ll N, ll G, ll I, ll E, ll X) {
  ll Y = G-2*X;
  ll Z = N-X-Y;
  ll res = G;

  // extroverts
  // try to sit next to the easy going people first
  if (Y >= E) {
    // all extroverts are seated
    res += E;
    Y -= E;
    E = 0;
  }
  else {
    // not enough seats next to easy going people
    res += Y;
    Y = 0;
    E -= Y;
    
    // sit in pairs
    if (Z >= E/2) {
      // all extrovert pairs can be seated
      res += E/2*2;
      Z -= E/2;
      E %= 2;

      if (Z == 0) return res;
      if (E == 1) Z -= 1;
    }
    else {
      // fill the rest of the seats
      res += 2*Z;
      Z = 0;
      E -= 2*Z;
      return res;
    }
  }

  // introverts
  if (Z >= I) {
    // all introverts can be seated
    res += I;
    Z -= I;
    I = 0;
    return res;
  }
  else {
    // no more empty pairs
    res += Z;
    ll ZI = Z;
    I -= Z;
    Z = 0;
    if (I == 0) return res;

    if (E == 1 && I > 0) {
      res += 1; 
      I -= 1;
      E -= 1;

      res -= min(ZI, I);
      return res;
    }

    if (Y >= I) {
      return res;
    }
    else {
      I -= Y;
      res -= min(ZI, I);
    }
  }

  return res;
}

ll other_solve(ll n, ll g, ll i, ll e, ll x) {
  ll y = g-2*x;
  ll z = n-x-y;

  ll h = g;
  // all extroverts next to easygoing
  if (e <= y) {
    h += e;
    ll y_rem = y - e;
    if (z >= i) {
      // all introverts happy
      h += i;
    }
    else {
      // some introverts not happy
      h += z;
      ll i_rem = i - z;

      // sit next to easy going
      i_rem -= y_rem;

      // sit next to other introverts
      h -= max(0ll, min(z, i_rem));
    }
  }
  // some extroverts not next to easy going
  else {
    ll e_rem = e - y;
    ll is_odd = e_rem % 2;
    h += e;

    z -= ((e_rem / 2) + is_odd);

    if (is_odd) {
      h--;
      // all introverts are happy
      if (z >= i) {
        h += i;
      }
      else {
      // some introverts not happy
        h += z;
        ll i_rem = i - z;
        i_rem -= is_odd;
        h -= max(0ll, min(z, i_rem));
        h++;
      }
    }
    else {
      // all introverts are happy
      if (z >= i) {
        h += i;
      }
      else {
      // some introvers not happy
        h += z;
        ll i_rem = i - z;
        h -= max(0ll, min(z, i_rem));
      }
    }
  }
  return h;
}

ll get_prob(ll N, ll x, ll y) {
  ll prob = comb(N, x);
  prob = prob * comb(N-x, y) % MOD;
  prob = prob * modpow(2, y) % MOD;
  return prob;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  compute_fact();
  ll N, G, I, E; cin >> N >> G >> I >> E;
  if (2*N <= G + E) {
    cout << 2*N << endl;
    return 0;
  }

  ll total = 0;

  ll totalprob = 0;
  for (ll x = 0; 2*x <= G && x <= N; x++) {
    if (G-2*x > N-x) continue;

    ll prob = get_prob(N, x, G-2*x);
    ll cnt = other_solve(N, G, I, E, x);

    totalprob += prob;
    totalprob %= MOD;
    total += prob * cnt % MOD;
    total %= MOD;
    //cout << x << " " << G-2*x << " " << prob << endl;

  }

  //cout << "Final: " << totalprob << " " << comb(2*N, G) << endl;

 //assert(totalprob * inv(comb(2*N, G)) % MOD == 1);
  
  total = total * inv(comb(2*N, G)) % MOD;
  cout << total << endl;
  return 0;
}
