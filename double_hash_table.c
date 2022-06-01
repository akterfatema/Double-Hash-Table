#include <stdio.h>
#include <Math.h>
int prime;
int array[50];
int size;

int hash1(int element)
{
    return element % size;
}

int hash2(int element)
{
    return prime - (element % prime);
}

int modified_hash1(int element)
{
    int i = 1;
    while (array[(hash1(element) + (i * hash2(element))) % size] != 0 && i < size)
    {
        i++;
    }
    if (i == size)
    {
        printf("The value cannot be inserted");
        return;
    }
    return (hash1(element) + (i * hash2(element))) % size;
}
// input: 1 5 1 15 1 25 1 35 1 45 1  55 1 65 1 75 1 85
void insert()
{
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    int index = hash1(element);
    if (array[index] == 0)
    {
        array[index] = element;
    }
    else if (array[index] != 0)
    {
        index = modified_hash1(element);
        array[index] = element;
    }
}

void search()
{
    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    int i = 0;
    while (array[(hash1(key) + (i * hash2(key))) % size] != key && i < size)
    {
        i++;
    }
    if (i == size)
    {
        printf("%d is NOT FOUND in the hash table.\n", key);
    }
    else
    {
        printf("%d is FOUND after %d cycle/s at index %d.\n", key, i, (hash1(key) + (i * hash2(key))) % size);
    }
}

int delete ()
{
    int key;
    printf("Enter the value to delete: ");
    scanf("%d", &key);
    int i = 0;
    while (array[(hash1(key) + (i * hash2(key))) % size] != key && i < size)
    {
        i++;
    }
    if (i == size)
    {
        printf("%d is NOT FOUND in the hash table.\n", key);
        return 0;
    }
    else
    {
        printf("%d is deleted.\n", key);
        array[(hash1(key) + (i * hash2(key))) % size] = 0;
        return 1;
    }
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void find_prime()
{
    for (int i = size - 1; i >= 1; i--)
    {
        int flag = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            prime = i;
            return;
        }
    }
}

int main()
{
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    find_prime();
    int j = 0;

    while (1)
    {
        int choice;
        printf("\n=========DOUBLE HASH TABLE MENU=========\n");
        printf("\t1. Insert element\n");
        printf("\t2. Search an element\n");
        printf("\t3. Remove an element\n");
        printf("\t4. Display the elements\n");
        printf("\t5. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (j < size)
            {
                insert();
                j++;
            }
            else
                printf("\nHash table is already full\n");
        }
        else if (choice == 2)
        {
            if (j == 0)
            {
                printf("\nHash table is empty.\n");
            }
            else
                search();
        }
        else if (choice == 3)
        {
            if (j == 0)
            {
                printf("\nHash table is empty.\n");
            }
            else
            {
                int flag = delete ();
                if (flag == 1)
                {
                    j--;
                }
            }
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
        {
            break;
        }
    }
}