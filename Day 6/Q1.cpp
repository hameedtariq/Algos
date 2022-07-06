/*
	LINK: https://leetcode.com/problems/merge-intervals/submissions/


*/

// brute force approach. Time limit reached!


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    stack<vector<int>> newIntervals;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a,vector<int> &b ){return a[0] < b[0];});
    if(intervals.size() == 1) return intervals;
    auto i = intervals.begin();
    auto end = intervals.end();
    newIntervals.push(*i); intervals.erase(i);
    while(intervals.size() != 0){
        if(newIntervals.top()[1] >= (*i)[0]){
            vector<int> temp; temp.push_back(newIntervals.top()[0]);  temp.push_back((*i)[1] > newIntervals.top()[1] ? (*i)[1] : newIntervals.top()[1]);
            newIntervals.pop();
            intervals.erase(i);
            newIntervals.push(temp);

            continue;
        }else {
            newIntervals.push(*i);
            intervals.erase(i);

        }
    }
    while(!newIntervals.empty()){
        intervals.insert(intervals.begin(), newIntervals.top()); newIntervals.pop();
    }
    return intervals;
}









// modified the code a little to remove extra overhead. Works like a charm!
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> newIntervals;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a,vector<int> &b ){return a[0] < b[0];});
    if(intervals.size() == 1) return intervals;
    auto i = intervals.begin();
    auto end = intervals.end();
    // newIntervals.push_(*i); intervals.erase(i);
    while(i != end){
        
        if(newIntervals.empty() || newIntervals.back()[1] < (*i)[0])
        {
            newIntervals.push_back(*i);
            i++;
        } else
        {
            newIntervals.back()[1] = ((*i)[1] > newIntervals.back()[1] ? (*i)[1] : newIntervals.back()[1]);
            i++;
        }
    }
    
    return newIntervals;
}
};