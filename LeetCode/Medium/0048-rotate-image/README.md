# 🔄 LeetCode Problem: Rotate Image (90° Matrix Rotation)

## 🧾 Problem Statement

You are given an `n x n` 2D matrix representing an image, rotate the image by **90 degrees clockwise** in-place.

---

## ✅ Solution Approach: Transpose + Reverse Rows

```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
````

---

## 🧠 Intuition

### 🔷 What is a 90° clockwise rotation?

You want to rotate all elements such that:

* First row becomes the last column
* Second row becomes second-last column
* And so on...

For example:

**Input:**

```
1 2 3
4 5 6
7 8 9
```

**Output after 90° Clockwise:**

```
7 4 1
8 5 2
9 6 3
```

---

## 🧮 Step-by-Step Explanation

### ✅ Step 1: **Transpose the Matrix**

Swap `matrix[i][j]` with `matrix[j][i]`. This reflects the matrix across its main diagonal.

**After Transpose:**

```
1 4 7
2 5 8
3 6 9
```

### ✅ Step 2: **Reverse Each Row**

This makes the rows flip horizontally — giving the final rotated form.

**After Reverse:**

```
7 4 1
8 5 2
9 6 3
```

---

## 🔁 Other Rotations Intuition

### 🔁 90° Counter-Clockwise

* **Reverse columns**
* Then **transpose**

```cpp
// Step 1: Reverse columns
for (int j = 0; j < n; j++) {
    for (int i = 0, k = n - 1; i < k; i++, k--) {
        swap(matrix[i][j], matrix[k][j]);
    }
}
// Step 2: Transpose
transpose(matrix);  // same transpose logic as above
```

### 🔁 180° Rotation

Can be done in two ways:

* Reverse both rows and columns
* Or do `reverse(matrix.begin(), matrix.end())` then `reverse(matrix[i].begin(), matrix[i].end())` for each row

```cpp
for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
reverse(matrix.begin(), matrix.end());
```

---

## ⏱ Time & Space Complexity

| Operation    | Time  | Space |
| ------------ | ----- | ----- |
| Transpose    | O(n²) | O(1)  |
| Reverse Rows | O(n²) | O(1)  |

**Total:**
✅ Time Complexity: `O(n²)`
✅ Space Complexity: `O(1)` (In-place)

---

## 📌 Final Notes

* **Transpose + reverse rows** → 90° clockwise
* **Transpose + reverse columns** → 90° counter-clockwise
* **Reverse both rows & columns** → 180° rotation
* Code runs in-place with constant extra space.
