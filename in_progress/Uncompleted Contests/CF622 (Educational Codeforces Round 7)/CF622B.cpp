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
  
  string s; cin >> s;
  int n; cin >> n;
  int hh = stoi(s.substr(0,2));
  int mm = stoi(s.substr(3));

  mm += n;
  hh += mm/60;
  mm %= 60;
  hh %= 24;
  
  cout << setfill('0') << setw(2) << hh;
  cout << ":";
  cout << setfill('0') << setw(2) << mm;
  cout << endl;

  return 0;
}
