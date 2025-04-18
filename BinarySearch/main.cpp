#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> & nums, int target) {
    if (nums.empty()) return -1;

    int start = 0; int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if( target > nums[mid]) {
            start = mid + 1;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            return mid; // index
        }
    }

    return -1;  
}

int recusriveBinarySearch(const std::vector<int> & nums, int start, int end, int target) {
    if (nums.empty()) return -1;
    
    if (start > end) return -1;

    int mid = start + (end - start)/2;

    if( target > nums[mid]) {
        return recusriveBinarySearch(nums, mid+1, end, target);
    } else if (target < nums[mid]) {
        return recusriveBinarySearch(nums, start, mid-1, target);
    } else {
        return mid; // index
    }

    return -1;   
}



int main() {

    std::vector<int> ip {1,2,3,4,5,6,7,8};
    int target = 0;
    std::cout << "index is: " << binarySearch(ip, target) << std::endl;
    std::cout << "index is: " << recusriveBinarySearch(ip, 0, ip.size()-1, target) << std::endl;
  
    return 0;
}
