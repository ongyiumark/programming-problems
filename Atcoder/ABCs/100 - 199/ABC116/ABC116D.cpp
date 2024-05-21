/*
  It's optimal to choose the k most delicious sushi. 
  Then, trade off 'repeat' sushi (i.e., sushi that you had more than one of)
    for the best of that new type of sushi.

  Simply sort by deliciousness. Keep track of the 'repeat' sushi in a stack.
  If you encounter a new type, subtract from the total the lowest 'repeat' sushi.
    This would be the top of the stack if you went through it in sorted order.
  Add this new sushi to the total and compare the best answer.  
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
const ll INF = 1e18;
pair<ll,ll> sushi[N];
int n, m, k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> sushi[i].second >> sushi[i].first;
  sort(sushi, sushi+n, greater<pair<ll,ll>>());

  ll total = 0;
  unordered_set<int> types;
  stack<ll> repeat;
  for (int i = 0; i < k; i++) {
    total += sushi[i].first;
    if (types.find(sushi[i].second) != types.end()) {
      repeat.push(sushi[i].first);
    }
    types.insert(sushi[i].second);
  }

  ll t = types.size();
  ll best = total + t*t;
  for (int i = k; i < n; i++) {
    if (types.find(sushi[i].second) == types.end() && !repeat.empty()){
      types.insert(sushi[i].second);
      t++;
      total -= repeat.top();
      repeat.pop();
      total += sushi[i].first;

      best = max(best, total + t*t);
    }
  }
  
  cout << best << endl;
  return 0;
}
