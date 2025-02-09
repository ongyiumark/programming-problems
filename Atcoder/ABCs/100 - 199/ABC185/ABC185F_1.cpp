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

const int N = 3e5+5;
const int SQN = 550;
int A[N], SQA[SQN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  memset(SQA, 0, sizeof SQA);
  for (int i = 0; i < n; i++) {
    SQA[i/SQN] ^= A[i];
  }

  while(q--) {
    int t, x, y; cin >> t >> x >> y;
    if (t == 1) {
      // update
      x--;

      SQA[x/SQN] ^= y;
      A[x] ^= y;
    } 
    else {
      // query
      x--; y--;
      int l = x/SQN;
      int r = y/SQN;

      int ans = 0;    
      if (l == r) {
        while(x <= y) ans ^= A[x++];
      }  
      else {
        while(x/SQN == l) ans ^= A[x++];
        while(y/SQN == r) ans ^= A[y--];

        while(l+1 < r) ans ^= SQA[++l];
      }
      cout << ans << "\n"; 
    }
  }
  
  return 0;
}
