### **Understanding the Logic of This Code**
This code finds the **majority element** in a given array (`nums`), meaning the number that appears **more than half** the times (`n/2`). It uses the **Boyer-Moore Voting Algorithm**, which efficiently identifies the majority element in **O(n) time** without sorting.

---

### **Step-by-Step Explanation**
#### **Phase 1: Finding the Candidate**
- Start with the **first element** (`nums[0]`) as the "candidate."
- Keep a `count` to track how frequently the candidate appears.
- If the current element (`nums[i]`) is **equal** to the candidate, increase the count.
- If it’s **different**, reduce the count.
- **If count reaches 0**, assume the current number (`nums[i]`) is a better candidate and **switch to it**.

#### **Phase 2: Verifying the Candidate**
- Once we finish scanning the array, we **count occurrences** of the chosen candidate.
- If it appears **more than `n/2` times**, we return it; otherwise, we return `-1` (no majority element found).

---

### **Dry Run Example**
#### **Input:** `nums = [2,2,1,1,1,2,2]`
#### **Expected Output:** `2`

#### **Phase 1 (Finding the Majority Candidate)**  
| Step | `nums[i]` | `candidate` | `count` | Action |
|------|----------|------------|--------|--------|
| 1    | `2`      | `2`        | `1`    | Initial candidate |
| 2    | `2`      | `2`        | `2`    | Increment count |
| 3    | `1`      | `2`        | `1`    | Decrement count |
| 4    | `1`      | `2`        | `0`    | Count hits 0 → **New candidate: `1`** |
| 5    | `1`      | `1`        | `1`    | Increment count |
| 6    | `2`      | `1`        | `0`    | Count hits 0 → **New candidate: `2`** |
| 7    | `2`      | `2`        | `1`    | Increment count |

**Candidate after phase 1:** `2`

#### **Phase 2 (Verifying Majority)**
- Count occurrences of `2`: **Appears 4 times**
- Since `4 > n/2 = 3.5`, we return `2`.

---

### **Why This Works?**
✔ **Efficient:** Runs in `O(n)` time without sorting.  
✔ **Handles edge cases well:** Works even if no majority element exists.  
