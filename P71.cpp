class Solution {
public:
    string simplifyPath(string path) {
        path = path+"/0";
        stack<string> stk;
        string tmp;
        for(int i=0; i<path.size();++i){
            char c = path[i];
            if (c=='/'){
                // work with tmp, in stack or...
                if (!tmp.empty()){
                    if (tmp == ".."){
                        if(!stk.empty()){
                            stk.pop();
                        }
                    }else if (tmp == "."){
                    }else{
                        // ...
                        stk.push(tmp);
                    }
                    tmp.clear();
                }
            }else{
                tmp = tmp + c;
            }
        }
        string res;
        if (stk.empty()){
            return "/";
        }
        res = "/"+stk.top();
        stk.pop();
        while(!stk.empty()){
            res = '/'+stk.top() +res;
            stk.pop();
        }
        return res;
    }
};
