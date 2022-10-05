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
Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    Node *q = NULL;
    if (pos == 0)
    {
        head = temp->next;
        delete temp;
    }

    else
    {
        for (int j = 0; j < pos && temp != NULL; j++)
        {
            q = temp;
            temp = temp->next;
        }
        q->next = temp->next;
        delete temp;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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
    Node *head = takeInput();
    print(head);
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);

    return 0;
}