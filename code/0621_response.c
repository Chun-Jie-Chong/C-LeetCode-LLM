#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int taskCount[26] = {0};
    for (int i = 0; i < tasksSize; i++) {
        taskCount[tasks[i] - 'A']++;
    }
    
    int maxCount = 0;
    int maxTasks = 0;
    for (int i = 0; i < 26; i++) {
        if (taskCount[i] > maxCount) {
            maxCount = taskCount[i];
            maxTasks = 1;
        } else if (taskCount[i] == maxCount) {
            maxTasks++;
        }
    }
    
    int partCount = maxCount - 1;
    int partLength = n - (maxTasks - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasksSize - maxCount * maxTasks;
    int idles = emptySlots - availableTasks;
    
    return tasksSize + (idles > 0 ? idles : 0);
}
