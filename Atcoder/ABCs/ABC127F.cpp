/*
  This is a rolling median problem.
  This is because the x that minimizes |x-a1| + |x-a2| + ... is the median of
    {a1, a2, ...}.
  Note that b1, b2, b3, ... just add to the final total, so we can just keep track of their sum as they come.

  We can get the median with an ordered_set, but the 'traditional way' is with two priority queues.
    That is, one max heap and one min heap.
    This can also be done with a fenwick tree.

  We can then compute for the change in 'distance' when the median changes.
  It turns out that the median only changes when it increases.
  When the median get bigger, we simply subtract the distance from the previous median to the current median.
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
  int q; cin >> q;
  ll totala = 0, totalb = 0;
  ll currmed, prevmed;
  currmed = prevmed = 1e10;
  priority_queue<ll> lpq;
  priority_queue<ll, vector<ll>, greater<ll>> rpq;

  while(q--){
   int x; cin >> x;
   if (x == 1){
    ll a, b; cin >> a >> b;
    totalb += b;

    if (currmed == 1e10) currmed = a;
    else {
      totala += abs(currmed-a);
    }
    rpq.push(a);
    if (lpq.size() < rpq.size()){
      lpq.push(rpq.top());
      rpq.pop();
    }
    else if (lpq.top() > rpq.top()){
      rpq.push(lpq.top());
      lpq.pop();
      lpq.push(rpq.top());
      rpq.pop();
    }

    if (!lpq.empty()){
      prevmed = currmed;
      currmed = lpq.top();
      if (prevmed < currmed){
        totala -= abs(currmed-prevmed);
      }
    }

   } 
   else {
     cout << currmed << " " << totalb + totala << endl; 
   }
  }
  return 0;
}
