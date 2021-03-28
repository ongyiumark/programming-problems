/*
  I tried a dp solution, but i kept getting MLE and TLE.
  I found a more greedy solution.
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
const int N = 5000;
int A[N], B[N];
int a, b;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b;
  for (int i = 0; i < a; i++) cin >> A[i];
  for (int i = 0; i < b; i++) cin >> B[i];

  int j = 0;
  int cnt = 0;
  int ans = 0;
  for (int x = 0; x < b; x++) {
    int i = x;
    j = 0;
    cnt = 0;
    while(i < b && j < a){
      while(j < a && A[j] != B[i]) j++;
      if (j >= a) break;
      i++;
      j++;
      cnt++;
    }

    ans = max(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}
