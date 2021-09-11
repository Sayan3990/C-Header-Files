//Fisrt write "struct node* head_name == NULL;" then call, "single_linked_list(&head_name);";
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct node {
  float val;
  struct node *next;
};

//Create linked list
  void Create_linked_list(struct node **start_add) {
    int i,n;
    struct node *end_add;
    if (*start_add == NULL) {
      printf("\n Enter size : ");
      scanf("%d",&n);
      printf("\n Enter values : \n");
      for (i=0;i<n;i++) {
          struct node *curr = (struct node*)malloc(sizeof(struct node));
          printf(" Val-%d : ",i+1);
          scanf("%f",&curr->val);
          curr->next = NULL;
          if(*start_add == NULL) {
            *start_add = curr;
            end_add = curr;
          } else {
            end_add->next = curr;
            end_add = end_add->next;
          }
      }
    } else {
      printf("\n Already, linked list is created.\n");
    }
  }

//Display all values
  void Display_linked_list(struct node *start_add) {
    struct node *curr = NULL;
    if (start_add != NULL) {
        printf("\n Displaying values : ");
        for ( curr = start_add ; curr != NULL ; curr = curr->next ) {
          printf("%0.2f, ",curr->val);
        }
    } else {
        printf("\n No data found.\n");
    }
  }

//Searching position by value
  void Searching_position_linked_list_by_value(struct node *start_add) {
    int i=1, flag=0;
    float value;
    printf("\n Enter value to search : ");
    scanf("%f",&value);
    struct node *curr = NULL;
      for ( curr = start_add ; curr != NULL ; curr = curr->next) {
        if ( curr->val == value ) {
          printf("\n %0.2f is found at position %d ",value, i);
          flag++;
        }
        i++;
      }
      if(flag == 0) {
        printf("\n %0.2f is not found.\n",value);
      }
  }

//Searching value by position
  void Searching_value_linked_list_by_position(struct node *start_add) {
    int i=1,pos;
    printf("\n Enter index postion to search : ");
    scanf("%d",&pos);
    if(start_add == NULL) {
        printf("\n No data found.\n");
    } else if ( pos > 0 ) {
      struct node *ptr = start_add;
        while ( i < pos && ptr != NULL ) {
          ptr = ptr->next;
          i++;
        }
        if (ptr == NULL) {
          printf("\n Size of list is %d, can't find value present at position %d.\n",i-1,pos);
        } else {
          printf("\n The value at position %d, is %f\n",pos,ptr->val);
        }
    } else {
      printf("\n Invalid index postion.\n");
      Searching_value_linked_list_by_position(start_add);
    }
  }

  //Deleting value by postion
  void Deleting_value_linked_list_by_position(struct node **start_add) {
    if(*start_add == NULL) {
      printf("\n No data found.\n");
    } else {
      int pos,i=1;
      struct node *ptr = *start_add;
      struct node *ptrv = NULL;
      printf("\n Enter the position to delete value : ");
      scanf("%d",&pos);
      if ( pos < 1) {
        printf("\n Invalid index position.\n");
        Deleting_value_linked_list_by_position(start_add);
      }
      else if(pos == 1) {
        *start_add = ptr->next;
        free(ptr);
      } else {
          while( i<pos && ptr!=NULL ) {
            ptrv = ptr;
            ptr = ptr->next;
            i++;
        }
        if (ptr == NULL) {
          printf("\n Size of list is %d, can't delete value present at position %d.\n",i-1,pos);
        } else {
          ptrv->next = ptr->next;
          free(ptr);
        }
      }
    }
  }

  //Deleting value by value
  void Deleting_value_linked_list_by_value(struct node **start_add) {
    if(*start_add == NULL) {
      printf("\n No data found.\n");
    } else {
        float valuedel;
        int i=1;
        struct node *ptr = *start_add;
        struct node *ptrv = NULL;
        printf("\n Enter value to delete : ");
        scanf("%f",&valuedel);
        while (ptr->val != valuedel) {
          ptrv = ptr;
          ptr = ptr->next;
          i++;
          if(ptr==NULL) {
            break;
          }
        }
        if ( ptr == NULL) {
          printf("\n %0.2f is not found.\n",valuedel);
        } else if(i == 1) {
          *start_add = ptr->next;
          free(ptr);
          printf("\n Deleted.\n");
        } else {
          ptrv->next = ptr->next;
          free(ptr);
          printf("\n Deleted.\n");
        }
    }
  }

//Inserting value by postion
  void Inserting_value_linked_list_by_position(struct node **start_add) {
    if(*start_add == NULL) {
      printf("\n No data found.\n");
    } else {
        float new_val;
        int pos,i=1;
        printf("\n Enter postion to insert value : ");
        scanf("%d",&pos);
        if (pos > 0) {
          struct node *ptr = *start_add;
          struct node *ptrv = NULL;
          struct node *curr = (struct node *)malloc(sizeof(struct node));
          printf("\n Enter value to insert : ");
          scanf("%f",&new_val);
          curr->val = new_val;
          curr->next = NULL;
            if(pos == 1) {
              *start_add = curr;
              curr->next = ptr;
            } else {
                while (i < pos) {
                  if(ptr==NULL) {
                    break;
                  }
                  ptrv = ptr;
                  ptr = ptr->next;
                  i++;
                }
                if (i == pos && ptr == NULL) {
                  ptrv->next = curr;
                  ptr = curr;
                  printf("\n Inserted.\n");
                }
                else if (ptr == NULL) {
                  printf("\n Size of list is %d, can't insert new value at position %d.\n",i-1,pos);
                } else {
                  ptrv->next = curr;
                  curr->next = ptr;
                  printf("\n Inserted.\n");
                }
            }
        } else {
          printf("\n Invalid index position.\n");
          Inserting_value_linked_list_by_position(start_add);
        }
    }
  }

//Changing value by value
  void Changing_value_by_value(struct node *start_add) {
    if(start_add == NULL) {
      printf("\n No data found.\n");
    } else {
        float value, valadd;
        struct node *ptr = start_add;
        printf("\n Enter value to change : ");
        scanf("%f",&value);
        while (ptr->val != value) {
          ptr = ptr->next;
          if(ptr==NULL) {
            break;
          }
        }
        if ( ptr == NULL) {
          printf("\n %0.2f is not found.\n",value);
        } else {
          printf("\n %0.2f is found.\n Enter the new value : ",value);
          scanf("%f",&valadd);
          ptr->val = valadd;
          printf("\n value is changed to %0.2f \n",valadd);
        }
    }
  }

//Changing value by postion
  void Changing_value_by_position(struct node *start_add) {
    if(start_add == NULL) {
      printf("\n No data found.\n");
    } else {
        float valadd;
        int pos,i=1;
        printf("\n Enter postion of value to change : ");
        scanf("%d",&pos);
        if (pos > 0) {
            struct node *ptr = start_add;
            while (i < pos) {
              if(ptr==NULL) {
                break;
              }
              ptr = ptr->next;
              i++;
            }
            if ( ptr == NULL) {
              printf("\n Size of list is %d, can't change value present at position %d.\n",i-1,pos);
            } else {
              printf("\n Value at position %d is %0.2f \n Enter the new value : ",pos,ptr->val);
              scanf("%f",&valadd);
              ptr->val = valadd;
              printf("\n Value is changed to %0.2f \n",valadd);
            }
          } else {
            printf("\n Invalid index position.\n");
            Changing_value_by_position(start_add);
          }
      }
  }

//Reverse linked list
  void Reverse_linked_list(struct node **start_add) {
    if(*start_add == NULL) {
      printf("\n No data is found.\n");
    } else if ((*start_add)->next == NULL) {
      printf("\n Only one node is present.\n");
    } else {
        struct node *ptr, *ptrv, *add;
        ptrv = *start_add;
        ptr = (*start_add)->next;
        (*start_add)->next = NULL;
        while(ptr!=NULL) {
          add = ptrv;
          ptrv = ptr;
          ptr = ptr->next;
          ptrv->next = add;
        }
        *start_add = ptrv;
        printf("\n The single linked list is reversed.\n");
    }
  }

//Deleting all value
  void Deleting_all_values(struct node *start_add) {
    struct node *curr = NULL, *ptr = NULL;
    for ( curr = start_add ; curr != NULL ; ) {
        ptr = curr;
        curr = curr->next;
        free(ptr);
    }
    printf("\n All data deleted.\n");
  }

//Options for link list
  void single_linked_list(struct node **h) {
    system("clear");
    int  op;
    do {
      printf("\n\n\n");
      for (int k=0;k<100;k++) {
        printf("-");
      }
      printf("\n\n Create a single linked list (code-'1')");
      printf("\n Display all values of linked list (code-'2')");
      printf("\n Search the position of linked list by giving value of that postion (code-'3')");
      printf("\n Search the value by giving position of linked list (code-'4')");
      printf("\n Insert a new value by giving position of linked list (code-'5')");
      printf("\n Change a value by giving current value (code-'6')");
      printf("\n Change a value by giving postion (code-'7')");
      printf("\n Delete a value of linked list by giving that value (code-'8')");
      printf("\n Delete value linked list by giving position (code-'9')");
      printf("\n Reverse the linked list (code-'10')");
      printf("\n Quit program, deleting all exisitng values (code-'11')");
      printf("\n\n  Enter correct code : ");
      scanf("%d",&op);
      system("clear");
      switch(op) {
        case 1:
              printf("\n <-- Creating a linked list -->\n");
              Create_linked_list(h);
              break;
        case 2:
              printf("\n <-- Displaying all values of linked list -->\n");
              Display_linked_list(*h);
              break;
        case 3:
              printf("\n <-- Searching the position of linked list by giving value of that postion -->\n");
              Searching_position_linked_list_by_value(*h);
              break;
        case 4:
              printf("\n <-- Searching the value by giving position of linked list -->\n");
              Searching_value_linked_list_by_position(*h);
              break;
        case 5:
              printf("\n <-- Inserting a new value by giving position of linked list -->\n");
              Inserting_value_linked_list_by_position(h);
              break;
        case 6:
              printf("\n <-- Changing a value by giving current value -->\n");
              Changing_value_by_value(*h);
              break;
        case 7:
              printf("\n <-- Changing a value by giving postion -->\n");
              Changing_value_by_position(*h);
              break;
        case 8:
              printf("\n <-- Deleting a value of linked list by giving that value -->\n");
              Deleting_value_linked_list_by_value(h);
              break;
        case 9:
              printf("\n <-- Deleting value linked list by giving position -->\n");
              Deleting_value_linked_list_by_position(h);
              break;
        case 10:
              printf("\n <-- Reversing value linked list -->\n");
              Reverse_linked_list(h);
              break;
        case 11:
              Deleting_all_values(*h);
              break;
        default:
          system("clear");
          printf("\n Invalid code.\n");
      }
    } while(op!=11);
    system("clear");
    printf("\n\n\t <-- Thank you -->\n\n");
  }

//End
