#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("File opened successfully.\n");

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Read line: %s\n", line ? line : "No line read");

        free(line);
    }

    printf("End of file or error.\n");
    close(fd);
    return 0;
}
