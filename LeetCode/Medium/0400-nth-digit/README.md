# Find the N-th Digit in an Infinite Integer Sequence

## Problem Statement

We are given a positive integer `n` and asked to return the `n-th` digit in the infinite integer sequence formed by concatenating positive integers:

```
123456789101112131415...
```

For example:
- Input: `n = 11`
- Output: `0`  
- Explanation: The 11th digit is `'0'` in `"12345678910"`

---

## C++ Solution

```cpp
#include <cmath>   // for pow()
#include <string>  // for to_string()

class Solution {
public:
    int findNthDigit(int n) {
        int numDigits = 1;
        long digitCount = 9;

        // Find the digit-length group where n lies
        while (1LL * numDigits * digitCount < n) {
            n -= numDigits * digitCount;
            numDigits++;
            digitCount *= 10;
        }

        // Calculate the actual number containing the nth digit
        int number = pow(10, numDigits - 1) + (n - 1) / numDigits;

        // Find the digit position within that number
        int indexInNumber = (n - 1) % numDigits;
        string numberStr = to_string(number);

        // Return the digit at the position
        return numberStr[indexInNumber] - '0';
    }
};
```

---

## Logic & Explanation

### Step 1: Determine Digit Length Group
- Numbers have:
  - 1-digit: 1 to 9 → 9 digits
  - 2-digit: 10 to 99 → 90 × 2 = 180 digits
  - 3-digit: 100 to 999 → 900 × 3 = 2700 digits
- Loop subtracts group sizes from `n` to narrow down which digit-length group contains the n-th digit.

### Step 2: Find the Exact Number
```cpp
int number = pow(10, numDigits - 1) + (n - 1) / numDigits;
```
This gives the actual number in the digit stream that contains the `n-th` digit.

### Step 3: Extract the Digit
```cpp
string numberStr = to_string(number);
return numberStr[indexInNumber] - '0';
```
Converts the number to a string and accesses the desired digit using indexing.

---

## Example Dry Run: n = 15

- 1-digit numbers → 9 digits → `n = 15 - 9 = 6`
- Now in 2-digit range (`10, 11, 12, ...`)
- `number = 10 + (6 - 1)/2 = 12`
- `indexInNumber = (6 - 1) % 2 = 1`
- `numberStr = "12" → numberStr[1] = '2'`

Output: `2`

---

## Time and Space Complexity

| Operation | Complexity |
|-----------|------------|
| Time      | O(log₁₀n) (due to digit group looping and string conversion) |
| Space     | O(1) (constant extra space used) |

---

## Related Concepts

- Math (Digit distribution)
- Strings and indexing
- Greedy / Positional simulation
