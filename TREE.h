// Include the library to use some operation on TREE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define MAX 50


/**
 * @brief Make gap using new line 
 * 
 * @param n Number of new line for gapping
 */
void gapline(int n) {

    for (int i = 0 ; i < n ; i++) {
        printf("\n");
    }
}


/**
 * @brief Node for Binary TREE [BTREE]
 * 
 */
struct node_BTREE {
   
    struct node_BTREE *left;
    int data;
    struct node_BTREE *right;

};


/**
 * @brief Node for Single Thread Binary TREE [STBTREE]
 * 
 */
struct node_STBTREE {

    struct node_STBTREE *left;
    int data;
    struct node_STBTREE *right;
    char right_verification;

};


/**
 * @brief Node for Double Thread Binary TREE [DTBTREE]
 * 
 */
struct node_DTBTREE {

    struct node_DBTREE *left;
    char left_verification;
    int data;
    struct node_DBTREE *right;
    char right_verification;

};


/**
 * @brief Initialize the root of Binary Tree BTREE as NULL
 * 
 * @param root Address of pointer pointing to the root node (struct node_BTREE **)
 */
void initialize_root_BTREE(struct node_BTREE **root) {
    *root = NULL;
}


/**
 * @brief Initialize the root of Binary Tree STBTREE as NULL
 * 
 * @param root Address of pointer pointing to the root node (struct node_STBTREE **)
 */
void initialize_root_STBTREE(struct node_STBTREE **root) {
    *root = NULL;
}


/**
 * @brief Initialize the root of Binary Tree DTBTREE as NULL
 * 
 * @param root Address of pointer pointing to the root node (struct node_DTBTREE **)
 */
void initialize_root_DTBTREE(struct node_DTBTREE **root) {
    *root = NULL;
}


/**
 * @brief It is a STACK_BTREE using array for Binary TREE [BTREE]
 * It has two variable
 * 1) top : STACK_BTREE's top
 * 2) *element[] : Array of pointers of struct node_BTREE type
 */
typedef struct {

    struct node_BTREE *element[MAX]; 
    int top;

} STACK_BTREE;


/**
 * @brief It is a STACK_STBTREE using array for Single Thread Binary TREE [STBTREE]
 * It has two variable
 * 1) top : STACK_STBTREE's top
 * 2) *element[] : Array of pointers of struct node_STBTREE type
 */
typedef struct {

    struct node_STBTREE *element[MAX]; 
    int top;

} STACK_STBTREE;


/**
 * @brief It is a STACK_DTBTREE using array for Double Thread Binary TREE [DTBTREE]
 * It has two variable
 * 1) top : STACK_DTBTREE's top
 * 2) *element[] : Array of pointers of struct node_DTBTREE type
 */
typedef struct {

    struct node_DTBTREE *element[MAX]; 
    int top;

} STACK_DTBTREE;



/**
 * @brief Initialize the STACK_BTREE
 * 
 * @param s Address of STACK_BTREE
 */
void initialize_STACK_BTREE(STACK_BTREE *s) {
    s->top = -1;
}


/**
 * @brief Initialize the STACK_STBTREE
 * 
 * @param s Address of STACK_STBTREE
 */
void initialize_STACK_STBTREE(STACK_STBTREE *s) {
    s->top = -1;
}


/**
 * @brief Initialize the STACK_DTBTREE
 * 
 * @param s Address of STACK_DTBTREE
 */
void initialize_STACK_DTBTREE(STACK_DTBTREE *s) {
    s->top = -1;
}


/**
 * @brief Verify is the STACK_BTREE empty or not
 * 
 * @param s Address of STACK_BTREE
 * @return  1 : STACK_BTREE is not empty 0 : Empty STACK_BTREE
 */
int isEmpty_STACK_BTREE(const STACK_BTREE *s) {
    
    if(s->top == -1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Verify is the STACK_BTREE full or not
 * 
 * @param s Address of STACK_BTREE
 * @return  1 : STACK_BTREE is not full 0 : Full STACK_BTREE
 */
int isFull_STACK_BTREE(const STACK_BTREE *s) {
    
    if(s->top == MAX - 1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Verify is the STACK_STBTREE empty or not
 * 
 * @param s Address of STACK_STBTREE
 * @return  1 : STACK_STBTREE is not empty 0 : Empty STACK_STBTREE
 */
int isEmpty_STACK_STBTREE(const STACK_STBTREE *s) {
    
    if(s->top == -1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Verify is the STACK_STBTREE full or not
 * 
 * @param s Address of STACK_STBTREE
 * @return  1 : STACK_STBTREE is not full 0 : Full STACK_STBTREE
 */
int isFull_STACK_STBTREE(const STACK_STBTREE *s) {
    
    if(s->top == MAX - 1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Verify is the STACK_DTBTREE empty or not
 * 
 * @param s Address of STACK_DTBTREE
 * @return  1 : STACK_DTBTREE is not empty 0 : Empty STACK_DTBTREE
 */
int isEmpty_STACK_DTBTREE(const STACK_DTBTREE *s) {
    
    if(s->top == -1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Verify is the STACK_DTBTREE full or not
 * 
 * @param s Address of STACK_DTBTREE
 * @return  1 : STACK_DTBTREE is not full 0 : Full STACK_DTBTREE
 */
int isFull_STACK_DTBTREE(const STACK_DTBTREE *s) {
    
    if(s->top == MAX - 1) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief Push an element into STACK_BTREE
 * 
 * @param s Address of STACK_BTREE
 * @param v Value of element which will be pushed
 * @return 1 : Fail to push 0 : Successfully pushed 
 */
int push_STACK_BTREE(STACK_BTREE *s, struct node_BTREE *v) {
  
  if(s->top == MAX-1) {
    return 1;
  } else {
      s->element[++s->top] = v;
    return 0;
  }

}


/**
 * @brief Pop one node from STACK_BTREE
 * 
 * @param s Address of STACK_BTREE
 * @param k Address of node where the deleted node's address will be stored
 * @return 1 : Fail to pop 0 : Successfully popped
 */
int pop_STACK_BTREE(STACK_BTREE *s, struct node_BTREE **k) {
  
  if(s->top == -1) {
    return 1;
  } else {
    *k = s->element[s->top];
    s->top--;
    return 0;
  }

}


/**
 * @brief Push an element into STACK_STBTREE
 * 
 * @param s Address of STACK_STBTREE
 * @param v Value of element which will be pushed
 * @return 1 : Fail to push 0 : Successfully pushed 
 */
int push_STACK_STBTREE(STACK_STBTREE *s, struct node_STBTREE *v) {
  
  if(s->top == MAX-1) {
    return 1;
  } else {
      s->element[++s->top] = v;
    return 0;
  }

}


/**
 * @brief Pop one node from STACK_STBTREE
 * 
 * @param s Address of STACK_STBTREE
 * @param k Address of node where the deleted node's address will be stored
 * @return 1 : Fail to pop 0 : Successfully popped
 */
int pop_STACK_STBTREE(STACK_STBTREE *s, struct node_STBTREE **k) {
  
  if(s->top == -1) {
    return 1;
  } else {
    *k = s->element[s->top];
    s->top--;
    return 0;
  }

}


/**
 * @brief Create a new Node for Binary TREE [BTREE] 
 * 
 * @param v Value[int] for node which will be stored
 * @return Address of created node (struct node_BTREE*) 
 */
struct node_BTREE* createNode_BTREE(int v) {
    
    struct node_BTREE *curr = (struct node_BTREE*)malloc(sizeof(struct node_BTREE));
    
    curr->data = v;
    curr->left = curr->right = NULL;
    return curr;

}


/**
 * @brief Create a new Node for Single Thread Binary TREE [STBTREE] 
 * 
 * @param v Value[int] for node which will be stored
 * @return Address of created node (struct node_STBTREE*) 
 */
struct node_STBTREE* createNode_STBTREE(int v) {
    
    struct node_STBTREE *curr = (struct node_STBTREE*)malloc(sizeof(struct node_STBTREE));
    
    curr->data = v;
    curr->left = curr->right = NULL;
    curr->right_verification = 0;
    return curr;

}


/**
 * @brief Create a new Node for Double Thread Binary TREE [DTBTREE] 
 * 
 * @param v Value[int] for node which will be stored
 * @return Address of created node (struct node_DTBTREE*) 
 */
struct node_DTBTREE* createNode_DTBTREE(int v) {
    
    struct node_DTBTREE *curr = (struct node_DTBTREE*)malloc(sizeof(struct node_DTBTREE));
    
    curr->data = v;
    curr->left = curr->right = NULL;
    curr->right_verification = curr->left_verification = 0;
    return curr;

}


/**
 * @brief Inorder Traversal of Binary Tree using recursion
 * 
 * @param root Address of root node of Tree
 */
void inorder_recursion_print_BTREE(struct node_BTREE *root) {
    
    if (root != NULL) {
        inorder_recursion_print_BTREE(root->left);
        printf("%d ", root->data);
        inorder_recursion_print_BTREE(root->right);

    }

}


/**
 * @brief Preorder Traversal of Binary Tree using recursion
 * 
 * @param root Address of root node of Tree
 */
void preorder_recursion_print_BTREE(struct node_BTREE *root) {
    
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_recursion_print_BTREE(root->left);
        preorder_recursion_print_BTREE(root->right);

    }

}


/**
 * @brief Postorder Traversal of Binary Tree using recursion
 * 
 * @param root Address of root node of Tree
 */
void postorder_recursion_print_BTREE(struct node_BTREE *root) {
    
    if (root != NULL) {
        postorder_recursion_print_BTREE(root->left);
        postorder_recursion_print_BTREE(root->right);
        printf("%d ", root->data);

    }

}


/**
 * @brief Inorder Traversal of Binary Tree without recursion
 * 
 * @param root Address of root node of Tree
 */
void inorder_non_recursive_print_extraction_BTREE(struct node_BTREE *root) {
    STACK_BTREE t;
    struct node_BTREE *curr = root;
    
    initialize_STACK_BTREE(&t);
    
    while(curr != NULL) {
        push_STACK_BTREE(&t, curr);
        curr = curr->left;
    }

    while(isEmpty_STACK_BTREE(&t)) {
        
        pop_STACK_BTREE(&t, &curr);
        printf("%d ",curr->data);
        curr = curr->right;
        
        while(curr != NULL) {
            push_STACK_BTREE(&t, curr);
            curr = curr->left;
        } 

    }

}


/**
 * @brief Preorder Traversal of Binary Tree without recursion
 * 
 * @param root Address of root node of Tree
 */
void preorder_non_recursive_print_extraction_BTREE(struct node_BTREE *root) {
    STACK_BTREE t;
    struct node_BTREE *curr;

    initialize_STACK_BTREE(&t);
    push_STACK_BTREE(&t, root);
    
    while(isEmpty_STACK_BTREE(&t)) {

        pop_STACK_BTREE(&t, &curr);
        printf("%d ",curr->data);
        if(curr->right != NULL) {
            push_STACK_BTREE(&t, curr->right);

        }
        if(curr->left != NULL) {
            push_STACK_BTREE(&t, curr->left);

        }

    }

}


/**
 * @brief Postorder Traversal of Binary Tree without recursion
 * 
 * @param root Address of root node of Tree
 */
void postorder_non_recursive_print_extraction_BTREE(struct node_BTREE *root) {
    STACK_BTREE t;
    struct node_BTREE *curr = root;
    struct node_BTREE *m1, *m2;

    initialize_STACK_BTREE(&t);
    while(curr != NULL) {

        if(curr->right != NULL) {
            push_STACK_BTREE(&t, curr->right);
        }
        push_STACK_BTREE(&t, curr);
        curr = curr->left;
    }

    while(isEmpty_STACK_BTREE(&t)) {

        pop_STACK_BTREE(&t, &m1);
        if(m1->right == NULL) {
            printf("%d ", m1->data);

        } else if ( !isEmpty_STACK_BTREE(&t) ) {
            printf("%d ", m1->data);

        } else {
            pop_STACK_BTREE(&t, &m2);
            if(m1->right == m2) {
                push_STACK_BTREE(&t, m1);
                curr = m2;

                 while(curr != NULL) {

                    if(curr->right != NULL) {
                        push_STACK_BTREE(&t, curr->right);
                    }
                    push_STACK_BTREE(&t, curr);
                    curr = curr->left;
                }

            } else {
                printf("%d ", m1->data);
                push_STACK_BTREE(&t, m2);
                
            }
           
        }
    }
}



/**
 * @brief Inorder Traversal of Single Thread Tree without recursion
 * 
 * @param root Address of root node of Tree
 * @param h Array of struct node_STBTREE type storing the values in inorder format for extraction
 * @param n Address of int type variable where the size of array will be stored 
 */
void inorder_non_recursive_extraction_STBTREE(struct node_STBTREE *root, struct node_STBTREE **h, int *n) {
    int i = 0;
    STACK_STBTREE t;
    struct node_STBTREE *curr = root;
    
    initialize_STACK_STBTREE(&t);
    
    while(curr != NULL) {
        push_STACK_STBTREE(&t, curr);
        curr = curr->left;
    }

    while(isEmpty_STACK_STBTREE(&t)) {
        
        pop_STACK_STBTREE(&t, &curr);
        h[i] = curr;
        i++;
        curr = curr->right;
        
        while(curr != NULL) {
            push_STACK_STBTREE(&t, curr);
            curr = curr->left;
        } 

    }
    *n = i;

}


/**
 * @brief Make the Single Thread Binary Tree from Binary Tree with node_STBTREE format. Make the connection between node_STBTREE and its inorder successor
 * 
 * @param h Array of struct node_STBTREE type storing the values in inorder format
 * @param n Size of node_STBTREE type array h 
 */
void Make_STBTREE(struct node_STBTREE **h, int n) {

    for (int i = 0 ; i < n - 1 ; i++) {
        if( h[i]->right == NULL ) {
            h[i]->right = h[i+1];
            h[i]->right_verification = 1;

        }
    }
}


/**
 * @brief Print Single Thread Binary Tree in inorder form using Single Thread characteristics 
 * 
 * @param root root node of Single Thread Binary Tree
 */
void print_inorder_from_STBTREE(struct node_STBTREE *root) {

    struct node_STBTREE *curr = root;
    
    while(curr->left != NULL) {
        curr = curr->left;
    }

    while(curr->right != NULL) {
        
        printf("%d ", curr->data);

        if(curr->right_verification == 1) {
            curr = curr->right;

        } else {
            curr = curr->right;

            while(curr->left != NULL) {
                curr = curr->left;
            }

        }

    }
    printf("%d", curr->data);

}


/**
 * @brief Insert any value(int type) into Binary Search Tree (node_BTREE) Recursively
 * 
 * @param root Address of root node of BTREE 
 * @param newV The new value(int type) which will be inserted
 * @return Address of root node(struct node_BTREE*) of BTREE with updation 
 */
struct node_BTREE* insert_in_Binary_search_tree_recursion_BTREE(struct node_BTREE *root, int newV) {

    if(root == NULL) {
        root = (struct node_BTREE*)malloc(sizeof(struct node_BTREE));
        root->data = newV;
        root->left = root->right = NULL;

    } else {
        if(root->data > newV) {
            root->left = insert_in_Binary_search_tree_recursion_BTREE(root->left, newV);

        } else {
            root->right = insert_in_Binary_search_tree_recursion_BTREE(root->right, newV);

        }

    }
    return root;

} 


/**
 * @brief Search any value in Binary Search Tree (node_BTREE) Recursively
 * 
 * @param root Address of root node 
 * @param val The value(int type) to search
 * @return Address of required Node(struct node_BTREE* type) : if it is found \n NULL : If it is not found
 */
struct node_BTREE* search_element_in_Binary_search_tree_recursion_BTREE(struct node_BTREE *root, int val) {
    if(root == NULL) {
        return NULL;

    } else if(root->data == val) {
        return root;

    } else if(root->data > val) {
        return search_element_in_Binary_search_tree_recursion_BTREE(root->left, val);

    } else {
        return search_element_in_Binary_search_tree_recursion_BTREE(root->right, val);

    }

}


/**
 * @brief Find Maximum value of Binary Search Tree (node_BTREE) Recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Maximum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MAX_element_in_Binary_search_tree_recursion_BTREE(struct node_BTREE *root) {

    if(root == NULL) {
        return NULL;

    } else {
        if(root->right != NULL) {
            return find_MAX_element_in_Binary_search_tree_recursion_BTREE(root->right);

        } else {
            return root;

        }

    }

}


/**
 * @brief Find Minimum value of Binary Search Tree (node_BTREE) Recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Minimum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MIN_element_in_Binary_search_tree_recursion_BTREE(struct node_BTREE *root) {

    if(root == NULL) {
        return NULL;

    } else {
        if(root->left != NULL) {
            return find_MIN_element_in_Binary_search_tree_recursion_BTREE(root->left);

        } else {
            return root;

        }

    }

}



/**
 * @brief Insert any value(int type) into Binary Search Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node of BTREE 
 * @param newV The new value(int type) which will be inserted
 * @return Address of root node(struct node_BTREE*) of BTREE with updation 
 */
struct node_BTREE* insert_into_Binary_search_tree_non_recursion_BTREE(struct node_BTREE *root, int newV) {
    struct node_BTREE *currprv = root, *curr = root;

    while(curr != NULL) {
        if(curr->data > newV) {
            currprv = curr;
            curr = curr->left;

        } else {
            currprv = curr;
            curr = curr->right;

        }
    }

    curr = (struct node_BTREE*)malloc(sizeof(struct node_BTREE));
    curr->data = newV;
    curr->left = curr->right = NULL;
    
    if(currprv == NULL) {
        root = curr;
        
    } else {
        if(currprv->data > newV) {
            currprv->left = curr;

        } else {
            currprv->right = curr;

        }

    }
    return root;
} 


/**
 * @brief Search any value in Binary Search Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node 
 * @param val The value(int type) to search
 * @return Address of required Node(struct node_BTREE* type) : if it is found \n NULL : If it is not found
 */
struct node_BTREE* search_element_in_Binary_search_tree_non_recursion_BTREE(struct node_BTREE *root, int val) {
    struct node_BTREE *curr = root;

    while(curr != NULL) {

        if(curr->data == val) {
            break;
        } else if(curr->data > val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

    }
    return curr;
}
    


/**
 * @brief Find Maximum value of Binary Search Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Maximum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MAX_element_in_Binary_search_tree_non_recursion_BTREE(struct node_BTREE *root) {
    struct node_BTREE *curr = root;

    if(root == NULL) {
        return NULL;

    }

    while(curr->right != NULL) {
        curr = curr->right;
    }
    return curr;

}


/**
 * @brief Find Minimum value of Binary Search Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Minimum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MIN_element_in_Binary_search_tree_non_recursion_BTREE(struct node_BTREE *root) {
    struct node_BTREE *curr = root;
    if(root == NULL) {
        return NULL;

    }

    while(curr->left != NULL) {
        curr = curr->left;   
    }

    return curr;
}


/**
 * @brief Search any value in any type of Binary Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node
 * @param val The value(int type) to search
 * @return Address of required Node(struct node_BTREE* type) : if it is found \n NULL : If it is not found
 */
struct node_BTREE* search_element_BTREE(struct node_BTREE *root, int val) {
    if(root == NULL) {
        return NULL;

    }

    STACK_BTREE t;
    struct node_BTREE *curr = NULL;

    initialize_STACK_BTREE(&t);
    push_STACK_BTREE(&t, root);

    while(isEmpty_STACK_BTREE(&t)) {

        pop_STACK_BTREE(&t, &curr);
        if(curr->data == val) {
            return curr;

        }
        if(curr->right != NULL) {
            push_STACK_BTREE(&t, curr->right);

        }
        if(curr->left != NULL) {
            push_STACK_BTREE(&t, curr->left);

        }

    }
    return NULL;
} 


/**
 * @brief Find Maximum value of any Binary Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Maximum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MAX_element_BTREE(struct node_BTREE *root) {

    if(root == NULL) {
        return NULL;

    }

    int max;
    STACK_BTREE t;
    struct node_BTREE *curr, *ptr;

    initialize_STACK_BTREE(&t);
    push_STACK_BTREE(&t, root);
    max = root->data;
    ptr = root;
    
    while(isEmpty_STACK_BTREE(&t)) {

        pop_STACK_BTREE(&t, &curr);

        if(max < curr->data) {
            max = curr->data;
            ptr = curr;

        }
        if(curr->right != NULL) {
            push_STACK_BTREE(&t, curr->right);

        }
        if(curr->left != NULL) {
            push_STACK_BTREE(&t, curr->left);

        }

    }
    return ptr;
} 


/**
 * @brief Find Minimum value of any type of Binary Tree (node_BTREE) Non-recursively
 * 
 * @param root Address of root node 
 * @return Address of required node containing Minimum value(struct node_BTREE* type) \n NULL : If Tree is not formed
 */
struct node_BTREE* find_MIN_element_BTREE(struct node_BTREE *root) {
    
    if(root == NULL) {
        return NULL;

    }

    int min;
    STACK_BTREE t;
    struct node_BTREE *curr, *ptr;

    initialize_STACK_BTREE(&t);
    push_STACK_BTREE(&t, root);
    min = root->data;
    ptr = root;
    
    while(isEmpty_STACK_BTREE(&t)) {

        pop_STACK_BTREE(&t, &curr);

        if(min > curr->data) {
            min = curr->data;
            ptr = curr;
        }
        if(curr->right != NULL) {
            push_STACK_BTREE(&t, curr->right);

        }
        if(curr->left != NULL) {
            push_STACK_BTREE(&t, curr->left);

        }

    }
    return ptr;

}


/**
 * @brief Delete an element by value the nodes of Tree BTREE
 * 
 * @param root Address of root node (struct node_BTREE **)
 * @param v The value to delete
 * @return struct node_BTREE* 
 */
struct node_BTREE* delete_an_element_recursively_BTREE(struct node_BTREE *root, int v) {
    if(root == NULL) {
        return root;

    } else if (root->data > v) {
        root->left = delete_an_element_recursively_BTREE(root->left, v);
        return root;

    } else if (root->data < v) {
        root->right = delete_an_element_recursively_BTREE(root->right, v);
        return root;

    } else {
        struct node_BTREE *temp;

        if (root->left != NULL && root->right != NULL) {
            temp = find_MAX_element_BTREE(root->left);
            root->data = temp->data;
            delete_an_element_recursively_BTREE(root->left, temp->data);
            return root;

        } else if(root->left != NULL) {
            temp = root->left;
            free(root);
            return temp;

        } else if (root->right != NULL) {
            temp = root->right;
            free(root);
            return temp;

        } else {
            free(root);
            return NULL;

        }

    }

}


/**
 * @brief Delete all the nodes of Tree BTREE
 * 
 * @param root Address of pointer pointing to the root node (struct node_BTREE **)
 */
void delete_all_node_BTREE(struct node_BTREE **root) {

    if(*root != NULL) {
        delete_all_node_BTREE(&((*root)->left));
        delete_all_node_BTREE(&((*root)->right));
        free(*root);
        *root = NULL;

    }

}


/**
 * @brief Delete all the nodes of Tree STBTREE
 * 
 * @param root Address of pointer pointing to the root node (struct node_STBTREE **)
 */
void delete_all_node_STBTREE(struct node_STBTREE **root) {

    if(*root != NULL) {
        delete_all_node_STBTREE(&((*root)->left));
        delete_all_node_STBTREE(&((*root)->right));
        free(*root);
        *root = NULL;

    }

}
