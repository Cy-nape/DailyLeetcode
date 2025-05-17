# ✅ LeetCode Problem: Contains Duplicate

**Problem Statement:**

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

### 🧠 Approaches Implemented:

---

## 🧩 1. Sorting Approach

```cpp
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}
````

**Logic:**

* Sort the array so that duplicates come next to each other.
* Then check for adjacent equal elements.

**Time Complexity:** `O(n log n)`
**Space Complexity:** `O(1)` (ignoring sort space)

---

## 🔁 2. Hash Set Approach

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```

**Logic:**

* Use a hash set to track seen elements.
* If an element is already in the set, it's a duplicate.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

---

## 📊 3. Frequency Map Approach

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > 1) return true;
    }
    return false;
}
```

**Logic:**

* Count frequency of each number.
* If any number appears more than once, return true.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`
