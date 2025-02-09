/*
  Case Bashing. It's always possible when A + B + C >= 2 and the start is possible.
  Look forward one to make sure you always keep everything possible.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll val[3];
const int N = 1e5+5;
vector<string> ar;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < 3; i++) cin >> val[i];
  ar.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  ll total = 0;
  for (int i = 0; i < 3; i++) total += val[i];

  if (total == 0) {
    cout << "No" << endl;
    return 0;
  }

  if (total == 1) {
    bool valid = 1;
    vector<char> ans(n);
    for (int i = 0; i < n; i++) {
      if (val[ar[i][0]-'A'] == 0 && val[ar[i][1]-'A'] == 0) {
        valid = 0;
        break;
      }
      if (val[ar[i][0]-'A'] == 0) {
        ans[i] = ar[i][0];
        val[ar[i][0]-'A']++;
        val[ar[i][1]-'A']--;
      }
      else {
        ans[i] = ar[i][1];
        val[ar[i][0]-'A']--;
        val[ar[i][1]-'A']++;
      }
    }

    if (valid) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
      }
    }
    else {
      cout << "No\n";
    }
    return 0;
  }


  if (val[ar[0][0]-'A'] == 0 && val[ar[0][1]-'A'] == 0) {
    cout << "No\n";
  }
  else {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      if (val[ar[i][0]-'A'] == 0) {
        cout << ar[i][0] << "\n";
        val[ar[i][0]-'A']++;
        val[ar[i][1]-'A']--;
      }
      else if (val[ar[i][1]-'A'] == 0){
        cout << ar[i][1] << "\n";
        val[ar[i][0]-'A']--;
        val[ar[i][1]-'A']++;
      }
      else if (val[ar[i][0]-'A'] == 1 && val[ar[i][1]-'A'] == 1 && i+1 < n && ar[i] != ar[i+1]) {
        vector<int> has(3);
        for (char ch : ar[i]) has[ch-'A']++;
        for (char ch : ar[i+1]) has[ch-'A']++;

        for (char ch : ar[i]) {
          if (has[ch-'A'] > 1) {
            cout << ch << "\n";
            val[ch-'A']++;
          }
          else {
            val[ch-'A']--;
          }
        }
      }
      else if (val[ar[i][0]-'A'] <= val[ar[i][1]-'A']) {
        cout << ar[i][0] << "\n";
        val[ar[i][0]-'A']++;
        val[ar[i][1]-'A']--;
      }
      else {
        cout << ar[i][1] << "\n";
        val[ar[i][0]-'A']--;
        val[ar[i][1]-'A']++;
      }
    }
  }
  

  return 0;
}
