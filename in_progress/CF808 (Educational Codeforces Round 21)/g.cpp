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

const int N = 2e5+5;
int p[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t; cin >> s >> t;
  string st = t+"#"+s;
  int n = st.size();
  int L = 0, R = 1;
  p[0] = 0;
  while(R < n) {
    if (st[L] == st[R]) {
      p[R] = L+1;
      L++; R++;
    }
    else if (L > 0 && st[L-1] == st[R-1]) L = p[L-1];
    else {
      p[R] = 0;
      R++;
    }
  }

  cout << st << endl;
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  
  return 0;
}
