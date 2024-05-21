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

int ceildiv(int a, int b) { return (a+b-1)/b; }
int main(){
  cin.tie(0)->sync_with_stdio(false);

  int n, d; cin >> n >> d;
  cout << ceildiv(n, 2*d+1) << "\n";
  
  return 0;
}
