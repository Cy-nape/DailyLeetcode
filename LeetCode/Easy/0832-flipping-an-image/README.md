# Flipping and Inverting a Binary Image

## Introduction
This repository implements an algorithm to **flip** and **invert** a binary matrix efficiently. Each row is reversed (mirrored) and each bit (`0` → `1`, `1` → `0`) is flipped.

## Problem Statement
Given a **binary image matrix** (`0s` and `1s`), the function should:
1. **Reverse (flip) each row** so that left-most elements move to the right.
2. **Invert each element** (`0 → 1` and `1 → 0`).

### **Example Input & Output**
#### **Example 1**
```cpp
Input: image = [[1,1,0], [1,0,1], [0,0,0]]
Output: [[1,0,0], [0,1,0], [1,1,1]]
```
#### **Transformation Steps**
1. **Flip (reverse) each row**  
   `[[0,1,1], [1,0,1], [0,0,0]]`
2. **Invert each element**  
   `[[1,0,0], [0,1,0], [1,1,1]]`

---

## **Algorithm Explanation**
### **Code Implementation**
```cpp
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto& row : image) {
        int i = 0, j = row.size() - 1;

        // Two-pointer approach to swap and invert elements simultaneously
        for (; i < j; ++i, --j) {
            if (row[i] == row[j]) {
                row[i] ^= 1; // Flip 0 → 1 or 1 → 0
                row[j] ^= 1; // Flip 0 → 1 or 1 → 0
            }
        }
        
        // If row has an odd number of elements, the middle one needs flipping
        if (i == j) {
            row[i] ^= 1;
        }
    }
    return image;
}
```

### **Logic Breakdown**
1. **Iterate over each row in the matrix.**
2. **Use two pointers (`i` and `j`)**:
   - `i` starts from the left.
   - `j` starts from the right.
   - Swap and invert the bits **only if both bits are equal** (ensuring flipping happens efficiently).
3. **Middle element correction**:
   - If the row length is odd (`i == j` at the middle), flip the middle element.

---

## **Time Complexity Analysis**
- **O(N × M / 2) ≈ O(N × M)**
  - Since each row is processed **with two pointers**, work is reduced by half.
- **O(1) Space Complexity** (In-place modification).
