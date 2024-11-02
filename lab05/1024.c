#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    int data;
    struct t_node* left;
    struct t_node* right;
}t_node, *tree, *node;

node create_node(int data){
    node n = malloc(sizeof(t_node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
} 

tree insert(tree root, int data){
    if(root==NULL){
        return create_node(data);
    }

    if(data < root->data){
        root = insert(root->left, data);
    }
    else if(data > root->data){
        root = insert(root->right, data);
    }

    return root;
}

void pre_order(tree root){
    if(root==NULL){
        return;
    }

    printf("%d", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

node search(tree root, int data){
    if(root == NULL || root->data == data){
        return root;
    }

    if(data < root->data){
        return search(root->left ,data);
    }
    else{
        return search(root->right, data);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_struct{
    int *data;
    int top;
    int max_size;
}stack_struct, *Stack;

bool is_full(Stack s){
    return (s->top == s->max_size-1);
}

bool is_empty(Stack s){
    return (s->top == -1);
}

Stack create_stack(int max_size){
    Stack s = malloc(sizeof(stack_struct));
    s->data = malloc(max_size * sizeof(int));
    s->top = -1;
    s->max_size = max_size;
    return s;
}

bool push(Stack s, int item){
    if(is_full(s)){
        printf("stack is full\n");
        return false;
    }
    s->data[++(s->top)] = item;
    return true;
}

int pop(Stack s){
    if(is_empty(s)){
        printf("stack is empty\n");
        return -1;
    }
    int ele = s->data[s->top];
    s->top--;
    return ele;
}

void free_stack(Stack s){
    if(s!=NULL){
        free(s->data);
        free(s);    
    }
    return;
}

void validate(int max_size, int seq_length, int k_lines){
    // push sequence
    int push_seq[seq_length];
    for(int i=0; i<seq_length; i++){
        push_seq[i] = i+1;
    }
    
    while(k_lines--){
        // 准备工作，读入pop_seq
        Stack s = create_stack(max_size);
        int pop_seq[seq_length];
        for(int q=0; q<seq_length; q++){
            scanf("%d", &pop_seq[q]);
        }

        int w = 0;
        bool possible = true;
        for(int j=0; j<seq_length;j++){
            if(is_full(s)){
                possible = false;
                break;
            }
            push(s, push_seq[j]);
            while(s->data[s->top] == pop_seq[w] && w<seq_length && !is_empty(s)){
                pop(s);
                w++;
            }
        }

        if(is_empty(s) && possible){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        free_stack(s);
    }
    
}

int main(){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    validate(M,N,K);
}

// 用堆栈模拟中序遍历
void tree_stack(tree t){
    Stack s = malloc(sizeof(stack_struct));
    tree ptr = t;
    while(ptr || !is_empty(s)){
        while(t){
            push(s, ptr);
            ptr = ptr->left;
        }
        if(!is_empty(s)){
            ptr = pop(s);
            printf("%d", ptr->data);
            ptr = ptr->right; 
        }
    }
    free_stack(s);
}

void level_traversal(tree t){

    queue q = malloc(sizeof(q_struct));
    q.add(t);

    while(!q.isempty()){
        tree tmp = q.delete();
        printf();
        if(t->left){
            q.add(t->left);
        }
        if(t->right){
            q.add(t->left);
        }
    }
}




