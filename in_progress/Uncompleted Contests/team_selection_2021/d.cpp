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
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
ll a[N];
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) cin >> a[i];

  ordered_set<ll> s;
  int sz = 0;
  int j = 0;
  ll prevhi = -1;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
    int m = s.size();
    ll hi = *s.find_by_order(m-1);
    if (i == 0){
      total += hi;
      sz++;
    }
    else {
      if (prevhi == hi){
        int pos = s.order_of_key(a[i]);
        //if (pos < 0) pos = 0;
        if (pos < j) {
          for (int k = j; k >= pos; k--) {
            total -= *s.find_by_order(k);
            sz--;
          }
        }
        j = pos;
      }
      else {
        total -= prevhi;
        total += hi;
      }
    }
    pair<ll,ll> mean = {total, sz};
    while(j < m-1){
      total += *s.find_by_order(j);
      sz++;
      pair<ll,ll> nmean = {total, sz};
      if (nmean.first*mean.second <= mean.first*nmean.second){
        mean = nmean;
      }
      else break;
      j++;
    }

    cout << (ld)hi - ((ld)mean.first/mean.second) << endl;
    total = mean.first;
    sz = mean.second;
    prevhi = hi;
  }
  return 0;
}
