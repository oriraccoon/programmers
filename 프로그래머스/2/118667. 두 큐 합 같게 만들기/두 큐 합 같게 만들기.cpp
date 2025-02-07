#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1{{begin(queue1), end(queue1)}};
    queue<int> q2{{begin(queue2), end(queue2)}};

    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long target = (sum1 + sum2) / 2;
    
    int max_operations = queue1.size() * 4;
    int count = 0;
    
    if ((sum1 + sum2) % 2 == 1) return -1;

    while (count < max_operations) {    
        if (sum1 < sum2) {
            int a = q2.front();
            q2.pop();
            q1.push(a);
            sum1 += a;
            sum2 -= a;
        }
        else if (sum1 > sum2) {
            int b = q1.front();
            q1.pop();
            q2.push(b);
            sum1 -= b;
            sum2 += b;
        }
        else {
            return count;
        }
        count++;
    }
    return -1;
}
