/*
  The last card in the deck will always be part of the score.
  Player X can force a comparison between W and the last card, or the last card and the second to the last card.
  That is, |W - a_n| or |a_n - a_{n-1}| 

  Player X can't do better than this because, player Y can always force |a_n - a_{n-1}|.
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

const int N = 2000;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, z, w;
  cin >> n >> z >> w;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n == 1) cout << abs(a[0]-w) << endl;
  else cout << max(abs(a[n-1]-w), abs(a[n-2]-a[n-1])) << endl;
  return 0;
}
