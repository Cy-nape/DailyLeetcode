# Trailing Zeroes in Factorial - Explained

### Problem Statement:
Given an integer `n`, return the number of **trailing zeroes** in `n!` (n factorial).

Trailing zeroes are the number of zeroes at the end of the factorial result. For example:

- `5! = 120` → **1 trailing zero**
- `10! = 3628800` → **2 trailing zeroes**
- `100!` → **24 trailing zeroes**

---

### Core Idea:
A trailing zero is created with a factor of **10**, and `10 = 2 × 5`. 

But in the multiplication of numbers from `1 to n`, there are more `2`s than `5`s. So, the number of trailing zeroes is **determined by the number of `5`s** in the factorization of `n!`.

We need to count:
- How many numbers ≤ `n` are divisible by `5` (e.g., `5, 10, 15, ...`)
- How many are divisible by `25` (e.g., `25, 50, 75, ...`) — each contributes **an extra 5**
- Similarly for `125`, `625`, etc.

---

### Logic Walkthrough:

```cpp
int trailingZeroes(int n) {
    int k = 5, ans = 0;
    while(n / k != 0){
        ans += (n / k);  // Count how many multiples of 5^k
        k *= 5;          // Go to next power of 5
    }
    return ans;
}
