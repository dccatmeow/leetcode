/*
Design a logger system that receives a stream of messages along with their timestamps. 
Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp 
it will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.

Example 1:

Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]
*/

class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.count(message)){
            if (timestamp >= m[message]){
                m[message] = timestamp+10;
                return true;
            }
        }else{
            // save to m
            m[message] = timestamp+10;
            return true;
        }
        return false;
    }
private:
    // m stores key and the next time it can print message
    unordered_map<string, int> m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
