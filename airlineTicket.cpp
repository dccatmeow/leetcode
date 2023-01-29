/*You're building a tool to estimate the cost of various airplane tickets based on the airline, distance and seating class. Your tool must 
take in this information as a series of inputs (one ticket calculation per line of input) and produce a list of output costs.

Each airline contains its own cost requirements. Ultimately, the airline is only interested in two major components: 
the space you take on the plane, and the distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir

Operating Costs:

- Economy:  No charge
- Premium:  $25
- Business: $50 + $0.25/mile

Per-Airline Prices:

- Delta charges $0.50/mile
   + OperatingCost

- United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats

- Southwest charges $1.00/mile

- LuigiAir charges $100 or 2 * OperatingCost, whichever is higher

Keep in mind that, while there are only four airlines listed above, your solution should be able to expand to dozens of individual airlines, 
whose ticket cost can be based on arbitrary functions of "Operating Costs", miles, and/or seating class.

Example Input:
-------------------------------------------
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy
LuigiAir 50.0 Business
-------------------------------------------

Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------

Explanation of Output:
-------------------------------------------
152.50      (150.0 * (0.75 + 0.10) + 25)
95.00       (60.0 * (0.50 + 0.25) + 50)
1000.00     (1000.0 * 1.00)
125.00      (100 <= 2 * (50 + 50 * 0.25))
---------------------‍‍‍‍‌‌‌‌‌‍‍‌‍‍‍‌‌‍‍‌----------------------
'''

test_input = [
    "United 150.0 Premium",
    "Delta 60.0 Business",
    "Southwest 1000.0 Economy",
    "LuigiAir 50.0 Business"
]
*/

#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;
enum Seat{ eco, pre, bus};
enum Airline{ delta, united, southwest, luigiair};
unordered_map<string, Airline> airlines {{"delta",delta}, {"united",united}, {"southwest",southwest}, {"luigiair", luigiair}};
unordered_map<string, Seat> seats{{"economy",eco}, {"premium",pre}, {"business",bus}};

class AirlineCalculator{
public:
static AirlineCalculator* create(Airline air); // factory pattern
virtual float calcFee(Seat s, float dis) = 0;
protected:
virtual float getOpCost (Seat s, float dis) {
    switch(s){
        case(eco):
        return 0.;
        case(pre):
        return 25.;
        case(bus):
        return 50.+0.25*dis;
    }
    return 0;
}
};

class DeltaCalculator:public AirlineCalculator{
public:
float calcFee(Seat s,float dis) override {
    float opCost = getOpCost(s,dis);
    return opCost + dis * 0.5;
}
static AirlineCalculator* get(){ // singleton
    static thread_local DeltaCalculator calc;
    return &calc;
    }
private:
DeltaCalculator() = default;
};

class UnitedCalculator:public AirlineCalculator{
public:
float calcFee(Seat s,float dis) override {
    float opCost = getOpCost(s,dis);
    return opCost + dis * 0.75;
}
static AirlineCalculator* get(){
    static thread_local UnitedCalculator calc;
    return &calc;
}
private:
UnitedCalculator() = default;
protected:
float getOpCost(Seat s, float dis) override{
    switch(s){
        case(eco):
        return 0.;
        case(pre):
        return 25.+0.1*dis;
        case(bus):
        return 50.+0.25*dis;
    }
    return 0;
}
};

class SouthwestCalculator:public AirlineCalculator{
public:
float calcFee(Seat s,float dis) override{
    return 1. * dis;
    }
static AirlineCalculator* get(){
    static thread_local SouthwestCalculator calc;
    return &calc;
}
private:
SouthwestCalculator() = default;
};

class LuigiairCalculator:public AirlineCalculator{
public:
    float calcFee(Seat s,float dis) override{
        float opCost = 2*getOpCost(s,dis);
        return max(opCost, (float)100);
    }
    static AirlineCalculator* get(){
        static thread_local LuigiairCalculator calc;
        return &calc;
    }
private:
LuigiairCalculator() = default;
};


AirlineCalculator* AirlineCalculator::create(Airline air){
    switch(air){
        case delta:
        return DeltaCalculator::get();
        case united:
        return UnitedCalculator::get();
        case southwest:
        return SouthwestCalculator::get();
        case luigiair:
            return LuigiairCalculator::get();
        }
}

vector<string> parse(string s, char delim = ' ');
vector<string> parse(string s, char delim){
    vector<string> res;
    // switch to lower case
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim) ) {
        if(token != "\0"){
            res.push_back(token);
        }
    }
    return res;
}

vector<float> calCost(vector<string>& ticketData){
    vector<float> res;
    for(auto &ticket:ticketData){
        vector<string> data = parse(ticket);
        float dis;
        // string to float
        dis = stof(data[1]);
        // Factory pattern
        AirlineCalculator* clc = AirlineCalculator::create(airlines[data[0]]);
        res.push_back(clc->calcFee(seats[data[2]], dis));
    }
    return res;
}

int main() {
    vector<string> input{"United 150.0 Premium", "Delta 60.0 Business", "SouthWest 1000.0 Economy", "LuigiAir 50.0 Business"};
    vector<float> costs = calCost(input);
    int n=input.size();
    for(int i = 0 ; i < n; i++){
        cout<< input[i]<<" The cost: $"<<costs[i]<<endl;
        }
        return 0;
}
