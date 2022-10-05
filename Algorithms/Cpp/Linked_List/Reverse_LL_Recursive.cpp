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
// 💥 Method - 2 | Updating tail as well with head
class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverse_LL_2(Node *head)
{
    Pair ans;
    if (head == NULL || head->next == NULL)
    {
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse_LL_2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverse_LL_Better(Node *head)
{
    return reverse_LL_2(head).head;
}

// 💥 Method - 1
Node *reverse_LL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = reverse_LL(head->next);
    head->next->next = head;
    head->next = NULL;

    return smallHead;
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
    reverse_LL(head);
    print(head);

    return 0;
}
