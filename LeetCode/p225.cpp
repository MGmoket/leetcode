/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <queue>

using namespace std;
namespace p225 {

    class MyStack {
        queue<int> stage;
    public:
        /** Initialize your data structure here. */
        MyStack() {
        }

        /** Push element x onto stack. */
        void push(int x) {
            stage.push(x);
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            for (size_t i = 1; i < stage.size(); ++i) {
                stage.push(stage.front());
                stage.pop();
            }
            int ret = stage.front();
            stage.pop();
            return ret;
        }

        /** Get the top element. */
        int top() {
            return stage.back();
        }

        /** Returns whether the stack is empty. */
        bool empty() {
            return stage.empty();
        }
    };

}


int test_p225_MyStack() {
    using namespace p225;

    MyStack stack;

    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.empty() << endl;

    return 0;
}


