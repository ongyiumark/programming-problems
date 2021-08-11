/*
  Work backwards. Start from the last bridge and count how many it connects.
    Then, count how many the 2nd to the last connects.
    This can be done by DSU.
*/
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
int A[N], B[N];

struct dsu{
  vector<ll> arr;
  
  dsu(int n) : arr(n,-1) {}

  int find(int x) {
    if (arr[x] < 0) return x;
    return arr[x] = find(arr[x]);
  }

  ll unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (arr[a] < arr[b]) swap(a,b);
    ll ans = sz(a)*sz(b);
    arr[b] += arr[a];
    arr[a] = b;
    return ans;
  }

  ll sz(int x){
    x = find(x);
    return -arr[x];
  }

};

dsu d(N);
ll res[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> A[i] >> B[i];

  for (int i = m-1; i >= 0; i--){
    res[i] = d.unite(A[i], B[i]);
  }
  for (int i = 1; i < m; i++) res[i] += res[i-1];

  for (int i = 0; i < m; i++){
    cout << res[i] << endl;
  }
  return 0;
}
