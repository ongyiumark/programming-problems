/*
  Same idea as the proper one, implemented with bitsets instead.
  Cheese.
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

const int N = 6e4+1;
bitset<2*N+5> holes[3];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n[3];
  for (int i = 0; i < 3; i++){
    cin >> n[i];
    holes[i].reset();
    for (int j = 0; j < n[i]; j++){
      int x; cin >> x;
      x += 30000;
      if (i <= 1) holes[i].set(x);
      else holes[i].set(2*N-x);
    }
  }

  int cnt = 0;
  for (int i = N; i >= 0; i--){
    if (holes[1][i] == 0) {
      holes[2] >>= 2;
      continue;
    }
    cnt += (holes[0]&holes[2]).count();
    holes[2] >>= 2;
  }
  cout << cnt << endl;
  return 0;
}
