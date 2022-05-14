// Aditya Chandra
#include <bits/stdc++.h>

// short snip
#define ll long long
#define ld long double
#define FOR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define for1(e) FOR(i, 0, e, 1)
#define for2(i, e) FOR(i, 0, e, 1)
#define for3(b, e) FOR(i, b, e, 1)
#define for4(i, b, e) FOR(i, b, e, 1)
#define EACH(x, a) for (auto& x : a)
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define YES "YES"
#define NO "NO"

constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

using namespace std;

void bestFit(vi blocks, int m, vi processes, int n) {
    vi alloc(n, -1);
    for1(n) {
        int best = -1;
        for2(j, m) {
            if (blocks[j] >= processes[i]) {
                if (best == -1)
                    best = j;
                else if (blocks[best] > blocks[j])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            blocks[best] -= processes[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for1(n) {
        cout << "   " << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void firstFit(vi blocks, int m, vi processes, int n) {
    vi alloc(n, -1);
    for1(n) {
        for2(j, m) {
            if (blocks[j] >= processes[i]) {
                alloc[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for1(n) {
        cout << " " << i + 1 << "\t\t"
             << processes[i] << "\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // solve();
    // ll t = 1;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    ll m, n;
    cout << "Enter number of blocks: " << endl;
    cin >> n;
    cout << "Enter number of processes: " << endl;
    cin >> m;

    vi blocks(n), processes(m);

    for1(n) cin >> blocks[i];
    for1(m) cin >> processes[i];

    bestFit(blocks, m, processes, n);
    firstFit(blocks, m, processes, n);
}

/*
//----------------------------------------------------------------

IN
4
4
10 30 40 50
34 32 12 56

//----------------------------------------------------------------

OUT
Enter number of blocks:
Enter number of processes:

Process No.	Process Size	Block no.
   1		34		3
   2		32		4
   3		12		4
   4		56		Not Allocated

Process No.	Process Size	Block no.
 1		34		3
 2		32		4
 3		12		2
 4		56		Not Allocated

 */
