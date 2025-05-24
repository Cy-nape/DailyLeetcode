# Implementing a Stack Using Two Queues

## Introduction
This repository contains an implementation of a **Last-In-First-Out (LIFO) stack** using **two queues**. The solution provides standard stack operations (`push`, `pop`, `top`, and `empty`) while respecting queue constraints.

## Problem Statement
You need to implement a **stack** using only two **queues**, supporting the following operations:
- **push(x)** → Pushes element `x` onto the stack.
- **pop()** → Removes the top element of the stack.
- **top()** → Returns the top element.
- **empty()** → Returns `true` if the stack is empty, `false` otherwise.

### **Example Usage**
#### Example 1:
```cpp
Input:
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]

Output:
[null, null, null, 2, 2, false]
```

#### Explanation:
```cpp
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top();    // returns 2
myStack.pop();    // returns 2
myStack.empty();  // returns False
```

---

## **Approach**
### **Using Two Queues (`q1` and `q2`)**
1. `q1` stores elements in correct **LIFO order**.
2. `q2` helps reorganize elements during `push`.

### **Algorithm**
- **Push(x)**:
  - Insert `x` into `q2`.
  - Transfer all elements from `q1` into `q2` (this ensures `x` is at the front).
  - Swap `q1` and `q2` to maintain correct order.

- **Pop()**:
  - Remove the front element from `q1`.

- **Top()**:
  - Return the front element of `q1`.

- **Empty()**:
  - Check if `q1` is empty.

---

## **Code Implementation**
```cpp
#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2; // Two queues for stack functionality

public:
    MyStack() { }
    
    void push(int x) {
        q2.push(x); // Push new element into q2

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 (q1 now holds elements in correct order)
        std::swap(q1, q2);
    }
    
    int pop() {
        if (q1.empty()) return -1; // Handle empty stack case
        int topElement = q1.front(); // Get the top element
        q1.pop(); // Remove it
        return topElement;
    }
    
    int top() {
        return q1.empty() ? -1 : q1.front(); // Return top element
    }
    
    bool empty() {
        return q1.empty(); // Return true if stack is empty
    }
};
```

---

## **Complexity Analysis**
| Operation | Time Complexity | Explanation |
|------------|---------------|-------------|
| **Push(x)**  | **O(n)** | Rearranges elements to maintain LIFO order |
| **Pop()**    | **O(1)** | Directly removes the top element |
| **Top()**    | **O(1)** | Directly returns the top element |
| **Empty()**  | **O(1)** | Checks if `q1` is empty |
