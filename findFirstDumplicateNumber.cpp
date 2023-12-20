#include "util.hpp"

class Solution
{
public:
    int duplicate(vector<int> &numbers)
    {
        if (numbers.size() <= 0)
            return -1;
        for (int i : numbers)
        {
            if (i < 0 || i >= numbers.size() - 1)
                return -1;
        }
        for (int i = 0; i < numbers.size()-1; i++){
            if (numbers[i] == i){
                continue;
            }else{
                while (numbers[i] != i){
                    if (numbers[i] == numbers[numbers[i]]){
                        return numbers[i];
                    }else{
                        int temp = numbers[i];
                        numbers[i] = numbers[temp];
                        numbers[temp] = temp;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> numbers = {2,3,1,0,2,5,3};
    Solution sol;
    int res = sol.duplicate(numbers);
    
    return 0;
}