/*
  You can flip two bits in two moves by having the same m-1 bits other than the two target bits.
  Thus, if the number of zeroes is even, it can be done in the number_of_zeroes days.
  
  If it's odd and m is even, then it's impossible because any move will change the number of zeros by an even amount.
  If it's odd and m is also odd, then we flip once and we should have an even number of zeros.
    Here we should prioritize all the zeros first so that we can have at most n-1 zeros.
  
  Annoyinh edge case: n = m. 
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

vector<string> solve(string s, int m){
  vector<int> zero;
  int n = s.size();
  for (int i = 0; i < n; i++){
    if (s[i] == '0') zero.push_back(i);
  }
  assert(zero.size()%2 == 0);
  vector<string> ans;
  for (int i = 0; i < zero.size(); i+=2){
    string t1; t1.append(n, '0');
    string t2; t2.append(n, '0');
    int cnt = m-1;
    for (int j = 0; j < n; j++){
      if (j == zero[i]) t1[j] = '1';
      if (j == zero[i+1]) t2[j] = '1';
    }
    for (int j = 0; j < n; j++){
      if (t1[j] == '0' && t2[j] == '0' && cnt > 0){
        t1[j] = t2[j] = '1';
        cnt--;
      }
    }

    ans.push_back(t1);
    ans.push_back(t2);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    
    int zero = count(s.begin(), s.end(), '0');
    if (m == n){
      if (!(zero == 0 || zero == n)) cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS" << endl;
      else if (zero == n){
        cout << 1 << endl;
        string t; t.append(n, '1');
        cout << t << endl;
      }
      else cout << 0 << endl;
      continue;
    }
    if (zero%2 == 0){
      cout << zero << endl;
      vector<string> ans = solve(s, m);
      for (string t : ans) cout << t << endl;
    }
    else {
      if (m%2 == 0) {
        cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS" << endl;
        continue;
      }
      int need = abs(zero-m);
      cout << need+1 << endl;
      string t; t.append(n, '0');
      int cnt = m;
      for (int i = 0; i < n; i++){
        if (cnt > 0 && s[i] == '0'){
          t[i] = '1';
          s[i] = '1';
          cnt--;
        }
      }

      for (int i = 0; i < n; i++){
        if (cnt > 0 && s[i] == '1' && t[i] == '0'){
          t[i] = '1';
          s[i] = '0';
          cnt--;
        }
      }

      cout << t << endl;
      vector<string> ans = solve(s, m);
      for (string t : ans) cout << t << endl;
    }
  }
  return 0;
}
