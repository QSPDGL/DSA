#include <stdio.h>

int main()
{

    int arr[100], n, ch, num, pos, choice, elem = 0;

    printf("\nEnter the number of elements you want in your array (max: 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray : \n\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d)%d ", i + 1, arr[i]);
    }

    printf("\n\nDo you want to modify the array? (If yes press '1') : ");
    scanf("%d", &choice);

    if (choice != 1)
    {
        printf("\nThank You!\n\n");
    }
    else
    {
        while (ch != 10)
        {
            printf("\nChoices :\n");
            printf("\n\t1.Add element at begnning\n\t2.Add element in middle\n\t3.Add element at last\n");
            printf("\t4.Update an element");
            printf("\n\t5.Delete element at begnning\n\t6.Delete element in middle\n\t7.Delete element at last\n");
            printf("\t8.Search element\n");
            printf("\t9.Print code\n");
            printf("\t10.Exit code\n");
            printf("\nEnter your choice : ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                // add to begnning
                printf("\nEnter the number to be inserted : ");
                scanf("%d", &num);
                if (n == 0)
                {
                    arr[0] = num;
                }
                else
                {
                    for (int i = n - 1; i >= 0; i--)
                    {
                        arr[i + 1] = arr[i];
                    }
                    arr[0] = num;
                    n++;
                }

                printf("Inserting completed!!!\n");

                break;

            case 2:
                // add in middle
                printf("\nEnter position where you want to insert : ");
                scanf("%d", &pos);

                printf("Enter the number to be inserted : ");
                scanf("%d", &num);

                for (int i = n - 1; i >= pos - 1; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[pos - 1] = num;
                n++;

                printf("Inserting completed!!!\n");

                break;

            case 3:
                // add at last
                printf("\nEnter the number to be inserted : ");
                scanf("%d", &num);

                arr[n] = num;
                n++;

                printf("Inserting completed!!!\n");

                break;

            case 4:
                // updating an element
                printf("\nEnter position where you want to update : ");
                scanf("%d", &pos);

                printf("Enter the number to be inserted : ");
                scanf("%d", &num);

                arr[pos - 1] = num;

                printf("Updation completed!!!\n");

                break;

            case 5:
                // delete at beginning
                for (int i = 0; i < n; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;

                printf("\nDeletion completed!!!\n");

                break;

            case 6:
                // delete in middle
                printf("\nEnter position where you want to delete : ");
                scanf("%d", &pos);

                for (int i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;

                printf("Deletion completed!!!\n");

                break;

            case 7:
                // delete at last
                n--;

                printf("\nDeletion completed!!!\n");

                break;

            case 8:
                // searching an element
                printf("\nEnter the number you are looking for : ");
                scanf("%d", &num);
                int found = 0, index;

                for (int i = 0; i < n; i++)
                {
                    if (arr[i] == num)
                    {
                        found = 1;
                        index = i + 1;
                        break;
                    }
                }

                if (found == 1){
                    printf("\nElement found at index %d.\n", index);
                }
                else{
                    printf("\nElement not found!\n");
                }

                break;

            case 9:
                // print code
                printf("\nArray : \n\t");
                for (int i = 0; i < n; i++)
                {
                    printf("%d)%d ", i + 1, arr[i]);
                }

                printf("The element %d is found in index %d\n", num, elem + 1);

                break;

            case 10:
                // exit
                printf("\n\nThank You!\n\n");

                break;

            default:
                printf("\nEnter valid input\n");

                break;
            }
        }
    }

    return 0;
}
