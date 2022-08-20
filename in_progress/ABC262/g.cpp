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

const int N = 55;
int cnt[N][N];
int a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  memset(cnt, 0, sizeof cnt);
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      cnt[i][j] += cnt[i+1][j];
    }
    cnt[i][a[i]]++;
  } 

  return 0;
}
