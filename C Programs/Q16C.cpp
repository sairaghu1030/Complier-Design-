#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct three
{
    char data[10], temp[7];
} s[30];

int main()
{
    char d1[7], d2[7] = "t";
    int i = 0, j = 1, len = 0;
    FILE *f1, *f2;

    // Open input and output files
    f1 = fopen("sum.txt", "r");
    if (f1 == NULL) {
        printf("Error opening input file.");
        return 1;
    }

    f2 = fopen("out.txt", "w");
    if (f2 == NULL) {
        printf("Error opening output file.");
        return 1;
    }

    // Read input and store in array of structs
    while (fscanf(f1, "%s", s[len].data) != EOF)
        len++;

    // Generate temporary variables and write to output file
    itoa(j, d1, 10); // Convert integer to string
    strcat(d2, d1); // Append integer string to "t"
    strcpy(s[j].temp, d2); // Copy temporary variable to struct
    strcpy(d1, "");
    strcpy(d2, "t");

    // Write initial assignment statement to output file
    fprintf(f2, "%s=%s", s[j].temp, s[i].data);
    j++;

    // Process input and write intermediate code to output file
    for (i = 1; i < len - 1; i += 2)
    {
        itoa(j, d1, 10);
        strcat(d2, d1);
        strcpy(s[j].temp, d2);
        if (!strcmp(s[i].data, "+"))
            fprintf(f2, "\n%s=%s+%s", s[j].temp, s[j - 1].temp, s[i + 1].data);
        else if (!strcmp(s[i].data, "-"))
            fprintf(f2, "\n%s=%s-%s", s[j].temp, s[j - 1].temp, s[i + 1].data);
        strcpy(d1, "");
        strcpy(d2, "t");
        j++;
    }

    // Write final assignment statement to output file
    fprintf(f2, "\n%s=%s", s[0].data, s[j - 1].temp);

    // Close files
    fclose(f1);
    fclose(f2);

    printf("Output has been written to out.txt\n");

    return 0;
}
