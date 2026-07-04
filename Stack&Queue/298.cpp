class twoStacks {
  public:
  
    int *arr;
    int top1;
    int top2;
    int size;

    twoStacks() {
        this->size = 200;
        arr = new int[200];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top1 +1 < top2 && top1 < size-1){
            top1++;
            arr[top1] = x;
        }
        else{
            return;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(top1 +1 < top2 && top2 >= 0){
            top2--;
            arr[top2] = x;
        }
        else{
            return;
        }
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(top1 == -1){
            return -1;
        }
        return arr[top1--];
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2 == size){
            return -1;
        }
        return arr[top2++];
    }
};