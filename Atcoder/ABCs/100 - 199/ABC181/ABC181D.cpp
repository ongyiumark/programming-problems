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

string convert(int x) {
  string x_str = to_string(x);
  if (x_str.size() == 3) return x_str;

  string res = "";
  res.append(3-x_str.size(), '0');
  res = res + x_str;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  if (s.size() <= 5) {
    sort(s.begin(), s.end());
    bool found = false;
    do {
      int s_int = stoi(s);
      if (s_int % 8 == 0) found |= true;
    }
    while (next_permutation(s.begin(), s.end()));
    cout << (found ? "Yes" : "No") << "\n";
    return 0;
  }

  vector<int> freq(10);
  for (char ch : s) freq[ch-'0']++;

  bool found = false;
  for (int x = 0; x < 1000; x += 8) {
    string t = convert(x);
    vector<int> nfreq(10);
    for (char ch : t) nfreq[ch-'0']++;

    bool valid = true;
    for (int i = 0; i < 10; i++) valid &= (nfreq[i] <= freq[i]);
    found |= valid;
  }

  cout << (found ? "Yes" : "No") << "\n";
  
  return 0;
}
