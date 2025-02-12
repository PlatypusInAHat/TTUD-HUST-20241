#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void DFS_first(int **graph, int size, int vertex, bool *visited, int *stack, int *stackIndex) {
    visited[vertex] = true;
    for (int i = 0; i < size; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS_first(graph, size, i, visited, stack, stackIndex);
        }
    }
    stack[(*stackIndex)++] = vertex;
}


void DFS_second(int **graph, int size, int vertex, bool *visited) {
    visited[vertex] = true;
    for (int i = 0; i < size; i++) {
        if (graph[i][vertex] == 1 && !visited[i]) {
            DFS_second(graph, size, i, visited);
        }
    }
}


bool check(char s1[], char s2[]) {
    int check_s1[5] = {0, 1, 1, 1, 1};
    int check_s2[5] = {0}; 
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (check_s1[i] == 1 && check_s2[j] == 0 && s1[i] == s2[j]) {
                check_s1[i] = 0; 
                check_s2[j] = 1; 
                break;
            }
        }
    }
    
    for (int i = 1; i < 5; i++) {
        if (check_s1[i] == 1) {
            return false;
        }
    }
    
    return true;
}



int main()
{
    FILE *file = fopen("sgb-words.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Không thể mở tệp.\n");
        return 1;
    }

    char word[5757][6];

    int **graph = (int **)malloc(5757 * sizeof(int *));
    for (int i = 0; i < 5757; i++)
    {
        graph[i] = (int *)malloc(5757 * sizeof(int));
    }

    for (int i = 0; i < 5757; i++)
    {
        for (int j = 0; j < 5757; j++)
        {
            graph[i][j] = 0;
        }
    }

    int i = 0;
    while (fscanf(file, "%s", word[i]) != EOF)
    {
        i++;
    }

    fclose(file);

    for (int k = 0; k < 5757; k++)
    {
        for (int j = 0; j < 5757; j++)
        {
            if (k != j)
            {
                if (check(word[k], word[j]) == true)
                {
                    graph[k][j] = 1;
                }
            }
        }
    }
    int count = 0;
    int stack[5757];
    int stackIndex = 0;
    bool visited[5757];
    memset(visited, false, sizeof(visited));
    // chay dfs lan 1 tim sap xep topo
    for (int i = 5756; i >= 0; i--) {
        if (!visited[i]) {
            DFS_first(graph, 5757, i, visited, stack, &stackIndex);
        }
    }
    //ifstream in;
    //for (int i = 0; i <= 5756;i++) printf("%d\n",stack[i]);
    for (int i = 5756; i >= 5000;i--) printf("%d\n",stack[i]);

    // do thi dao
    int **transpose = (int **)malloc(5757 * sizeof(int *));
    for (int i = 0; i < 5757; i++) {
        transpose[i] = (int *)malloc(5757 * sizeof(int));
        for (int j = 0; j < 5757; j++) {
            transpose[i][j] = graph[j][i];
        }
    }

    // dfs lan 2 tim scc
    memset(visited, false, sizeof(visited));
    int sccCount = 0;

    for (int i = stackIndex - 1; i >= 0; i--) {
        int vertex = stack[i];
        if (!visited[vertex]) {
            sccCount++;
            DFS_second(transpose, 5757, vertex, visited);
        }
    }

    printf("Number of Strongly Connected Components: %d\n", sccCount);

    // Step 4: Free memory
    for (int i = 0; i < 5757; i++) {
        free(graph[i]);
        free(transpose[i]);
    }
    free(graph);
    free(transpose);

    return 0;
}
