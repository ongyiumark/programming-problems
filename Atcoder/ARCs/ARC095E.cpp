/*
    Notice that swapping rows and columns are commutative, 
      so try permutations of columns first, then check if the rows are valid.
    
    You can check if the rows are valid by pairing up strings with its reverse.
    If there are even rows, each string must have a pair.
    If there are odd rows, then only one string doesn't have a pair.

    For the columns, we don't have to try all 12! permutations. 
    We simply need to pair up indices since permutations with the same (j, w-1-j) pairs are equivalent.
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

vector<int> perm;
int h, w;
bool found = false;
vector<string> words(12);

void solve(){
    vector<string> nwords(h);
    for (int i = 0; i < h; i++){
        char tmp[w];
        int idx = 0;
        if (w%2 == 1){
            tmp[w/2] = words[i][perm[0]];
            for (int j = 1; j < w; j+=2, idx++){
                tmp[idx] = words[i][perm[j]];
                if (j+1 < w) tmp[w-1-idx] = words[i][perm[j+1]];
            }
        }
        else {
            for (int j = 0; j < w; j+=2, idx++){
                tmp[idx] = words[i][perm[j]];
                if (j+1 < w) tmp[w-1-idx] = words[i][perm[j+1]];
            }
        }

        string tmpstr;
        for (int j = 0; j < w; j++){
            tmpstr += tmp[j];
        }
        nwords[i] = tmpstr;
    }

    // check if paired
    set<int> paired;
    for (int i = 0; i < h; i++){
        if (paired.find(i) != paired.end()) continue;
        string tmp = nwords[i];
        reverse(tmp.begin(), tmp.end());
        for (int k = 0; k < h; k++){
            if (paired.find(k) != paired.end()) continue;
            if (i == k) continue;
            
            if (tmp == nwords[k]){
                paired.insert(i);
                paired.insert(k);
                break;
            }
        }
    }

    if ((h%2==0 && paired.size()==h) || (h%2==1 && paired.size()==h-1)) {
        cout << "YES" << endl;
        found = true;
    }

}

void print_debug(){
    for (int j = 0; j < w; j++) cout << perm[j] << " ";
    cout << endl;
}

void generate_permutations(int i){
    if (found) return;
    if (i >= w){
        solve();

        //print_debug();
        return;
    }

    if (w%2 == 1 && i == 0){
        for (int j = 0; j < w; j++){
            swap(perm[i], perm[j]);
            generate_permutations(i+1);
            swap(perm[i], perm[j]);
        }
        return;
    }

    for (int j = i+1; j < w; j++){
        swap(perm[i+1], perm[j]);
        generate_permutations(i+2);
        swap(perm[i+1], perm[j]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        cin >> words[i];
    }
    
    perm.resize(w);
    iota(perm.begin(), perm.end(), 0);
    generate_permutations(0);

    if (!found) cout << "NO" << endl;
    return 0;
}