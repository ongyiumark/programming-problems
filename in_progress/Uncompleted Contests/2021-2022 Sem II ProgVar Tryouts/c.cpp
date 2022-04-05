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
  
  int a[3], b[3];
  for (int i = 0; i < 3; i++) {
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) swap(a[i], b[i]);
  }

  for (int i = 0; i < (1<<3); i++) {
    int tmpA[3], tmpB[3];
    for (int j = 0; j < 3; j++) {
      if ((1<<j)&i) {
        tmpA[j] = a[j];
        tmpB[j] = b[j];
      }
      else {
        tmpA[j] = b[j];
        tmpB[j] = a[j];
      }
    } 

    if (tmpA[0] == tmpA[1] && tmpA[1] == tmpA[2] && tmpA[0] == tmpB[0]+tmpB[1]+tmpB[2]) {
      cout << "YES" << endl;
      return 0;
    }  
    if (tmpA[0] == tmpA[1]+tmpA[2] && tmpA[0] == tmpB[0]+tmpB[1] && tmpB[1] == tmpB[2]) {
      cout << "YES" << endl;
      return 0;
    }
    if (tmpA[2] == tmpA[1]+tmpA[0] && tmpA[2] == tmpB[2]+tmpB[1] && tmpB[1] == tmpB[0]) {
      cout << "YES" << endl;
      return 0;
    }
    if (tmpA[1] == tmpA[0]+tmpA[2] && tmpA[1] == tmpB[1]+tmpB[0] && tmpB[0] == tmpB[2]) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
