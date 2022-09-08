/*
You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect.
Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
Finds the maximum price the stock has been based on the current records.
Finds the minimum price the stock has been based on the current records.
Implement the StockPrice class:

StockPrice() Initializes the object with no price records.
void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
int current() Returns the latest price of the stock.
int maximum() Returns the maximum price of the stock.
int minimum() Returns the minimum price of the stock.
 
Example 1:

Input
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
Output
[null, null, null, 5, 10, null, 5, null, 2]
*/

class StockPrice {
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (m.count(timestamp)){
            // need to reduce old price frequency
            int oldPrice = m[timestamp];
            mFreq[oldPrice]--;
            if (mFreq[oldPrice]==0){
                // remove key if no key present
                mFreq.erase(oldPrice);
            }
        }
        // update new price to system
        mFreq[price]++;
        m[timestamp] = price;
        currentT = max(currentT, timestamp);
    }
    
    int current() {
        return m[currentT];
    }
    
    int maximum() {
        return mFreq.rbegin()->first;
    }
    
    int minimum() {
        return mFreq.begin()->first;
    }
private:
    // timestamp, price
    unordered_map<int,int> m;
    int currentT;
    // price, frequency, sorted from small to large
    map<int, int> mFreq;
    
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
