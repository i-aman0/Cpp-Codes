#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int> nums, int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while(s < e){
        if(nums[mid] >= nums[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }

        mid = s + (e - s) / 2;
    }

    return s;
}

int binarySearch(vector<int> nums, int start, int end, int target){
    int s = start;
    int e = end;
    int mid = s + (e - s) / 2;

    while(s <= e){
        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}

int searchRotated(vector<int> nums, int target){
    int n = nums.size();
    int pivot = getPivot(nums, n);

    if(target >= nums[pivot] && target <= nums[n - 1]){
        return binarySearch(nums, pivot, n - 1, target);
    }
    else{
        return binarySearch(nums, 0, pivot - 1, target);
    }
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    cout << "The element 0 is present at index : " << searchRotated(arr, 0) << endl;
    return 0;
}