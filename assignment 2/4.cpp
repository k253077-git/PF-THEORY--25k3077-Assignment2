#include <stdio.h>

int push(int stack[], int top, int maxsize){
	int value;
    if(top == maxsize - 1) {       
        printf("Stack Overflow, Cannot push more elements");
    }else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack", value);
    }
    return top;
}

int pop(int stack[], int top){
	if(top == -1){
		printf("Stack underflow, No element to pop");
	}else {
		printf("%d popped from stack", stack[top]);
		top--;
	}
    return top;
}

void peek(int stack[], int top) {
    if(top == -1)
        printf("Stack is empty");
    else
        printf("Top element is: %d", stack[top]);
}

void display(int stack[], int top){
	if(top == -1){
		printf("stack is empty");
	}else {
		printf("stack elements are:\n");
		for(int i = top; i >= 0; i--){
			printf("%d\n",stack[i]);
		}
	}
}

int main(){
	int stack[10];
	int top = -1;
	int choice, size;
	
	printf("Enter the size of stack: ");
	scanf("%d", &size);
	
	do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            top = push(stack, top, size);
        else if(choice == 2)
            top = pop(stack, top);
        else if(choice == 3)
            peek(stack, top);
        else if(choice == 4)
            display(stack, top);
        else if(choice == 5)
            printf("Thank you\n");
        else
            printf("Invalid choice\n");

    } while(choice != 5);

    return 0;
}
