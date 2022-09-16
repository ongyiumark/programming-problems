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

const int N = 2e5+5;
int a[N], b[N];
bool visA[N], visB[N];

int logroot(int x) {
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

void testcase() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) visA[i] = visB[i] = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
  multiset<pii> as, bs;
  priority_queue<pair<int,pii>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({a[i], {0, i}});
    as.insert({a[i],i});
  }
  for (int i = 0; i < n; i++) {
    pq.push({b[i], {1, i}});
    bs.insert({b[i],i});
  }

  int cnt = 0;
  while(!pq.empty()) {
    auto u = pq.top();
    int x = u.first;
    int tt = u.second.first;
    int idx = u.second.second;
    //cout << x << " " << tt << " " << idx << endl;
    pq.pop();

    if (tt == 0 && visA[idx]) continue;
    if (tt == 1 && visB[idx]) continue;

    if (tt == 0) {
      auto it = bs.lower_bound({x,-1});
      if (it != bs.end() && it->first == x) {
        visB[it->second] = 1;
        visA[idx] = 1;
        bs.erase(it);
        as.erase(as.find({x,idx}));
      }
      else {
        as.erase(as.find({x,idx}));
        int xx = logroot(x);
        as.insert({xx,idx});
        pq.push({xx, {tt,idx}});
        cnt++;
      }
    }
    else {
      auto it = as.lower_bound({x,-1});
      if (it != as.end() && it->first == x) {
        visA[it->second] = 1;
        visB[idx] = 1;
        as.erase(it);
        bs.erase(bs.find({x,idx}));
      }
      else {
        bs.erase(bs.find({x,idx}));
        int xx = logroot(x);
        bs.insert({xx,idx});
        pq.push({xx, {tt,idx}});
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
