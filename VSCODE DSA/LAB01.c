#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day
{
    char *dayName;
    char date[11]; // To store date as a string in the format dd/mm/yyyy
    char *activity;
};

void create(struct Day *day)
{
    day->dayName = (char *)malloc(sizeof(char) * 20);   // Allocate memory for dayName
    day->activity = (char *)malloc(sizeof(char) * 100); // Allocate memory for activity

    if (day->dayName == NULL || day->activity == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the day name: ");
    scanf("%13s", day->dayName); // Limit input to avoid overflow

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%10s", day->date); // Read the date as a string with format dd/mm/yyyy

    getchar(); // To consume the newline character left by scanf

    printf("Enter the activity for the day: ");
    fgets(day->activity, 100, stdin);                   // Use fgets for safer input
    day->activity[strcspn(day->activity, "\n")] = '\0'; // Remove newline character from fgets
}

void read(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter details for day %d:\n", i + 1);
        create(&calendar[i]);
    }
}

void display(struct Day *calendar, int size)
{
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Day %d\n", i + 1);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Date: %s\n", calendar[i].date); // Display the date in the format dd/mm/yyyy
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}

void freeMemory(struct Day *calendar, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}

int main()
{
    printf("BHAVYA\n");
     printf("USN:1AY23CS056\n");
    int size;
    printf("Enter the number of days in the week: ");
    scanf("%d", &size);

    struct Day *calendar = (struct Day *)malloc(sizeof(struct Day) * size);
    if (calendar == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    read(calendar, size);
    display(calendar, size);

    freeMemory(calendar, size);
    free(calendar);
    return 0;
}