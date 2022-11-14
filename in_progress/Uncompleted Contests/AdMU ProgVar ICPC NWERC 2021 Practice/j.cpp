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

  int n; cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] = (b[i]+180)*2;
  }

  bool vis[720];
  int N = 720;
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++) {
    int x = b[i];
    int y = b[(i+1)%n];

    if (x == y) {
      vis[x] = 1;
      continue;
    }
    
    int left = 0;
    int right = 0;
    int curr = x;
    while((curr+N)%N != y) {
      curr--;
      left++;
    }
    curr = x;
    while((curr+N)%N != y) {
      curr++;
      right++;
    }

    if (left == right) {
      cout << "yes" << endl;
      return 0;
    }

    //cout << left << " " << right << endl;

    if (left > right) {
      curr = x;
      while((curr+N)%N != y) {
        vis[(curr+N)%N] = 1;
        curr++;
      }
      vis[(curr+N)%N] = 1;
    }
    else {
      curr = x;
      while((curr+N)%N != y) {
        vis[(curr+N)%N] = 1;
        curr--;
      }
      vis[(curr+N)%N] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      cout << "no " << i/2-180 << (i%2==0 ? ".0" : ".5") << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  
  return 0;
}
