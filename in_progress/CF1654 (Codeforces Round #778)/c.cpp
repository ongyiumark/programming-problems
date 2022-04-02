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
multiset<ll> a;

void testcase(){
  int n; cin >> n;
  a.clear();
  ll total = 0;
  for (int i = 0; i < n; i++) {
    ll tmp; cin >> tmp;
    a.insert(tmp);
    total += tmp;
  }

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  pq.push(total);
  while (!pq.empty()){
    ll top = pq.top();

    auto it = a.find(top);
    if (it == a.end()){
      if (top == 1) {
        cout << "NO" << endl;
        return;
      }
      pq.pop();
      auto it1 = a.find(top/2);
      if (it1 != a.end()) a.erase(it1);
      else pq.push(top/2);

      auto it2 = a.find((top+1)/2);
      if (it2 != a.end()) a.erase(it2);
      else pq.push((top+1)/2);
    }
    else {
      a.erase(it);
      pq.pop();
    }
  }

  cout << "YES" << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
