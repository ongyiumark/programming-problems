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

const int N = 1e5+5;
vector<bool> error(N);
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, n; cin >> c >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    error[x] = 1;
  }

  int i = 1;
  int j = 1;
  vector<ii> correct, wrong;

  while (i <= c) {
    while (error[i] == error[j] && j <= c) j++;
    if (error[i]) wrong.push_back({i,j-1});
    else correct.push_back({i, j-1});
    
    i = j;
  } 

  cout << "Errors: ";
  for (int k = 0; k < (int)wrong.size(); k++) {
    auto [l,r] = wrong[k];
    if (l == r) cout << l;
    else cout << l << "-" << r;
    if (k+2 < (int)wrong.size()) cout << ", ";
    else if (k+2 == (int)wrong.size()) cout << " and ";
  }
  cout << endl;

  cout << "Correct: ";
  for (int k = 0; k < (int)correct.size(); k++) {
    auto [l,r] = correct[k];
    if (l == r) cout << l;
    else cout << l << "-" << r;
    if (k+2 < (int)correct.size()) cout << ", ";
    else if (k+2 == (int)correct.size()) cout << " and ";
  }
  cout << endl;

  
  return 0;
}
