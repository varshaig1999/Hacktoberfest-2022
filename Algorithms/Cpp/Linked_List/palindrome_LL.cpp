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
int count(Node *head, int num)
{
    Node *temp = head;
    while (temp != NULL)
    {
        num++;
        temp = temp->next;
    }
    return num;
}
Node *reverse(Node *head)
{
    Node *p = head, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}
bool palindromeLL(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    int x = count(head, 0);
    Node *temp = head;
    Node *q = reverse(head);
    while (x / 2)
    {
        if (temp->data != q->data)
        {
            return false;
        }
        else
        {
            temp = temp->next;
            q = q->next;
        }
    }
    return true;
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
    cout << palindromeLL(head);
    return 0;
}
