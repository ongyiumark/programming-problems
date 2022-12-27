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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<pair<vector<bool>, int>> ar;
    ar.resize(n);

    int total = 0;
    vi cnt(n);
    for (int i = 0; i < n; i++) {
      ar[i].first.resize(m);
      for (int j = 0; j < m; j++) {
        int x; cin >> x;
        total += x;
        cnt[i] += x;

        ar[i].first[j] = x;
        ar[i].second = i;
      }
    }

    if (total % n != 0) {
      cout << -1 << "\n";
      continue;
    }

    int need = total/n;

    vector<tuple<int,int,int>> res;
    for (int j = 0; j < m; j++) {
      sort(ar.begin(), ar.end(), [&cnt](const pair<vector<bool>,int> &left, const pair<vector<bool>, int> &right) {
        return cnt[left.second] > cnt[right.second]; 
      });

      int l = 0;
      int r = n-1;

      while(l < n && !ar[l].first[j]) l++;
      while(r >= 0 && ar[r].first[j]) r--;

      while(l < r) {
        if (cnt[ar[l].second] <= need || cnt[ar[r].second] >= need) break;
        swap(ar[l].first[j], ar[r].first[j]);
        cnt[ar[l].second]--; cnt[ar[r].second]++;
        res.push_back({ar[l].second, ar[r].second, j});

        while(l < n && !ar[l].first[j]) l++;
        while(r >= 0 && ar[r].first[j]) r--;
      }
    }  

    int k = res.size();
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
      auto &[x,y,z] = res[i];
      cout << x+1 << " " << y+1 << " " << z+1 << "\n";
    }  
  }

  return 0;
}
