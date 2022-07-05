/*
	LINK: https://www.codingninjas.com/codestudio/problems/find-peak-element_1081482?leftPanelTab=1
	
*/



int findPeak(vector<int> &arr) {
    bool increasing = true, decreasing = true;
    for(auto i = 1; i < arr.size()-1; i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            return arr[i];
        }else if(!(arr[i-1] < arr[i] && arr[i] < arr[i+1] && increasing)){
            increasing = false;
        }else if(!(arr[i-1] > arr[i] && arr[i] > arr[i+1] && decreasing)){
            decreasing = false;
        }
        
    }
    if(increasing) return arr[arr.size()-1];
    if(decreasing) return arr[0];
}
