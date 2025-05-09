# 💡 Bulb Switcher Problem - Explanation

## 🧩 Problem Statement

You are given **`n` bulbs**, all initially **off**.

You perform `n` rounds of operations:

- **Round 1**: Turn **on** all bulbs.
- **Round 2**: Toggle every **2nd** bulb.
- **Round 3**: Toggle every **3rd** bulb.
- ...
- **Round i**: Toggle every **ith** bulb.
- ...
- **Round n**: Toggle the **nth** bulb (if exists).

Each bulb will be toggled in rounds corresponding to its divisors.

---

## ✅ Goal

Return the **number of bulbs that are on** after `n` rounds.

---

## 🔍 Example

### Input: `n = 3`

- Initial state: `[off, off, off]`
- Round 1 (all bulbs toggled): `[on, on, on]`
- Round 2 (every 2nd): `[on, off, on]`
- Round 3 (every 3rd): `[on, off, off]`

✅ Output: `1` (Only 1st bulb is on)

---

## 🔢 Key Insight

A bulb at position `i` is toggled in each round `k` where `k` is a **divisor of `i`**.

- So, the number of times a bulb is toggled = number of divisors of its position index.
- Most numbers have **even number of divisors** (pairs like (1, i), (2, i/2)).
- But **perfect squares** have **odd number of divisors**. (E.g., 9 has 1, 3, 9 — because 3×3 counts only once)

Hence, **only bulbs at positions which are perfect squares will remain ON** after all rounds.

---

## ✨ Final Formula

Count of bulbs that are ON = **Number of perfect squares ≤ n**

➡️ Which is simply:  
```cpp
return floor(sqrt(n));
