//#include<iostream>
//using namespace std;
//
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
//template <typename ITEM> Node<ITEM>::Node() { next = back = NULL; }
//template <typename ITEM> Node<ITEM>::Node(ITEM p_item) :Node() { item = p_item; }
//template <typename ITEM> void Node<ITEM>::setNext(Node <ITEM>* n) { next = n; }
//template <typename ITEM> void Node<ITEM>::setBack(Node <ITEM>* b) { back = b; }
//template <typename ITEM> Node<ITEM>* Node<ITEM>::getNext() { return next; }
//template <typename ITEM> Node<ITEM>* Node<ITEM>::getBack() { return back; }
//template <typename ITEM> ITEM& Node<ITEM>::getItem() { return item; }
//template <typename ITEM> Node<ITEM>::~Node() {}
//
//template <typename ITEM>
//class ListLinkedList {
//private:
//	Node<ITEM>* head;
//	Node<ITEM>* tail;
//	int size;
//
//public:
//	
//	ListLinkedList();
//	int append(ITEM item);
//	bool removeEnd(ITEM& item);
//	void emptyList();
//	bool isEmpty();
//	void printList();
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
//	if (head == NULL) {
//		
//		return true;
//	}
//	else return false;
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
//	item = cur->getItem();
//	delete(cur);
//	return true;
//}
//
////TO EMPTY THE LIST IN THE DECONSTRUCTOR 
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
////PRINT FUNCTION USED ONLY WHILE DEBUGGING  
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
//public:
//
//	Stack();
//	
//	bool push(ITEM item);
//	bool pop(ITEM& item);
//	void display();
//	bool isEmpty();
//	~Stack();
//};
//
////STACK CONSTRUCTOR
//template <typename ITEM>
//Stack<ITEM>::Stack() {}
//
////PUSH METHOD
//template <typename ITEM>
//bool Stack<ITEM>::push(ITEM item) {
//	//l.append(item);
//	return l.append(item);
//}
//
//template <typename ITEM>
//bool Stack<ITEM>::isEmpty() { //implemented a function is empty because since the list instance is 
//	//private we cant access its function in the queue
//	return l.isEmpty(); 
//}
//
////POP METHOD
//template <typename ITEM>
//bool Stack<ITEM>::pop(ITEM& item) {
//	if (l.isEmpty()) {
//		cout << "Sorry, nothing to pop." << endl;//handling that stack is empty
//	}
//	return l.removeEnd(item);
//}
//
//
////DISPLAY METHOD
//template <typename item>
//void Stack <item> ::display() {
//	l.printList();
//}
//
////STACK DECONSTRUCTOR
//template <typename ITEM>
//Stack<ITEM>::~Stack() { }
//
//
////QUEUE CLASS 
//template <typename ITEM>
//class Queue :public ListLinkedList <ITEM> {
//private:
//	Stack <ITEM> s1;
//	Stack <ITEM> s2;
//public:
//	
//	Queue();
//	//using first method
//	void enqueue1(ITEM item);
//	void dequeue1(ITEM& item);
//
//	void display();
//	void display2();
//	~Queue();
//
//
//};
//template <typename ITEM>
//Queue<ITEM>::Queue() {}
//
////ENQUEUE
//template <typename ITEM>
//void Queue<ITEM>::enqueue1(ITEM item) {//ENQUING USING PUSH
//	s1.push(item);//using push to enqueue items to the queue (stack)
//
//}
//
////DEQUEUE
//template <typename ITEM>
//void Queue<ITEM>::dequeue1(ITEM& item) {//DEQUEUEING USING POP
//	if (s1.isEmpty()) {
//		cout << "error,Nothing to dequeue" << endl;
//		return;
//	
//	}
//	if (s2.isEmpty()) {//while s1 is not empty keep popping,store value 
//		//popped in var then psuh in s2
//		while (!s1.isEmpty()) {
//			s1.pop(item);
//			ITEM temp = item;
//			s2.push(item);
//			//s2.push(s1.pop(item));
//			
//		}
//	}
//	//we reversed the order of elements 
//	s2.pop(item);//popping top element
//
//	while (!s2.isEmpty()) {//returning the elements back to stack 1
//		//WE WROTE S2.L.ISEMPTY BCS THE ISEMPTY IS A FUNCTION FOR LIST ONLYYYYYY
//		s2.pop(item);
//		ITEM temp = item;
//		s1.push(item);
//		//s1.push(s2.pop(item));
//	}
//
//
//}
//
//
////DISPLAY
//template <typename item>
//void Queue <item> ::display() {
//	s1.display();
//}
//
//template <typename item>
//void Queue <item> ::display2() {
//	s2.display();
//}
//
//
//
////QUEUE DECONSTRUCTOR
//template <typename ITEM>
//Queue<ITEM>::~Queue() { }
//
//int main() {
//	Queue <int> q;
//	q.enqueue1(6);
//	q.enqueue1(7);
//	q.enqueue1(8);
//	q.enqueue1(9);
//	q.enqueue1(10);
//	q.display();
//	int y;
//	q.dequeue1(y);
//	cout << "after calling dequeue function " << endl;
//	q.display();
//	q.dequeue1(y);
//	cout << "after calling dequeue pt2 function " << endl;
//	q.display();
//	q.dequeue1(y);
//	cout << "after calling dequeue pt2 function " << endl;
//	q.display();
//	q.dequeue1(y);
//	cout << "after calling dequeue pt2 function " << endl;
//	q.display();
//	q.dequeue1(y);
//	cout << "after calling dequeue pt2 function " << endl;
//	q.display();
//	q.dequeue1(y);
//	cout << "after calling dequeue pt2 function " << endl;
//	q.display();
//
//
//
//
//
//
//
//}
