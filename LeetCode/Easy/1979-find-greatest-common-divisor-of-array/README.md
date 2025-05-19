### **Explanation of `findGCD()` Function**
The `findGCD()` function finds the **Greatest Common Divisor (GCD)** of the smallest and largest number in a given array using the **Euclidean Algorithm**, which is an efficient method for computing GCD.

#### **Key Steps in the Code**
1. **Find the smallest (`s`) and largest (`m`) elements in the array**
   - `s = *min_element(nums.begin(), nums.end());` → Finds the **smallest number**.
   - `m = *max_element(nums.begin(), nums.end());` → Finds the **largest number**.

2. **Use the Euclidean Algorithm to find the GCD**
   - The **Euclidean Algorithm** states that:
     \[
     \text{GCD}(m, s) = \text{GCD}(s, m \mod s)
     \]
   - It repeatedly replaces `m` with `s` and `s` with `m % s` **until `s` becomes 0**.

3. **Return the final value of `m` (which holds the GCD)**.

---

### **Dry Run Example**
#### **Input:** `{6, 7, 9}`
- **Step 1:** Find min and max  
  - `s = 6`, `m = 9`

#### **Step-by-Step Execution**
| Step | `m` | `s` | `m % s` | Updated `m` | Updated `s` |
|------|----|----|------|----------|----------|
| 1 | `9` | `6` | `9 % 6 = 3` | `6` | `3` |
| 2 | `6` | `3` | `6 % 3 = 0` | `3` | `0` |

- **Loop Ends** (`s == 0`), so **GCD = `3`**.

#### **Final Output:** `3`

---

### **Time Complexity**
- **Finding min/max:** `O(n)`
- **Euclidean Algorithm:** `O(log(min(s, m)))`
- **Overall Complexity:** `O(n + log(min(s, m)))` → **Very efficient!**
