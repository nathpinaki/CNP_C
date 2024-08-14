#include <stdio.h>
#include <string.h>

struct Node {
    int set;
} node[100];

struct Edge {
    int first_node, second_node, selected, distance;
} e[100];

int edge_count = 0;

void getdata(int index, int total) {
    int i;
    for (i = index + 1; i < total; i++) {
        printf("\nEnter distance between Vertex %c and %c: ", index + 65, i + 65);
        scanf("%d", &e[edge_count].distance);
        e[edge_count].first_node = index;
        e[edge_count].second_node = i;
        ++edge_count;
    }
}

void init(int total) {
    int i;
    for (i = 0; i < total; i++)
        node[i].set = i;
    for (i = 0; i < edge_count; i++)
        e[i].selected = -1;
}

void sort() {
    int i, j;
    struct Edge temp;
    for (i = 0; i < edge_count - 1; i++) {
        for (j = 0; j < edge_count - i - 1; j++) {
            if (e[j].distance > e[j + 1].distance) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, total, j, k, m, n, edgeselected = 0, nodel, noder;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &total);

    for (i = 0; i < total; i++)
        getdata(i, total);

    init(total);
    sort();

    printf("\nThe Sorted order of edges:");
    for (i = 0; i < edge_count; i++) {
        printf("\nEdge: %d First node: %c Second node: %c Distance: %d",
               i, e[i].first_node + 65, e[i].second_node + 65, e[i].distance);
    }

    i = 0;
    do {
        e[i].selected = 1;
        nodel = e[i].first_node;
        noder = e[i].second_node;

        if (node[nodel].set == node[noder].set)
            e[i].selected = -1;
        else {
            edgeselected++;
            m = node[nodel].set;
            k = node[noder].set;
            for (n = 0; n < total; n++) {
                if (node[n].set == k)
                    node[n].set = m;
            }
        }
        i++;
    } while (edgeselected < (total - 1));

    printf("\nMinimum Spanning Tree is:");
    for (i = 0; i < edge_count; ++i) {
        if (e[i].selected == 1)
            printf("\n%c <-------> %c Distance %d",
                   e[i].first_node + 65, e[i].second_node + 65, e[i].distance);
    }

    return 0;
}