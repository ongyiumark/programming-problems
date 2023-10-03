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

  int n, L, p; cin >> n >> L >> p;

  vector<int> cars(n);
  int dist = 0;
  for (int i = 0; i < p; i++) {
    int x; cin >> x;
    
    if (x < L/2) {
      cars[0] += 1;
      dist = max(dist, L/2-x);
      continue;
    }

    int r = (x-L/2)%L;
    if (2*r < L) {
      dist = max(dist, r);
      cars[(x-L/2)/L]++;
    }
    else {
      dist = max(dist, L-r);
      cars[((x-L/2)+L-1)/L]++;
    }
  }
  
  int hi = 0;
  for (int i = 0; i < n; i++) hi = max(hi, cars[i]);
  cout << dist << "\n" << hi << "\n"; 
  
  return 0;
}
