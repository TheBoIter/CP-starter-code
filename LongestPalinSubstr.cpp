// Manacher's Algorithm
// O(n) time, O(n) memory
string longestPalindrome(string s) {
        int n = s.size();
        string ss = "";
        for(int i = 0; i < n; i++){
            ss += '|';
            ss += s[i];
        }
        ss += '|';
        n = ss.size();
        ss = "@" + ss + "$";
        s = ss;
            s = "@" + s + "$";
        vector<int> len(n + 1);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++)
        {
            len[i] = min(r - i, len[l + (r - i)]);
            while(s[i - len[i]] == s[i + len[i]])
                len[i]++;
            if(i + len[i] > r)
            {
                l = i - len[i];
                r = i + len[i];
            }
        }
        len.erase(len.begin());

        int mx = 0, cur = -1;
        for(int i = 0; i < n; i++){
            if(len[i] > mx){
                mx = len[i];
                cur = i;
            }
        }
        string put = "";
        for(int i = 1; i < mx; i++){
            if(ss[cur-mx+i] != '|') put += ss[cur-mx+i];
        }
        for(int i = 0; i < mx; i++){
            if(ss[cur+i] != '|') put += ss[cur+i];
        }
        return put;
    }
