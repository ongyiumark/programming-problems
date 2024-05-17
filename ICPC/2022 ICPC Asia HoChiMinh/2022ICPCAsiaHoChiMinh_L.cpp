#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &freq, int k, char prev, int cnt) {
  int largest = 0;
  int total = 0;

  char largest_char = '$';
  for (int i = 0; i < 26; i++) {
    if (freq[i] > largest) {
      largest = freq[i];
      largest_char = i+'a';
    }
    total += freq[i];
  }
  
  int cnt_largest = 0;
  for (int i = 0; i < 26; i++) {
    if (largest == freq[i]) cnt_largest++;
  }
  if (prev != largest_char || cnt_largest > 1) return (largest+k-2)/(k-1)-1 <= total-largest;
  else return (freq[largest_char-'a']+cnt+k-2)/(k-1)-1 <= total-largest;
}

void testcase() {
  string s; cin >> s;
  int k; cin >> k;
  if (k == 1) {
    cout << "OH NO!\n";
    return;
  }

  vector<int> freq(26);
  for (char &ch : s) freq[ch-'a']++;
  if (!possible(freq, k, '$', 0)) {
    cout << "OH NO!\n";
    return;
  }

  int n = s.size();
  string ans;
  char prev = '$';
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (freq[j] == 0) continue;
      if (prev == j+'a' && cnt == k-1) continue;
      freq[j]--;
      if (possible(freq, k, j+'a', (prev == j+'a' ? cnt+1 : 1))) {
        ans.append(1, j+'a');
        if (prev != j+'a') {
          prev = j+'a';
          cnt = 1;
        }
        else cnt++;
        break;
      }
      freq[j]++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while (t--) testcase();

  return 0;
}
