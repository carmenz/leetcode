#include <iostream>
#include <vector>
#include <unordered_map>

// nums.size() = 4
// sizeof(nums) = 24

class Solution {
public:
	// O(n^2)
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> sum;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    sum.push_back(i);
                    sum.push_back(j);
                    return sum;
                }
            }
        }
        return sum;
    }

    // O(n) 
    std::vector<int> twoSum2(std::vector<int>& nums, int target) {
    	std::unordered_map<int, int> hashMap;
    	for(int i = 0; i < nums.size(); i++) {
    		hashMap.insert(std::make_pair(nums[i], i));
    	}
    		
    	for(int i = 0; i < nums.size(); i++) {
    		auto j = hashMap.find(target - nums[i]);
    		if (j != hashMap.end() && j->second != i) {
    			return {i, j->second};
    		}
    	}
    	return {};
    }

    // O(n)
    std::vector<int> twoSum3(std::vector<int>& nums, int target) {
    	std::unordered_map<int, int> hashMap{std::make_pair(nums[0], 0)};

    	for(int i = 0; i < nums.size(); i++) {
    		auto j = hashMap.find(target - nums[i]);
    		// segmentation fault if order is swapped due to map::end iterator
    		if (j != hashMap.end() && j->second != i) {

                return {j->second, i};
    		}
    		hashMap.insert(std::make_pair(nums[i], i));
    	}
    	return {};
    }
};

int main(){
	std::vector<int> vect;  
	vect.push_back(4);
	vect.push_back(15);
	vect.push_back(11);
	vect.push_back(7);  
	int target = 15;
	std::vector<int> sum = Solution().twoSum(vect, target);
	std::vector<int> sum2 = Solution().twoSum2(vect, target);
	std::vector<int> sum3 = Solution().twoSum3(vect, target);
	std::cout << "sum 1: ";
	for(int i = 0; i < sum.size(); ++i){
		std::cout << sum[i] << " ";
	}
	std::cout << "\nsum 2: ";
	for(int i = 0; i < sum2.size(); ++i){
		std::cout << sum2[i] << " ";
	}
	std::cout << "\nsum 3: ";
	for(int i = 0; i < sum3.size(); ++i){
		std::cout << sum3[i] << " ";
	}
}


/* 
map has a O(1) time complexity for both get and put.
make_pair(key, value)
a key maps to a hash code which then maps to the index.
The array that stores the data from the hash table is much much smaller than all the variables.
two keys can have different hash code but the same index. -> collision
- when there is a collision, store the pair (key, value) in a linked list.
Potentially, a linear search is needed down the linked list, but this is close to O(1).

map.find() returns an iterator to it if found, otherwise it returns an iterator to map::end.
*/







