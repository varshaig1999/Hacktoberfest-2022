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
// Node *Reverse(Node *head)
// {
//     if (head == NULL)
//     {
//         return head;
//     }
//     Node *temp = head;
//     Node *a = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//         // if (temp->next == NULL)
//         // {
//         //     temp->next = a->next;
//         // }
//     }
//     head->next = NULL;
//     temp->next = a->next;

//     return temp;
// }
void ReverseLL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    ReverseLL(head->next);
    cout << head->data << " ";
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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
    // print(head);
    // head = Reverse(head);
    ReverseLL(head);
    // print(head);

    return 0;
}