#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int _val): val(_val), next(NULL) {}
	~Node() {
		if (next != NULL)
			delete next;
	}
};

Node* reverseLinkedList(Node* head);

Node* reverseLinkedList(Node* head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	Node* tail = head->next;
	Node* newhead = reverseLinkedList(tail);
	tail->next = head;
	head->next = NULL;
	return newhead;
}

void printLinkedList(Node* head) {
	for (Node* it=head; it!=NULL; it=it->next)
		cout << it->val << ' ';
	cout << endl;
}

void testReverseLinkedList(Node* toTest) {
	cout << "original: ";
	printLinkedList(toTest);
	toTest = reverseLinkedList(toTest);
	cout << "reversed: ";
	printLinkedList(toTest);
}

int main() {
	// testing list of 0 to 9
	Node* linkedList_1 = new Node(0);
	Node* writePt = linkedList_1;
	for (int i=1; i<10; ++i) {
		writePt->next = new Node(i);
		writePt = writePt->next;
	}
	testReverseLinkedList(linkedList_1);
	delete linkedList_1;
	// testing list of one element
	Node* linkedList_2 = new Node(42);
	testReverseLinkedList(linkedList_2);
	delete linkedList_2;
	// testing list of nothing
	Node* linkedList_3 = NULL;
	testReverseLinkedList(linkedList_3);
}