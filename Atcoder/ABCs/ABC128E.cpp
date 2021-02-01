#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;

struct roadwork {
  int time, type, val;
};

struct CompareRoad{
  bool operator() (const roadwork& a, const roadwork& b){
    return a.time > b.time;
  }
};

priority_queue<roadwork, vector<roadwork>, CompareRoad > works;
multiset<int> closed;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++){
    int s, t, x;
    cin >> s >> t >> x;
    works.push({s-x, 1, x});
    works.push({t-x, -1, x});
  }

  for (int i = 0; i < q; i++){
    int d; cin >> d;
    while(!works.empty() && works.top().time <= d){
      auto curr = works.top();
      int type = curr.type;
      int val = curr.val;
      if (type == 1) closed.insert(val);
      else closed.erase(closed.find(val));
      works.pop();
    }

    if (closed.size()) cout << *closed.begin() << endl;
    else cout << -1 << endl;
  }
  return 0;
}
