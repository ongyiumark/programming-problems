/*
  Count the frequency of the two elements in the two partitions.
  Subtract the highest frequency from the total number of elements.
  If the number with the highest frequency in both partitions are the same, 
    get the second highest (whichever is greater).
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

const int  N = 1e5;
int v[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];

  unordered_map<int,int> evens, odds;
  for (int i = 0; i < n; i++){
    if (i&1) odds[v[i]]++;
    else evens[v[i]]++;
  }

  vector<pii> oddlist, evenlist;
  for (auto it : odds) oddlist.push_back({it.second, it.first});
  for (auto it : evens) evenlist.push_back({it.second, it.first});
  sort(oddlist.begin(), oddlist.end(), greater<pii>());
  sort(evenlist.begin(), evenlist.end(), greater<pii>());

  if (n == 1) cout << 0 << endl;
  else {
    if (oddlist[0].second != evenlist[0].second) cout << n - oddlist[0].first - evenlist[0].first << endl;
    else {
      int subtract = 0;
      if (oddlist.size() > 1) subtract = max(subtract, oddlist[1].first+evenlist[0].first);
      if (evenlist.size() > 1) subtract = max(subtract, evenlist[1].first+oddlist[0].first);
      subtract = max({subtract, oddlist[0].first, evenlist[0].first});
      cout << n -subtract << endl;
    }
  } 
  return 0;
}
