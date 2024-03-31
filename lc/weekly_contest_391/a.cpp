#include <bits/stdc++.h>

using namespace std;

/*
An integer divisible by the sum of its digits is said to be a Harshad number.
You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.
Input: x = 18

Output: 9

Explanation:

The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number and the answer is 9.
*/

int sumOfTheDigitsOfHarshadNumber(int x) {
    string numStr = to_string(x);
    int sumDigits = 0;
    for (auto& c: numStr) {
        sumDigits += (c - '0');
    }
    return x % sumDigits == 0 ? sumDigits : -1;
}

int main() {
    // Test 1
    int x = 18;
    int ans = sumOfTheDigitsOfHarshadNumber(x);
    cout << ans << endl;

    // Test 1
    x = 23;
    ans = sumOfTheDigitsOfHarshadNumber(x);
    cout << ans << endl;
    return 0;
}