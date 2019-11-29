#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* arrL[100];
struct node* arrR[100];
//___________________________________________ARRAY SE 2 STACKS BANAYE__________________________________________

int top=-1;
void pushL(struct node* temp){
    top++;
   arrL[top] = temp;
}
int top2 = -1;
void pushR(struct node* temp){
    top2++;
    arrR[top2] = temp;
}

struct node* popL(){
    top--;
    return arrL[top+1];
}
struct node* popR(){
    top2--;
    return arrR[top2+1];
}
//______________________________________________________________________________________________________________

struct node* head = NULL;

void display(struct node* head){
    if(head == NULL)
    {
        return;
    }

    else{
        display(head->left);
        printf("%d ->",head->data);
        display(head->right);
    }

}

void insert(int inp, struct node* head){
    if(inp < head->data && head->left == NULL){
            struct node* new2 = (struct node*)malloc(sizeof(struct node));
            new2->left = NULL;
            new2->right = NULL;
            new2->data = inp;
            head->left = new2;
    }

    else if(inp< head->data&& head->left !=NULL){
        insert(inp,head->left);
    }

    else if(inp > head->data && head->right == NULL){
            struct node* new2 = (struct node*)malloc(sizeof(struct node));
            new2->left = NULL;
            new2->right = NULL;
            new2->data = inp;
            head->right = new2;
    }

    else if(inp> head->data&& head->right !=NULL){
        insert(inp,head->right);
    }

}
int a=0;
int count = 0;
void zigzag(struct node* head){

    if(count == 0 && top == -1 && top2 == -1){
        pushL(head);
        goto label;
    }
    else if(top2 == -1){
        while(top!=-1)
        {
            if(arrL[top]->left != NULL) pushR(arrL[top]->left);
            if(arrL[top]->right != NULL) pushR(arrL[top]->right);
            printf("%d ->",arrL[top]->data);
            popL();
        }
        goto label;
    }


    else if(top == -1){
        while(top2!=-1)
        {
            if(arrR[top2]->right != NULL) pushL(arrR[top2]->right);
            if(arrR[top2]->left != NULL) pushL(arrR[top2]->left);
            printf("%d ->",arrR[top2]->data);
            popR();
        }
    }
    label:
    count++;
    zigzag(head);
}

void main()
{
    int n;
    while(n!=3)
    {
        printf("\n1 Insert\n2 Inorder Display\n3 Zig Zag Traversal\n4 Exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                int inp;
                printf("Data: ");
                scanf("%d",&inp);
                if(head == NULL){
                        struct node* new2 = (struct node*)malloc(sizeof(struct node));
                        new2->left = NULL;
                        new2->right = NULL;
                        new2->data = inp;
                        head = new2;
                }

                else{
                    insert(inp,head);
                }
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 4:{
                return;
                break;
            }

            case 3:{
                zigzag(head);
                break;
            }
        }
    }

}
