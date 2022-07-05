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
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
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

// Finding the aage vala in even number of nodes.
Node *find_middle_node_1(Node *head)
{
    Node *sp = head, *fp = head;
    while (fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp;
}

// Finding the peeche vala in even number of nodes.
int find_middle_node_2(Node *head)
{
    if (head == NULL)
        return -1;

    Node *sp = head, *fp = head->next;
    while (fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next->next;
    }
    return sp->data;
}
bool is_palindrome(Node *head)
{
    Node *mid = find_middle_node_1(head);
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
Node *merge_two_sorted_ll(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            dummy->next = head1;
            head1 = head1->next;
        }
        else
        {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }

    if (head1)
        dummy->next = head1;
    if (head2)
        dummy->next = head2;

    // NO NEED TO LOOP THROUGH AGAIN
    // while (head1)
    // {
    //     dummy->next = head1;

    //     dummy = dummy->next;
    //     head1 = head1->next;
    // }
    // while (head2)
    // {
    //     dummy->next = head2;
    //     dummy = dummy->next;
    //     head2 = head2->next;
    // }
    return temp->next;
}

Node *even_after_odd(Node *head)
{
    if (!head || !head->next)
        return head;

    // creating a dummy node will avoid checking empty nodes.
    Node *even_head = new Node(-1);
    Node *odd_head = new Node(-1);

    Node *even_tail = even_head;
    Node *odd_tail = odd_head;

    Node *curr = head;
    while (curr)
    {
        int data = curr->data;
        if (data & 1)
        {
            odd_tail->next = curr;
            odd_tail = odd_tail->next;
        }
        else
        {
            even_tail->next = curr;
            even_tail = even_tail->next;
        }
        curr = curr->next;
    }

    if (odd_head->next)
    {
        odd_tail->next = even_head->next;
        even_tail->next = NULL;
        return odd_head->next;
    }

    return even_head->next;
}

Node *delete_n_nodes_after_every_m_nodes(Node *head, int m, int n)
{
    if (head == NULL)
        return head;

    Node *pre = NULL, *curr = head;

    while (curr)
    {
        int tm = m, tn = n;

        while (tm-- && curr)
        {
            pre = curr;
            curr = curr->next;
        }

        while (tn-- && curr)
        {
            Node *to_del = curr;
            curr = curr->next;
            delete to_del;
        }
        if (pre == NULL)
            pre = curr;
        else
        {
            pre->next = curr;
            pre = curr;
        }
    }

    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        print(head);

        // cout << find_middle_node_2(head) << endl;

        // Node *head1 = takeInput();
        // print(head1);
        // Node *head2 = takeInput();
        // print(head2);
        // Node *merged_head = merge_two_sorted_ll(head1, head2);
        // print(merged_head);

        // head = even_after_odd(head);
        // print(head);

        int m, n;
        cin >> m >> n;
        print(delete_n_nodes_after_every_m_nodes(head, m, n));
    }
    return 0;
}