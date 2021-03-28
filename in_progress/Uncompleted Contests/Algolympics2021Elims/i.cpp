/*
  We can check if crewmate i can be eliminated one by one.
  Crewmate i can be eliminated if when we put all the remaining votes against that crewmate, his total is greater than the rest.
    We can check this by simply comparing the new vote count of crewmate i to the maximum of the old vote counts.
    However, we need separately consider the crewmate whose vote count was the old maximum.
      If we have 0 remaining votes, this crewmate can only be eliminated if he's the only one with that number of votes.
  
  Now, it is possible for noone to be eliminated if we can tie any vote.
  So, check if the old vote count plus all the remaining votes is greater than or equal to the maximum.
    This works because we can just assume the everyone will abstain once we equalize.
  However, if the abstain count is the highest, then we don't need to check for ties.
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

void solve(){
  int n; cin >> n;
  vector<int> votes(n+1);
  int no_vote = 0;
  for (int i = 1; i <= n; i++){
    int v; cin >> v;
    if (v != -1) votes[v]++;
    else no_vote++;
  }

  int hi = 0;
  int curr_hi = 0;
  for (int i = 0; i <= n; i++){
    if (hi < votes[i]) {
      hi = votes[i];
      curr_hi = i;
    }
  }

  vector<int> ans;
  // check if 0 is possible
  bool zero = 0;
  for (int i = 0; i <= n; i++){
    if (curr_hi == i) {
      if (i == 0) zero = 1;
      continue;
    }
    if (votes[i] + no_vote >= hi) zero = 1;
  }

  if (zero) ans.push_back(0);

  // check if 1 to n is possible
  int hicnt = 0;
  for (int i = 0; i <= n; i++){
    if (votes[i] == hi) hicnt++;
  }

  for (int i = 1; i <= n; i++){
    if (curr_hi == i && no_vote == 0 && hicnt == 1) ans.push_back(i);
    if (votes[i]+no_vote > hi) ans.push_back(i);
  }

  for (int i = 0; i < (int)ans.size(); i++){
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
