class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array <char, 128> dict0 {0}, dict1 {0};

        for (int i = 0; i < s.size(); ++i)
        {
            char sc = s[i], tc = t[i];
            if (dict0[sc] == 0 && dict1[tc] == 0)
            {
                dict0[sc] = tc;
                dict1[tc] = sc;
            }else if (dict0[sc] != tc)
            {
                return false;
            }else if (dict1[tc] != sc)
            {
                return false;
            }
        }

        return true;
    }
};
