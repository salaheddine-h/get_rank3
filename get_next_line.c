#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

char    *ft_strdup(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    char    *ptr = malloc(i + 1 * sizeof(char));
    if(!ptr)
        return(NULL);
    i = 0;
    while(str[i])
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\0';
    return(ptr);
}
char    *get_next_line(int fd)
{
    static char buffer_read[BUFFER_SIZE];
    static char line[7000];
    static int copy_pos;
    static int read_num;
    int i = 0;

    if(fd < 0 || BUFFER_SIZE < 0)
        return(NULL);
    while(1)
    {
        if(copy_pos >= read_num)
        {
            read_num = read(fd, buffer_read, BUFFER_SIZE);
            copy_pos = 0;
            if(read_num <= 0)
                break;
        }
        line[i++] = buffer_read[copy_pos++];
        if(line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return(NULL);
    return(ft_strdup(line));
}


int main(void)
{
    int fd;
    char *line;
    int line_count = 0;

    // Test 1: Create a test file
    printf("Creating test file...\n");
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Error creating test file\n");
        return 1;
    }

    write(fd, "Line 1\n", 7);
    write(fd, "Line 2\n", 7);
    write(fd, "Line 3 without newline", 22);
    write(fd, "\nLine 4\n", 8);
    write(fd, "Final line", 10);
    close(fd);

    // Test 2: Read the file line by line
    printf("\nReading file line by line:\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening test file\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        printf("Line %d: '%s'\n", line_count, line);
        free(line); // Don't forget to free the memory!
    }

    close(fd);
    printf("\nTotal lines read: %d\n", line_count);

    // Test 3: Test with invalid file descriptor
    printf("\nTesting with invalid fd:\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("Correctly returned NULL for invalid fd\n");
    else
        printf("ERROR: Should have returned NULL for invalid fd\n");

    // Test 4: Test with empty file
    printf("\nTesting with empty file:\n");
    fd = open("empty.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close(fd);

    fd = open("empty.txt", O_RDONLY);
    line = get_next_line(fd);
    if (line == NULL)
        printf("Correctly returned NULL for empty file\n");
    else
        printf("ERROR: Should have returned NULL for empty file\n");
    close(fd);

    printf("\nTests completed!\n");

    // Clean up test files
    unlink("test.txt");
    unlink("empty.txt");

    return 0;
}
