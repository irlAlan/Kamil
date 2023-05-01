#include "../../include/Kamil/Utils/Stack.h"

int main(){
    Command::Stack<int> st{5};
    st.push(5);
    st.push(7);
    st.printStack();

    return 0;
}
