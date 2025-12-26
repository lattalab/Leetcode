
typedef struct Node {
	int val;
	struct Node* next;
} Node;

typedef struct {
    int size;
    struct Node* start; // point to empty node
} MyLinkedList;

// manage unit
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    // create empty head
    Node* head = (Node*)malloc(sizeof(Node));
	head->next = (void*)0;
	obj->start = head;
    obj->size = 0;
	return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    Node *cur = obj->start->next;
    int idx  = 0;
    while (idx++ != index){
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->val = val;

    tmp->next = obj->start->next;
	obj->start->next = tmp;

    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    // find last element
    Node *cur = obj->start;
    while (cur->next){
        cur = cur->next;
    }

    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->val = val;
    // IMPORTANT
    tmp->next = NULL;
    cur->next = tmp;

    obj->size++;
}

/** 
Add a node of value val before the index-th node in the linked list. 
If index equals to the length of linked list, the node will be appended to the end of linked list. 
If index is greater than the length, the node will not be inserted. 
*/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;

    Node *cur = obj->start;
    int idx = 0;
    while(idx++ != index){
        cur = cur->next;
    }

    // create new element
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = cur->next;
    cur->next = tmp;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node *cur = obj->start;

    int idx = 0;
    while(idx++ != index){
        cur = cur->next;
    }

    Node* tmp = cur->next;
	cur->next = tmp->next;
	free(tmp);
	obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    // empty all list
    Node *prev, *cur = obj->start;
    while(cur != NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // empty top class at the end
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/