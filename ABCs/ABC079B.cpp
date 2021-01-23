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

  int n; cin >> n;
  ll lucas[n+1];
  lucas[0] = 2;
  lucas[1] = 1;
  for (int i = 2; i <= n; i++){
    lucas[i] = lucas[i-1]+lucas[i-2];
  }
  cout << lucas[n] << endl;
  return 0;
}
