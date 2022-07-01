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

const int N = 1e7+5;
vector<bool> is(N);
vector<int> primes;

void sieve() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] < N; j++) {
      is[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }
}

const int M = 105;
int idx[M], partner[M];
int vis[M];

vector<int> x(M);
vector<int> d;
vector<int> graph[M];

void decide(int u) {
  if (graph[u].size() == 0) return;
  vis[u] = 1;
  while (idx[u] < graph[u].size() && partner[graph[u][idx[u]]] == -1) {
    idx[u]++;
  }
  if (idx[u] == graph[u].size()) {
    int v = graph[u][idx[u]-1];
    int other = partner[v];
    partner[v] = u;
    partner[u] = v;
    partner[other] = -1;
    if (vis[other] != 1) decide(other); 
    return;
  }

  int v = graph[u][idx[u]];
  partner[u] = v;
  partner[v] = u;
  vis[u] = 2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  sieve();
  is[1] = 1;
  is[2] = 1;

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (i == 0) {
      d.push_back(x[i]);
      d.push_back(x[i]+1);
    }
    else if (x[i-1] == x[i]-1) d[d.size()-1] = x[i]+1;
    else {
      d.push_back(x[i]);
      d.push_back(x[i]+1);
    }
  }

  int even = 0, odd = 0;
  int sz = d.size();
  for (int i = 0; i < sz; i++) {
    if (d[i]&1) odd++;
    else even++;
    //cout << "TEST " << d[i] << endl; 
  }

  for (int i = 0; i < sz; i++) {
    for (int j = i+1; j < sz; j++) {
      if(!is[d[j]-d[i]]){
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }

  memset(idx, 0, sizeof idx);
  memset(partner, -1, sizeof partner);
  memset(vis, 0, sizeof vis);
  
  for (int i = 0; i < n; i++) {
    decide(i);
  }

  int cnt = 0;
  for (int i = 0; i < sz; i++) {
    if (partner[i] == -1) continue;
    //cout << d[i] << " " << d[partner[i]] << endl;
    cnt++;
  }

  int ans = cnt + (odd-cnt)/2*2 + (even-cnt)/2*2 + (((even-cnt)%2 == 1 || (odd-cnt)%2 == 1) ? 1 : 0)*3;
  cout << ans << endl;
  return 0;
}
