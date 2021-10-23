class Solution {
public:
    
    int partition(vector<vector<int>> &arr, int low, int high)
    {
        int pivot_index = low;
        vector<int> pivot,temp;
        pivot = arr[high];
        for(int i = low ; i <= high-1 ; i++)
        {
            if(arr[i][0] <= pivot[0])
            {
                temp = arr[i];
                arr[i] = arr[pivot_index];
                arr[pivot_index] = temp;
                pivot_index++;
            }
        }
        temp = arr[high];
        arr[high] = arr[pivot_index];
        arr[pivot_index] = temp;
        return pivot_index;
    }

    void quick_sort(vector<vector<int>> &arr, int low, int high)
    {
        if(low<high){
        int pivot_index = partition(arr , low , high);
        quick_sort(arr , low , pivot_index-1);
        quick_sort(arr , pivot_index + 1 , high);
        }

    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {  
        //sort(intervals.begin(),intervals.end(),compareInterval);
        
        quick_sort(intervals , 0 , intervals.size()-1);
        
        vector<int> temp = intervals[0];
        vector<vector<int>> merge;
        for(int i=0;i<intervals.size();i++)
        {
            if(temp[1]>=intervals[i][0])
            {
                if(temp[1]<=intervals[i][1])
                temp[1] = intervals[i][1];
            }
            else
            {
                merge.push_back(temp);
                temp = intervals[i];
            }
        }
         merge.push_back(temp);
        return merge;
    }
};
