#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include"printVector.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//链表有head和p，head为头节点，p为普通结点。
//删除重复元素的函数
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p=head;
    if(p==nullptr) return head;
    while(p->next!= nullptr){
        if(p->next->val==p->val){       //头节点带数据
            p->next=p->next->next;
            //要不要删被丢弃的那个内存？
        }else{
            p=p->next;
        }
    }
    return head;        //返回链表
}

//两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head=nullptr,*p= nullptr;    //新建一个链表,p为普通结点
    int ret=0,temp=0,x1=0,x2=0;
    while(l1!= nullptr || l2!= nullptr){
        x1=l1?l1->val:0;
        x2=l2?l2->val:0;
        temp=x1+x2+ret;
        if(head== nullptr){     //后续要返回head这个链表
            head=p=new ListNode(temp%10);
        }else{
            p->next=new ListNode(temp%10);
            p=p->next;
        }
        ret=temp/10;
        if(l1!=nullptr){l1=l1->next;}    //更新l1,l2 指针指向
        if(l2!=nullptr){l2=l2->next;}
    }
    if(ret>0){
        p->next = new ListNode(ret);
    }
    return head;
}

//尾插法:head为头节点，其余的为普通结点
ListNode * createListNode3(int x,ListNode *head){
    cout<<"尾插法建链表"<<endl;
    ListNode *p= nullptr;
    int ret=0;
    for(int i=0;i<x;i++){
        cout<<"请输入结点值:"<<endl;
        cin>>ret;
        if(head== nullptr){     //不能操纵空指针
            head=p=new ListNode(ret);
        }else{
            p->next=new ListNode(ret);  //先开辟普通结点
            p=p->next;
        }
    }
    return head;
}

//头插法：创建一个逆序存储的链表函数
ListNode * createListNode2(int x,ListNode *head){
    cout<<"头插法建链表"<<endl;
    ListNode *p= nullptr;
    int ret=0;
    for(int i=0;i<x;i++){
        cout<<"请输入结点的值"<<endl;
        cin>>ret;
        if(head== nullptr){
            head=new ListNode(ret);
        }else{
            p=new ListNode(ret);    //新开辟的给p
            p->next=head;
            head=p;     //更新头节点
        }
    }
    return head;
}

//输出结构体数组的打印函数
void showStruct(ListNode* head){
    ListNode *p=head;
    if(p==nullptr)  cout<<"链表为空"<<endl;
    while(p!= nullptr){
        if(p->next!=nullptr){
            cout<<p->val<<"->";
        }else{
            cout<<p->val;
        }
        p=p->next;
    }
}

int main(){
    struct ListNode *p1= nullptr,*p2= nullptr,*p3= nullptr;
    p1= createListNode2(3,p1);
    p2= createListNode2(3,p1);
    // p1=deleteDuplicates(p1);
    showStruct(addTwoNumbers(p1,p2));
    return 0;
}


