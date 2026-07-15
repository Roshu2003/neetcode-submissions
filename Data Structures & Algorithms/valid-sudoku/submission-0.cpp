class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        unordered_map<int,unordered_set<char>> row,col;
        map<pair<int,int>,unordered_set<char>> sq;

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(b[r][c] == '.')continue;
                char x = b[r][c];
                pair<int,int> key = {r / 3,c / 3};
                if(row[r].count(x) || col[c].count(x) || sq[key].count(x))return false;
                row[r].insert(x);
                col[c].insert(x);
                sq[key].insert(x);
            }
        }
        return true;
    }
};
