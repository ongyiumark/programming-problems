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

vector<set<string>> dic(100001);
map<string, int> cnt;
set<string> strs;
 
vector<string> split(string s){
  cout << s.size() << ": ";
  vector<string> res;
  if (s.size() == 0) return res;
  size_t pos = s.find(" ");
  while(pos != string::npos){
    res.push_back(s.substr(0, pos));
    s.erase(0, pos+1);
    pos = s.find(" ");
  }
  res.push_back(s);
  return res;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string curr = string(n,'0');
	vector<string> S(n+1);
	S[0] = curr;
	cin.ignore();
	for (int i=0; i<n; i++){
		string s;
		getline(cin, s);
		// cout<<s<<endl;
		vector<string> v = split(s);
		for (int j=0; j<v.size(); j++){
      cout << v[j] << " ";
			int a = stoi(v[j]);
			if (a == 0 && curr[a] == '0') curr[a] = '1';
			else if (a == 0) curr[a] = '0';
			else if (a > 0) curr[a] = '1';
			else curr[-a] = '0';
		}
    cout << endl;
	
		S[i + 1] = curr;
		// cout<<curr<<endl;
	
	}
 
	int x = 0;
	for (int i=0; i<n; i++){
		int d; cin >> d;
		bitset<100005> tmp(S[d]);
		tmp >>= x;
		x = (x + tmp.count()) % n;
	}
	cout<<x<<endl; 
}
