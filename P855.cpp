/*
There is an exam room with n seats in a single row labeled from 0 to n - 1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.

Design a class that simulates the mentioned exam room.

Implement the ExamRoom class:

ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
int seat() Returns the label of the seat at which the next student will set.
void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.
 

Example 1:

Input
["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
[[10], [], [], [], [], [4], []]
Output
[null, 0, 9, 4, 2, null, 5]

Explanation
ExamRoom examRoom = new ExamRoom(10);
examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
examRoom.seat(); // return 9, the student sits at the last seat number 9.
examRoom.seat(); // return 4, the student sits at the last seat number 4.
examRoom.seat(); // return 2, the student sits at the last seat number 2.
examRoom.leave(4);
examRoom.seat(); // return 5, the student sits at the last seat number 5.

*/

using pii=pair<int,int>;
auto comp = [](pii const& p1, pii const& p2){
    // [1,4],[1,5] has the same dist
    int dist1 = (p1.second-p1.first)/2;
    int dist2 = (p2.second-p2.first)/2;
    if (dist1 == dist2){
        // put lowest pos int front
        return p1.first<p2.first;
    }else{
        return dist1>dist2;
    }
};
class ExamRoom {
public:
    ExamRoom(int n) :
    num(n),
    gap(comp){}
    
    int seat() {
        if (pos.empty()){
            // insert first element
            pos.insert(0);
            return 0;
        }else if (pos.size()==1){
            // insert second element
            int tmp = *pos.begin();
            if (num-1-tmp > tmp){
                pos.insert(num-1);
                gap.insert(pii(tmp, num-1));
                return num-1;
            }else{
                pos.insert(0);
                gap.insert(pii(0, tmp));
                return 0;
            }
        }else{
            auto [l,r]=*gap.begin();
            int tmp = (l+r)/2;
            int midP = tmp-l;
            // compare three section
            // (l,tmp), min-0, num-1-max
            int startP, endP;
            startP = *pos.begin();
            endP = num-1-*(pos.rbegin());
            if (startP >= endP && startP >= midP){
                // prefer smaller position with largest or equal gap
                pos.insert(0);
                gap.insert(pii(0, startP));
                return 0;
            }else if (endP > midP){
                pos.insert(num-1);
                gap.insert( pii(*(pos.rbegin()), num-1) );
                return num-1;
            }else{
                gap.erase(gap.begin());
                gap.insert(pii(l,tmp));
                gap.insert(pii(tmp,r));
                pos.insert(tmp);
                return tmp;
            }
        }
    }
    
    void leave(int p) {
        if (pos.size()<2){
            pos.erase(p);
            gap.clear();
            return;
        }
        if (p == 0){
            gap.erase(pii(0, *pos.begin()));
        }else if (p == num-1){
            gap.erase(pii(*pos.rbegin(), num-1));
        }else{
            auto iter = pos.find(p);
            if (*iter == *pos.rbegin() ){
                // most right section
                gap.erase(pii(p, num-1));
            }else if (iter == pos.begin()){
                // most left section
                gap.erase(pii(0,p));
            }else{
                // middle section
                int l = *(std::prev(iter));
                int r = *(std::next(iter));
                gap.erase(pii(l,p));
                gap.erase(pii(p,r));
                gap.insert(pii(l,r));
            }
        }
        pos.erase(p);
        
    }
private:
    int num;
    set<int> pos;
    set<pii, decltype(comp)> gap;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
