#### **Step 1: Find the First Zero in the Array**
```cpp
int j=-1;
for(int i=0;i<nums.size();i++){
    if(nums[i]==0){
        j=i;
        break;
    }
}
```
- We initialize `j = -1`, which will **track the first zero** in the array.
- We iterate from index `i = 0` to `nums.size() - 1`:
  - If we **find a zero**, we set `j = i`, marking the first zero's index.
  - **Break** after finding the first zero to start swapping.

#### **Step 2: Swap Non-Zero Elements with `j`**
```cpp
if(j!=-1){
    for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}
```
- **Condition `if(j != -1)`** ensures we only run swapping if at least **one zero** exists.
- We iterate **from `j+1` onwards**:
  - **If `nums[i] != 0`**, swap `nums[i]` with `nums[j]`.
  - Increment `j` to track the position of the next zero.

### **Dry Run of the Code**
#### **Input:** `[0, 1, 0, 3, 12]`
Let's go step by step to see how the array transforms:

| `i`  | `nums` Before Swap | `j` | Swap Condition | `nums` After Swap |
|------|--------------------|-----|---------------|------------------|
| `0`  | `[0, 1, 0, 3, 12]` | `0` | — Found first zero (`j=0`) | — |
| `1`  | `[0, 1, 0, 3, 12]` | `0` | `nums[1] != 0` → Swap `nums[1] ↔ nums[0]` | `[1, 0, 0, 3, 12]` |
| `2`  | `[1, 0, 0, 3, 12]` | `1` | `nums[2] == 0`, skip | `[1, 0, 0, 3, 12]` |
| `3`  | `[1, 0, 0, 3, 12]` | `1` | `nums[3] != 0` → Swap `nums[3] ↔ nums[1]` | `[1, 3, 0, 0, 12]` |
| `4`  | `[1, 3, 0, 0, 12]` | `2` | `nums[4] != 0` → Swap `nums[4] ↔ nums[2]` | `[1, 3, 12, 0, 0]` |

**Final Output:** `[1, 3, 12, 0, 0]`

### **Time Complexity Analysis**
- The first loop **finds the first zero**: **O(n)**
- The second loop **moves non-zero elements forward**: **O(n)**
- **Overall Complexity:** **O(n)** (single pass solution)

### **Potential Issues & Fixes**
1. **Handles Only One Zero at a Time Initially**  
   - Instead of breaking early, we could directly track all zero positions for efficiency.
2. **Alternative Approach (Two-Pointer Method)**  
   - Instead of using `j`, start swapping zeroes **in-place**, ensuring fewer operations.
