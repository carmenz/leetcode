#include <iostream>

using namespace std;

class Solution {
public:
	// O(n)
	string convert(string s, int numRows) {
        if(numRows == 1) {
        	return s;
        }

        // creates a 2D array
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool nextRow = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
            	nextRow = !nextRow;
            }
            curRow += nextRow ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

int main() {
	char string1[] = "PAHNAPLSIIGYIR"
	cout << "-----Case 1-----" << '\n';
	string output = Solution.convert(string1, 3);
	cout << "output 1: " << output << '\n';

	cout << "-----Case 2-----" << '\n';
	output = Solution.convert(string1, 4);
	cout << "output 1: " << output << '\n';
}