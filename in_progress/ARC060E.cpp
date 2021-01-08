/*
  Lots of binary search.
  Precompute right[2^i][n] and left[2^i][n].
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;

int rights[31][N], lefts[31][N];
int hotels[N];
int n;

int right_check(int x, int days){
  int ans = x;

  for (int i = 0; i <= 30; i++){
    if (ans == -1 || ans == n) continue;
    if ((1 << i) & days){
      ans = rights[i][ans];
    }
  }

  return ans;
}

int left_check(int x, int days){
  int ans = x;

  for (int i = 0; i <= 30; i++){
    if (ans == -1) continue;
    if ((1 << i) & days){
      ans = lefts[i][ans];
    }
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(rights, -1, sizeof rights);
  memset(lefts, -1, sizeof lefts);

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> hotels[i];
  }
  int l; cin >> l;

  for (int i = 0; i < n; i++){
    int lo = i+1;
    int hi = n;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      if (hotels[mid]-hotels[i] <= l){
        rights[0][i] = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
  }

  for (int i = 1; i <= 30; i++){
    for (int j = 0; j < n; j++){
      if (rights[i-1][j] == -1) continue;
      rights[i][j] = rights[i-1][rights[i-1][j]];
    }
  }

  for (int i = n-1; i >= 0; i--){
    int lo = 0;
    int hi = i-1;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      if (hotels[i]-hotels[mid] <= l){
        lefts[0][i] = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
  }

  for (int i = 1; i <= 30; i++){
    for (int j = n-1; j >= 0; j--){
      if (lefts[i-1][j] == -1) continue;
      lefts[i][j] = lefts[i-1][lefts[i-1][j]];
    }
  }

  int q; cin >> q;
  while(q--){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a < b){
      int lo = 0;
      int hi = 1e9;
      int ans = -1;
      while(lo <= hi){
        int mid = hi - (hi-lo)/2;
        int check = right_check(a, mid);
        if (check == -1 || check >= b){
          hi = mid-1;
          ans = mid;
        } 
        else lo = mid+1;
      } 
      cout << ans << endl;
    }
    else {
      int lo = 0;
      int hi = 1e9;
      int ans = -1;
      while(lo <= hi){
        int mid = hi - (hi-lo)/2;
        int check = left_check(a, mid);
        if (check == -1 || check <= b){
          hi = mid-1;
          ans = mid;
        } 
        else lo = mid+1;
      } 
      cout << ans << endl;
    }
  }
  return 0;
}
