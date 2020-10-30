#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  
  int arr[26];
  memset(arr, -1, sizeof arr);

  int l = -1; 
  int r = -1;

  int n = s.size();
  for (int i = 0; i < n; i++){
    int curr = s[i]-'a';
    if (arr[curr] == -1) arr[curr] = i;
    else {
      if (i-arr[curr]+1 <= 3){
        l = arr[curr]+1;
        r = i+1;
        break;
      }
      arr[curr] = i;
    }
  }

  cout << l << " " << r << endl;
  return 0;
}
