#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void decimalToBinary(unsigned int n) {
    stack<int> st;

    if (n == 0) {
        cout << 0;
        return;
    }

    while (n > 0) {
        st.push(n % 2);
        n /= 2;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

unsigned int binaryToDecimal(const char binary[]) {
    queue<int> q;

    for (int i = 0; binary[i] != '\0'; i++) {
        q.push(binary[i] - '0');
    }

    unsigned int decimal = 0;
    while (!q.empty()) {
        decimal = decimal * 2 + q.front();
        q.pop();
    }

    return decimal;
}

void decimalToHex(unsigned int n) {
    stack<char> st;

    if (n == 0) {
        cout << 0;
        return;
    }

    while (n > 0) {
        int remainder = n % 16;
        if (remainder < 10) {
            st.push(remainder + '0');
        }
        else {
            st.push(remainder - 10 + 'A');
        }
        n /= 16;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

unsigned int hexToDecimal(const char hex[]) {
    queue<char> q;

    for (int i = 0; hex[i] != '\0'; i++) {
        q.push(toupper(hex[i]));
    }

    unsigned int decimal = 0;
    while (!q.empty()) {
        char digit = q.front();
        q.pop();
        if (digit >= '0' && digit <= '9') {
            decimal = decimal * 16 + (digit - '0');
        }
        else if (digit >= 'A' && digit <= 'F') {
            decimal = decimal * 16 + (digit - 'A' + 10); 
        }
    }

    return decimal;
}

