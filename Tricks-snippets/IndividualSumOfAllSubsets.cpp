#include<bits/stdc++.h>
using namespace std;

#define MAX_NUM_VALUE 100
#define MAX_ARRAY_SIZE 200
#define BITSET_SIZE ((MAX_NUM_VALUE * MAX_ARRAY_SIZE) / 2 + 1)

bitset<10001> individualSumOfAllSubsets(vector<int>& nums) {
    bitset<BITSET_SIZE> bits(1);
    int sum = 0;
    for (auto n : nums) {
        sum += n;
        bits |= (bits << n);
    }
    // for(int i = 0; i <= 10000; ++i){
    //     if(bits[i] == 1) {
    //         cout << i << " " << bits[i] << endl;
    //     }
    // }
    return bits;
}


int main() {
    vector<int> nums = {0, 3, 332, 2};
    individualSumOfAllSubsets(nums);
}
/*
0 1
2 1
3 1
5 1
332 1
334 1
335 1
337 1
*/
