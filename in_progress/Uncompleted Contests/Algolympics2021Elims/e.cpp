/*
  We can keep track of the position of the first letter of each word.
  Then, we can attach a boolean variable to that position to determine if the word is infected.
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

bool infected[300];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c; cin >> c;
  cin.ignore();
  while(c--){
    string s; getline(cin, s);
    memset(infected, 0, sizeof infected);
    int n = s.size();
    
    int last = 0;
    for (int i = 0; i < n; i++){
      if (s[i] == ' ') last = i+1;
      if (isupper(s[i])) infected[last] = 1;
    }

    bool virus = 0;
    for (int i = 0; i < n; i++){
      if (infected[i]) virus = 1;
      if (s[i] == ' ') virus = 0;
      if (virus) cout << (char)toupper(s[i]);
      else cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
