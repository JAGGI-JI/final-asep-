#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    int isCompleted;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task description: ");
        getchar(); // To consume newline character from previous input
        fgets(tasks[taskCount].description, MAX_DESC_LENGTH, stdin);
        tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; // Remove newline
        tasks[taskCount].isCompleted = 0; // Initially not completed
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached (max %d tasks).\n", MAX_TASKS);
    }
}

void markTaskCompleted() {
    int taskNumber;
    printf("Enter task number to mark as completed: ");
    scanf("%d", &taskNumber);
    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].isCompleted = 1;
        printf("Task %d marked as completed!\n", taskNumber);
    } else {
        printf("Invalid task number.\n");
    }
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
    } else {
        printf("\nDaily Tasks:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s [%s]\n", i + 1, tasks[i].description,
                   tasks[i].isCompleted ? "Completed" : "Pending");
        }
    }
}

void saveTasksToFile() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error saving tasks to file.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s,%d\n", tasks[i].description, tasks[i].isCompleted);
    }
    fclose(file);
    printf("Tasks saved to 'tasks.txt' successfully.\n");
}

void loadTasksFromFile() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No previous tasks found.\n");
        return;
    }
    taskCount = 0;
    while (fscanf(file, "%[^,],%d\n", tasks[taskCount].description, &tasks[taskCount].isCompleted) != EOF) {
        taskCount++;
    }
    fclose(file);
    printf("Tasks loaded from 'tasks.txt' successfully.\n");
}

int main() {
    int choice;

    loadTasksFromFile();

    do {
        printf("\n--- Daily Progress Tracker ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Save Tasks to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                saveTasksToFile();
                break;
            case 5:
                printf("Exiting the program. Have a productive day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
