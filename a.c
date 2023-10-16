#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

void pwrite(struct node *head);
void create(struct node *head);
void padd(struct node *head, struct node *head2);

int main()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *head2 = malloc(sizeof(struct node));
    head->next = NULL;
    create(head);
    create(head2);
    padd(head, head2);
}

void create(struct node *head)
{
    int c, p, a;

    struct node *temp1 = head;
    printf("Enter the number of terms\n");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter coefficent\n");
        scanf("%d", &c);
        printf("Enter pow\n");
        scanf("%d", &p);
        struct node *temp = malloc(sizeof(struct node));
        temp->coeff = c;
        temp->pow = p;
        temp1->next = temp;
        temp1 = temp1->next;
        temp->next = NULL;
    }
}

void pwrite(struct node *head)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr = head->next;
    int y;
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->pow);
        ptr = ptr->next;
        if (ptr->coeff >= 0)
        {
            if (ptr != NULL)
                printf("+ ");
        }
    }
}

void padd(struct node *head, struct node *head2)
{
    struct node *head3 = malloc(sizeof(struct node));
    struct node *ptr = head3;

    while (head != NULL && head2 != NULL)
    {
        if (head->pow == head2->pow)
        {
            ptr->coeff = head->coeff + head2->coeff;
            ptr->pow = head->pow;
            head = head->next;
            head2 = head2->next;
            ptr=ptr->next;
        }
        else if(head->pow > head2->pow){
            ptr->coeff=head->coeff;
            ptr->pow=head->pow;

            head=head->next;
            ptr=ptr->next;
        }
        else if(head2->pow > head->pow){
            ptr->coeff=head2->coeff;
            ptr->pow=head2->pow;

            head2=head2->next;
            ptr=ptr->next;
        }
    }
    pwrite(head3);
}
