/*
-----Description-----
    Name        : APC Project
    Date        : 15-12-2025
    AUTHOR      : AJAY KRISHNA M U

    Project Description     :
        perform Addition, Subtraction, Multiplication,  and Division of Signed and Unsigned numbers.
*/


#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include <string.h>

int main(int argc , char *argv[])
{
    // check arguments
    if(argc != 4)
    {
        printf("ERROR : \nFormat:->  ./a.out <Number1> <Operation> <Number2>\n");
        return FAILURE;
    }

    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *resh = NULL;
    Dlist *rest = NULL;
    // check for sign
    int i=0;
    int sign1 = 0;
    int sign2 = 0;
    if(argv[1][0] == '-')
    {
        sign1 = 1;
        i++;
    }
    // load into linked list
    while(argv[1][i])
    {
        int data = argv[1][i] - '0';
        dl_insert_last(&head1, &tail1, data);
        i++;
    }
    pre_zero(&head1, &tail1);
    i=0;
    if(argv[3][0] == '-')
    {
        sign2 = 1;
        i++;
    }
    while(argv[3][i])
    {
        int data = argv[3][i] - '0';
        dl_insert_last(&head2, &tail2, data);
        i++;
    }
    pre_zero(&head2, &tail2);
    // check operation and perform operations
    switch (argv[2][0])
    {
        case '+':
        {
            printf("Result :     %s + %s = ", argv[1], argv[3]);
            if(sign1 == sign2)
            {
                Add(&head1, &tail1, &head2, &tail2, &resh, &rest);
                if(sign1 && sign2)
                {
                    printf("-");
                }
                pre_zero(&resh, &rest);
                print_list(resh);
                printf("\n");
                break;
            }
            else
            {
                int cmp = compare(head1, head2);

                if (cmp == 0)
                {
                    printf("0");
                }
                else if (cmp > 0)
                {
                    Substraction(&head1, &tail1, &head2, &tail2, &resh, &rest);
                    if (sign1 )
                        printf("-");

                    pre_zero(&resh, &rest);
                    print_list(resh);
                }
                else
                {
                    Substraction(&head2, &tail2, &head1, &tail1, &resh, &rest);
                    if (sign2 )
                        printf("-");

                    pre_zero(&resh, &rest);
                    print_list(resh);
                }
            }

            printf("\n");
            break;
            
        }  
        case '-':
        {
            printf("Result :     %s - %s = ", argv[1], argv[3]);
            sign2 = !sign2;   
            if (sign1 == sign2)
            {
                Add(&head1, &tail1, &head2, &tail2, &resh, &rest);
                if (sign1)
                {
                    printf("-");
                }
                pre_zero(&resh, &rest);
                print_list(resh);
            }
            else
            {
                int cmp = compare(head1, head2);
                if (cmp == 0)
                {
                    printf("0");
                }
                else if (cmp > 0)
                {
                    Substraction(&head1, &tail1, &head2, &tail2, &resh, &rest);
                    if (sign1)
                    {
                        printf("-");
                    }
                    pre_zero(&resh, &rest);
                    print_list(resh);
                }
                else
                {
                    Substraction(&head2, &tail2, &head1, &tail1, &resh, &rest);
                    if (sign2)
                    {
                        printf("-");
                    }
                    pre_zero(&resh, &rest);
                    print_list(resh);
                }
            }

            printf("\n");
            break;
        }
        case '*':
        case 'x':
        case 'X':
        {
            printf("Result :     %s X %s = ", argv[1], argv[3]); 
            multiplication(&head1, &tail1, &head2, &tail2, &resh, &rest);
            pre_zero(&resh, &rest);
            if(sign1^sign2)
            {
                printf("-");
            }
            print_list(resh);
            printf("\n");
            break;
        }
            
        case '/':
            {
                int cmp = compare(head1, head2);
                if(cmp == FAILURE || !(strcmp(argv[3],"0")))
                {
                    printf("Invalid : cannot do division\n");
                    break;
                }
                printf("Result :     %s / %s = ", argv[1], argv[3]); 
                Division(&head1, &tail1, &head2, &tail2, &resh, &rest);
                if(sign1^sign2)
                {
                    printf("-");
                }
                print_list(resh);
                printf("\n");
                break;
            }
        
        default:
            break;
    }

    return 0;
}



