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
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head, *tempNext = head->next;
    while (tempNext != NULL)
    {
        if (temp->data == tempNext->data)
        {
            temp->next = tempNext->next;
            Node *t = tempNext;
            tempNext = tempNext->next;
            delete t;
        }
        else
        {
            temp = temp->next;
            tempNext = tempNext->next;
        }
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
    removeDuplicates(head);
    print(head);

    return 0;
}