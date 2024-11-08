#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Course {
    int id;
    char *name;
};

struct Course *make_course(int id, char *name) {
    struct Course *new_course = malloc(sizeof(struct Course) + 1);
    if(new_course == NULL){
        exit(1);
    }

    new_course->id = id;
    new_course->name = name;

    return new_course;
}

int main() {
    struct Course *cs161 = make_course(161, "Computer Security");
    printf("Welcome to CS%d: %s!\n", cs161->id, cs161->name);

    free(cs161->name);
    free(cs161);

    return 0;
}


