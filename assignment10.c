#include <stdio.h>

int main()
{
    int year, i, j, day;
    int days[12] = {31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31};

    char *months[12] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    printf("Enter the year: ");
    scanf("%d", &year);

    if (year < 1)
    {
        printf("Invalid year!");
        return 0;
    }

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

    // Calculate first day of the year
    int y = year - 1;

    day = (365 * y + y / 4 - y / 100 + y / 400) % 7;

    // Print calendar
    for (i = 0; i < 12; i++)
    {
        printf("\n\n       %s %d\n", months[i], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (j = 0; j < day; j++)
        {
            printf("    ");
        }

        for (j = 1; j <= days[i]; j++)
        {
            printf("%4d", j);

            if ((day + j) % 7 == 0)
            {
                printf("\n");
            }
        }

        day = (day + days[i]) % 7;
    }

    return 0;
}
