#include <bits/stdc++.h>
#include <vector>
#include <fstream>

using namespace std;
string file = "gc_1000_3";
int main()
{
    ifstream graph;
    graph.open(file + ".txt");
    ifstream colors;
    colors.open(file + "tomau.txt");
    vector<int> vertices_coloring;
    int k = 0;
    colors>>k;     // Check if graph is k-colorable?
    cout << k;
    // 1. Check if k is maximum color.
    int c=0;
    while (colors>>c)
    {
        if (c > k || c < 1)
        {
            cerr<<"ERR: the color is invalid!"<<endl;
            return 1;
        }
        vertices_coloring.push_back(c);     // vertices_coloring[i] = color of vertice i
    }

    int number_of_vertices = 0;
    graph>>number_of_vertices;

    int number_of_edges = 0;
    graph >> number_of_edges;

    // 2. Check that each vertice has a color
    if (vertices_coloring.size() != number_of_vertices)
    {
        //cout << number_of_vertices << endl;
        cerr<<"ERR: The number of vertices are invalid!"<<endl;
        return 0;
    }

    // 3. Check that no two adjacent vertices are of the same color
    int u, v;
    for (size_t i = 0; i < number_of_edges; i++)
    {
        graph>>u>>v;
        if (vertices_coloring[u-1] == vertices_coloring[v-1])
        {
            cerr<<"ERR: The colors of "<<u<<" and " <<v<<" are the same!"<<endl;
            return 0;
        }
    }

    // Everything is OK
    cout<<": OK"<<endl;
    return 0;
}
/*
ofstream outfile(file + "tomau.txt"); // Open output file
            if (!outfile)
            {
                cerr << "Cannot open output file";
                return 1;
            }
            int colors = 0;
            for (int i = 0; i < n; ++i) colors = max(colors,best_solution[i]);
            outfile << colors << endl;
            cout << "Found colors" << colors << endl;
            for (int i = 0; i < n; ++i) // Write best solution to output file
            {
                outfile << best_solution[i] << endl;
            }

            outfile.close();
*/
