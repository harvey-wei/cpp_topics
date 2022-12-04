#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool is_seg_valid(const string& seg)
    {
        return stoi(seg) <= 255 && (seg == "0" || seg[0] != '0');
    }

    void helper(string& s, int start, int seg_idx, string curr_seg, string ip,
            vector<string>& result)
    {
        if (start == s.size() && seg_idx == 3)
        {
            result.push_back(ip + curr_seg);
        }
        else if (start < s.size() && seg_idx <= 3)
        {
            char ch = s[start];
            /* start a new seg or append to current seg */

            string seg_new = "";
            seg_new += ch;
            if (curr_seg.size() > 0 && seg_idx < 3 && is_seg_valid(seg_new))
            {
                helper(s, start + 1, seg_idx + 1,  seg_new, ip + curr_seg + ".", result);
            }

            if (is_seg_valid(curr_seg + ch))
            {
                helper(s, start + 1, seg_idx, curr_seg + ch, ip, result);
            }
        }
        else
        {
            /* Do nothing*/
        }

        return;
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        helper(s, 0, 0, "", "", result);

        return result;

    }
};

int main()
{
    return 0;
}
