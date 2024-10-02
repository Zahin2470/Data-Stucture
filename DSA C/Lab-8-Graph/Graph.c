#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize the adjacency list with NULL
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int source, int destination) {
    // Add edge from source to destination
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;

    // Add edge from destination to source (assuming an undirected graph)
    newNode = createNode(source);
    newNode->next = graph->adjacencyList[destination];
    graph->adjacencyList[destination] = newNode;
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    printf("Graph with %d nodes:\n", graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* currentNode = graph->adjacencyList[i];
        printf("Node %d:", i);

        while (currentNode != NULL) {
            printf(" -> %d", currentNode->vertex);
            currentNode = currentNode->next;
        }

        printf("\n");
    }
}

int main() {
    int numVertices, source, destination;
    
    // Get the number of nodes in the graph
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numVertices);

    // Create a graph with the given number of vertices
    struct Graph* graph = createGraph(numVertices);

    // Get edges from user input and add them to the graph
    printf("Enter the source and destination of connecting edge (e.g., 0 1). Enter -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &source, &destination);
        if (source == -1 || destination == -1) {
            break;
        }
        addEdge(graph, source, destination);
    }

    // Display the graph
    displayGraph(graph);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        struct Node* currentNode = graph->adjacencyList[i];
        while (currentNode != NULL) {
            struct Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(graph->adjacencyList);
    free(graph);

    return 0;
}