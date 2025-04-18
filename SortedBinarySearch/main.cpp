#include <iostream>
#include <vector>

/* In rotated sorted array, either left or right side of mid is sorted.
 * Step 1: calcuclate mid
 * Step 2: determine if left or right side of mid is sorted
 * Step 3: use binary search algorithm to further divide and search
*/
int search(const std::vector<int> & nums, int target) {
    if (nums.empty()) return -1;

    int start = 0; int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if (nums[mid] == target) return mid; // if mid is traget

        // check if left of mid is sorted
        if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target < nums[mid]) { // if target is in left side mid array
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else { // right half is sorted
            if (target > nums[mid] && target <= nums[end]) { // if target in right side of mid array
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
   
}

int recursiveSearch(const std::vector<int>& nums, int start, int end, int target) {
    if (nums.empty()) return -1;

    if (start > end) return -1;

    int mid = start + (end - start) / 2;

    if (nums[mid] == target) return mid;

    if (nums[start] <= nums[mid]) {
        if (nums[start] <= target && target < nums[mid]) {
            return recursiveSearch(nums, start, mid - 1, target);
        } else {
            return recursiveSearch(nums, mid + 1, end, target);
        }
    } else {
        if (nums[mid] < target && target <= nums[end]) {
            return recursiveSearch(nums, mid + 1, end, target);
        } else {
            return recursiveSearch(nums, start, mid - 1, target);
        }
    }
}

int main() {

    std::vector<int> ip {4,5,6,7,8,1,2,3};
    int target = 7;
    std::cout << "index of " << target << " is: " << search(ip, target) << std::endl;
    std::cout << "index of " << target << " is: " << recursiveSearch(ip, 0, ip.size() - 1, target) << std::endl;

    return 0;
}
