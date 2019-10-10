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
void printall(listNode *p);                                      // �L�X linklist ���Ҧ����e
listPointer addlistNode(listNode *p,int n);                // �[�J�@�Ӹ`�I ���K�@Sorting
listPointer reverselist(listNode *p);                         // ����list
listPointer combinelist(listNode *p1,listNode *p2);   // ���X���List

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
    listPointer temp = p;//�Ȧsp����m
    // �إ߷s�`�I
    listPointer pnewNode = new listNode;
    pnewNode->value = n;
    pnewNode->next = null;

    if(p != null) {
        // ���P�_��list���ɾ��άO����
        if(p->next != null) {
            // �Y�����h����
            if(p->value > p->next->value) {reverselist(p);temp = p;}//p��value > p���U�@�檺value
            // ��� fore_node.value <= n ����m���J
            listPointer pForeNode = null;
            while(p != null and p->value < n) {//
                pForeNode = p;//�{�b�����з|�ܦ����@�U��"�e�@��"
                p = p->next;//���ʨ�U�@��
            }

            // �p��Ĥ@�Ӹ`�I
            if(pForeNode == null) temp = pnewNode;//�P�_�p�Gn�O�̤p�� list���дN�������s�`�I
            else pForeNode->next = pnewNode;//�Ϥ��N��s�`�I����list���Y�@�q  pf -> pn -> p
            pnewNode->next = p;//p���쪺�a�赹next��
        } else {
            // �Ylist���Ȥ@�Ӹ`�I�h�����P�_�j�p�ᴡ�J
            if(p->value < n) p->next = pnewNode;
            else {pnewNode->next = p;temp = pnewNode;}
        }
    } else {
        temp = pnewNode;
    }

    // �^�ǭ�list�}�Y
    return temp;
}
listPointer reverselist(listNode *p){
    listPointer fore = null;
    // �����٦��`�I�ɡA�N�{�����`�I���V�e�����`�I
    while(p != null) {
        listPointer next = p->next;
        p->next = fore;
        fore = p;//�Ȧsp
        if(next == null) break;
        p = next;
    }//       fore <- p
    return p;
}
listPointer combinelist(listNode *p1,listNode *p2){
    listPointer temp = p1;
    // �N���в��ʨ�̫�@�Ӹ`�I
    if(p1 != null) while(p1->next != null) p1 = p1->next;
    // �Nlist p2���Y�`�I��m��list p1����
    p1->next = p2;
    return temp;
}
