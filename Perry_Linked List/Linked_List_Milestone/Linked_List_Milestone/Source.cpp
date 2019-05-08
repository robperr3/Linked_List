#include <iostream>
#include <string>

using namespace std;

template <typename generic_type>  //creating a template of generic data type
class Node// my class for nodes
{
public:
	Node* next;  // pointer for next node
	Node* prev; // pointer for previous node
	generic_type data; // variable for class

	Node()
	{
		data = NULL; //nullifying the variable data;
		next = nullptr;//nullifying the pointer
		prev = nullptr;
	}

	Node(generic_type init_D)
	{// passing the class constructor w/ all its data members
		data = init_D; //initializing data members
		next = nullptr;//nullifying the pointer
		prev = nullptr;
	}

	Node(generic_type init_D,Node* init_N, Node* init_PV)
	{
		data = init_D;
		next = init_N; //initializing next pointer
		prev = init_PV;//initializing previous pointer
	}

};

template <typename generic_type>
class DL_List // creating the doubly-linked list class
{

public:
	DL_List<generic_type>*L1;// linked list pointer;
	Node<generic_type>* top;// creating the head & tail pointer
	Node<generic_type>* bottom;

	DL_List()// creating the linked list default constructor (w/ empty head & tail )
	{
		top = 0;
		bottom = 0;
	}

	DL_List( DL_List* init_T, DL_List* init_B)// linked list constructor w/ data passed in
	{
		top = init_T; // initializing next pointer
		bottom = init_B;// initializing previous pointer
	}

	void Insert( generic_type init_D)// creates node object using node data passed in & puts it on top of list
	{
		Node<generic_type>*N1 = new Node<generic_type>(init_D);//automatically creating new node & pointer 

		if (bottom == nullptr)// if linked list is empty
		{
			top = N1;//point head pointer to new node
			bottom = N1;//since its the only node, its also the tail 
			N1->next = 0;//its next & previous pointers are null since its by itself
			N1->prev = 0;
		}
		else// if linked list does in fact contain a node
		{
			N1->prev = top;// adds new node to list and link it and head pointer to each other
			top->next = N1;
			top = N1;// point head pointer to new node
		}
	}

	Node<generic_type>* Find(generic_type init_D)// takes in data to compare to nodes in the list
	{
		if (top == NULL)// if list is empty print message saying so
		{cout << "This list is empty!" << endl; }
		
		if (top->data = init_D)// if data of head node matches data being passing in 
		{
			cout << "Here's your Node " << top->data << endl;// tell user this
			return top;	//and return head node
		}
			// for as long as the next node is NOT null
		while (top->next != NULL){
			if (top->next->data = init_D)//if data for the next node matches data being passed 
			{return top->next;}//return pointer of that node

			else // otherwise if data doesn't match data of any nodes, then node isn't here
			{cout << "Sorry, it's not here!!!" << endl;}
		}
			
	}
		
		

	void Delete(Node<generic_type>*delN)// delelte function removes node in list with pointer passed in
	{
		if (bottom == NULL)// if list is empty, tell user this
		{
			cout << "\nThis list is empty!." << endl;
		}
		else
		{
			if (delN == top && delN == bottom)// if the node's is the only node in the list
			{
				top = NULL;// turn both head & tail pointers into null, emptying the list
				bottom = NULL;
			}
			else if (delN == top)// if head node is node you want to delete
			{
				top = top->prev;// make pointer of head now point to tail
				top->next = NULL;// old pointer of heads next node is now tail 
			}
			else if (delN == bottom)// if node you want deleted is the tail node
			{
				bottom = bottom->next;// tail is now pushed to head position (next of tail)
				bottom->prev = NULL;
			}
			else if
			{// otherwise move next pointer of the node before node you want deleted to the node after target node
				delN->prev->next = delN->next;
				delN->next->prev = delN->prev;// and move pointer of target node from the next node to node before target node
			}
			delete delN;//then delete the target node
			else // otherwise if data doesn't match data of any nodes, then node isn't here
			{
				cout << "Sorry, it's not here!!!" << endl;
			}
		}
	}

	void DisplayDLL()// prints out data of all nodes within linked list
	{
		 Node<generic_type>* temp;// make pionter for current node
		temp = bottom;// current pointer now points to tail
		if (temp == nullptr) { cout << "\nThis Linked List is empty!" << endl; }// if tail  is null list is empty
		else 
		{// other wise as long as currretn node pointer isnt null
			while (temp != nullptr)
			{//print out the data of the current node
				cout << "\nNode: " << temp->data << endl;
				temp = temp->next;// the current node is now the next node
			}//it will keep moving thorug hte list of nodes until current node is null
		}
	}
};

// ***************Here's my Testing Suite for the doubly-linked list**************************************************************
void main()
{
	int choice;
	DL_List<int> List1;
	//creating a do while loop for a menu
	do {
		
		cout << "\nWelcome to the Linked List Application. PLease choose a valid option\n" << endl;
		cout << "1. Test default constructor (also ensures default constructor is empty)" << endl;
		cout << "2. Test Push function with 1 Node" << endl;
		cout << "3. Deleting a Linked List with only one Node (the head)"<< endl;
		cout << "4. Deleting a only the last Node (the tail)" << endl;
		cout << "5. Deleting a Node in the middle of the List" << endl;
		cout << "6. Finding different Nodes" << endl;
		cout << "7. Quit" << endl;
		cin >> choice;// take user input as variable

		if (choice == 1)
		{
			List1 = DL_List<int>();// Create an empty linked list & give user message
			cout << "\nA Linked List has been created" << endl;
			Node<int>*N1 = new Node<int>(1);// create a new node object but dont insert it into list
			List1.Delete(N1);// Now try deleting a node from the empty list, it should give you an "empty list" message
		}

		if (choice == 2)
		{
			DL_List<int> L1;// Create a new list
			Node<int>*N1 = NULL;// Create new empty node
			cout << "\nCreating a Linked List with 1 Node only" << endl;
			L1.Insert(1);// Test inserting new node with data passed in into list
			L1.DisplayDLL();// Display new list to ensure insert function worked properly
		}
		if (choice == 3)
		{		 
			DL_List<int> L1;//Create a new List
			Node<int>*N1 = NULL;// Create new empty node
			// I used object.method so as not to leave any garbage behind in the heap
			cout << "\nCreating a Linked List with 1 Node" << endl;
			L1.Insert(1);// Insert new node with data passd into insert function into list 
			L1.DisplayDLL();// Show that this was successful
			cout << "Beginning the processs of delelting the only Node..." << endl;
			N1 = L1.Find(1); // Now use Find function to locate new node & return node 
			L1.Delete(N1);// Use returned node for delete function
			L1.DisplayDLL(); // Show that node was deleted successfully

		}
		if (choice == 4)
		{
			DL_List<int> L1;// New list created
			Node<int>*N1 = NULL;// Two new nodes created
			Node<int>*N2 = NULL;

			cout << "\nCreating a Linked List with 2 Nodes" << endl;
			L1.Insert(1);// Insert node 1 into list
			L1.Insert(2);// Insert node 2 into list
			L1.DisplayDLL(); //Show that this was done 
			N2 = L1.Find(2);// Locate tail node  
			L1.Delete(N2);// Delete tail node 
			L1.DisplayDLL();// Show list to prove function can delete tail nodes

		}

		if(choice == 5)
		{
			DL_List<int> L1;
			Node<int>*N1 = NULL;// Four new nodes created
			Node<int>*N2 = NULL;
			Node<int>*N3 = NULL;
			Node<int>*N4 = NULL;
			cout << "Creating a multinode list....." << endl;
			L1.Insert(1);// Insert node 1 into list
			L1.Insert(2);// Insert node 2 into list
			L1.Insert(3);// Insert node 3 into list
			L1.Insert(4);// Insert node 4 into list
			L1.DisplayDLL(); // Show list
			cout << "Searching for the third Node and deleting it...." << endl;
			N3 = L1.Find(3);// Locate node 3
			L1.Delete(N3);// Delete node 3 
			cout << "Here's your new linked list!" << endl;
			L1.DisplayDLL();// Show that function can delete nodes in middle of list
		}

		if (choice == 6)
		{
			DL_List<int> L1;// New list 
			Node<int>*N1 = NULL;// Create 4 new nodes
			Node<int>*N2 = NULL;
			Node<int>*N3 = NULL;
			Node<int>*N4 = NULL;
			cout << "Creating a multinode list....." << endl;
			L1.Insert(1);// Insert node 1 into list
			L1.Insert(2);// Insert node 2 into list
			L1.Insert(3);// Insert node 3 into list
			L1.Insert(4);// Insert node 4 into list
			L1.DisplayDLL(); 
			cout << "\nSearching for the third Node..." << endl;
			N3 = L1.Find(3);// Prove we can locate middle nodes
			cout << "Now searching for the fourth Node..." << endl;
			N4 = L1.Find(4);// Prove we can locate any node
			cout << "Now searching for the first Node..." << endl;
			N1 = L1.Find(1);// Prove we can locate head node
		}
	
	} while (choice != 7);// If user chooses 7, end program


}