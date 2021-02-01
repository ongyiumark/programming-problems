/*
  How do we count the sum of the digits of a number?
  If we construct a graph such that (x,x+1) has an edge of 1 and (x, 10x) has a weight of 0,
  the sum of the digits of x is simply the shortest path from 0 to x.
  This isn't a problem for numbers ending in 9 because the shortest path will reach it the other way.

  Thus, the answer to the problem is the shortest path from 0 to any multiple of k.
  We can compress the graph by taking nodes that are congruent modulo k as the same.
  This is problematic for 0, so we start at 1 instead.
  The answer becomes the distance from 1 to 0, plus 1.

  This can be solved with 01BFS or Dijkstra.
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
int dist[N];
int k;

void solve(int s){
  deque<int> dq;
  dq.push_back(s);
  memset(dist, 63, sizeof dist);
  dist[s] = 0;

  while(!dq.empty()){
    int u = dq.front();
    dq.pop_front();
    int v1 = (u+1)%k;
    int v2 = (u*10)%k;

    if (dist[u]+1 < dist[v1]){
      dist[v1] = dist[u]+1;
      dq.push_back(v1);
    }
    if (dist[u] < dist[v2]){
      dist[v2] = dist[u];
      dq.push_front(v2);
    }
  }
}
unordered_map<int, bool> seen;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k;
  solve(1);
  cout << dist[0]+1 << endl;
  return 0;
}
