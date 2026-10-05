#include <iostream>
#include <fstream>


void dfs(int vertex, int n, int** graph, bool* visited)
{
    visited[vertex] = true;
    std::cout << vertex + 1 << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i, n, graph, visited);
        }
    }
}

int main()
{
    std::ifstream file("input.txt");

    if (!file)
    {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    int n;
    file >> n;

    int** graph = new int*[n];

    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            file >> graph[i][j];
        }
    }

    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    dfs(0, n, graph, visited);

    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        delete[] graph[i];
    }

    delete[] graph;
    delete[] visited;

    file.close();

    return 0;
}

