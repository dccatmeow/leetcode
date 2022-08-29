/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right)
justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' 
when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // linear scan
        vector<string> tmp;
        int count(0);
        vector<string> res;
        // in order to excercise all the strings in words, add a dummy string at the end
        words.push_back(string(maxWidth,'a'));
        for (int i=0; i< words.size(); ++i){
            int sz = words[i].size();
            // count is pure words
            // necessary space is tmp.size()-1
            // add a new word need sz+1
            if (count+tmp.size()+sz>maxWidth){
                if (i!=words.size()-1){
                    // reach boundary, construct string
                    int blankspace, leftspace;
                    string str;
                    if (tmp.size() == 1){
                        blankspace = maxWidth-tmp[0].size();
                        leftspace = 0;
                        // construct string
                        str = tmp[0] + string(blankspace, ' ');
                    }else{
                        blankspace = (maxWidth-count)/(tmp.size()-1);
                        leftspace = (maxWidth-count)%(tmp.size()-1);
                        // construct string
                        string blankStr(blankspace, ' ');
                        for (int j=0; j<tmp.size();++j){
                            if (leftspace!=0){
                                str = str+ tmp[j]+blankStr+' ';
                                leftspace--;
                            }else{
                                if (j!=tmp.size()-1){
                                    str = str+ tmp[j]+blankStr;
                                }else{
                                    // last word in a row
                                    str = str+tmp[j];
                                }
                            }
                        }
                    }
                    // save in res
                    res.push_back(str);
                    // set count and tmp,
                    count = sz;
                    tmp = vector<string>{words[i]};
                }else{
                    // last row, treat it with single space
                    string str;
                    for (int j=0; j<tmp.size(); ++j){
                        if (j!=tmp.size()-1){
                            str = str+ tmp[j]+' ';
                        }else{
                            // last row
                            str = str+tmp[j];
                        }
                    }
                    string leftspace(maxWidth-str.size(), ' ');
                    str = str + leftspace;
                    res.push_back(str);
                }
            }else{
                // keep adding words[i] to tmp
                count += sz;
                tmp.push_back(words[i]);
            }
        }
        
        return res;
    }
};
