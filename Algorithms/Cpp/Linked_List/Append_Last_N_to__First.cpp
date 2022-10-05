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
Node *append_last_N_to_first(Node *head, int n)
{
    int count = -n;
    Node *temp = head, *a = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (temp->next != NULL)
    {
        if (count >= 0)
        {
            a = a->next;
        }
        temp = temp->next;
        count++;
    }
    temp->next = head;
    head = a->next;
    a->next = NULL;
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
    Node *head = takeInput();
    int n;
    cin >> n;
    print(head);
    append_last_N_to_first(head, n);
    print(head);

    return 0;
}