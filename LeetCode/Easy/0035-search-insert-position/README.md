### **README.md** – Search Insert Position (Binary Search Approach)
# Search Insert Position (Binary Search Approach)

## Problem Statement
Given a sorted array `nums` and a target integer `target`, return the index where `target` should be inserted to maintain the sorted order. If the target is already present, return its index.

### **Example Scenarios**
#### Example 1:
```cpp
Input: nums = [1,3,5,6], target = 5
Output: 2
Explanation: Target 5 exists at index 2.
```

#### Example 2:
```cpp
Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: Target 2 should be inserted at index 1 to maintain sorted order.
```

#### Example 3:
```cpp
Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: Target 7 should be inserted at index 4.
```

#### Example 4:
```cpp
Input: nums = [1,3,5,6], target = 0
Output: 0
Explanation: Target 0 should be inserted at index 0.
```

---

## **Approach**
### **Binary Search**
Instead of iterating through the entire array (O(n) complexity), we use **binary search** to achieve an efficient **O(log n)** solution.

### **Algorithm**
1. Set two pointers: `lo = 0` and `hi = nums.size() - 1`.
2. Perform binary search:
   - Find the **mid-point**.
   - If `nums[mid] == target`, return `mid`.
   - If `nums[mid] < target`, move `lo` to `mid + 1`.
   - If `nums[mid] > target`, move `hi` to `mid - 1`.
3. **At the end**, `lo` will be the correct insertion index.

---

## **Corrected Code Implementation**
```cpp
int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo; // lo represents the correct insertion index
}
```

---

## **Time Complexity Analysis**
- **Binary Search** reduces the problem space **by half** in each iteration.
- **Best Case:** `O(1)` (if target is found immediately).
- **Average & Worst Case:** `O(log n)`, since the search space halves in every step.

## **Space Complexity**
- `O(1)`, as only a few integer variables (`lo`, `hi`, `mid`) are used.
