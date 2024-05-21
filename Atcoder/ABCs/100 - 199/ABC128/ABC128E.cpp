/*
  Let's say a person starts at time d.
  Then, we simply need to find the first roadblock such that s <= d+x < t.
    By first roadblock, we mean the smallest x.
    The distance travelled would be x.

  We can rearrange this inequality to s-x <= d < t-x.
  Now, we can put all the (s-x) and all the (t-x) in one array and sort them,
    keeping track of x and whether or not its a start or an end.
  
  We can then linearly sweep through this array (two-pointers) to find which roadblocks would block the person.
  To get the minimum x, we can maintain a set.
  If we encounter a start time, we insert the corresponding x into the set.
  If we encounter an end time, we remove the corresponding x from the set.

  The answer is the the smallest number in the set. 
  If there are no elements in the set, then the person works forever.
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

const int N = 2e5+5;
struct roadblock{
  ll val,x;
  bool type;

  bool operator < (const roadblock &other) const{
    if (val == other.val){
      return type < other.type;
    }
    return val < other.val;
  }
};

vector<roadblock> block;
ll D[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    ll s, t, x; cin >> s >> t >> x;
    block.push_back({s-x, x, 1});
    block.push_back({t-x, x, 0});
  }
  for (int i = 0; i < q; i++) cin >> D[i];

  sort(block.begin(), block.end());

  set<ll> tracker;
  int j = 0;
  for (int i = 0; i < q; i++){
    // find a block where s <= x + D[i] < t
    // find a block where s-x <= D[i] < t-x
    while (j < 2*n && block[j].val <= D[i]){
      if (block[j].type == 1) tracker.insert(block[j].x);
      else tracker.erase(tracker.find(block[j].x));
      j++;
    }
    if (tracker.size() == 0) cout << -1 << endl;
    else cout << *tracker.begin() << endl;
  }
  return 0;
}
