//#include<iostream>
//using namespace std;
//
////CLASS NODE
//template <typename ITEM>
//class Node
//{
//private:
//	ITEM item;
//	Node <ITEM>* next;
//	Node <ITEM>* back;
//public:
//	Node();
//	Node(ITEM p_item);
//	void setNext(Node <ITEM>* n);
//	void setBack(Node <ITEM>* b);
//	Node<ITEM>* getNext();
//	Node<ITEM>* getBack();
//	ITEM& getItem();
//	~Node();
//};
//
////FUNCTION IMPLEMENTATIONS+CONSTRUCTOR+DESTRUCTOR
//template <typename ITEM> Node<ITEM>::Node() { next = back = NULL; }
//template <typename ITEM> Node<ITEM>::Node(ITEM p_item) :Node() { item = p_item; }
//template <typename ITEM> void Node<ITEM>::setNext(Node <ITEM>* n) { next = n; }
//template <typename ITEM> void Node<ITEM>::setBack(Node <ITEM>* b) { back = b; }
//template <typename ITEM> Node<ITEM>* Node<ITEM>::getNext() { return next; }
//template <typename ITEM> Node<ITEM>* Node<ITEM>::getBack() { return back; }
//template <typename ITEM> ITEM& Node<ITEM>::getItem() { return item; }
//template <typename ITEM> Node<ITEM>::~Node() {}
//
//
////CLASS LINKED LIST
//template <typename ITEM>
//class ListLinkedList {
//protected:
//	Node<ITEM>* head;
//	Node<ITEM>* tail;
//	int size;
//	Node<ITEM>* getIndex(int index);
//
//public:
//	ListLinkedList();
//	int append(ITEM item);
//	bool removeEnd(ITEM& item);
//	void emptyList();
//	int removeAt(int index);
//	bool insert(ITEM item, int index);
//	bool isEmpty();
//	void printList();
//
//
//
//	~ListLinkedList();
//};
//
////CONSTRUCTOR 
//template <typename ITEM>
//ListLinkedList<ITEM>::ListLinkedList() {
//	head = tail = NULL;
//	size = 0;
//}
//
////FUNCTION TO CHECK IF THE STACK IS EMPTY
//template <typename ITEM>
//bool ListLinkedList<ITEM>::isEmpty()
//{
//	if (head == NULL) return true; else return false;
//}
//
////GET INDEX METHOD USED IN INSERT
//template <typename ITEM>
//Node<ITEM>* ListLinkedList<ITEM>::getIndex(int index) {
//	int i = 0;
//	for (Node <ITEM>* cur = head;cur != NULL; cur = cur->getNext(), i++)
//		if (i == index) return cur;
//	return NULL;
//}
//
////INSERT METHOD USED FOR PUSHING
//template <typename ITEM>
//bool ListLinkedList<ITEM>::insert(ITEM item, int index) {
//	if (isEmpty()) {
//		head = tail = new Node <ITEM>(item);
//		size++;
//		return true;
//	}
//	Node <ITEM>* cur = getIndex(index);
//	if (cur != NULL) {
//		Node <ITEM>* newNode = new Node <ITEM>(item);
//		newNode->setNext(cur);
//		newNode->setBack(cur->getBack());
//		cur->setBack(newNode);
//		if (cur == head) head = head->getBack();
//		else newNode->getBack()->setNext(newNode);
//		size++;
//		return true;
//	}
//	else return false;
//}
//
////REMOVE AT METHOD USED IN POPPING
//template <typename ITEM>
//int ListLinkedList<ITEM>::removeAt(int index)
//{
//	Node <ITEM>* cur = getIndex(index);
//	if (cur != NULL)
//	{
//		if (cur != tail) cur->getNext()->setBack(cur->getBack());
//		else tail = cur->getBack();
//		if (cur != head) cur->getBack()->setNext(cur->getNext());
//		else head = cur->getNext();
//		delete (cur);
//		size--;
//	}
//	return size;
//}
//
////FOR PUSHING TO STACK
//template <typename ITEM>
//int ListLinkedList<ITEM>::append(ITEM item) {
//	if (isEmpty()) {
//		head = tail = new Node <ITEM>(item);
//		size++;
//		return true;
//	}
//	tail->setNext(new Node <ITEM>(item));
//	tail->getNext()->setBack(tail);
//	tail = tail->getNext();
//	size++;
//	return size;
//}
//
//
////FOR POPPING FROM STACK 
//template <typename ITEM>
//bool ListLinkedList<ITEM>::removeEnd(ITEM& item) {
//	if (isEmpty()) return false;
//	Node <ITEM>* cur = tail;
//	if (head != tail) {
//		tail = tail->getBack();
//		tail->setNext(NULL);
//	}
//	else {
//		cur = head;
//		head = tail = NULL;
//	}
//
//	item = cur->getItem();
//	delete(cur);
//	return true;
//}
//
//
////TO EMPTY THE LIST IN THE CONSTRUCTOR 
//template <typename ITEM>
//void ListLinkedList<ITEM>::emptyList() {
//	if (isEmpty()) return;
//	if (head != tail) {
//		Node <ITEM>* cur = NULL;
//		while (head != NULL) {
//			cur = head;
//			head = head->getNext();
//			delete(cur);
//		}
//	}
//	head = tail = NULL;
//}
//
////DESTRUCTOR 
//template <typename ITEM>
//ListLinkedList<ITEM>::~ListLinkedList()
//{
//	emptyList();
//}
//
//
////PRINT FUNCTION TO DISPLAY THE STACK
//template <typename ITEM>
//void ListLinkedList<ITEM>::printList() {
//	for (Node <ITEM>* cur = head; cur != NULL; cur = cur->getNext())
//		cout << cur->getItem() << endl;
//}
//
////STACK CLASS 
//template <typename ITEM>
//class Stack :public ListLinkedList <ITEM>
//{
//private:
//	ListLinkedList <ITEM> l;
//
//public:
//
//	Stack();
//	bool push(ITEM item);
//	bool pop(ITEM& item);
//	void display();
//	void removeAt(int index);
//	void insert(ITEM item, int index);
//	bool isEmpty();
//	~Stack();
//};
//
////CONSTRUCTOR
//template <typename ITEM>
//Stack<ITEM>::Stack() {}
//
////INSERT FUNCTION FOR NEW PUSH
//template <typename ITEM>
//void Stack<ITEM>::insert(ITEM item, int index) {
//	l.insert(item, index);
//}
//
////REMOVE AT FUNCTION FOR NEW POP
//template <typename ITEM>
//void Stack<ITEM>::removeAt(int index)
//{
//	l.removeAt(index);
//}
////PUSH FUNCTION
//template <typename ITEM>
//bool Stack<ITEM>::push(ITEM item) {
//
//	return l.append(item);
//}
//
////POP FUNCTION
//template <typename ITEM>
//bool Stack<ITEM>::pop(ITEM& item) {
//	if (l.isEmpty()) {
//		cout << "Sorry, nothing to pop." << endl;//handling that stack is empty
//	}
//	return l.removeEnd(item);
//}
//
//
//
////FUNCTION TO CHECK IF STACK IS EMPTY
//template <typename ITEM>
//bool Stack<ITEM>::isEmpty() { //implemented a function is empty because since the list instance is 
//	//private we cant access its function in the queue
//	return l.isEmpty();
//}
//
////FUNCTION TO DISPLAY
//template <typename ITEM>
//void Stack <ITEM> ::display() {
//	l.printList();
//}
//
////DESTRUCTOR
//template <typename ITEM>
//Stack<ITEM>::~Stack() { }
//
////STACK CLASS THAT INHERITS FROM ORIGINAL STACK CLASS BUT WILL IMPLEMENT THE CHANGES FOR THE POP AND PUSH
//template <typename ITEM>
//class Stack1 :public Stack <ITEM>
//{
//private:
//	Stack<ITEM> s1;
//	bool flagrev = 0;//boolean flag
//public:
//
//	Stack1();
//	void push(ITEM item);
//	void pop(ITEM& item);
//	bool isEmpty();
//	void display();
//	void setReverse();
//	~Stack1();
//};
//
////CONSTRUCTOR
//template <typename ITEM>
//Stack1<ITEM>::Stack1() {}
//
////SET REVERSE
//template <typename ITEM>
//void Stack1 <ITEM> ::setReverse() {//Reverse function that sets the flag to the opposite of its current state
//	if (flagrev == 0) {
//		flagrev = 1;
//	}
//	else if (flagrev == 1) {
//		flagrev = 0;
//	}
//
//}
//
//
////FUNCTION TO CHECK IF STACK IS EMPTY
//template <typename ITEM>
//bool Stack1<ITEM>::isEmpty() { 
//	return s1.isEmpty();
//}
//
//
////PUSH FUNCTION
//template <typename ITEM>
//void Stack1<ITEM>::push(ITEM item) {//THE FUNCTIONS IMPLEMENTED BY INHERITING FROM THE ORIGINAL STACK AND LINKED LIST CLASSES
//	if (flagrev == 1) {//if stack is reversed will insert at head
//		
//		s1.insert(item,0);
//
//	}
//	else if (flagrev == 0) {//else if stack is not reversed will append at tail using push
//		
//		s1.push(item);
//	}
//}
//
////POP FUNCTION
//template <typename ITEM>
//void Stack1<ITEM>::pop(ITEM& item) {
//
//	if (flagrev == 1) {//if stack is reversed meaning the bottom element is now at the top
//		//we can pop
//		s1.removeAt(0);
//	}
//	else if (flagrev == 0) {//else if its not reversed we will "reverse" it and then pop from it
//		setReverse();
//		s1.removeAt(0);
//	}
//	
//}
//
//
////DISPLAY FUNCTION
//template <typename ITEM>
//void Stack1 <ITEM> ::display() {
//	s1.display();//calls display from stack class
//}
//
//
////DESTRUCTOR
//template <typename ITEM>
//Stack1<ITEM>::~Stack1() { }
//
//
//
////QUEUE CLASS 
//template <typename ITEM>
//class Queue :public Stack1 <ITEM> {
//private:
//	Stack1 <ITEM> s1;//created an instance from class stack 1 that has the boolean flag
//	
//public:
//	Queue();
//	void enqueue2(ITEM item);
//	void dequeue2(ITEM& item);
//	void displayQ();
//	~Queue();
//
//};
//
////CONSTRUCTOR
//template <typename ITEM>
//Queue<ITEM>::Queue() {}
//
////ENQUEUE METHOD
//template <typename ITEM>
//void Queue<ITEM>::enqueue2(ITEM item) {//ENQUEUEING USING NEW PUSH FROM STACK 1 CLASS
//		s1.push(item);
//}
//
////DEQUEUE METHOD
//template <typename ITEM>
//void Queue<ITEM>::dequeue2(ITEM& item) {//DEQUEUEING USING NEW POP FROM STACK 1 CLASS
//	if (s1.isEmpty()) {
//		cout << "Sorry, nothing to dequeue" << endl;//handling that stack is empty
//
//	}
//	s1.pop(item);
//	
//}
//
////DISPLAY METHOD
//template <typename item>
//void Queue <item> ::displayQ() {
//	s1.display();
//}
//
////DECONSTRUCTOR
//template <typename ITEM>
//Queue<ITEM>::~Queue() { }
//
//int main() {
//	Queue <int> q;
//	q.enqueue2(6);
//	q.enqueue2(7);
//
//	q.enqueue2(8);
//	q.enqueue2(9);
//	q.enqueue2(10);
//	q.displayQ();
//	int y ;
//	q.dequeue2(y);
//	cout << "after dequeuing" << endl;
//	q.displayQ();
//	int x;
//	q.dequeue2(x);
//	cout << "after dequeuing" << endl;
//	q.displayQ();
//	q.dequeue2(x);
//	cout << "after dequeuing" << endl;
//	q.displayQ();
//	q.dequeue2(x);
//	cout << "after dequeuing" << endl;
//	q.displayQ();
//	q.dequeue2(x);
//	cout << "after dequeuing" << endl;
//	q.displayQ();
//	q.dequeue2(x);
//	
//}
