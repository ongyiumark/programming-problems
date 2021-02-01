/*
  It's optimal to use only the strongest wield attack because any wield attack will not change your options.
  
  Suppose a solution involves an some combination of throws and wields.
  It's easy to see that we can rearrange the solution having all the wields first.
    abbabab.. --> ..aaabbb..
  Now we can replace all the wields with the strongest wield attack, say A, to output even more damage.
    ..aaabbb.. <= ..AAAbbb..
  Thus, its optimal to only use the strongest wield attack. Q.E.D.

  From this, we can see that it also doesn't make sense to use any throw attack whose damage is less than A
  because we can simply replace that with A to output more damage.
  Thus, the optimal solution is to use all throws greater or equal to A followed by A any number of times.
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

const int N = 1e5;
vector<pii> katanas;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, h; cin >> n >> h;
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    katanas.push_back({a,1});
    katanas.push_back({b,2});
  }

  sort(katanas.begin(), katanas.end(), greater<pii>());

  int total = 0;
  for (int i = 0; i < 2*n; i++){
    int damage = katanas[i].first;
    int type = katanas[i].second;
    if (type == 2) total += damage;
    else{
      int left = h-total;
      cout << i + (left+damage-1)/damage << endl;
      return 0;
    }
    if (total >= h){
      cout << i+1 << endl;
      return 0;
    }
  }

  return 0;
}
