class Solution {
public:
	int longestValidParentheses(string &x) {

		int ans = 0;
		stack<int> s;

		s.push(0);

		for (int i = 1; i < x.size(); ++i)
		{
			if (x[i] == '(' || s.empty()) {
				s.push(i);
			}
			else {
				if (x[s.top()] == '(') {
					s.pop();

					if (s.empty()) ans = max(ans, i + 1);
					else ans = max(ans, i - s.top());
				}
				else {
					s.push(i);
				}
			}
		}

		return ans;
	}
};