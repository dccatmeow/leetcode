/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) 
for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 
Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]
*/

class StockSpanner{
    private:
    // monotonically decreasing stack store idx and price
    stack<pair<int, int>> s;
    int idx = 0;
    
    public:
    StockSpanner(){}
    
    int next(int price) {
        while (!s.empty() && price >= s.top().second){
            // pop out small numbers between current idx and
            // the one which s.top().second > price
            s.pop();
        } 
        int res;
        if (!s.empty()){
            // e.g. stack has (0,100) (1,80)
            res = idx - s.top().first;    
        }else{
            // s empty, current element is the largest
            res = idx+1;
        }
        
        s.push({idx, price});        
        ++idx;
        return res;
    }
};
