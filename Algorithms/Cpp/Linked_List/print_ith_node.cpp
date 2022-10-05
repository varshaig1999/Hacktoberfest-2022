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
void printith(Node *head, int pos)
{
    int count = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cout << temp->data << endl;
        }
        count++;
        temp = temp->next;
    }
}
int main()
{
    Node *head = takeInput();
    int pos;
    cin >> pos;
    printith(head, pos);

    return 0;
}
