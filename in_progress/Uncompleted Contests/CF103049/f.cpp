#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll x[N], v[N];
int before[N], after[N];
bool crash[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  memset(crash, 0, sizeof crash);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> v[i];
    before[i] = i-1;
    after[i] = i+1;
  }

  priority_queue<piii, vector<piii>, greater<piii> > pq;
  for (int i = 0; i < n; i++){
    // this and before
    if (before[i] >= 0){
      if (v[before[i]]-v[i] > 0) {
        ld t = (ld)(x[i]-x[before[i]])/(v[before[i]]-v[i]);
        pq.push({t,{before[i], i}});
      } 
    }

    // this and after
    if (after[i] < n) {
      if (v[i]-v[after[i]] > 0) {
        ld t = (ld)(x[after[i]]-x[i])/(v[i]-v[after[i]]);
        pq.push({t,{i, after[i]}});
      } 
    }
  }

  while(!pq.empty()){
    piii curr = pq.top();
    pq.pop();

    int a = curr.second.first;
    int b = curr.second.second;
    if (crash[a] || crash[b]) continue;
    //cout << a << " " << b << " " << curr.first << endl;

    crash[a] = crash[b] = 1;
    if (after[b] < n){
      before[after[b]] = before[a];
    }
    if (before[a] >= 0){
      after[before[a]] = after[b];
    }

    int c = before[a];
    int d = after[b];
    if (c >= 0 && d < n){
      if (v[c]-v[d] > 0){
        ld t = (ld)(x[d]-x[c])/(v[c]-v[d]);
        pq.push({t,{c,d}});
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++){
    if (!crash[i]) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++){
    cout << ans[i]+1;
    cout << (i+1 == (int)ans.size() ? "\n" : " ");
  }

  return 0;
}
