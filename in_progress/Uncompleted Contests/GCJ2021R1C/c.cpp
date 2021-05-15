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

string s, e;
string notstr(string t){
  for (char &c : t){
    if (c == '0') c = '1';
    else c = '0';
  }
  if (t.find('1') == -1) return "0"; 
  int pos = t.find('1');
  return t.substr(pos);
}

void testcase(){
  cin >> s >> e;
  if (s.size() > 10 || e.size() > 10){
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  
  unordered_set<string> seen;
  queue<string> q;
  q.push(s);
  int moves = 0;
  int currlayers = 1;
  int nextlayers = 0;
  seen.insert(s);

  while(!q.empty()){
    string curr = q.front();
    q.pop();
    if (curr == e) {
      cout << moves << endl;
      return;
    }
    string dubstr = curr;
    if (dubstr != "0") dubstr.append(1, '0');
    string other = notstr(curr);
    if (seen.find(dubstr) == seen.end() && dubstr.size() <= 20){
      q.push(dubstr);
      seen.insert(dubstr);
      nextlayers++;
    } 
    if (seen.find(other) == seen.end()){
      q.push(other);
      seen.insert(other);
      nextlayers++;
    }

    currlayers--;
    if (currlayers == 0){
      currlayers = nextlayers;
      nextlayers = 0;
      moves++;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
