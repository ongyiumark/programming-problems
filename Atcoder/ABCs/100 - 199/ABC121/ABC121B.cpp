/*
  Just add and check.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, C; cin >> N >> M >> C;
  int B[M]; 
  for (int i = 0; i < M; i++) cin >> B[i];
  int A[N][M];

  int ans = 0;
  for (int i = 0; i < N; i++){
    int total = C;
    for (int j = 0; j < M; j++){
      cin >> A[i][j];
      total += A[i][j]*B[j];
    }
    ans += total > 0;
  }
  cout << ans << endl;
  return 0;
}
