/*
  Merge consecutive shows in the same channel.
  Then, end each time one second later.
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
int channels[31][N];
vector<pii> times;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(channels, 0, sizeof channels);
  int n, c; cin >> n >> c;
  for (int i = 0; i < n; i++){
    int s, t, c;
    cin >> s >> t >> c;
    channels[c][s]++;
    channels[c][t]--;
  }
  for (int i = 1; i <= 30; i++){
    for (int j = 1; j < N; j++){
      channels[i][j] += channels[i][j-1];
    }
    int j = 0;
    while(j < N){
      while(j < N && channels[i][j] == 0)
        j++;
      if (j == N) break;
      times.push_back({j, 1});
      while(j < N && channels[i][j] == 1)
        j++;
      times.push_back({j+1, -1});
    }
  }
  sort(times.begin(), times.end());
  int ans = 0;
  int cans = 0;
  for (int i = 0; i < (int)times.size(); i++){
    cans += times[i].second;
    ans = max(ans, cans);
  }
  cout << ans << endl;
  return 0;
}
