#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long max_sum = LLONG_MIN;
    long long current_sum = 0;
    int best_left = 0, best_right = 0;
    int current_left = 0;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (current_sum + a[i] >= a[i]) {
            current_sum += a[i];
        } else {
            current_sum = a[i];
            current_left = i;
        }
        
        if (!found || current_sum > max_sum || 
            (current_sum == max_sum && (current_left < best_left || 
             (current_left == best_left && i < best_right)))) {
            max_sum = current_sum;
            best_left = current_left;
            best_right = i;
            found = true;
        }
    }
    
    if (max_sum <= 0) {
        cout << "-1 -1\n";
    } else {
        cout << best_left + 1 << " " << best_right + 2 << "\n";
    }
    
    return 0;
}
