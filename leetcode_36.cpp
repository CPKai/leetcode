#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> tempBoard = board;

        unordered_map<char,int> unorMap;

        // 一行一行掃  9橫排
        for (int row = 0; row < 9; row++)
        {
            unorMap = {};
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    unorMap[board[row][col]]++;
                    if (unorMap[board[row][col]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        
        // 一欄一欄掃，共9欄
        for (int col = 0; col < 9; col++)
        {
            unorMap = {};
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] != '.')
                {
                    unorMap[board[row][col]]++;
                    if (unorMap[board[row][col]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        
        // 一格一格掃，共9格
        for (int rowBase = 0; rowBase < 3; rowBase++)
        {
            for (int colBase = 0; colBase < 3; colBase++)
            {
                unorMap = {};
                for (int row = 0+rowBase*3; row < 3+rowBase*3; row++)
                {
                    for (int col = 0+colBase*3; col < 3+colBase*3; col++)
                    {
                        if (board[row][col] != '.')
                        {
                            unorMap[board[row][col]]++;
                            if (unorMap[board[row][col]] > 1)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};