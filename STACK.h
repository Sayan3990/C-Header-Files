// This header file is for C/C++
// It has two types of data structure
// One is stack using array
// Another is stack using single linked list

#include<stdio.h>
#include<stdlib.h>


// STACK USING ARRAY


/**
 * @brief It is a STACK using dynamic array 
 * It has 3 variables 
 * 1) *arr : int type array
 * 2) len : size of arr
 * 3) top : STACK_ARR top element
 */
typedef struct {
  int *arr;
  int len;
  int top;
} STACK_ARR;


/**
 * @brief Initialize the STACK_ARR dynamically
 * 
 * @param s Address of STACK_ARR 
 * @param n Size of arr of STACK_ARR 
 */
void initialize_SA(STACK_ARR *s, int n) {
    s->top = -1;
    s->len = n;
    s->arr = (int*)malloc( n*sizeof(int) );
}


/**
 * @brief Delete all element of STACK_ARR dynamically
 * 
 * @param s The address of STACK_ARR which will be deleted
 */
void deleteAllElements_SA(STACK_ARR *s) {
    s->top = -1;
    s->len = 0;
    free(s->arr);
}


/**
 * @brief Push an element into STACK_ARR
 * 
 * @param s The address of STACK_ARR 
 * @param v Value of element which will be pushed
 * @return 1 : Fail to push 0 : Successfully pushed 
 */
int push_SA(STACK_ARR *s, int v) {
  if(s->top == s->len-1) {
    return 1;
  } else {
    s->arr[++(s->top)] = v;
    return 0;
  }
}


/**
 * @brief Pop an element from STACK_ARR
 * 
 * @param s The address of STACK_ARR
 * @param k Address of integer variable where the deleted value will be stored
 * @return 1 : Fail to pop 0 : Successfully popped
 */
int pop_SA(STACK_ARR *s, int *k) {
  if(s->top == -1) {
    return 1;
  } else {
    *k = s->arr[s->top];
    s->top --;
    return 0;
  }
}


/**
 * @brief Push multiple element into STACK_ARR
 * 
 * @param s The address of STACK_ARR
 * @param a Array carrying the pushable values
 * @param n Size of the array a
 * @return 1 : Fail to push 0 : Successfully pushed
 */
int multiplePush_SA(STACK_ARR *s, int a[], int n) {
  int status = 0;
  for (int i = 0; i < n; i++) {
    status = push_SA(s, a[i]);
    if (status == 1) {
      break;
    }
  }
  return status;
}


/**
 * @brief Pop multiple element from STACK_ARR
 * 
 * @param s The address of STACK_ARR
 * @param a Array of integer variables where the deleted values will be stored
 * @param n Size of the array a
 * @return 1 : Fail to pop 0 : Successfully popped
 */
int multiplePop_SA(STACK_ARR *s, int a[], int n) {
  int status = 0;
  for (int i = 0; i < n; i++) {
    status = pop_SA(s, &a[i]);
    if (status == 1) {
      break;
    }
  }
  return status;
}


/**
 * @brief Display STACK_ARR 
 * 
 * @param s The address of STACK_ARR
 * @param state 1 : Reverse display 0 : Normal display
 */
void display_SA(STACK_ARR *s, int state) {
  if(s->top == -1) {
    return;
  }
  int m;
  pop_SA(s, &m);
  if(state == 0) {
    display_SA(s, state);
    printf("%d, ",m);
  } else {
    printf("%d, ",m);
    display_SA(s, state);
  }
  push_SA(s, m);
}


/**
 * @brief Copy one STACK_ARR to another STACK_ARR
 * 
 * @param s The address of source STACK_ARR
 * @param d The address of destination STACK_ARR 
 */
void copyElements_SA(STACK_ARR *s, STACK_ARR *d) {
  deleteAllElements_SA(d);
  initialize_SA(d, s->len);
  if(s->top == -1) {
    return;
  }
  int m;
  pop_SA(s, &m);
  copyElements_SA(s, d);
  push_SA(d, m);
  push_SA(s, m);
}


/**
 * @brief Sort the STACK_ARR
 * 
 * @param s The address of STACK_ARR
 */
void sortElements_SA(STACK_ARR *s) {
  int m1, m2, flag = 0, len;
  STACK_ARR t1, t2;
  
  len = s->len;
  initialize_SA(&t1, len);
  initialize_SA(&t2, len);  
  copyElements_SA(s, &t1);
  deleteAllElements_SA(s);
  initialize_SA(s, len);

  while(t1.top != -1) {
      pop_SA(&t1, &m1);
      while(1) {
        if(s->top == -1) {
            push_SA(s, m1);
            flag = 0;
        } else {
          pop_SA(s, &m2);
          if(m1 > m2) {
            push_SA(s, m2);
            push_SA(s, m1);
            flag = 0;
          } else {
            push_SA(&t2, m2);
            flag = 1;
          }
        }
        if(flag == 0) {
          break;
        }
      }
      while(t2.top != -1) {
        pop_SA(&t2, &m1);
        push_SA(&t1, m1);
      }
  }
  deleteAllElements_SA(&t1);
  deleteAllElements_SA(&t2);

}


/**
 * @brief Reverse the STACK_ARR
 * 
 * @param s The address of STACK_ARR
 */
void makeReverse_SA(STACK_ARR *s) {
  int m;
  STACK_ARR t;

  initialize_SA(&t, s->len);
  copyElements_SA(s, &t);
  s->top = -1;
  for (int i = 1; i < s->len; i++) {
    pop_SA(&t, &m);
    push_SA(s, m);
  } 
  deleteAllElements_SA(&t);
}


// STACK USING SINGLE LINKED LIST


/**
 * @brief The node of single linked list
 * It has 2 variables
 * 1) data : int type
 * 2) next : struct nodeSLL type pointer
 */
struct nodeSLL {
  int data;
  struct nodeSLL *next;
};


/**
 * @brief It is a STACK using single linked list 
 * It has only one variable
 * 1) top : STACK_SLL's top
 */
typedef struct {
  struct nodeSLL *top;
} STACK_SLL;


/**
 * @brief Initialize the STACK_SLL
 * 
 * @param s Address of header node of STACK_SLL  
 */
void initialize_SA(STACK_SLL *s) {
    s->top = NULL;
}


/**
 * @brief Push an element into STACK_SLL
 * 
 * @param s Address of header node of STACK_SLL
 * @param v Value of element which will be pushed
 * @return 1 : Fail to push 0 : Successfully pushed 
 */
int push_SL(STACK_SLL *s, int v) {
  struct nodeSLL *curr = (struct nodeSLL*)malloc(sizeof(struct nodeSLL));
  if(curr == NULL) {
    return 1;
  } else {
    curr->next = s->top;
    curr->data = v;
    s->top = curr;
    return 0;
  }
}


/**
 * @brief Pop one node from STACK_SLL
 * 
 * @param s Address of header node of STACK_SLL
 * @param k Address of node where the deleted node's address will be stored
 * @return 1 : Fail to pop 0 : Successfully popped
 */
int pop_SL(STACK_SLL *s, struct nodeSLL **k) {
  if(s->top == NULL) {
    return 1;
  } else {
    *k = s->top;
    s->top = s->top->next;
    return 0;
  }
}