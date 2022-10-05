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
Node *deleteNodeRecursive(Node *head, int pos)
{
    if (pos == 0)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    if (head == NULL)
    {
        return head;
    }
    head->next = deleteNodeRecursive(head->next, pos);
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
    }
    cout << endl;
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

    return 0;
}