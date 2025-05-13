## Problem Statement:

**Reverse an integer** — Given a signed 32-bit integer `x`, return its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range (`[-2³¹, 2³¹ - 1]`), return `0`.

---

## Constraints:

* Input is a signed 32-bit integer.
* You cannot use **extra space** like converting to a string or array.
* Must handle **negative numbers**.
* Must handle **integer overflow**.

---

## Expected Output:

* Input: `123` → Output: `321`
* Input: `-123` → Output: `-321`
* Input: `120` → Output: `21`
* Input: `1534236469` → Output: `0` (since reversed number causes overflow)

---

## Common Mistakes:

1. **Forgetting to handle negative numbers**

   * `abs(x)` isn't enough. It fails for `INT_MIN` = `-2,147,483,648` because `abs(INT_MIN)` is undefined (overflow).

2. **Incorrect overflow check**

   * Writing something like:

     ```cpp
     if (reversed > INT_MAX || reversed < INT_MIN)
     ```

     after the reversal is **too late** — overflow might have already happened.

3. **Chaining comparisons incorrectly**

   * `if (pow(2,-31) <= reversed <= pow(2,31))` is invalid in C++. You need:

     ```cpp
     if (reversed >= INT_MIN && reversed <= INT_MAX)
     ```

4. **Using `int` instead of `long long`**

   * This causes silent overflow **before** your checks run.

---

## Correct Approach (with explanation):

### Key Idea:

Build the reversed number **digit by digit**, and **check for overflow before multiplying/adding**.

### Final Code:

```cpp
int reverse(int x) {
    long long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    // Check if reversed fits in 32-bit signed integer range
    if (reversed < INT_MIN || reversed > INT_MAX) {
        return 0;
    }

    return reversed;
}
```

---

## Explanation Step-by-Step:

Let's take `x = -123` as an example.

### Step 1: Initialize `reversed = 0`

### Step 2: Loop while `x != 0`

Each iteration:

* Get the last digit: `digit = x % 10`
* Append it to `reversed`: `reversed = reversed * 10 + digit`
* Remove last digit from `x`: `x /= 10`

| Iteration | `x`  | `digit = x % 10` | `reversed`              |
| --------- | ---- | ---------------- | ----------------------- |
| 1         | -123 | -3               | 0 \* 10 + (-3) = -3     |
| 2         | -12  | -2               | -3 \* 10 + (-2) = -32   |
| 3         | -1   | -1               | -32 \* 10 + (-1) = -321 |
| 4         | 0    | —                | End                     |

Final `reversed = -321`.

---

## Overflow Handling:

Use `long long` while building `reversed`, and at the end, check:

```cpp
if (reversed < INT_MIN || reversed > INT_MAX)
```

This is needed because:

* C++ `int` is 32-bit
* Multiplying and adding might cause it to exceed the limit silently

---

## Edge Case: `INT_MIN = -2,147,483,648`

If you do `x = abs(INT_MIN)`, it **crashes** because:

* `abs(INT_MIN)` = `2147483648` → **Overflow**

This is why we don’t use `abs()` — instead, handle `x` as-is (negative or positive) and use `%` and `/`.
