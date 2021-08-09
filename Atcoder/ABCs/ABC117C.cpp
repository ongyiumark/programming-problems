/*
  Notice that moving one direction is optimal so that we don't retrace steps.
  So, think about the problem with the pieces all moving right.

  We want to put the pieces in front of the n largest jumps.
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

const int N = 1e5+5;
int X[N];
pii diff[N];
int n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> X[i];
  
  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }

  sort(X, X+m);

  diff[0] = {1e7, 0};
  for (int i = 1; i < m; i++){
    diff[i] = {X[i]-X[i-1], i};
  }  

  sort(diff, diff+m, greater<pii>());
  vector<int> places;
  for (int i = 0; i < n; i++){
    places.push_back(diff[i].second);
  }
  sort(places.begin(), places.end());
  int total = 0;
  for (int i = 1; i < places.size(); i++){
    total += X[places[i]-1] - X[places[i-1]];
  }
  total += X[m-1] - X[places.back()];
  cout << total << endl;
  return 0;
}
