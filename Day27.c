#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Build linked list from array
struct Node* buildList(int arr[], int n) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* temp = createNode(arr[i]);

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection (by value as per example)
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2)
        for (int i = 0; i < diff; i++) p1 = p1->next;
    else
        for (int i = 0; i < diff; i++) p2 = p2->next;

    // Traverse together
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {
    int n, m;

    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    int *b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    struct Node* head1 = buildList(a, n);
    struct Node* head2 = buildList(b, m);

    int ans = findIntersection(head1, head2);

    if (ans == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", ans);

    return 0;
}