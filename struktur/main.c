#include <printf.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

enum STATUS
{
    DO, GOING, DONE
};

struct Task
{
    char description[50];
    enum STATUS status;
    struct Task *nextTask;
};

struct TaskList
{
    struct Task *firstTask;
    struct Task *lastTask;
    int length;
};

struct Task *create_task(char *description)
{
    struct Task *newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->status = DO;
    newTask->nextTask = NULL;
    int i = 0;
    while (i < 50 && description[i] != '\0') {
        newTask->description[i] = description[i];
        //printf("copied\n");
        //printf("copied %c ", description[i]);
        //printf("  to %c \n", newTask.description[i]);
        i++;
    }
    return newTask;
}

void add(struct TaskList *taskList, struct Task *task)
{
    // Liste ist leer
    if (taskList->firstTask == NULL)
    {
        taskList->firstTask = task;
        taskList->lastTask = task;
        taskList->length++;
    } else if (taskList->firstTask != NULL) {
        //Liste hat 1 oder mehr Tasks
        taskList->lastTask->nextTask = task;
        taskList->lastTask = task;
        taskList->length++;
    }

}

bool delete_first(struct TaskList *list)
{
    if (list->firstTask->status == DONE) {
        struct Task *p_taskToDelete = list->firstTask;
        list->firstTask = p_taskToDelete->nextTask;
        p_taskToDelete->nextTask = NULL;
        list->length--;
        free(p_taskToDelete);
        return true;
    } else {
        return false;
    }
}

/**
 * Main Function that calls all necessary methods for praktikum 3
 * @return -1 when done with the operations
 */
int main()
{
    {
        struct TaskList taskList;
        taskList.firstTask = NULL;
        taskList.lastTask = NULL;
        taskList.length = 0;
        struct TaskList *p_taskList = &taskList;
        struct Task *p_task1;
        struct Task *p_task2;
        struct Task *p_task3;
        p_task1 = create_task("Task 1");
        //printf("Concent of 1 %s \n", p_task1->description);
        add(p_taskList, p_task1);
        assert(p_taskList->length == 1);
        p_task2= create_task("Task 2");
        add(p_taskList, p_task2);
        assert(p_taskList->length == 2);
        printf("address %p \n", p_taskList->firstTask->nextTask);
        printf("address %p \n", p_taskList->lastTask);
        assert(delete_first(p_taskList) == false);
        assert(p_taskList->length == 2);
        p_taskList->firstTask->status = DONE;
        assert(delete_first(p_taskList) == true);
        assert(p_taskList->length == 1);
        printf("address %p \n", p_taskList->firstTask);
        printf("address %p \n", p_taskList->lastTask);
    }

    printf("test est");
    return -1;
}
