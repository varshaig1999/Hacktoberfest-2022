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
int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
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
};

Node *mergeSoretedLL(Node *head1, Node *head2)
{
    Node *p = NULL, *q = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;

    if (temp1 == NULL && temp2 == NULL)
    {
        return NULL;
    }

    if (temp2 == NULL)
    {
        return head1;
    }

    if (temp1->data < temp2->data)
    {
        p = temp1;
        q = temp1;
        temp1 = temp1->next;
    }

    else if (temp1->data >= temp2->data)
    {
        p = temp2;
        q = temp2;
        temp2 = temp2->next;
    }

    while (temp1 && temp2)
    {
        // Node *a = temp1;
        // Node *b = temp2;
        if (temp1->data < temp2->data)
        {
            q->next = temp1;
            q = temp1;
            temp1 = temp1->next;
            q->next = NULL;
        }
        else if (temp1->data >= temp2->data)
        {
            q->next = temp2;
            q = temp2;
            temp2 = temp2->next;
            q->next = NULL;
        }
    }
    if (temp1)
    {
        q->next = temp1;
    }
    if (temp2)
    {
        q->next = temp2;
    }
    return p;
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
    Node *head1 = takeInput();
    print(head1);
    Node *head2 = takeInput();
    print(head2);
    mergeSoretedLL(head1, head2);
    print(head1);

    return 0;
}
