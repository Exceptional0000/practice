#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long answer = 0;
    
    for (int k = 2; k < n; k++) {
        int i = 0;
        int j = k - 1;
        
        while (i < j) {
            if (a[i] + a[j] > a[k]) {
                answer += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
