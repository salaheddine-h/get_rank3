#include "get_next_line.h"

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
