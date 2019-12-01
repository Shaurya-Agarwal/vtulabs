#include<stdio.h>
#include<string.h>

int i=0, j=0, k=0, len=0;
char input[16], action[20], stack[15], shift[10];

void check() {
	strcpy(action,"REDUCE TO E");
	for(k=0; k<len; k++)
		if(stack[k]=='i' && stack[k+1]=='d') {
			stack[k]='E';
			stack[k+1]='\0';
			printf("\n$%s\t%s$\t%s", stack, input, action);
			j++;
		}
	
	for(k=0; k<len; k++)
		if(stack[k]=='E' && stack[k+1]=='+' && stack[k+2]=='E') {
			stack[k]='E';
			stack[k+1]='\0';
			stack[k+2]='\0';
			printf("\n$%s\t%s$\t%s", stack, input, action);
			i=i-2;
		}
	
	for(k=0; k<len; k++)
		if(stack[k]=='E' && stack[k+1]=='*' && stack[k+2]=='E') {
			stack[k]='E';
			stack[k+1]='\0';
			stack[k+2]='\0';
			printf("\n$%s\t%s$\t%s", stack, input, action);
			i=i-2;
		}
	
	for(k=0; k<len; k++)
		if(stack[k]=='(' && stack[k+1]=='E' && stack[k+2]==')') {
			stack[k]='E';
			stack[k+1]='\0';
			stack[k+2]='\0';
			printf("\n$%s\t%s$\t%s",stack,input,action);
			i=i-2;
		}
}

int main() {
	puts("GRAMMAR is\nE->E+T|T\nT->T*F|F\nF->(E)|id\n");
	puts("Enter input string:");
	fgets(input, 9, stdin);
	
	len = strlen(input);
	strcpy(shift, "SHIFT->");
	
	puts("\nStack\tInput\t\tAction");
	// i - stack index
	// j- input index
	for(i=0, j=0; j<len; i++,j++) {
		if(input[j]=='i' && input[j+1]=='d') { // id
			stack[i]=input[j];
			stack[i+1]=input[j+1];
			stack[i+2]='\0';
			
			input[j]=' ';
			input[j+1]=' ';
			
			printf("\n$%s\t%s$\t%sid", stack, input, shift);
			check();
		} else { // symbol
			stack[i]=input[j];
			stack[i+1]='\0';
			input[j]=' ';
			printf("\n$%s\t%s$\t%ssymbol", stack, input, shift);
			check();
		}
	}
	printf("\n\nString accepted\n");
	return 0;
}
