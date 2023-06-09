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


ld herons(ld a, ld b, ld c) {
  ld s = (a+b+c)/2;
  return sqrtl(s*(s-a)*(s-b)*(s-c));
}

const ld EPS = 1e-9;
const int iter = 10000;

ld solvec(ll a, ll b) {
  ld lo = fabs(a-b);
  ld hi = a+b;

  for (int i = 0; i < iter; i++) {
    ld m1 = (2*lo + hi)/3;
    ld m2 = (lo + 2*hi)/3;

    ld h1 = herons(a, b, m1);
    ld h2 = herons(a, b, m2);

    if (h1 <= h2) lo = m1;
    else hi = m2;
  }
  //cout << "optimal c: " << (lo+hi)/2 << endl;
  return herons(a, b, (lo+hi)/2);
}

pair<ld,ll> solveab(ll total) {
  ll lo = 1;
  ld hi = total/2;

  ld ans = -1e18;
  ll cut = -1;
  while(lo <= hi) {
    ll m1 = (2*lo+hi)/3;
    ll m2 = (lo+2*hi)/3;

    ld h1 = solvec(m1, total-m1);
    ld h2 = solvec(m2, total-m2);

    if (h1 <= h2) {
      lo = m1+1;
      cut = m2;
      ans = h2;
    }
    else {
      hi = m2-1;  
      cut = m1;
      ans = h1;
    }
  }

  return {ans,cut};
}



vector<pair<ll, int>> x;
vector<pair<ll, int>> l, r;
void testcase() {
  int n; cin >> n;
  x.resize(n);

  ll total = 0;
  for (int i = 0; i < n; i++) {
    ll tmp; cin >> tmp;
    x[i] = {tmp, i};
    total += tmp;
  }

  pair<ld, int> p = solveab(total);
  ld ans = p.first;
  ld need = p.second;

  sort(x.begin(), x.end(), greater<pair<ll,int>>());

  ll tl = 0;
  ll tr = 0;
  for (int i = 0; i < n; i++) {
    if (tl < need) {
      tl += x[i].first;
      l.push_back(x[i]); 
    }
    else {
      tr += x[i].first;
      r.push_back(x[i]);
    }
  }

  int iskip = -1;
  ll cut1 = -1;
  ll cut2 = -1;

  if (need == tl) {
    for (int i = 0; i < (int)l.size(); i++) {
      if (l[i].first > 1) {
        l.push_back({1, n});
        l.push_back({l[i].first-1, n+1});

        iskip = l[i].second;
        cut1 = 1;
        cut2 = l[i].first-1;
        break;
      }
    }
  }
  else {
    for (int i = 0; i < (int)l.size(); i++) {
      if (l[i].first > tl-need) {
        l.push_back({tl-need, n});
        r.push_back({l[i].first-(tl-need), n+1});

        iskip = l[i].second;
        cut1 = tl-need;
        cut2 = l[i].first-(tl-need);
        break;
      }
    }
  }


  cout << iskip+1 << " " << cut1 << " " << cut2 << "\n";
  for (int i = 0; i < (int)l.size(); i++) {
    if (l[i].second == iskip) continue;
    cout << l[i].second+1;
    if (i+1 < (int)l.size()) cout << " ";
    else cout << "\n";
  }
  for (int i = 0; i < (int)r.size(); i++) {
    if (r[i].second == iskip) continue;
    cout << r[i].second+1;
    if (i+1 < (int)r.size()) cout << " ";
    else cout << "\n";
  }

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(20) << fixed;
  
  ll t; cin >> t;
  while(t--) {
    testcase();
  }

  return 0;
}
