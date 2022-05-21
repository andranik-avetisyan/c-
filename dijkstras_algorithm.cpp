#include <iostream>

#define SIZE 6
#define INFINITY 10000

int main()
{
  int nodes[SIZE]; // nodes
  int edges[SIZE][SIZE]; // edges matrix
  int distance[SIZE]; // minimal distance

  int temp, minindex, min;
  int begin_index = 0;

    // Initializing edges matrix
  for (int i = 0; i<SIZE; i++)
  {
    edges[i][i] = 0;
    for (int j = i + 1; j < SIZE; j++) 
    {
      std::cout << "Enter the coast of " <<  i + 1 << " - " << j + 1 << ":";
      std::cin >> temp;
      edges[i][j] = temp;
      edges[j][i] = temp;
    }
  };

    // Print edges matrix
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      std::cout << "\t" << edges[i][j];
    }
    std::cout << std::endl;
  };

    // Initializing distance and nodes
  for (int i = 0; i < SIZE; i++)
  {
    distance[i] = INFINITY;
    nodes[i] = 1; // 1 not visited
  };
    // Distance to entry node is 0
  distance[begin_index] = 0;

  // Algorithm step
  do {
    minindex = INFINITY;
    min = INFINITY;
    for (int i = 0; i < SIZE; i++)
    {
      if ((nodes[i] == 1) && (distance[i] < min)) // if node not visited and coast lower than min
      {
        min = distance[i];
        minindex = i;
      }
    }
    // adding founded minimal coast 
    // to current coast of node
    // and compare with current minimal coast of node
    if (minindex != INFINITY)
    {
      for (int i = 0; i < SIZE; i++)
      {
        if (edges[minindex][i] > 0)
        {
          temp = min + edges[minindex][i];
          if (temp < distance[i])
          {
            distance[i] = temp;
          }
        }
      }
      nodes[minindex] = 0; // visited
    }
  } while (minindex < INFINITY);

  // printing edges lowest coast 
  std::cout << "Edges lowest coast:" << std::endl;
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << "\t" << distance[i];
  }
  std::cout << std::endl;

    // Finding shortest way
  int visited[SIZE]; // array of visited nodes for shortest way 
  int end = 4; // index of last node 5 - 1
  visited[0] = end + 1; // first element - last point
  int k = 1; // index of previous node
  int weight = distance[end]; // coast of last node

  while (end != begin_index) // while dont reach to first point
  {
    for (int i = 0; i < SIZE; i++) // looking for all nodes
      if (edges[i][end] != 0)   // if connected with last node 
      {
        int temp = weight - edges[i][end]; // coast of previous node
        if (temp == distance[i]) // if coast is match
        {
          weight = temp; // saving new coast
          end = i;       // saving previous node
          visited[k] = i + 1; // and adding to visited array
          k++;
        }
      }
  }
  // Print shortest way
  std::cout << "The shortest way:" << std::endl;
  for (int i = k - 1; i >= 0; i--)
  {
    std::cout << "\t" << visited[i];
  }
  std::cout << std::endl;
  return 0;
};