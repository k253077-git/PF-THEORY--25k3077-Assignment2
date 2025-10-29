#include <stdio.h>

void push(int stack[], int *top, int maxsize){
	int value;
    if(*top == maxsize - 1) {        // maxsize-1 represent index value
        printf("Stack Overflow, Cannot push more elements");
    }else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d pushed into stack", value);
    }
}

void pop(int stack[], int *top){
	if(*top==-1){
		printf("Stack underflow, No element to pop");
	}else {
		printf("%d popped from stack", stack[*top]);
		(*top)--;
	}
}

void peek(int stack[], int top) {
    if(top == -1)
        printf("Stack is empty");
    else
        printf("Top element is: %d", stack[top]);
}

void display(int stack[], int top){
	if(top==-1){
		printf("stack is empty");
	}else {
		printf("stack elements are:\n");
		for(int i=top; i>0;i--){
			printf("%d\n",stack[i]);
		}
	
	}
}


int main(){
	int stack[10];
	int top= -1;
	int choice ,size;
	
	printf("Enter the size of stack: ");
	scanf("%d",&size);
	
	do {
        printf("\n--- Stack Menu ---\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        if(choice == 1)
            push(stack, &top, size);
        else if(choice == 2)
            pop(stack, &top);
        else if(choice == 3)
            peek(stack, top);
        else if(choice == 4)
            display(stack, top);
        else if(choice == 5)
            printf("Thankyou\n");
        else
            printf("Invalid choice\n");

    } while(choice != 5);

    return 0;
}

