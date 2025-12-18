#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        int ans=q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }
};

int main() {
    Stack st;

    st.push(5);
    st.push(3);

    cout << "Size: " << st.size() << endl;
    cout << "Top: " << st.top() << endl;

    st.pop();
    cout << "Top: " << st.top() << endl;

    st.pop();
    cout << "Empty: " << st.empty() << endl;

    cout<<st.pop()<<endl;;

    return 0;
}
