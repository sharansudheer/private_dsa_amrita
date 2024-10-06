#include <iostream>
#include <stack>

using namespace std;

// Function to combine two stacks S1 and S2
stack<int> combineStacks(stack<int> S1, stack<int> S2) {
    stack<int> tempStack;  // Temporary stack to help with ordering
    stack<int> resultStack; // Final result stack

    // Ensure both stacks have the same number of elements (alternating elements)
    while (!S1.empty() || !S2.empty()) {
        if (!S1.empty()) {
            tempStack.push(S1.top()); // Push element from S1 into tempStack
            S1.pop();
        }
        if (!S2.empty()) {
            tempStack.push(S2.top()); // Push element from S2 into tempStack
            S2.pop();
        }
    }

    // Now, pop from tempStack and push into resultStack to maintain order
    while (!tempStack.empty()) {
        resultStack.push(tempStack.top());
        tempStack.pop();
    }

    return resultStack;
}

// Helper function to print the stack elements
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Define two sample stacks S1 and S2
    stack<int> S1, S2;

    // Push elements into S1
    S1.push(3);
    S1.push(2);
    S1.push(1);

    // Push elements into S2
    S2.push(6);
    S2.push(5);
    S2.push(4);

    // Combine the two stacks
    stack<int> resultStack = combineStacks(S1, S2);

    // Print the result
    cout << "Combined stack (alternating S1 and S2): ";
    printStack(resultStack);

    return 0;
}
