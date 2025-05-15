# Judge Square Sum

## Code Explanation

### First Implementation:
```cpp
bool judgeSquareSum(int c) {
    int lo = 0;
    int hi = sqrt(c);

    while (lo <= hi) {
        long long sum = (long long)lo * lo + (long long)hi * hi;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            lo++;
        } else {
            hi--;
        }
    }

    return false;
}
```
#### Logic:
1. We initialize two pointers: `lo = 0` and `hi = sqrt(c)`, reducing the search space.
2. We check if `lo^2 + hi^2 == c`.
3. If the sum is less than `c`, we increment `lo` to get a larger sum.
4. If the sum is greater than `c`, we decrement `hi` to get a smaller sum.
5. The loop terminates when `lo > hi`, ensuring all possible combinations are tested.

### Second Implementation:
```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqrtNum = sqrt(num);
        return (sqrtNum * sqrtNum == num);
    }

    bool judgeSquareSum(int c) {
        int lo = 0;
        int hi = c;
        while (lo <= hi) {
            if (isPerfectSquare(lo) && isPerfectSquare(hi)) {
                return true;
            } else {
                lo++;
                hi--;
            }
        }
        return false;
    }
};
```
#### Logic:
1. This approach checks if both numbers `lo` and `hi` are perfect squares rather than calculating their squares directly.
2. The `isPerfectSquare()` function verifies whether a given number is a perfect square using `sqrt()` and squaring it again for confirmation.
3. We iterate from `lo = 0` to `hi = c`, checking whether both `lo` and `hi` are perfect squares.
4. If both numbers satisfy the condition, return `true`. Otherwise, continue the iteration.

## Time Complexity Comparison
### First Implementation:
- The loop runs approximately `O(sqrt(c))` times, making the time complexity **O(sqrt(c))**.
- This approach efficiently reduces the search space by leveraging the two-pointer technique.

### Second Implementation:
- The loop runs **O(c)** times in the worst case (linear iteration from `0` to `c`).
- The `isPerfectSquare()` function runs in **O(1)** time.
- Overall, the time complexity is **O(c)**, which is significantly less efficient than the first implementation.

## Conclusion
- The first implementation (`judgeSquareSum()`) utilizing the two-pointer approach is more efficient (`O(sqrt(c))`).
- The second implementation (`judgeSquareSum() with isPerfectSquare()`) is **less optimal** due to its linear time complexity (`O(c)`), making it impractical for large values of `c`.

