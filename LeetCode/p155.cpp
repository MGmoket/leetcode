/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> _stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        //_stack.resize(16);
    }

    void push(int x) {
        _stack.push_back(x);
    }

    void pop() {
        _stack.pop_back();
    }

    int top() {
        if (_stack.size() != 0) return _stack.back();
        return -1;
    }

    int getMin() {
        if (_stack.size() == 0) return -1;
        int minVal = _stack.front();
        for (int i : _stack) {
            if (i < minVal) {
                minVal = i;
            }
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */