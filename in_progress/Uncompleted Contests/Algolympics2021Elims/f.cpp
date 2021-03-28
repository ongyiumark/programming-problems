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

unordered_set<string> us;

string process_word(string s){
  string ret;
  for (char &c : s){
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){
      ret += tolower(c);
    }
  }
  return ret;
}

void split_and_hash(string s){
  size_t pos = 0;
  while((pos = s.find(' ')) != string::npos){
    string word = s.substr(0, pos);
    s.erase(0, pos+1);
    us.insert(process_word(word));
  }
  us.insert(process_word(s));
}

pii count_words(string s){
  size_t pos = 0;
  int words = 0;
  int same = 0;
  while((pos = s.find(' ')) != string::npos){
    string word = s.substr(0, pos);
    s.erase(0, pos+1);
    words++;
    if (us.count(process_word(word)) > 0) same++;
  }
  words++;
  if (us.count(process_word(s)) > 0) same++;
  return {same, words};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int l; cin >> l;
  cin.ignore();
  for (int i = 0; i < l; i++){
    string s; getline(cin, s);
    split_and_hash(s);
  }

  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int m; cin >> m;
    cin.ignore();
    int words = 0;
    int same = 0;
    for (int j = 0; j < m; j++){
      string s; getline(cin, s);
      pii cnts = count_words(s);
      same += cnts.first;
      words += cnts.second;
    }
    if (2*same >= words) cout << "GOOD BOY!\n";
    else cout << "BIG HANDS!\n"; 
  }

  return 0;
}
