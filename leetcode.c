
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *current = &dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return dummy.next;
}

void display(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head = NULL, *tail = NULL, *newNode;
    int n, i, value, del;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct ListNode));

        printf("Enter element: ");
        scanf("%d", &value);

        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original linked list: ");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &del);

    head = removeElements(head, del);

    printf("Linked list after deletion: ");
    display(head);

    return 0;
}
