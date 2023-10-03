#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string evaluate(string guess, string hidden) {
    string res = "-----";
    int hiddenmap[26];
    for (int i = 0; i < 26; i++) hiddenmap[i] = 0;

    for (int i = 0; i < 5; i++) {
        if (guess[i] == hidden[i]) {
            res[i] = 'G';
            continue;
        }
        hiddenmap[hidden[i]-'A']++;
    }
    for (int i = 0; i < 5; i++) {
        if (res[i] == 'G') continue;
        if (hiddenmap[guess[i]-'A'] > 0) {
            res[i] = 'Y';
            hiddenmap[guess[i]-'A']--;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w; cin >> n >> w;
    vector<string> guess, guess_result;
    vector<string> words;

    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        guess.push_back(s);
        guess_result.push_back(t);
    }

    for (int i = 0; i < w; i++) {
        string s; cin >> s;
        words.push_back(s);
    }
    
    for (int i = 0; i < w; i++) {
        bool valid = 1;
        for (int j = 0; j < n; j++) {
            if (evaluate(guess[j],words[i]) != guess_result[j]) valid = 0;
        }
        if (valid) cout << words[i] << endl;
    }
    
    return 0;
}