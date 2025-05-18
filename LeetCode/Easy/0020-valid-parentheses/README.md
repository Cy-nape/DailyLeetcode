# Valid Parentheses Checker

## Overview
This repository contains an optimized **O(n)** solution for checking whether a given string of brackets (`()`, `{}`, `[]`) is **balanced and properly nested**.

## Problem Statement
Given a string `s` consisting of **only parentheses characters** (`(`, `)`, `{`, `}`, `[`, `]`), determine if the brackets are **valid**.

A string is considered **valid** if:
- Every **open bracket** has a corresponding **close bracket**.
- Brackets are **nested correctly** (e.g., `{[()]}` is valid, but `{[(])}` is not).

### **Example 1**
```cpp
Input: s = "{[()]}"
Output: true
Explanation: All brackets are correctly matched.
```

### **Example 2**
```cpp
Input: s = "(]"
Output: false
Explanation: Open bracket `(` does not have a corresponding `)`.
```

## Solution Approach
This approach utilizes a **stack data structure**:
1. **Push open brackets** (`(`, `{`, `[`) onto the stack.
2. **On encountering close brackets** (`)`, `}`, `]`):
   - Check if the **stack is empty** (invalid case).
   - Compare with the **top of the stack** to ensure proper matching.
   - If matched, **pop** the stack; otherwise, return **false**.
3. **At the end**, check if the stack is **empty**. If yes, the brackets are balanced.

### **Implementation**
```cpp
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s = "{[()]}";
    cout << (isValid(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
```

### **Complexity Analysis**
- **Time Complexity**: `O(n)`, since each character is processed once.
- **Space Complexity**: `O(n)`, in the worst case where all characters are open brackets.

