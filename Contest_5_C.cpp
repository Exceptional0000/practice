#include <iostream>
 
using namespace std;
 
const long long MOD = 1000000007;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    long long answer = 1;
    
    for (int i = 2; i <= N - 1; i++) {
        answer = (answer * i) % MOD;
    }
    
    if (N > 2) {
        answer = (answer * 500000004) % MOD;  
    }
    
    cout << answer << "\n";
    
    return 0;
}
