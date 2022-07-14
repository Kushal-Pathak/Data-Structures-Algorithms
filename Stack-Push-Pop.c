#include<stdio.h>
#include<stdlib.h>
#define size 4
//Below is the structure of stack being defined which contains an array to hold data and an integer to keep track of top of stack.
struct stack{
	int data[size];
	int tos;
};
//Giving a new data type name to struct stack, programmer can now write 'stk' instead of 'struct stack'
typedef struct stack stk;
//Declaring push function which takes pointer of type stk and an integer as parameters.
void push(stk *, int);
//Declaring pop function which takes pointer type of stk as parameter.
void pop(stk *);
//Declaring display function.
void display(stk *);
void main(){
	int choice, dat;
	//Declaring a new stk pointer s.
	stk *s;
	//Allocating memory for the stack and storing its address in pointer s.
	s=(stk*)malloc(sizeof(stk));
	//Stack start from 0th position and ends at 4th position in this program.
	/*Declaring top of stack(tos) to be -1. Top of stack can't be 0 in the beginning or if stack is empty, 
	because top of stack is the latest top position which holds latest data, since 0th position holds no data right now so tos=-1 */
	s->tos=-1;
	printf("Welcome to Stack Operations\n");
	printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n---------------------------\n");
	while(1){
		printf("Enter the choice: ");
		scanf("%d", &choice);
			switch(choice){
		case 1:
			printf("Enter data to push: ");
			scanf("%d", &dat);
			push(s, dat);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			display(s);
			break;
		case 4:
			printf("Exiting...");
			exit(1);
		default:
			printf("Invalid choice\n");
	}
	}
	//Freeing the allocated memory for stack.
	free(s);
}
//Defining push function, pushes integer x to stack pointed by the pointer a.
void push(stk *a, int x){
	//Checking if stack is full, if stack is not full then push data to top of stack + 1th position, otherwise do nothing.
	if(a->tos < size-1){
		a->tos++;
		a->data[a->tos]=x;
		printf("Pushed %d to stack\n", a->data[a->tos]);
	}else{
		printf("Cannot Push, Stack Overflow!\n");
	}
}
//Defining pop function, does pop operation on the stack pointed by a.
void pop(stk *a){
	/*Checking if stack is empty, if stack is not empty then display the data on top of stack and decrement tos variable by 1, 
	otherwise do nothing.*/
	if(a->tos == -1){
		printf("Cannot Pop Empty Stack!\n");
	}else{
		printf("Pop: %d\n", a->data[a->tos]);
		a->tos--;
	}
}
//Defining display function, displays all the data stored in the stack.
void display(stk *a){
	int i;
	//Checking if stack is empty, if stack is not empty then display all the data on it using loop, otherwise do nothing.
	if(a->tos==-1){
		printf("No data to show, Empty Stack!\n");
	}else{
		printf("Displaying stack: ");
		for(i = 0; i <= a->tos; i++){
			printf("%d ", a->data[i]);
		}
		printf("\n");
	}
}










