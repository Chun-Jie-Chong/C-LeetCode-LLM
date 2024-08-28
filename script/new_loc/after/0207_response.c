#include <stdio.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int graph[numCourses][numCourses];
    int indegree[numCourses];
    for(int i = 0; i < numCourses; i++) {
        indegree[i] = 0;
        for(int j = 0; j < numCourses; j++) 
            graph[i][j] = 0;
    }
    for(int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        if(graph[prereq][course] == 0) {
            graph[prereq][course] = 1;
            indegree[course]++;
        }
    }
    int stack[numCourses], top = -1;
    for(int i = 0; i < numCourses; i++) 
        if(indegree[i] == 0) 
            stack[++top] = i;
    
    int count = 0;
    while(top != -1) {
        int node = stack[top--];
        count++;
        for(int i = 0; i < numCourses; i++) {
            if(graph[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    stack[++top] = i;
            }
        }
    }
    return count == numCourses;
}
