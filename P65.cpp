//65. Valid Number


class Solution {
public:
    bool isNumber(string s) {
        bool e_flag = false;
        bool dot_flag = false;
        for (int i=0; i<s.size();++i){
            char c = s[i];
            if (c == 'e'||c=='E'){
                if (e_flag){
                    // miltiple e
                    return false;
                }
                e_flag = true;
                if (i==s.size()-1||i==0){
                    return false;
                }
                if (s[i-1]=='.'){
                    if (s[i+1]!='+'&&s[i+1]!='-'){
                        continue;
                    }else{
                        i++;
                    }
                }else if (s[i-1]<'0'||s[i-1]>'9'){
                    // e
                    return false;
                }
                if (s[i+1]=='+'||s[i+1]=='-'){
                    if (i+1 == s.size()-1){
                        return false;
                    }
                    ++i;
                }
                if (s[i+1]<'0'||s[i+1]>'9'){
                    // e.
                    return false;
                }
            }else if (c=='+'||c=='-'){
                if (i!=0){
                    return false;
                }
                if (i==s.size()-1){
                    // sign can not at the end
                    return false;
                }
            }else if (c=='.'){
                if (dot_flag||e_flag){
                    return false;
                }
                dot_flag = true;
                if (i==s.size()-1&&i==0){
                    return false;
                }
                if (s[i+1]=='e'){
                    // .e
                    if (i==0){
                        return false;
                    }
                    // 3.e
                    continue;
                }
                if (i==0){
                    continue;
                }
                if (i==s.size()-1){
                    if (s[i-1]<'0'||s[i-1]>'9'){
                        return false;
                    }
                    continue;
                }
                if (s[i-1]=='e'){
                    // e.
                    return false;
                }
                if (s[i+1]<'0'||s[i+1]>'9'){
                    return false;
                }
            }else if (c>='0' && c<='9'){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
