#include  <iostream>
#include <string>
#include <stack>
#include <map>

int prec(const char chr) {
	if (chr == '+' || chr == '-') return 1;
	else if (chr == '*' || chr == '/') return 2;
	else return 0;
}

void infixToPostfix(std::string infix, std::string& postfix)
{

	std::stack<char> st;

	for (auto i = infix.begin(); i != infix.end(); i++) {
		char c = *i;

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			postfix += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty()
				&& prec(c) <= prec(st.top())) {
				if (c == '^' && st.top() == '^')
					break;
				else {
					postfix += st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
}

template <typename T>
T evaluatePostfix(const std::string postfix) {
	std::stack<T> stk;
	for (auto i = postfix.begin(); i != postfix.end(); i++) {
		if (*i >= 48 && *i <= 57) {
			stk.push(*i - 48);
		}
		else {
			T val1 = stk.top(); stk.pop();
			T val2 = stk.top(); stk.pop();
			switch (*i) {
			case '+': stk.push(val1 + val2); break;
			case '-': stk.push(val1 - val2); break;
			case '*': stk.push(val1 * val2); break;
			case '/': stk.push(val1 / val2); break;
			}
		}
	}

	return stk.top();
}


int main() {
	std::string infix;
	std::string postfix;

	infix = "3+4*5";
	infixToPostfix(infix, postfix);
	std::cout << infix << " ==>> " << postfix << std::endl;

	infix = "((3+4)*5)*5";
	postfix = "";
	infixToPostfix(infix, postfix);
	std::cout << infix << " ==>> " << postfix << std::endl;

	std::cout << evaluatePostfix<double>("34+5*5*7/") << std::endl;
}