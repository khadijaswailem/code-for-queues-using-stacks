//#include<iostream>
//using namespace std;

#include<iostream>
using namespace std;

template <typename ITEM>
class Node
{
private:
	ITEM item;
	Node <ITEM>* next;
	Node <ITEM>* back;
public:
	Node();
	Node(ITEM p_item);
	void setNext(Node <ITEM>* n);
	void setBack(Node <ITEM>* b);
	Node<ITEM>* getNext();
	Node<ITEM>* getBack();
	ITEM& getItem();
	~Node();
};

template <typename ITEM> Node<ITEM>::Node() { next = back = NULL; }
template <typename ITEM> Node<ITEM>::Node(ITEM p_item) :Node() { item = p_item; }
template <typename ITEM> void Node<ITEM>::setNext(Node <ITEM>* n) { next = n; }
template <typename ITEM> void Node<ITEM>::setBack(Node <ITEM>* b) { back = b; }
template <typename ITEM> Node<ITEM>* Node<ITEM>::getNext() { return next; }
template <typename ITEM> Node<ITEM>* Node<ITEM>::getBack() { return back; }
template <typename ITEM> ITEM& Node<ITEM>::getItem() { return item; }
template <typename ITEM> Node<ITEM>::~Node() {}

template <typename ITEM>
class ListLinkedList {
protected:
	Node<ITEM>* head;
	Node<ITEM>* tail;
	int size;


public:
	ListLinkedList();
	int append(ITEM item);
	bool removeEnd(ITEM& item);
	void emptyList();
	ITEM* getItemAt(int index);

	bool isEmpty();
	void printList();



	~ListLinkedList();
};

//CONSTRUCTOR 
template <typename ITEM>
ListLinkedList<ITEM>::ListLinkedList() {
	head = tail = NULL;
	size = 0;
}

//FUNCTION TO CHECK IF THE STACK IS EMPTY
template <typename ITEM>
bool ListLinkedList<ITEM>::isEmpty()
{
	if (head == NULL) return true; else return false;
}
//FOR PUSHING TO STACK
template <typename ITEM>
int ListLinkedList<ITEM>::append(ITEM item) {
	if (isEmpty()) {
		head = tail = new Node <ITEM>(item);
		size++;
		return true;
	}
	tail->setNext(new Node <ITEM>(item));
	tail->getNext()->setBack(tail);
	tail = tail->getNext();
	size++;
	return size;
}


//FOR POPPING FROM STACK 
template <typename ITEM>
bool ListLinkedList<ITEM>::removeEnd(ITEM& item) {
	if (isEmpty()) return false;
	Node <ITEM>* cur = tail;
	if (head != tail) {
		tail = tail->getBack();
		tail->setNext(NULL);
	}
	else {
		cur = head;
		head = tail = NULL;
	}

	item = cur->getItem();
	cout << "item: " << item << endl;
	delete(cur);
	return true;
}

//FOR GETTING ITEM AT A GIVEN INDEX
template <typename ITEM>
ITEM* ListLinkedList<ITEM>::getItemAt(int index) {
	int i = 0;
	for (Node <ITEM>* cur = head;cur != NULL; cur = cur->getNext(), i++)
		if (i == index) return &(cur->getItem());
	return NULL;
}

//TO EMPTY THE LIST IN THE CONSTRUCTOR 
template <typename ITEM>
void ListLinkedList<ITEM>::emptyList() {
	if (isEmpty()) return;
	if (head != tail) {
		Node <ITEM>* cur = NULL;
		while (head != NULL) {
			cur = head;
			head = head->getNext();
			delete(cur);
		}
	}
	head = tail = NULL;
}

//DESTRUCTOR 
template <typename ITEM>
ListLinkedList<ITEM>::~ListLinkedList()
{
	emptyList();
}


//PRINT FUNCTION 
template <typename ITEM>
void ListLinkedList<ITEM>::printList() {
	for (Node <ITEM>* cur = head; cur != NULL; cur = cur->getNext())
		cout << cur->getItem() << endl;
}

//STACK CLASS 
template <typename ITEM>
class Stack :public ListLinkedList <ITEM>
{
private:
	ListLinkedList <ITEM> l;
	bool flagrev = 0;
public:

	Stack();
	bool push(ITEM item);
	bool pop(ITEM& item);
	void display();
	ITEM* returntop();
	~Stack();
};

template <typename ITEM>
Stack<ITEM>::Stack() {}


template <typename ITEM>
bool Stack<ITEM>::push(ITEM item) {

	return l.append(item);
}

template <typename ITEM>
bool Stack<ITEM>::pop(ITEM& item) {
	if (l.isEmpty()) {
		cout << "Sorry, nothing to pop." << endl;//handling that stack is empty
	}
	return l.removeEnd(item);
}

template <typename ITEM>
ITEM* Stack <ITEM> ::returntop() {//implemented a function to get the bottom of the stack
	//using getitemat from th linkedlist class and returning it
	
	return (l.getItemAt(0));
} 

template <typename ITEM>
void Stack <ITEM> ::display() {
	l.printList();
}


template <typename ITEM>
Stack<ITEM>::~Stack() { }

//STACK CLASS THAT INHERITS FROM ORIGINAL STACK CLASS 
template <typename ITEM>
class Stack1 :public Stack <ITEM>
{
private:
	Stack<ITEM> s1;
	bool flagrev = 0;
public:

	Stack1();
	bool push1(ITEM item);
	bool pop1(ITEM& item);
	void display1();
	ITEM* returntop1();
	void setReverse();
	~Stack1();
};
template <typename ITEM>
Stack1<ITEM>::Stack1() {}

template <typename ITEM>
void Stack1 <ITEM> ::setReverse() {//Reverse function that sets the flag to the opposite of its
	//current state
	if (flagrev == 0) {
		flagrev = 1;
	}
	else if (flagrev == 1) {
		flagrev = 0;
	}
	
}

template <typename ITEM>
ITEM* Stack1 <ITEM> ::returntop1() {//implemented a function to get the bottom of the stack
	return s1.returntop();
}
template <typename ITEM>
bool Stack1<ITEM>::push1(ITEM item) {
	if (flagrev == 1) {//if stack is reversed will insert at head
		s1.push(item);
	}
	else if (flagrev == 0) {//else if stack is not reversed will append at tail
		setReverse();
		s1.push(item);

	}
	return s1.push(item);
}

template <typename ITEM>
bool Stack1<ITEM>::pop1(ITEM& item) {
	if (s1.isEmpty()) {
		cout << "Sorry, nothing to pop." << endl;//handling that stack is empty
		return false;
	}
	if (flagrev == 1) {//if stack is reversed meaning the bottom element is now at the top
		//we can pop
		s1.pop(*(s1.returntop()));
	}
	else if (flagrev == 0) {//else if its not reversed we will "reverse" it and then pop from it
		setReverse();
		s1.pop(*(s1.returntop()));
	}
	return s1.pop(item);
}


template <typename ITEM>
void Stack1 <ITEM> ::display1() {
	s1.display();
}



template <typename ITEM>
Stack1<ITEM>::~Stack1() { }



//QUEUE CLASS 
template <typename ITEM>
class Queue :public Stack1 <ITEM> {
private:
	Stack1 <ITEM> s;

public:
	Queue();

	//using second method
	void enqueue2(ITEM item);
	void dequeue2(ITEM& item);

	void displayQ();
	~Queue();


};
template <typename ITEM>
Queue<ITEM>::Queue() {}


template <typename ITEM>
void Queue<ITEM>::enqueue2(ITEM item) {//ENQUING USING NEW PUSH FROM STACK 1 CLASS
	s.push1(item);


}


template <typename ITEM>
void Queue<ITEM>::dequeue2(ITEM& item) {//DEQUEUEING USING NEW POP FROM STACK 1 CLASS
	s.pop1(item);
}

template <typename item>
void Queue <item> ::displayQ() {

	s.display1();
}


template <typename ITEM>
Queue<ITEM>::~Queue() { }

int main() {
	Queue <int> q;
	q.enqueue2(6);
	q.enqueue2(7);

	q.enqueue2(8);
	q.enqueue2(9);
	q.enqueue2(10);
	q.display();
	int y = 6;
	q.dequeue2(y);
	cout << "after dequeuing" << endl;
	q.display();
	int x = 8;
	q.dequeue2(x);
	cout << "after dequeuing" << endl;
	q.display();







}
