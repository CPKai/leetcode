#include <vector>
using namespace std;

class Solution37 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        writeValue(board, 0, 0);
    }
    
    bool writeValue(vector<vector<char>>& board, int row, int col){

        // row合格值為0~8，9為溢出
        if (row == 9)
        {
            // 返還true與整體writeValue邏輯有關
            // 整個wrtieValue是一個遞迴，唯二true的位置之一。
            // 另一個true需在if判斷條件(writeValue)中取得true，換言之此處是唯一能返還true的位子
            return true;
        }

        // col合格值為0~8，9為溢出，溢出後進入下一列，從0欄開始
        if (col == 9)
        {
            return writeValue(board, row+1, 0);
        }
        
        // 該格為空，需要填值
        if (board[row][col] == '.')
        {
            // 找尋該填入1~9中何值
            for (int inputVal = 1; inputVal < 10; inputVal++)
            {
                // 若不合格就直接進下一圈for
                if (isValid(board, row, col, inputVal))
                {
                    // 合格後直接先填入該值
                    // 因為board是裝char值，以int計算要加上基值(即char 0)
                    board[row][col] = inputVal + '0';

                    // 填完值後確認後續數值填入是否為true(可行)，此處會一直找下一個，想要找到true只有走到row=9的if式內
                    if (writeValue(board, row, col+1))
                    {
                        return true;
                    }
                    else
                    {
                        // 不可行的話將原填入的值改回'.'，讓for繼續測試下一個value
                        board[row][col] = '.';
                    }
                }
            }
            // for迴圈皆 { 非valid 或 valid但後續wrtieValue時return false }
            return false;
        }
        else
        {
            // 該格已有數字，則跳到下一欄
            return writeValue(board, row, col+1);
        }
    }

    bool isValid(vector<vector<char>>& board, int curRow, int curCol, int curVal){

        // 驗證同欄是否有重複值(僅變動列)
        for (int row = 0; row < 9; row++)
        {
            if (board[row][curCol] == curVal+'0')
            {
                return false;
            }
        }

        // 驗證同列是否有重複值(僅變動欄)
        for (int col = 0; col < 9; col++)
        {
            if (board[curRow][col] == curVal+'0')
            {
                return false;
            }
        }
        
        // base series param will be 0 || 3 || 6
        int baseRow = (curRow/3) * 3;
        int baseCol = (curCol/3) * 3;

        // 驗證同group是否有重複值
        for (int row = 0+baseRow; row < 3+baseRow; row++)
        {
            for (int col = 0+baseCol; col < 3+baseCol; col++)
            {
                if (board[row][col] == curVal+'0')
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};