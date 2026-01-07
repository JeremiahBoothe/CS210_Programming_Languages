/* Creates a linked list of contact information.  
* ***Point of excitement*** figuring out how to handle "a nonstatic member reference must be relative to a specific object" by pointing the head at the print method and passing head as an argument: head->PrintContactNode(head); where ContactNode::PrintContactNode(head); Did not work. 
* @author - Jeremiah Boothe
* @date - 10/13/2023
*/
#include <iostream>
#include <string>
using namespace std;

/* Input for Testing
Roxanne Hughes
443-555-2864
Juan Alberto Jr.
410-555-9385
Rachel Phillips
310-555-6610
*/

/* ContactNode class representing a node in a linked list.  Each node contains contactName, contactPhoneNumber, nextNodePointer.
*/
class ContactNode {
public:
    /* ContactNode Constructor(string, string)
     * @param string name - contactName stored in node
     * @param string phoneNumber - contactPhoneNumber stored in node
     */
    ContactNode(string name, string phoneNumber);
    
    /* Retrieves the name stored in the node
     * @param none
     * @returns string - contactName
     */
    string GetName() const;
    
    /* Retrieves the phone number stored in the node.
     * @param none
     * @returns string - contactPhoneNumber
     */
    string GetPhoneNumber() const;

    /* Inserts a new node after the current node and updates linked list pointers.
     * @param ContactNode* node - pointer to current node to insert next node after
     * @returns nothing
     */
    void InsertAfter(ContactNode* node);

    /* retrieves a pointer to the next node in a linked list
     * @param none
     * @returns ContactNode* nextNodePtr - points to next node
     */
    ContactNode* GetNext() const;

    /* Prints the name and phone number associated with the current contact node.
     * @param ContactNode* head - pointer to the linked list of the head.  Used as the starting point for print iteration.
     * @returns nothing - prints node contactName and contactPhoneNumber, formatted in two different ways.
     */
     void PrintContactNode(ContactNode* head) const;

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode* nextNodePtr;
};

ContactNode::ContactNode(string name, string phoneNumber)
    : contactName(name), contactPhoneNumber(phoneNumber), nextNodePtr(nullptr) {
}

string ContactNode::GetName() const {
    return contactName;
}

string ContactNode::GetPhoneNumber() const {
    return contactPhoneNumber;
}

void ContactNode::InsertAfter(ContactNode* node) {
    if (node != nullptr) {
        ContactNode* tmpNext = nextNodePtr; // Save the current next node
        nextNodePtr = node; // Set the next node to the new node
        node->nextNodePtr = tmpNext; // Set the next node of the new node to the saved next node
    }
}

ContactNode* ContactNode::GetNext() const {
    return nextNodePtr;
}

void ContactNode::PrintContactNode(ContactNode* head) const {
    ContactNode* currentNode = head;
    for (int i = 1; currentNode != nullptr; ++i) {
        string name = currentNode->GetName();
        string phoneNumber = currentNode->GetPhoneNumber();
        cout
            << "Person "
            << i
            << ": "
            << name
            << ", "
            << phoneNumber
            << endl;
        // Move to the next node
        currentNode = currentNode->GetNext();
    }

    cout
        << endl
        << "CONTACT LIST";

    // Output contacts
    currentNode = head;
    for (int i = 1; currentNode != nullptr; ++i) {
        string name = currentNode->GetName();
        string phoneNumber = currentNode->GetPhoneNumber();
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Phone number: " << phoneNumber << endl;
        // Move to the next node
        currentNode = currentNode->GetNext();
    }
    cout
        << endl;
}

int main() {
    ContactNode* head = nullptr; // Head of the linked list
    ContactNode* currentNode = nullptr;

    // Input contacts
    for (int i = 1; i <= 3; ++i) {
        string name, phoneNumber;
        //cout << "Enter Person " << i << " name: ";
        getline(cin, name);
        //cout << "Enter Person " << i << " phone number: ";
        getline(cin, phoneNumber);

        // Create a new ContactNode
        ContactNode* newNode = new ContactNode(name, phoneNumber);

        // Insert the new node after the current node
        if (currentNode != nullptr) {
            currentNode->InsertAfter(newNode);
        }
        else {
            // If it's the first node, update the head
            head = newNode;
        }
        // Update the current node to the new node
        currentNode = newNode;
    }

    // Uses head to gain pointer access to object method and passes the head value as a starting point for iteration, ContactNode::PrintContactNode(head) doesn't work because because a nonstatic member reference must be relative to a specific object.
    head->PrintContactNode(head);
   
    // Free memory by iterating through list until nullptr is reached and there are no more entries in the linked list
    currentNode = head;
    while (currentNode != nullptr) {
        ContactNode* nextNode = currentNode->GetNext();
        delete currentNode;
        currentNode = nextNode;
    }

    return 0;
}