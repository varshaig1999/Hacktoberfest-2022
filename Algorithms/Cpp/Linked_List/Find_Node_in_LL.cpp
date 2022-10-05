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
int FindNode(Node *head, int d)
{
    int count = -1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == d)
        {
            return count + 1;
        }
        count++;
        temp = temp->next;
    }
    return count;
}
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    Node *head = takeInput();
    int d;
    cin >> d;
    cout << FindNode(head, d);

    return 0;
}