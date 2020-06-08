#include <vector>
using namespace std;

class Solution48 {
private:
    int rowNum,colNum;

public:
    void rotate(vector<vector<int>>& matrix) {
        
        // 空matrix處理
        if (matrix.empty())
        {
            return;
        }
        
        rowNum = matrix.size();
        colNum = matrix[0].size();
        // 1,2,3
        // 4,5,6
        // 7,8,9

        // 進行反斜鏡像
        backslopeMirror(matrix);
        // 1,4,7
        // 2,5,8
        // 3,6,9


        // 進行中央垂直鏡像
        centralVerticalMirror(matrix);
        // 7,4,1
        // 8,5,2
        // 9,6,3

    }
    
    void backslopeMirror(vector<vector<int>>& matrix){
        // ＼ * * *
        // * ＼ * *
        // * * ＼ *
        // * * * ＼
        // 雙層for 每輪會轉換最上一row與最左一col (異動範圍=「)
        // 形同直線左上右下鏡面對切
        for (int row = 0; row < rowNum; row++)
        {
            for (int col = row; col < colNum; col++)
            {
                swap(matrix[row][col],matrix[col][row]);
            }
        }
    }

    void centralVerticalMirror(vector<vector<int>>& matrix){
        // * * | * *
        // * * | * *
        // * * | * *
        // * * | * *
        // 雙層for 每輪會轉換該row左側值與右側值
        // 形同直線從中央直切的鏡面
        for (int row = 0; row < rowNum; row++)
        {
            // 以colNum=3 or 4來看，兩者col index最高只能到1即到達一半，故採用/2-1來達成所需
            for (int col = 0; col <= colNum/2-1; col++)
            {
                // if colNum=7  則col index最高只到6，故計算反向時colNum需-1
                swap(matrix[row][col],matrix[row][colNum-1-col]);
            }
        }
    }
};