#include <iostream>  //C++ IO
//#include <cstdio>    //C   IO
//#include <stdlib.h>
#define null 0
using namespace std;

typedef struct listNode *listPointer;
typedef struct listNode{
    int value;
    listPointer next;
};
void printall(listNode *p);                                      // 印出 linklist 的所有內容
listPointer addlistNode(listNode *p,int n);                // 加入一個節點 順便作Sorting
listPointer reverselist(listNode *p);                         // 反轉list
listPointer combinelist(listNode *p1,listNode *p2);   // 結合兩個List

int main() {
    int a[10]={0,9,8,8,6,3,2,1,5,4};
    listPointer start1=NULL;
    for(int i=0;i<10;i++){
        start1=addlistNode(start1,a[i]);
    }
    printall(start1);
    start1=reverselist(start1);
    printall(start1);
    start1=reverselist(start1);
    printall(start1);
    int b[10]={3,7,0,4,6,9,1,2,5,7};
    listPointer start2=NULL;
    for(int i=0;i<10;i++){
        start2=addlistNode(start2,b[i]);
    }
    printall(start2);
    listPointer result=NULL;
    result=combinelist(start1,start2);
    printall(result);
    return 0;
}

void printall(listNode *p){
    bool first = true;
    while(p != null) {
        if(!first) cout << ' ';
        cout << p->value;
        p = p->next;
    }
    cout << endl;
}
listPointer addlistNode(listNode *p,int n){
    listPointer temp = p;//暫存p的位置
    // 建立新節點
    listPointer pnewNode = new listNode;
    pnewNode->value = n;
    pnewNode->next = null;

    if(p != null) {
        // 先判斷此list為升冪或是降冪
        if(p->next != null) {
            // 若降冪則反轉
            if(p->value > p->next->value) {reverselist(p);temp = p;}//p的value > p的下一格的value
            // 找到 fore_node.value <= n 的位置插入
            listPointer pForeNode = null;
            while(p != null and p->value < n) {//
                pForeNode = p;//現在的指標會變成等一下的"前一個"
                p = p->next;//移動到下一格
            }

            // 小於第一個節點
            if(pForeNode == null) temp = pnewNode;//判斷如果n是最小的 list指標就直接接新節點
            else pForeNode->next = pnewNode;//反之就把新節點接到list的某一段  pf -> pn -> p
            pnewNode->next = p;//p指到的地方給next指
        } else {
            // 若list中僅一個節點則直接判斷大小後插入
            if(p->value < n) p->next = pnewNode;
            else {pnewNode->next = p;temp = pnewNode;}
        }
    } else {
        temp = pnewNode;
    }

    // 回傳原list開頭
    return temp;
}
listPointer reverselist(listNode *p){
    listPointer fore = null;
    // 當後方還有節點時，將現有的節點指向前面的節點
    while(p != null) {
        listPointer next = p->next;
        p->next = fore;
        fore = p;//暫存p
        if(next == null) break;
        p = next;
    }//       fore <- p
    return p;
}
listPointer combinelist(listNode *p1,listNode *p2){
    listPointer temp = p1;
    // 將指標移動到最後一個節點
    if(p1 != null) while(p1->next != null) p1 = p1->next;
    // 將list p2的頭節點位置給list p1的尾
    p1->next = p2;
    return temp;
}
