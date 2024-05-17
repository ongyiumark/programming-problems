#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool query(string &s) {
  cout << "? " << s << endl;
  bool x; cin >> x;
  return x; 
}

void guess(string &s) {
  cout << "! " << s << endl;
}
int main(){
  cin.tie(0)->sync_with_stdio(false);
  
  int n; cin >> n;

  string t; t.append(n, '0');
  int cx = query(t);  

  int lo = 0;
  int hi = n;
  int ans = 0;

  while (lo <= hi) {
    int mid = hi -(hi-lo)/2;
    string s;
    s.append(mid, '1'); s.append(n-mid, '0');

    bool x = query(s);
    if (x != cx) {
      ans = mid;
      hi = mid-1;
    }
    else {
      lo = mid+1;
    }
  }

  string ss, ans_str;
  if (cx) {
    // more wrong -> more correct at ans
    // n+1 correct, n wrong
    ss.append(ans, '1'); ss.append(n-ans, '0');
    ans_str.append(ans, '1'); ans_str.append(n-ans, '0');
    for (int i = 0; i < n; i++) {
      if (i == ans-1) continue;
      ss[i] = (ss[i] == '0' ? '1' : '0');
      
      bool x = query(ss);
      if (x == cx) ans_str[i] = (ss[i] == '0' ? '1' : '0');
      else ans_str[i] = ss[i];
      
      ss[i] = (ss[i] == '0' ? '1' : '0');
    }
  }
  else {
    // more correct -> more wrong at ans
    // n correct, n+1 wrong
    ss.append(ans, '1'); ss.append(n-ans, '0');
    ans_str.append(ans, '1'); ans_str.append(n-ans, '0');
    ans_str[ans-1] = '0';
    for (int i = 0; i < n; i++) {
      if (i == ans-1) continue;
      ss[i] = (ss[i] == '0' ? '1' : '0');
      
      bool x = query(ss);
      if (x != cx) ans_str[i] = (ss[i] == '0' ? '1' : '0');
      else ans_str[i] = ss[i];
      
      ss[i] = (ss[i] == '0' ? '1' : '0');
    }
  }

  guess(ans_str);
  
  return 0;
}