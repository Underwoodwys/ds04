#include<stdio.h>
#include<stdlib.h>
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;
//以不带头节点的循环单链表表示队列
//只设一个指针指向队尾节点 不设头指针
QueuePtr rear;

int Init(QueuePtr &rear){
    /*
    rear=(QueuePtr)malloc(sizeof(QNode));
    if(!rear) return 0;
    rear->next=rear;
    return 1;
    */
    rear=NULL;
    return 1;
}
int Input(QueuePtr &rear,int data){
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) return 0;
    p->data=data;
    /*
    p->next=rear->next;
    rear->next=p;
    rear=p;
    */
    if(!rear) {rear=p;rear->next=rear;}
    else {p->next=rear->next;rear->next=p;
    rear=p;}
    return 1;
}
int Delete(QueuePtr &rear){
    if(!rear) return 0;
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) return 0;
    p=rear->next;
    rear->next=p->next;
    free(p);
    return 1;
}

void Print(QueuePtr rear){
    if(!rear) printf("队列中无元素！\n");
    printf("%d\n",rear->next->data);




}


int main(void){
    Init(rear);
    Input(rear,4);
    Input(rear,8);
    Print(rear);
    Delete(rear);
    Print(rear);
    return 0;
}






