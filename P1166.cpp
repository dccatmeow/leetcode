/*
1166. Design File System

You are asked to design a file system that allows you to create new paths and associate them with different values.

The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string "" and "/" are not.

Implement the FileSystem class:

bool createPath(string path, int value) Creates a new path and associates a value to it if possible and returns true. Returns false if the path already exists or its parent path doesn't exist.
int get(string path) Returns the value associated with path or returns -1 if the path doesn't exist.
 

Example 1:

Input: 
["FileSystem","createPath","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/a", 1); // return true
fileSystem.get("/a"); // return 1

*/
class FileSystem {
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        auto pos = path.find_last_of('/');
        string ppath = path.substr(0, pos);
        if (m.find(path) !=m.end()){
            return false;
        }else if (!ppath.empty() && m.find(ppath)==m.end()){
            return false;
        }else{
            m[path] = value;
        }
        return true;
    }
    
    int get(string path) {
        if (m.find(path)==m.end()){
            return -1;
        }else{
            return m[path];
        }
    }
private:
    unordered_map<string,int> m;
};
