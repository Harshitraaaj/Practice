#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack_array[max];
int top = -1;

void push(int data){
if(top==max){
    printf("stackoverflow\n");
    return;
}
    top+=1;
    stack_array[top]=data;
}
void print(){
    if(top==-1){
        printf("stackunderflow\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\t",stack_array[i]);
    
    }
    printf("\n");
}
int pop(){
    if(top==-1){
        printf("stackunderflow\n");
        exit(1);
    }
    int value;
    value=stack_array[top];
    top-=1;
    return value;
}

int main(){
    int data;
    push(2);
    push(6);
    push(80);
    
    data=pop();
   printf("%d",data);
   return 0;
}