You're absolutely right — computing the full product can easily lead to **overflow**, even with `long long`, especially for large arrays with large values.

### Optimization Strategy:

You **don’t need to calculate the exact product** — just track:

* If there's a `0` → result is `0`
* Count how many **negative numbers** there are:

  * Even negatives → positive product → return `1`
  * Odd negatives → negative product → return `-1`

---

### Optimized Code:

```cpp
int arraySign(vector<int>& nums) {
    int sign = 1;
    for (int num : nums) {
        if (num == 0) return 0;      // Product becomes 0
        if (num < 0) sign *= -1;     // Flip the sign
    }
    return sign;
}
```

---

### Time & Space Complexity:

* **Time**: O(n)
* **Space**: O(1)

This version avoids multiplication altogether and **prevents overflow** by working purely with signs.

