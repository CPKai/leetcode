#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution30 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        // 建立return 用變數
        vector<int> res;

        // input字串長=0 || words為空vector || words中的字串組合後長度>input字串長度
        if (s.length() == 0 || words.size() == 0 || words[0].length()*words.size() > s.length())
        {
            return res;
        }
        
        int sLength = s.length();
        int wordsSize = words.size();
        int wordLength = words[0].length();

        // 組建map
        unordered_map<string, int> word;
        for (int i = 0; i < wordsSize; i++)
        {
            word[words[i]]++;
        }
        
        // 等等迴圈內要使用的變數
        int j = 0;
        string w = "";

        // 假設words內字串合計長為10，i從0開始，i< input字串長度-10+1
        // (假設input字串長為10且剛好match words中所有字串，10-10=0 故可知此條件需+1)
        for (int i = 0; i < sLength-(wordLength*wordsSize)+1; i++)
        {
            // 建立進行比對使用的unordered_map，同樣位子的值不可>比對用的字典(即unordered_map word)
            unordered_map<string, int> runtimeMap;

            // 為j值歸0
            j = 0;
            while (j < wordsSize)
            {
                // 取出與word相同長度的字串來比較
                w = s.substr(i+(j*wordLength), wordLength);

                // 比對該word是否出現在字典中
                if (word.find(w) != word.end())
                {
                    // 配對成功，將比對用的字典欄位該word出現次數++
                    runtimeMap[w]++;
                    if (runtimeMap[w] > word[w])
                    {
                        // 成功配對word，但該word出現次數>字典內的次數，故此圈失敗
                        break;
                    }
                }
                else
                {
                    // 截取的字串與word配對失敗
                    break;
                }
                // 成功配對一個word，j的數量上升
                j++;
            }

            // 成功比對完所有字典中word(且出現次數也相等)，j == wordsSize，將結果(i)打進res中
            if (j == wordsSize)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};