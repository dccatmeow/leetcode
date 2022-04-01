    int minAddToMakeValid(string s) {
        int res(0);
        int l(0), r(0);
        for (auto c:s){
            if (c == ')'){
                if (l==0){
                    // need to insert a left braces to balance
                    res++;
                }else{
                    l--;
                }
            }else if (c=='('){
                l++;
            }
        }
        res = res+l;
        return res;
    }
