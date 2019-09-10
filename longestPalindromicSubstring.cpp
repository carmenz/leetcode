#include <iostream>		// std::cout
#include <algorithm>	// std::max

using namespace std;

class Solution {
public:
	// brute force O(n^3)
	string longestPalindrome(string s) {
		int maxLength = 0;
		string longestP = "";
		for(int i = 0; i < s.length(); ++i) {
		    for(int j = i; j <= s.length(); ++j) {
		        string sub = s.substr(i, j);
		            if(isPalindrome(sub) && sub.length() > maxLength) {
		                maxLength = sub.length();
		                longestP = sub;
		            }
		    }
		}
		return longestP;
	}

	bool isPalindrome(string s)
	{
	    if (s.length() == 0)
	        return false;
	    if (s.length() == 1)
	        return true;
	 
	    int len = s.length() - 1;
	    for (int i = 0; i < s.length() / 2; i++)
	    {
	        if (s[i] != s[len])
	        {
	            return false;
	        }
	        len--;
	    }
	    return true;
	}
	///////////////////////////////////////////////////////////////////////
	// Expand from center O(n^2)
	string longestPalindrome2(string s) {
		int start =0;
		int end = 0;
		if(!s[0]) {
			return "";
		} else {
			for(int center = 0; center < s.size(); center++) {
				int len1 = expandsOutward(center, center, s);
				int len2 = expandsOutward(center, center+1, s);
				// len1 is alway odd
				if(len1 > end - start) {
					start = center - len1/2;
					end = center + len1/2;
				}
				// len2 in effect only when there are two same consecutive characters, 0 otherwise
				if(len2 > end - start) {
                    start = center + 1 - len2/2;
                    end = center + len2/2;
                }
			}
		}
		return s.substr(start, end-start+1);	
    }

    // start from the center, "start" and "end" expands outward to check for matching
    int expandsOutward(int start, int end, string s) {
    	int length = 0;
    	while(start >= 0 && end <= s.size()) {
    		if(s[start] == s[end]) {
    			length = end - start + 1;
    			start--;
    			end++;
    		} else {
    			break;
    		}
    	}
    	return length;
    }
	///////////////////////////////////////////////////////////////////////
    // Same as approach 1 O(n^2), fewer lines of code
    string longestPalindrome3(string s) {
		int start = 0;
		int end = 0;
		if(!s[0]) {
			return "";
		} else {
			for(int center = 0; center < s.size(); center++) {
				int len1 = expandsOutward(center, center, s);
				int len2 = expandsOutward(center, center+1, s);
				
				int len = max(len1, len2);
				if(len > end - start) {
                    start = center -  (len - 1)/2;
                    end = center + len/2;
                }
			}
		}
		return s.substr(start, end-start+1);	
    }
   	///////////////////////////////////////////////////////////////////////
    // dynamic programming O(n^2)
    string longestPalindrome4(string s) {
		int n = s.size();  
    	bool table[n][n]; 
    	memset(table, 0, sizeof(table)); 


    	int maxLength = 1; 
	    for (int i = 0; i < n; ++i) 
	        table[i][i] = true; 
	  
	    // check for substring of length 2. 
	    int start = 0; 
	    for (int i = 0; i < n-1; i++) 
	    { 
	        if (s[i] == s[i+1]) 
	        { 
	            table[i][i+1] = true; 
	            start = i; 
	            maxLength = 2; 
	        } 
	    } 
	    for (int k = 3; k <= n; ++k) 
	    { 
	        for (int i = 0; i < n-k+1 ; i++) 
	        { 
	            // get the end index of substring from start to length k 
	            int j = i + k - 1; 
	  
	            // checking for s[i..j] iff s[i+1..j-1] is a palindrome 
	            if (table[i+1][j-1] && s[i] == s[j]) 
	            { 
	                table[i][j] = true; 
	  
	                if (k > maxLength) 
	                { 
	                    start = i; 
	                    maxLength = k; 
	                } 
	            } 
	        } 
	    }
	    return s.substr(start, maxLength);	
	}

    
};

int main() {
	char string1[] = "cabad";
	cout << "-----Case 1-----" << '\n';
	string output = Solution().longestPalindrome(string1);
	string output2 = Solution().longestPalindrome2(string1);
	string output3 = Solution().longestPalindrome3(string1);
	string output4 = Solution().longestPalindrome4(string1);
	cout << "output 1: " << output << '\n';
	cout << "output 2: " << output2 << '\n';
	cout << "output 3: " << output3 << '\n';
	cout << "output 4: " << output4 << '\n';


	cout << "-----Case 2-----" << '\n';
	char string2[] = "cbbd";
	output = Solution().longestPalindrome(string2);
	output2 = Solution().longestPalindrome2(string2);
	output3 = Solution().longestPalindrome3(string2);
	output4 = Solution().longestPalindrome4(string2);
	cout << "output 1: " << output << '\n';
	cout << "output 2: " << output2 << '\n';
	cout << "output 3: " << output3 << '\n';
	cout << "output 4: " << output4 << '\n';

	cout << "-----Case 3-----" << '\n';
	char string3[] = "pwwkrkw";
	output = Solution().longestPalindrome(string3);
	output2 = Solution().longestPalindrome2(string3);
	output3 = Solution().longestPalindrome3(string3);
	output4 = Solution().longestPalindrome4(string3);
	cout << "output 1: " << output << '\n';
	cout << "output 2: " << output2 << '\n';
	cout << "output 3: " << output3 << '\n';
	cout << "output 4: " << output4 << '\n';
}


// Afterall, len1 checks for odd palindrome and len2 checks for even palindrome
// .size() and .length are the same function, the latter is just more readable than the former







