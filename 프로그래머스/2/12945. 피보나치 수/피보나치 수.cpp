#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int MOD = 1234567;
    
    // 피보나치 수열의 첫 두 값을 초기화
    int prev2 = 0;  // F(0)
    int prev1 = 1;  // F(1)
    
    // n이 0이나 1이면 바로 반환
    if (n == 0) return prev2;
    if (n == 1) return prev1;
    
    // 피보나치 수열을 반복문으로 계산
    for (int i = 2; i <= n; ++i) {
        int current = (prev1 + prev2) % MOD;  // MOD 연산을 통해 큰 수 문제 해결
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;  // n번째 피보나치 수를 반환
}