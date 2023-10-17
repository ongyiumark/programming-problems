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

string query(int i, int j) {
  cout << "?" << " " << i << " " << j << endl;
  
  string res; cin >> res;
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int i = 0;
  int j = 1;
  int cnt = 0;
  
  while (j <= n) {
    string res = query(i, j);
    if (res == "present") j++;
    else {
      cnt++;
      i = j;
      j = i+1;
    }
  }

  cout << "! " << cnt << endl;
  
  return 0;
}
