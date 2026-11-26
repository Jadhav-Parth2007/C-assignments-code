#include <stdio.h>
#include <string.h>

int main()
{
    char str1[200], str2[200], result[400];
    int choice, i;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    do
    {
        printf("\n----- STRING OPERATIONS MENU -----\n");
        printf("1. Find Length of String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Convert to Uppercase\n");
        printf("7. Convert to Lowercase\n");
        printf("8. Search Character\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                strcpy(result, str1);
                printf("Copied String = %s\n", result);
                break;

            case 3:
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if (strlen(str1) + strlen(str2) < sizeof(result))
                {
                    strcpy(result, str1);
                    strcat(result, str2);
                    printf("Concatenated String = %s\n", result);
                }
                else
                    printf("Strings are too long!\n");
                break;

            case 4:
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 5:
                strcpy(result, str1);
                for (i = 0; i < strlen(result) / 2; i++)
                {
                    char temp = result[i];
                    result[i] = result[strlen(result) - 1 - i];
                    result[strlen(result) - 1 - i] = temp;
                }
                printf("Reversed String = %s\n", result);
                break;

            case 6:
                strcpy(result, str1);
                for (i = 0; result[i] != '\0'; i++)
                {
                    if (result[i] >= 'a' && result[i] <= 'z')
                        result[i] = result[i] - 32;
                }
                printf("Uppercase String = %s\n", result);
                break;

            case 7:
                strcpy(result, str1);
                for (i = 0; result[i] != '\0'; i++)
                {
                    if (result[i] >= 'A' && result[i] <= 'Z')
                        result[i] = result[i] + 32;
                }
                printf("Lowercase String = %s\n", result);
                break;

            case 8:
            {
                char ch;
                printf("Enter character to search: ");
                scanf("%c", &ch);
                getchar();

                if (strchr(str1, ch) != NULL)
                    printf("Character found in string.\n");
                else
                    printf("Character not found.\n");
                break;
            }

            case 9:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 9);

    return 0;
}
