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

ld area(ld a, ld b, ld theta) {
  return a*b*sin(theta)/2;
}

const int iter = 100000;
ld solve(ll a, ll b) {
  ld lo = 0;
  ld hi = acosl(-1);

  for (int i = 0; i < iter; i++) {
    ld m1 = (2*lo + hi)/3;
    ld m2 = (lo + 2*hi)/3;

    ld h1 = area(a, b, m1);
    ld h2 = area(a, b, m2);

    if (h1 <= h2) lo = m1;
    else hi = m2;
  }
  return area(a, b, (lo+hi)/2);
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

  ld ans = solve(total/2, total-total/2);

  sort(x.begin(), x.end(), greater<pair<ll,int>>());

  ll tl = 0;
  ll tr = 0;
  for (int i = 0; i < n; i++) {
    if (tl < total/2) {
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

  if (tl == total/2) {
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
    //cout << tl << " " << tr << " " << total/2 << endl;
    for (int i = 0; i < (int)l.size(); i++) {
      if (l[i].first > tl-total/2) {
        r.push_back({tl-total/2, n});
        l.push_back({l[i].first-(tl-total/2), n+1});

        iskip = l[i].second;
        cut1 = tl-total/2;
        cut2 = l[i].first-(tl-total/2);

        tl -= cut1;
        tr += cut1;
        break;
      }
    }
  }

  assert(tl == total/2);
  assert(tr == (total+1)/2);
  
  sort(l.begin(), l.end(), [](pair<ll, int> &left, pair<ll, int> &right) {return left.first < right.second;});
  sort(r.begin(), r.end(), [](pair<ll, int> &left, pair<ll, int> &right) {return left.first < right.second;});

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

  cout << total/2*(total-total/2)/2 << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(30) << fixed;
  
  ll t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}

