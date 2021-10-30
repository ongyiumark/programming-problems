/*
  Use a hashmap to count the frequency, then sort with a tuple.
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
  int n, k; cin >> n >> k;
  map<string, int> notes;
  map<string, int> idx;
  cin.ignore();
  for (int i = 0; i < 3*n; i++){
    string t;
    getline(cin, t);
    idx[t] = i;
    notes[t]++;
  }

  vector<tuple<int,int,string>> ans;

  for (auto it : notes){
    string t = it.first;
    ans.push_back({notes[t], idx[t], t});
    //cout << notes[t] << " " << idx[t] << " - " << t << endl; 
  } 

  sort(ans.begin(), ans.end(), [](const tuple<int,int,string> &left, const tuple<int,int,string> &right){
    if (get<0>(left) == get<0>(right)){
      return get<1>(left) > get<1>(right);
    }
    return get<0>(left) > get<0>(right);
  });

  for (int i = 0; i < min(k, (int)ans.size()); i++){
    cout << get<2>(ans[i]) << endl;
  }



  return 0;
}
