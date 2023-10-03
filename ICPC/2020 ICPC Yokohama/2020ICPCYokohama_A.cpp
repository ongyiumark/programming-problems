#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long ld;

bool read_char_bool() {
  char ch; cin >> ch;
  return ch == '1';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  bool cube[n][n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        cube[i][j][k] = true;
    
  // read projections
  int yz[n][n], zx[n][n], xy[n][n];
  for (int k = n-1; k >= 0; k--) 
    for (int j = 0; j < n; j++) 
      yz[j][k] = read_char_bool();

  for (int i = n-1; i >= 0; i--) 
    for (int k = 0; k < n; k++) 
      zx[k][i] = read_char_bool();
  
  for (int j = n-1; j >= 0; j--) 
    for (int i = 0; i < n; i++) 
      xy[i][j] = read_char_bool();

  // remove bright projections
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) 
        if (!xy[i][j] || !yz[j][k] || !zx[k][i]) 
          cube[i][j][k] = false;
    
  // check if valid
  bool fxy[n][n], fyz[n][n], fzx[n][n];
  memset(fxy, 0, sizeof fxy); memset(fyz, 0, sizeof fyz); memset(fzx, 0, sizeof fzx);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++){
        if (!xy[i][j]) fxy[i][j] = true;
        else if (xy[i][j] && cube[i][j][k]) fxy[i][j] = true;

        if (!yz[j][k]) fyz[j][k] = true;
        else if (yz[j][k] && cube[i][j][k]) fyz[j][k] = true;

        if (!zx[k][i]) fzx[k][i] = true;
        else if (zx[k][i] && cube[i][j][k]) fzx[k][i] = true;
      }
  
  bool valid = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      valid &= (fxy[i][j] && fyz[i][j] && fzx[i][j]);

  cout << (valid ? "Yes\n" : "No\n");
  return 0;
}