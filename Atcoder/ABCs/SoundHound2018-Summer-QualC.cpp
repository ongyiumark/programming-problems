/*
  Notice that the question is asking for the expected value of the sum of (m-1) pairs that satisfy the condition.
  Because of the linearity of the expectation, this is equivalent to thes sum of the expected value of (m-1) pairs.
  That is, the probability that two numbers from [1,n] have a difference of d, multiplied by (m-1).
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, d; cin >> n >> m >> d;
  cout << setprecision(10) << fixed << (d == 0 ? (ld)(m-1)/n : (ld)(m-1)*2*(n-d)/(n*n)) << endl;
  return 0;
}
