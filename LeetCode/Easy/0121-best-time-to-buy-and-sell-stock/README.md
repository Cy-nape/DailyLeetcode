# Stock Price Maximization

## Overview
This repository contains an optimized **O(n)** solution for calculating the **maximum profit** that can be achieved by buying and selling a stock on different days.

## Problem Statement
Given an array `prices` where `prices[i]` represents the price of a stock on the **i-th day**, determine the maximum profit that can be obtained **by choosing a single day to buy** and a later day to **sell**.

If no profit can be made, return `0`.

### **Example 1**
```cpp
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 6-1 = 5.
```

### **Example 2**
```cpp
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No profitable transactions, return 0.
```

## Solution Approach
The approach leverages **Kadane’s Algorithm-like logic**:
1. **Track the lowest price** encountered (`minPrice`).
2. **Calculate the possible profit** for each day (`price - minPrice`).
3. **Update maxProfit** whenever a higher profit is found.

### **Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);  
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
```

### **Complexity Analysis**
- **Time Complexity**: `O(n)`, since we traverse the array once.
- **Space Complexity**: `O(1)`, as we only use a few variables.

## Edge Cases Considered
- **All prices decreasing** → No profit possible (`Output: 0`).
- **Only one price available** → Not enough data to trade (`Output: 0`).
- **Constant prices** → No profit (`Output: 0`).

