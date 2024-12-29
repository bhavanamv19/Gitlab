#include <stdio.h>
#include <string.h>
void read();
void replace(int startIndex);
void print(int startIndex);
void position();
int i, j = 0, n; // Removed unused variable 'k'
char parent[100], pat[50], rep[50];
int main()
{
    read();
    position();             // Call position first to find the pattern
    printf("%s\n", parent); // Print the modified parent string
    return 0;
}
void read()
{
    printf("Enter the MAIN string: \n");
    scanf("%s", parent);
    printf("Enter a PATTERN string: \n");
    scanf("%s", pat);
    printf("Enter a REPLACE string: \n");
    scanf("%s", rep);
}
void position()
{
    int m = strlen(parent);
    n = strlen(pat);
    int patternFound = 0; // Flag to check if pattern is found

    for (i = 0; i <= m - n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (parent[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == n)
        {
            print(i);         // Pass the index where the pattern was found
            replace(i);       // Replace the pattern
            patternFound = 1; // Set flag if pattern is found
        }
    }

if (!patternFound)
    {
        printf("Pattern Not Found.\n");
    }
}
void replace(int startIndex)
{
    for (int a = 0; a < n; a++)
    {
        parent[startIndex + a] = rep[a]; // Replace the pattern with the new string
    }
}
void print(int startIndex)
{
    printf("Pattern found at %d\n", startIndex + 1);
}