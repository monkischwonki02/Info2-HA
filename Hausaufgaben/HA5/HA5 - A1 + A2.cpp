//Name: Adrian Hammermeister
// Studiengang: Physik (Bachelor)
// Matrikelnr.: 221200260
#include <iostream>

// Data structures
struct Element {
	int data;
	Element* next;
};

struct LinkedList {
	Element* head;
};

// Primary functions
LinkedList* create();
void destroy(LinkedList* l);
Element* begin(LinkedList* l);
Element* end(LinkedList* l);
void insert(LinkedList* l, Element* p, int e);
void remove(LinkedList* l, Element* p);
int retrieve(LinkedList* l, Element* p);
Element* locate(LinkedList* l, int e);

LinkedList* create() {
	LinkedList* l = new LinkedList; // Create list on heap
	l->head = nullptr; // Initialize head and size
	return l;
}

void destroy(LinkedList* l) {
	while (begin(l) != end(l)) { // Are there any elements
		remove(l, begin(l)); // If yes, remove from head
	}
	delete l; // Delete list structure
}

Element* begin(LinkedList* l) {
	return l->head;
}

Element* end(LinkedList* l) {
	return nullptr;
}

void insert(LinkedList* l, Element* p, int e) {
	Element* n = new Element; // Create new data element
	n->data = e;
	n->next = nullptr;

	if (begin(l) == end(l)) { // Special case: empty list
		l->head = n; // Make new element the head
	}
	else if (begin(l) == p) { // Special case: insertion at beginning of list
		n->next = l->head; // New element is followed by old head
		l->head = n; // New head is new element
	}
	else { // Regular case: insert anywhere in list (includes case of insertion at nullptr, which means at end)
		Element* c = l->head;
		while (c->next != p) { // Locate element preceding the position at which to insert
			c = c->next;
		}
		n->next = c->next; // Establish links between preceding, new, and following elements
		c->next = n;
	}
}

void remove(LinkedList* l, Element* p) {
	if (p == end(l)) { // Special case: p is not in list (== nullptr)
		// Do nothing
	}
	else if (p == begin(l)) { // Special case: removal at beginning of list
		Element* r = l->head; // The element to be removed
		l->head = l->head->next; // Automatically nulls the head if it was the last element
		delete r; // Remove element from memory
	}
	else { // Regular case: remove anywhere from list
		Element* c = l->head;
		while (c->next != p) { // Locate element preceding the element to be removed
			c = c->next;
		}
		Element* r = c->next; // The element to be removed
		c->next = r->next; // Bridge link between preceding and following element
		delete r; // Remove element from memory
	}
}

int retrieve(LinkedList* l, Element* p) {
	return p->data;
}

Element* locate(LinkedList* l, int e) {
	for (Element* c = begin(l); c != end(l); c = c->next) { // Scan all elements in list
		if (retrieve(l, c) == e)
			return c; // Return once a match has been found
	}
	return end(l); // Return end(l) if no match has been found
}

void print(LinkedList* l) {
	std::cout << "[";
	for (Element* c = begin(l); c != end(l); c = c->next) {
		std::cout << c->data;
		if (c->next != nullptr) {
			std::cout << " -> ";
		}
	}
	std::cout << "]" << std::endl;
}

// A1
void split(LinkedList* l, int v, LinkedList** a, LinkedList** b) {
	Element* c = locate(l, v); // O(n)
	if (c != nullptr) { // O(1)
		for (Element* d = begin(l); d != c; d = d->next) {
			insert(*a, end(*a), d->data);
		} // O(n), da insert O(n) und man m mal die Schleife durchgeht (m*n = O(n))
		for (Element* e = c; e != end(l); e = e->next) {
			insert(*b, end(*b), e->data);
		} // O(n), da Insert O(n) und man (n-m) mal die Schleife durchgeht ((n-m)*n = O(n))
	}
}
// Zeitaufwand: O(n²), da m*n + (n-m)*n + n = n² + n (Vereinfachung: Vergleiche für Schleife werden nicht mitgezählt)


// A2
void merge(LinkedList* a, LinkedList* b, LinkedList** l) {

	while (begin(a) != end(a)) {
		insert(*l, end(*l), begin(a)->data); // O(n)
		remove(a, begin(a)); // O(1)
	}
	
	while (begin(b) != end(b)) {
		insert(*l, end(*l), begin(b)->data); // O(n)
		remove(b, begin(b)); // O(1)
	}
}
// Zeitaufwand: best-case O(n²) Begründung: remove - O(1), insert - O(n), while1 - k, while2 - (n-k) : k*n + (n-k)*n = n²
//				worst-case O(n²) Begründung: remove - O(1), insert - O(n), while1 - k, while2 - (n-k) : k*n + (n-k)*n = n²


int main() {

	// A1
	LinkedList* l = create();
    LinkedList* a = create();
    LinkedList* b = create();

	int arr[10] = {1,5,8,7,33,12,9,6,11,120};

	print(l);
	print(a);
	print(b);
	for (int &elem: arr){
		insert(l, end(l), elem);
	}
	split(l, 33, &a, &b);
	print(a);
	print(b);

    destroy(a);	a = nullptr;
    destroy(b);	b = nullptr;
    destroy(l);	l = nullptr;


	std::cout << std::endl;

	// A2
	LinkedList* m = create();
	LinkedList* c = create();
	LinkedList* d = create();

	for (int i = 0; i < 10; i++){
		insert(c, end(c), i);
		insert(d, end(d), i+10);
	}
	print(c); print(d); print(m);

	merge(c,d,&m);
	print(c); print(d); print(m);

	destroy(c);	c = nullptr;
    destroy(d);	d = nullptr;
    destroy(m); m = nullptr;


	
}

