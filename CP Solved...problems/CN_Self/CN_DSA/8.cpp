#include <bits/stdc++.h>
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
int findLength(Node *head)
{
    int nodes = 0;
    while (head)
    {
        nodes++;
        head = head->next;
    }
    return nodes;
}

int findLengthRecursively(Node *head)
{
    if (head == NULL)
        return 0;
    return findLengthRecursively(head->next) + 1;
}
Node *insertNodeAtPosition(Node *head, int pos, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        int jumps = 0;
        while (temp && jumps < pos - 1)
        {
            temp = temp->next;
            jumps++;
        }
        if (temp)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

Node *insertNodeAtPositionRecursively(Node *head, int pos, int data)
{
    if (head == NULL)
        return new Node(data);
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
        head->next = insertNodeAtPositionRecursively(head->next, pos - 1, data);

    return head;
}

Node *deleteNodeAtPosition(Node *head, int pos)
{
    if (head == NULL)
        return head;
    Node *temp = head;

    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int jumps = 0;
    while (temp && jumps < pos - 1)
    {
        temp = temp->next;
        jumps++;
    }
    if (temp)
    {
        if (temp->next)
        {
            Node *next = temp->next;
            temp->next = next->next;
            delete next;
        }
    }
    return head;
}

Node *deleteNodeAtPositionRecursively(Node *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    else
        head->next = deleteNodeAtPositionRecursively(head->next, pos - 1);

    return head;
}

int findNode(Node *head, int data)
{
    if (head == NULL)
        return -1;

    int pos = 0;
    while (head)
    {
        if (head->data == data)
            return pos;
        pos++;
        head = head->next;
    }
    return -1;
}
Node *appendLastNtoFirst(Node *head, int n)
{
    int nodes = findLengthRecursively(head);
    if (nodes - n <= 0)
        return head;

    Node *tail = head;
    while (tail->next)
        tail = tail->next;

    int jumps = 0;
    Node *temp = head;
    Node *pre_head = head;
    while (jumps < (nodes - n))
    {
        pre_head = head;
        head = head->next;
        jumps++;
    }

    tail->next = temp;
    pre_head->next = NULL; // IMP ( to break the link of the nodes)
    return head;
}

Node *eliminateDuplicates(Node *head)
{
    Node *curr = head;
    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
void printReverse(Node *head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *next = head, *curr = head, *pre = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    return pre;
}
Node *reverse_ll_recursively(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *lastNode = reverse_ll_recursively(head->next);

    head->next->next = head;
    head->next = NULL;
    return lastNode;
}

// bool checkPalindrome(Node *head, Node *reversed_head)
// {
// This technique will not work as we have reversed the given LL.
// cout << findLength(head) << " " << findLength(reversed_head) << endl;
// if (findLength(head) != findLength(reversed_head))
//     return false;

// while (head)
// {
//     if (head->data != reversed_head->data)
//         return false;
//     head = head->next;
//     reversed_head = reversed_head->next;
// }

// return true;
// }
Node *find_middle_node(Node *head)
{
    Node *sp = head, *fp = head;
    while (fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp;
}
bool is_palindrome(Node *head)
{
    Node *mid = find_middle_node(head);
    Node *last = reverse_ll_recursively(mid);

    while (last)
    { // since last may have one node less than first-half
        if (head->data != last->data)
            return false;
        head = head->next;
        last = last->next;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        print(head);
        // cout << findLength(head) << endl;
        // cout << findLengthRecursively(head) << endl;

        // int pos, data;
        // cin >> pos >> data;
        // // head = insertNodeAtPosition(head, pos, data);
        // head = insertNodeAtPositionRecursively(head, pos, data);
        // print(head);

        // cin >> pos;
        // // head = deleteNodeAtPosition(head, pos);
        // head = deleteNodeAtPositionRecursively(head, pos);
        // print(head);
        // int data;
        // cin >> data;
        // cout << findNode(head, data);

        // int n;
        // cin >> n;
        // head = appendLastNtoFirst(head, n);
        // print(head);

        // head = eliminateDuplicates(head);
        // print(head);

        // printReverse(head);
        // cout << endl;

        // NOT WORK
        // Node *reversed = reverseLL(head);
        // cout<< checkPalindrome(head, reversed)<<endl;

        cout << is_palindrome(head) << endl;
        // print(head);
    }
    return 0;
}