#include <iostream>
#include <stack>
#include <string>

bool isValidExpression(const std::string& expression) {
    std::stack<char> st;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    std::string expression1; // Invalid
    std::cin >> expression1;
    if(isValidExpression(expression1) == 1)
        std::cout << "true";
    else std::cout << "false";
    return 0;
}
