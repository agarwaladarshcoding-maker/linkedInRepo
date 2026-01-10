#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    // Logic:
    // We need to find the k-th integer not divisible by n.
    // In the sequence of integers, every n-th number is divisible by n.
    // This means in every block of n numbers, (n-1) are valid.
    // We calculate how many 'skips' we need to make to reach the k-th valid number.
    
    long long ans = k + (k - 1) / (n - 1);

    cout << ans << endl;
}

int main() {
    // Fast I/O for performance and important for CP
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}