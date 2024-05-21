/*
  Just sort according the the rules. Learn how to do custom sorting in your language.
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
  int n; cin >> n;
  tuple<string, int, int> arr[n];
  for (int i = 0; i < n; i++){
    string s; int p;
    cin >> s >> p;
    arr[i] = {s,p,i+1};
  }

  sort(arr, arr+n, [](const tuple<string, int, int> left, const tuple<string, int, int> right){
    if (get<0>(left) == get<0>(right)){
      return get<1>(left) > get<1>(right);
    }
    return get<0>(left) < get<0>(right);
  });

  for (int i = 0; i < n; i++){
    cout << get<2>(arr[i]) << endl;
  }
  
  return 0;
}
