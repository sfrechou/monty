#include "monty.h"
int gnumber = 0;

int main(int argc, char *argv[])
{
    FILE *file;
    ssize_t line_chars = 0;
    size_t line_len = 0;
    unsigned int line_number = 1;
    char *line_buf = NULL;
    char *tok_op = NULL, *tok_num;
    stack_t *stack= NULL;

    if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    file = fopen(argv[1], "r");
    if (file == NULL)
	{
	    perror("fopen");
	    exit(EXIT_FAILURE);
	}

    while ((line_chars = getline(&line_buf, &line_len, file)) != -1)
    {
        line_number++;
        tok_op = strtok(line_buf, " \t\n\r");
        tok_num = strtok(NULL, " \t\n\r");
        if (tok_op == NULL)
            continue;
        if (strcmp(tok_op, "push") == 0)
        {
            gnumber = atoi(tok_num);
        }
        find_op(&stack, tok_op, line_number);
    }
    free(line_buf);
    line_buf = NULL;
    fclose(file);
    exit(EXIT_SUCCESS);
}