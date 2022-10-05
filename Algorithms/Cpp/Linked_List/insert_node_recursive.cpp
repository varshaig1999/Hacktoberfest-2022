#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}
Node *insertNodeRecursive(Node *head, int pos, int data)
{
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    if (head == NULL)
    {
        return head;
    }
    head->next = insertNodeRecursive(head, pos-1, data);
    return head;
}
int main()
{

    return 0;
}