#include <iostream>
#include <stack>

void calculateSpan(int price[], int n, int S[]){
    //create a stack and push index of first
    // element to it
    std::stack<int> st;
    st.push(0);

    //span value of first element is always 1
    S[0]=1;

    //calculate span values for the rest of the elements
    for (int i=1; i<n;i++){
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()]<=price[i]){
            st.pop();
        }
        // If statck becomes empty; the price[i] is
        // greater than all elementes on left of it,
        // i.e, price[0], price[1], ... price [i-1].
        // Else price[i] is greater then elements afeter
        // top of stack
        S[i]= (st.empty()) ? (i+1) : (i-st.top());

        //Push this element to stack
        st.push(i);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
