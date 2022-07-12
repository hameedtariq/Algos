/*
	LINK: https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
*/

class RandomizedSet {
    set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }else {
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
            s.erase(val);
            return true;
        }else {
            return false;
        }
    }
    
    int getRandom() {
        int index = rand()%s.size();
        auto it = s.begin();
        for(auto i = 0; i < index; i++){
            it++;
        }
        return *it;
    }
};
