#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
    int count = 0;
    for(int i = 0; i < nums.size()-2; i++){
        for(int j = i + 1; j < nums.size()-1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                if(!((i == j) && (i == k) && (j == k))){
                    int sum = nums[i] + nums[j] + nums[k];
                    bool isPrime = true;
                    for(int m = 2; m <= sqrt(sum); m++){
                        if(sum % m == 0){
                            isPrime = false;
                            break;
                        }   
                    }
                    if(isPrime)
                        count++;
                }
                                            
            }
        }
    }
    
    cout << count << endl;

    return count;
}