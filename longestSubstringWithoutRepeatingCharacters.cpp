#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
	// O(n^2)
    int lengthOfLongestSubstring(string s) {
    	int count = 1;
    	int maxcount = 1;
    	int j_start = 0;
    	if(!s[0]) {
    		return 0;
    	} else if (!s[1]) {
    		return 1;
    	}
        for(int i=1; i<s.size(); i++) {
        	for(int j=j_start; j<i; j++){
        		if(s[i] != s[j]) {
        			count++;
        		} else {
        			j_start = j+1;
        		}
        	}
        	if(maxcount < count) {
    			maxcount = count;
    		}
    		count = 1;
        }
        return maxcount;
    }

	// O(n)
    int lengthOfLongestSubstring2(string s) {
    	int maxcount = 0;
    	int j_start = 0;
    	map<char, int> myMap;
    	for(int i=0; i<s.size(); i++) {
    		// if string is found, reset the start position
    		if(myMap.find(s[i]) != myMap.end()) {
    			j_start = max(j_start, myMap[s[i]] + 1);
    		}
    		// add it to myMap, keeps track of the last index of each character
    		myMap[s[i]] = i;
    		maxcount = max(maxcount, i - j_start + 1);

    	}
    	return maxcount;
    }
};


int main() {
	char string1[] = "abcabcbb";
	cout << "-----Case 1-----" << '\n';
	int count = Solution().lengthOfLongestSubstring(string1);
	int count2 = Solution().lengthOfLongestSubstring2(string1);
	cout << "count 1: " << count << '\n';
	cout << "count 2: " << count2 << '\n';


	cout << "-----Case 2-----" << '\n';
	char string2[] = "bbbbb";
	count = Solution().lengthOfLongestSubstring2(string2);
	count2 = Solution().lengthOfLongestSubstring2(string2);
	cout << "count 1: " << count << '\n';
	cout << "count 2: " << count2 << '\n';

	cout << "-----Case 3-----" << '\n';
	char string3[] = "pwwkew";
	count = Solution().lengthOfLongestSubstring2(string3);
	count2 = Solution().lengthOfLongestSubstring2(string3);
	cout << "count 1: " << count << '\n';
	cout << "count 2: " << count2 << '\n';
}


/*
Map is a container that stores an element with a key (key, elem)
To initialize:
std::map<char,int> myMap;

To store elements:
mymap['a'] = 50;
mymap['b'] = 100;

To access the key:
myMap.find('a')->second;
myMap.find() returns a const_iterator if found, myMap.end() otherwise.
*/


