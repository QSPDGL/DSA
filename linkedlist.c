#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr);
struct Node *InsertAtFirst(struct Node *head, int data);
struct Node *InsertAtIndex(struct Node *head, int data, int index);
struct Node *InsertAtEnd(struct Node *head, int data);
struct Node *UpdateElement(struct Node *head, int elem, int index);
struct Node *DeleteAtFirst(struct Node *head);
struct Node *DeleteAtIndex(struct Node *head, int index);
struct Node *DeleteAtEnd(struct Node *head);
void SearchElement(struct Node *head, int elem);

int main()
{
    int c = 1, ch;

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printf("Linked list: \n");
    linkedlistTraversal(head);

    int num, index;

    while (c != 0)
    {
        printf("\n\n*****Menu*****\n1.Insert at beginning.\n2.Insert after a given node.\n3.Insert at end.");
        printf("\n4.Update an element.");
        printf("\n5.Delete first element.\n6.Delete element at index.\n7.Delete last element.");
        printf("\n8.Print List.");
        printf("\n9.Search an element.");
        printf("\n10.Exit.\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element you want to enter : ");
            scanf("%d", &num);
            head = InsertAtFirst(head, num);
            printf("\nElement appended at begnning of Linked List.\n");

            break;

        case 2:
            printf("\nEnter the value you want to enter : ");
            scanf("%d", &num);
            printf("Enter index : ");
            scanf("%d", &index);

            if (index == 1)
            {
                head = InsertAtFirst(head, num);
            }
            else
            {
                index = index - 1;
                head = InsertAtIndex(head, num, index);
            }
            printf("\nElement inserted at given position\n");

            break;

        case 3:
            printf("\nEnter the value you want to enter : ");
            scanf("%d", &num);
            head = InsertAtEnd(head, num);
            printf("\nElement appended at end of Linked List.\n");

            break;

        case 4:
            printf("\nEnter the index of value you want to update : ");
            scanf("%d", &index);
            printf("Enter value : ");
            scanf("%d", &num);
            head = UpdateElement(head, num, index);

            break;

        case 5:
            head = DeleteAtFirst(head);

            break;

        case 6:
            printf("\nEnter index of element you want to delete : ");
            scanf("%d", &index);
            head = DeleteAtIndex(head, index);

            break;

        case 7:
            head = DeleteAtEnd(head);

            break;

        case 8:
            printf("\nLinked list: \n");
            linkedlistTraversal(head);

            break;

        case 9:
            printf("\nEnter element you want to search : ");
            scanf("%d", &num);
            SearchElement(head, num);

            break;

        case 10:
            c = 0;
            printf("\nExiting...");

            break;

        default:
            printf("\nPlease enter valid option.\n");

            break;
        }
    }

    printf("Thank You!!!\n\n");

    return 0;
}

void linkedlistTraversal(struct Node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *UpdateElement(struct Node *head, int elem, int index)
{
    struct Node *ptr = head;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->data = elem;
    printf("\nUpdation completed!\n");

    return head;
}

struct Node *DeleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nElement deleted\n");

    return head;
}

struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    int listLength = 0;

    while (p != NULL)
    {
        listLength++;
        p = p->next;
    }

    p = head;

    if (index == 1)
    {
        DeleteAtFirst(head);
        printf("\nElement deleted\n");

        return head;
    }
    else if (index == listLength)
    {
        DeleteAtEnd(head);
        printf("\nElement deleted\n");

        return head;
    }
    else
    {
        while (i != index - 2 && p != NULL)
        {
            p = p->next;
            i++;
        }
        if (p == NULL || p->next == NULL)
        {
            printf("\nIndex out of bounds or NULL pointer encountered.\n");
            return head;
        }
        struct Node *q = p->next;
        p->next = q->next;
        free(q);
        printf("\nDeletion completed\n");
        
        return head;
    }
}

struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    while (q->next != NULL)
    {
        q = q->next;
    }
    while (p->next != q)
    {
        p = p->next;
    }
    p->next = NULL;
    free(q);
    printf("\nDeletion completed\n");

    return head;
}

void SearchElement(struct Node *head, int elem)
{
    struct Node *p = head;
    int found = 0, i = 1;
    while (p != NULL)
    {
        if (p->data == elem)
        {
            found = 1;
            break;
        }
        p = p->next;
        i++;
    }
    if (found == 1)
    {
        printf("\nElement found at index %d\n", i);
    }
    else
    {
        printf("\nElement not found!!!\n");
    }
}
