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

const int N = 51;
int memo[N][N][N];
int query(int i, int j, int k){
  int x = min({i,j,k});
  int z = max({i,j,k});
  int y = i+j+k-x-z;
  if (memo[x][y][z] != -1) return memo[x][y][z];
  cout << x << " " << y << " " << z << endl;
  int res; cin >> res;
  memo[x][y][z] = res;
  return res;
}

vector<int> solve(vector<int> arr){
  int n = arr.size();
  if (n <= 2) return arr;
  vector<int> lo, mid, hi;
  for (int i = 2; i < arr.size(); i++){
    int tmp = query(arr[0], arr[1], arr[i]);
    if (tmp == -1) return {};
    if (tmp == arr[0]) lo.push_back(arr[i]);
    else if (tmp == arr[1]) hi.push_back(arr[i]);
    else mid.push_back(arr[i]);
  }

  vector<int> ans;
  vector<int> loans = solve(lo);
  vector<int> midans = solve(mid);
  vector<int> hians = solve(hi);
  if (lo.size() >= 2){
    int tmp = query(lo[0], lo[1], arr[0]);
    if (tmp == -1) return {};
    if (tmp == lo[0]) reverse(loans.begin(), loans.end());
  }
  if (mid.size() >= 2){
    int tmp = query(mid[0], mid[1], arr[0]);
    if (tmp == -1) return {};
    if (tmp == mid[1]) reverse(midans.begin(), midans.end());
  }
  if (hi.size() >= 2){
    int tmp = query(hi[0], hi[1], arr[1]);
    if (tmp == -1) return {};
    if (tmp == hi[1]) reverse(hians.begin(), hians.end());
  }
  for (int v : loans) ans.push_back(v);
  ans.push_back(arr[0]);
  for (int v : midans) ans.push_back(v);
  ans.push_back(arr[1]);
  for (int v : hians) ans.push_back(v);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, q; cin >> t >> n >> q;  
  
  while(t--){
    memset(memo, -1, sizeof memo);
    vector<int> arr;
    for (int i = 1; i <= n; i++) arr.push_back(i);
    vector<int> ans = solve(arr);
    if (ans.size() == 0) return 0;
    for (int i = 0; i < n; i++){
      cout << ans[i];
      if (i == n-1) cout << endl;
      else cout << " ";
    }
    int res; cin >> res;
    if (res == -1) return 0;
  }
  return 0;
}
