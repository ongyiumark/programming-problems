/*
  Greedy algorithm.
  Always match the opponent's paper.
  Count how many papers are left and use up your extras. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
const int N = 1e5+1;
int arr[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  int n = s.size();

  memset(arr, 0, sizeof arr);
  arr[n-1] = s[n-1]=='p';
  for (int i = n-2; i >= 0; i--){
    arr[i] = arr[i+1]+(s[i]=='p');
  }

  int energy = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'g') {
      if (energy > arr[i]) {
        ans++;
        energy--;
      }
      else energy++;  
    }
    if (s[i] == 'p') energy--;
  }

  cout << ans << endl;
  return 0;
}
