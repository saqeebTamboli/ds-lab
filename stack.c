//stack display
#include<stdio.h>
#define max 5
int stack[max],top=-1;
void push(int data){
    if(top==max-1){
        printf("STACK OVERFLOW");
    }
    else{
        top++;
        stack[top]=data;
    }}
    void pop(){
        if(top<0){
            printf("STACK IS EMPTY,CANNOT POP ITEM");
            
        }
        else{
            printf("%d POPED FROM STACK",stack[top]);
            top--;
        }}
        void display(){
            if(top<0){
            printf("UNDERFLOW!!!!!!!!!!");
        }
        
        else{
            printf("THE STACK IYTEMS ARE---");
            for(int i=top;i>=0;i--){
                printf("%d\t",stack[i]);
                
            }
        }
        }    
    int main(){
        int choice,value;
        while(1){
            printf("\n ENTER YOUR CHOICE:::\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT \n");
            scanf("%d",&choice);
            switch(choice){
                case 1:printf("ENTER ITEM YOU WANT TO PUSH:");
                       scanf("%d",&value);
                       push(value);
                       break;
                case 2:pop();
                break;
                case 3:display();
                break;
                case 4:return 0;
                default:printf("INVALID");
            }
        }
        return 0;
    }
            