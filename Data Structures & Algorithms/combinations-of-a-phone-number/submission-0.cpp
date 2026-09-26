class Solution {
private:
    // Global phone keypad mapping matching array indices to digits 0-9
    const vector<string> phone_map = {
        "",     "",     "abc",  "def",  // 0, 1, 2, 3
        "ghi",  "jkl",  "mno",  "pqrs", // 4, 5, 6, 7
        "tuv",  "wxyz"                  // 8, 9
    };

    void backtrack(const string& digits, int index, string& current_path, vector<string>& combinations) {
        // Base case: if the combination is complete
        if (index == digits.length()) {
            combinations.push_back(current_path);
            return;
        }

        // Convert char to integer index (e.g., '3' -> 3)
        int digit_val = digits[index] - '0';
        const string& possible_letters = phone_map[digit_val];

        // Loop through all letters mapped to the current digit
        for (char letter : possible_letters) {
            current_path.push_back(letter);       // Choose
            backtrack(digits, index + 1, current_path, combinations); // Explore
            current_path.pop_back();              // Unchoose (Backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        
        // Edge case: if input string is empty
        if (digits.empty()) {
            return combinations;
        }

        string current_path = "";
        backtrack(digits, 0, current_path, combinations);
        return combinations;
    }
};
