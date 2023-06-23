/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "pstack.h"

/* The constants*/
static const int RIGHT_NUMBER_OF_ARGUMENTS = 2;

static const char *STUDENTS_FILE_FORMAT = " %u %f %u ";
static const int STUDENTS_FILE_FIELDS_FOR_RECORD = 3;
static const char *STUDENTS_DUMP_FORMAT = "%u: %f, %u -- %f";

static const char *ERR_FILE_NOT_EXIST = "File does not exist.\n";
static const char *ERR_INVALID_STUDENTS_LIST = "Invalid list of students.\n";

void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Read students with an associated priority and return the"
           "order in wich the patients are seen.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[])
{
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < RIGHT_NUMBER_OF_ARGUMENTS)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

pstack pstack_from_file(const char *filepath)
{
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", ERR_FILE_NOT_EXIST);
        exit(EXIT_FAILURE);
    }
    int res = 0;
    pstack s = pstack_empty();
    while (!feof(file))
    {
        pstack_elem student_id = 0u;
        float average_grade = 0.f;
        unsigned int approved_courses = 0u;
        res = fscanf(file, STUDENTS_FILE_FORMAT,
                     &student_id, &average_grade, &approved_courses);
        if (res != STUDENTS_FILE_FIELDS_FOR_RECORD)
        {
            fprintf(stderr, "%s", ERR_INVALID_STUDENTS_LIST);
            pstack_destroy(s);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        s = pstack_push(s, student_id, average_grade, approved_courses);
    }
    fclose(file);
    return s;
}

void pstack_dump(pstack s)
{
    pstack copy_s = NULL;
    copy_s = pstack_copy(s);

    unsigned int length = pstack_size(copy_s);
    fprintf(stdout, "length: %u\n", length);

    while (!pstack_is_empty(copy_s))
    {
        pstack_elem elem = pstack_top(copy_s);
        float average_grade = pstack_top_average_grade(copy_s);
        unsigned int approved_courses = pstack_top_approved_courses(copy_s);
        float priority = pstack_top_priority(copy_s);
        fprintf(stdout, STUDENTS_DUMP_FORMAT,
                elem, average_grade, approved_courses, priority);
        copy_s = pstack_pop(copy_s);
        if (!pstack_is_empty(copy_s))
        {
            fprintf(stdout, "\n");
        }
    }
    fprintf(stdout, "\n");
    pstack_destroy(copy_s);
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* get the pstack from the file */
    pstack s = pstack_from_file(filepath);

    /* call the function for show the priority stack elements */
    pstack_dump(s);

    /* destroy instance of pstack */
    s = pstack_destroy(s);

    return (EXIT_SUCCESS);
}
