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
int a[N];
int cnt[3][N];
int negs[N];
int nxttwo[N];
int n;


int count_negs(int l, int r) {
  if (l == 0) return negs[r];
  return negs[r]-negs[l-1];
}

int count_i(int l, int r, int i){
  if (l == 0) return cnt[i][r];
  return cnt[i][r]-cnt[i][l-1];
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i <= 2; i++) {
      cnt[i][0] = (a[0] == i); 
    }

    negs[0] = (a[0] < 0);
    for (int i = 1; i < n; i++) {
      negs[i] = (a[i] < 0);
      negs[i] += negs[i-1];
    }

    for (int i = 0; i <= 2; i++){
      for (int j = 1; j < n; j++) {
        cnt[i][j] = (a[j] == i);
        cnt[i][j] += cnt[i][j-1];
      }
    }

    if (cnt[2][n] == 0) {
      cout << 0 << " " << n << endl;
      continue;
    }

    int curr = n;
    for (int i = n-1; i >= 0; i--) {
      nxttwo[i] = curr;
      if (abs(a[i]) == 2) curr = i;
    }

    int bestl = 0, bestr = n-1;
    int best = 0;
    int l = 0;
    if (abs(a[l]) != 2) l = nxttwo[l];
    int r = l;
    while (l < n) {
      r = nxttwo[r];
      if (count_negs(l))
    }
  }

  return 0;
}
