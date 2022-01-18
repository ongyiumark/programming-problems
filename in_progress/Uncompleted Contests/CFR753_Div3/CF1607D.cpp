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
ll a[N];
bool red[N];
pair<ll, bool> arr[N];
bool pos[N];

void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    red[i] = (c=='R');
    arr[i] = {a[i], red[i]};
    pos[i+1] = 0;
  }
  sort(arr, arr+n);

  bool valid = 1;

  int idx = n;
  for (int i = n-1; i >= 0; i--){
    if (arr[i].second == 1) {
      if (arr[i].first <= idx){
        pos[idx] = 1;
        idx--;
      }
    }
  }

  idx = 1;
  for (int i = 0; i < n; i++){
    if (arr[i].second == 0){
      if (arr[i].first >= idx){
        pos[idx] = 1;
        idx++;
      }
    }
  }

  for (int i = 1; i <= n; i++){
    if (!pos[i]) valid = false;
  }

  cout << (valid ? "YES" : "NO") << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int k = 0; k < t; k++){
    testcase();
  }
  
  return 0;
}
