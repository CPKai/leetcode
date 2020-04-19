#include <vector>
#include <string>

using namespace std;

class Solution17 {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a','b','c'};
        d[3] = {'d','e','f'};
        d[4] = {'g','h','i'};
        d[5] = {'j','k','l'};
        d[6] = {'m','n','o'};
        d[7] = {'p','q','r','s'};
        d[8] = {'t','u','v'};
        d[9] = {'w','x','y','z'};



        vector<string> res = {""};
        if (digits.empty())
        {
            return {};
        }
        

        // BFS algorithm，廣度優先，一層一層彺下
        for (char digit : digits)
        {
            // 建立一個空vector<string>，準備裝「當前層」的運算結果
            vector<string> temp;

            // 第一圈res會有一個空字串成為s，此處res代表「前一層的字串」 ps:每一層為一個vector<string>
            for (string s : res)
            {
                // '2' = 51  當減去'0'可成功match到d[2]的區段，或可找其他手段讓digit直接轉int
                for (char c : d[digit - '0'])
                {
                    // 當前層新增字串，自字串內容為s+c
                    temp.push_back(s+c);
                }
            }
            // 當前層運算完後，與res交換
            res.swap(temp);
        }
        
        //                      ""
        //      "a",            "b",            "c"
        // "ad","ae","af","bd","be","bf","cd","ce","cf"






        return res;
    }

};