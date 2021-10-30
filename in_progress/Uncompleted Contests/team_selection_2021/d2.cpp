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

const int N = 1e5+5;
ll a[N];
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) cin >> a[i];
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
    if (s.size() <= 1) {
      cout << 0 << endl;
      continue;
    }
    ll hi = *--s.end();
    ll total = hi;
    pair<ll, ll> mean = {total, 1};
    int sz = 1;
    for (auto it = s.begin(); it != --s.end(); it++){
      sz++;
      total += *it;
      pair<ll,ll> nmean = {total, sz};
      if (nmean.first*mean.second < mean.first*nmean.second){
        mean = nmean;
      }
      else break;
    }
    cout << (ld)hi-((ld)mean.first/mean.second) << endl;
  }
  return 0;
}
