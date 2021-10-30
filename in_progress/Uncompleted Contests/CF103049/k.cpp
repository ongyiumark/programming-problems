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

  string s, t; 
  getline(cin, s);
  getline(cin, t);
  int n = s.size();
  int m = t.size();
  int i, j, li, lj;
  i = j = li = lj = 0;

  set<char> ans;
  while(i < n && j < m){
    while(i < n && s[i] == s[li]) i++;
    while(j < m && t[j] == t[lj]) j++;  

    //cout << i-li << " " << j-lj << " " << s[li] << " " << t[lj] << endl;
    if (2*(i-li) == (j-lj)) ans.insert(s[li]);
    li = i;
    lj = j;
  }

  for(char ch : ans){
    cout << ch;
  }
  cout << endl;
  
  return 0;
}
