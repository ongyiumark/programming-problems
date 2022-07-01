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

int check_type(string& s, char c) {
  int n = s.size();
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    if (s[i] == c) pos.push_back(i); 
  }
  for (int i = 1; i < pos.size(); i++){
    if (pos[i] != pos[i-1]+1) return -1;
  }

  // 0 for both, 1 for start, 2 for end, 3 for middle
  if (pos.size() == n) return 0;
  if (pos[0] == 0) return 1;
  if (pos.back() == n-1) return 2;
  return 3; 
}

void testcase(){
  int n; cin >> n;
  vector<string> towers(n);
  for (int i = 0; i < n; i++) cin >> towers[i];

  for (int k = 0; k < 26; k++) {
    char ch = k+'A';
    // Gather strings with letter ch.
    vector<string> tmp;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      bool val = 0;
      for (int j = 0; j < towers[i].size(); j++) {
        if (towers[i][j] == ch) val = 1;
      }
      if (val) {
        bool rem = 0;
        if (tmp.size()) rem = 1;
        else pos = i;
        tmp.push_back(towers[i]);
        if (rem) towers[i] = "";
      }
    }

    /*
    cout << ch << ": " << endl;
    for (int i = 0; i < tmp.size(); i++) {
      cout << tmp[i] << endl;
    }
    */
    

    // Check if tmp is valid.
    string sword = "", mword = "", eword = "";
    int m = tmp.size();
    for (int i = 0; i < m; i++) {
      int type = check_type(tmp[i], ch);
      //cout << tmp[i] << " " << type << endl;
      if (type == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
      if (type == 3) {
        if (m > 1) {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        else {
          mword += tmp[i];
        }
      }

      if (type == 0) mword += tmp[i];
      if (type == 1) {
        if (sword != "") {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        sword = tmp[i];
      }
      if (type == 2) {
        if (eword != "") {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        eword = tmp[i];
      }
    }

    string res = eword + mword + sword;

    if (m > 0) towers[pos] = res;
    //cout << ch << " " << pos << endl;
    
    /*
    cout << ch << ": " << endl;
    for (int i = 0; i < n; i++) {
      cout << towers[i] << endl;
    }
    */

  }

  for (int i = 0; i < n; i++) {
    cout << towers[i];
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
