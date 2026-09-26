class Solution {
public:
    bool wordSearch(int row, int col, vector<vector<char>>& board, string word, int word_index){
        // Base case: entire word is matched
        if(word_index == word.size()) return true;

        // FIX: Corrected col check to >= to properly guard the upper boundary
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;

        // Character mismatch
        if(board[row][col] != word[word_index]) return false;
        
        // Mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '*';

        // Explore all 4 directions
        bool output = wordSearch(row, col-1, board, word, word_index+1) || 
                      wordSearch(row, col+1, board, word, word_index+1) || 
                      wordSearch(row -1, col, board, word, word_index+1) || 
                      wordSearch(row+1, col, board, word, word_index+1);

        // Backtrack
        board[row][col] = temp;       
        
        // FIX: Added missing return statement
        return output;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // FIX: Removed 'word == NULL' which causes compilation errors since string is an object
        if(board.empty() || word.empty() || board.size() == 0) return false;

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if(wordSearch(row, col, board, word, 0)) return true;
            }
        }
        
        // FIX: Moved this inside the exist function body
        return false;
    }
};
