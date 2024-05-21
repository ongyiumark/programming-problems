/*
  Notice that if there is at least one 0 and at least one 1,
    there will be some 0 and 1 next to each other.
  So, we can remove 2*min(num_zero, num_one).
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

string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s;
  int n = s.size();
  int one = count(s.begin(), s.end(), '1');
  cout << 2*min(n-one, one) << endl;
  return 0;
}

