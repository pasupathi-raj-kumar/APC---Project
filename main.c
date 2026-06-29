#include "header.h"
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Invalid number of arguments\n");
        return FAILURE;
    }

    Dlist *head1 = NULL; 
	Dlist *tail1 = NULL;
    Dlist *head2 = NULL; 
	Dlist *tail2 = NULL; 
    Dlist *head = NULL;
    Dlist *tail = NULL;
    Dlist *temp1, *temp2;
    char *str1=argv[1], *str2 = argv[3], ch;
    int flag;
   if(validate(argv[1]) == SUCCESS)
   {
        int i = 0;
        while(str1[i]!= '\0')
        {
            dl_insert_last(&head1, &tail1, (str1[i]-'0'));
            i++;
        }
        
    }
    else
    {
            printf("Invalid first operand\n");
            return FAILURE;
    }
    ch = argv[2][0];
    if(validate(argv[3]) == SUCCESS)
    {        
        int i = 0;
        while(argv[3][i])
        {
            dl_insert_last(&head2, &tail2, argv[3][i] - '0');
            i++;
        }        
    }
    else
    {
            printf("Invalid second operand\n");
            return FAILURE;
    }
    switch(ch)
    {
        case '+':
        {
            addition( &tail1,  &tail2, &head, &tail);
            print_list(head);
   
            break;
        }

        case '-' :
        {
            if(strlen(str1) < strlen(str2))
            {
                subtraction( &tail2, &tail1, &head, &tail);
                printf("-");
                print_list(head);
                break;
            }
            else if(strlen(str1) == strlen(str2))
            {
                temp1 = head1;
                temp2 = head2;
                while(temp1 != NULL)
                {
                    flag = 0;
                    if(((temp1) -> data) < ((temp2) -> data))
                    {
                        subtraction( &tail2, &tail1, &head, &tail);
                        flag = 1;
                        printf("-");
                        print_list(head);
                       break;
                    }
                    else if(((temp1) -> data) > ((temp2) -> data))
                    {
                        subtraction( &tail1,  &tail2, &head, &tail);
                        flag = 1;
                        print_list(head);
                        break;
            
                    }
                    else
                    {
                        temp1 = temp1 -> next;
                        temp2 = temp2 -> next;
                    }
                }
                if(flag == 0)
                {
                subtraction(&tail1,  &tail2, &head, &tail);
                print_list(head);
                }

            }
            else
            {
                subtraction(&tail1,  &tail2, &head, &tail);
                print_list(head);

                break;
            }
            
            break;
        }

        case 'X' :
        {
          multiplication(&head1, &tail1, &head2, &tail2, &head, &tail);	
                print_list(head);
		printf("\n");
		return 0;
        }

        case 'x' :
        {
		multiplication(&head1, &tail1, &head2, &tail2, &head, &tail);	
                print_list(head);
		printf("\n");
		return 0;


        }
        
        case '/' :
        {
            if(strlen(str1) < strlen(str2))
            {
                dl_insert_first(&head,&tail, 0);
                print_list(head);
            }
            else if(strlen(str1) == strlen(str2))
            {
                temp1 = head1;
                temp2 = head2;
                while(temp1 != NULL)
                {
                    flag = 0;
                    if(((temp1) -> data) < ((temp2) -> data))
                    {
                        dl_insert_first(&head,&tail, 0);
                        flag = 1;
                        print_list(head);
                       break;
                    }
                    else if(((temp1) -> data) > ((temp2) -> data))
                    {
                        division(&head1, &tail1, &head2, &tail2, &head, &tail);
                        flag = 1;
                        print_list(head);
                        break;
            
                    }
                    else
                    {
                        temp1 = temp1 -> next;
                        temp2 = temp2 -> next;
                    }
                }
                if(flag == 0)
                {
                    dl_insert_first(&head,&tail, 1);
                print_list(head);
                }

            }
            else
            {
                division(&head1, &tail1, &head2, &tail2, &head, &tail);
                
                print_list(head);
                break;
            }
           
            break;
        }

           

    

        default :
        {
            printf("Invalid Operator");
            return FAILURE;
        }
    }

}

