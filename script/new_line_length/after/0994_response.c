#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *data;
    int size;
    int capacity;
} Queue;

void enqueue(Queue *q, Point p) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity * sizeof(Point));
    }
    q->data[q->size++] = p;
}

Point dequeue(Queue *q) {
    return q->data[--q->size];
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int fresh_count = 0, minutes = 0;
    Queue q = { malloc(rows * cols * sizeof(Point)), 0, rows * cols };
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                enqueue(&q, (Point){i, j});
            } else if (grid[i][j] == 1) {
                fresh_count++;
            }
        }
    }
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (q.size != 0 && fresh_count > 0) {
        int q_size = q.size;
        for (int i = 0; i < q_size; ++i) {
            Point p = dequeue(&q);
            for (int d = 0; d < 4; d++) {
                int nx = p.x + directions[d][0];
                int ny = p.y + directions[d][1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(&q, (Point){nx, ny});
                    fresh_count--;
                }
            }
        }
        minutes++;
    }
    
    free(q.data);
    return fresh_count == 0 ? minutes : -1;
}
