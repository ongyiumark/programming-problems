#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pair<ll,ll>, int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
ll x[N], y[N];
ll rx[N], ry[N];

struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}
  int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;

    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    p[b] = a;

    return true;
  }
} graph_dsu(N);

set<int> graph[N];
void connect(int a, int b) {
  if (graph_dsu.unite(a,b)){
    graph[a].insert(b);
    graph[b].insert(a);
  }
}

int cnt[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, a, b; cin >> n >> a >> b;
  a--; b--;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  ll d = abs(x[a]-x[b]) + abs(y[a]-y[b]);
  for (int i = 0; i < n; i++) {
    rx[i] = x[i]-y[i];
    ry[i] = x[i]+y[i];
  }
  // max(|rx[i]-rx[j]|, |ry[i]-ry[j]|) = d

  memset(cnt, 0, sizeof cnt);

  // rx[j]-rx[i] = d
  vector<piii> pairs;
  for (int i = 0; i < n; i++) {
    pairs.push_back({{rx[i], ry[i]}, i});
  }

  sort(pairs.begin(), pairs.end());
  for (int i = 0; i < n; i++) {
    ll cx = pairs[i].first.first;
    ll cy = pairs[i].first.second;
    int idx = pairs[i].second;

    // find j such that rx[j] = cx+d 
    // and |cy-ry[j]| <= d
    int lo = i;
    int hi = n-1;
    int lb = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (pairs[mid].first.first > cx+d) hi = mid-1;
      else if (pairs[mid].first.first < cx+d) lo = mid+1;
      else if (pairs[mid].first.second > cy-d) {
        lb = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    } 

    lo = i;
    hi = n-1;
    int rb = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (pairs[mid].first.first > cx+d) hi = mid-1;
      else if (pairs[mid].first.first < cx+d) lo = mid+1;
      else if (pairs[mid].first.second < cy+d) {
        rb = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    } 

    if (lb == -1 || rb == -1) continue;

    
    /*cerr << x[idx] << " " << y[idx] << endl;
    for (int j = lb; j <= rb; j++) {
      cerr << "   " << x[pairs[j].second] << " " << y[pairs[j].second] << endl;
    }*/
    //cout << idx << " " << lb << " " << rb << endl;
    
    connect(idx, pairs[lb].second);
    cnt[pairs[lb].second]++;
    for (int j = lb+1; j <= rb; j++) {
      cnt[pairs[j].second]++;
      connect(pairs[j-1].second, pairs[j].second);
    }

    cnt[idx] += rb-lb+1;
  }

  // ry[j]-ry[i] = d
  pairs.clear();
  for (int i = 0; i < n; i++) {
    pairs.push_back({{ry[i], rx[i]}, i});
  }

  sort(pairs.begin(), pairs.end());
  for (int i = 0; i < n; i++) {
    ll cx = pairs[i].first.first;
    ll cy = pairs[i].first.second;
    int idx = pairs[i].second;

    // find j such that rx[j] = cx+d 
    // and |cy-ry[j]| <= d
    int lo = i;
    int hi = n-1;
    int lb = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (pairs[mid].first.first > cx+d) hi = mid-1;
      else if (pairs[mid].first.first < cx+d) lo = mid+1;
      else if (pairs[mid].first.second > cy-d) {
        lb = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    } 

    lo = i;
    hi = n-1;
    int rb = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (pairs[mid].first.first > cx+d) hi = mid-1;
      else if (pairs[mid].first.first < cx+d) lo = mid+1;
      else if (pairs[mid].first.second < cy+d) {
        rb = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    } 

    if (lb == -1 || rb == -1) continue;
    
    /*cerr << x[idx] << " " << y[idx] << endl;
    for (int j = lb; j <= rb; j++) {
      cerr << "   " << x[pairs[j].second] << " " << y[pairs[j].second] << endl;
    }*/
    connect(idx, pairs[lb].second);
    cnt[pairs[lb].second]++;
    for (int j = lb+1; j <= rb; j++) {
      cnt[pairs[j].second]++;
      connect(pairs[j-1].second, pairs[j].second);
    }
    cnt[idx] += rb-lb+1;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (graph_dsu.find(i) == graph_dsu.find(0)) {
      ans += cnt[i];
      //cerr << ans << " " << cnt[i] << endl;
    }
  }

  cout << ans/2 << endl;

  return 0;
}
