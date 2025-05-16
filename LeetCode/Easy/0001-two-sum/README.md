### **Explanation of the Code: Two Sum Using Hash Map**
This `twoSum` function efficiently finds **two numbers** in the given vector `nums` that add up to `target`. Instead of using a brute-force approach (`O(n²)` time complexity), it leverages an **unordered_map** (hash map) to achieve a much faster **O(n)** time complexity.

#### **Step-by-Step Logic**
1. **Initialize an unordered_map (`map`)**:  
   - This hash map stores key-value pairs where the **key is the number in `nums`**, and the **value is its index in the array**.
   
2. **Iterate through the `nums` array**:
   - For each number, check if **target - nums[i]** exists in `map`.
   - If it does, return the indices of `target - nums[i]` and `nums[i]`, as they form a valid pair.
   - If not, store the current number in `map` with its index.

3. **If no valid pair is found**, return `{}` (an empty vector).

---

### **Concept of Adding & Removing Elements in a Hash Map**
#### **Adding Elements (`map[key] = value`)**
- When we store a number with its index in the hash map:
  ```cpp
  map[nums[i]] = i;
  ```
  - If `nums[i] = 5` and `i = 2`, this adds `{5 → 2}` to the map.
  - If `nums[i] = 8` and `i = 4`, it adds `{8 → 4}`.

#### **Searching for a Value (`map.find(key)`)**
- We check if `target - nums[i]` exists in the map:
  ```cpp
  if (map.find(target - nums[i]) != map.end())
  ```
  - `map.find(key)` returns an iterator pointing to the key if found, otherwise `map.end()`.
  - Example: If `target = 9` and `nums[i] = 4`, we check if `5` exists in the hash map.

#### **Deleting Elements (`map.erase(key)`)**
- If we needed to **remove an element**, we use:
  ```cpp
  map.erase(key);
  ```
  - Example: `map.erase(5);` removes `{5 → index}` from the hash map.

---

### **Efficiency Comparison**
Using a hash map allows:
**Instant lookup (`O(1)`)** for checking whether a complement exists.  
**Fast insertion (`O(1)`)** for storing numbers and indices.  
**Linear runtime (`O(n)`)**, much faster than brute-force (`O(n²)`).  

