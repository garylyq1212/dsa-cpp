#include <iostream>

class Node
{
public:
    int m_Value;
    Node *m_Next;

    Node(int value)
        : m_Value(value), m_Next(nullptr)
    {
    }
};

class LinkedList
{
public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        m_Head = newNode;
        m_Tail = newNode;
        m_Length = 1;
    }

    ~LinkedList()
    {
        Node *temp = m_Head;
        while (m_Head)
        {
            m_Head = m_Head->m_Next;
            delete temp;
            temp = m_Head;
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (m_Length == 0)
        {
            m_Head = newNode;
        }
        else
        {
            Node *newTail = newNode;
            m_Tail->m_Next = newTail;
            m_Tail = newTail;
        }

        m_Length += 1;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);

        if (m_Length == 0)
        {
            m_Head = newNode;
            m_Tail = newNode;
        }
        else
        {
            Node *previousHead = m_Head;
            newNode->m_Next = previousHead;
            m_Head = newNode;
        }

        m_Length += 1;
    }

    void removeLast()
    {
        Node *temp = m_Head;

        if (m_Length == 0)
        {
            return;
        }
        else if (m_Length == 1)
        {
            m_Head = nullptr;
            m_Tail = nullptr;
        }
        else
        {
            Node *previous = m_Head;
            while (temp->m_Next)
            {
                previous = temp;
                temp = temp->m_Next;
            }

            m_Tail = previous;
            m_Tail->m_Next = nullptr;
        }

        delete temp;
        m_Length -= 1;
    }

    void removeFirst()
    {
        Node *temp = m_Head;

        if (m_Length == 0)
        {
            return;
        }
        else if (m_Length == 1)
        {
            m_Head = nullptr;
            m_Tail = nullptr;
        }
        else
        {
            m_Head = temp->m_Next;
        }

        delete temp;
        m_Length -= 1;
    }

    void printList()
    {
        if (m_Length == 0)
        {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        else
        {
            Node *temp = m_Head;
            while (temp)
            {
                std::cout << temp->m_Value << std::endl;
                temp = temp->m_Next;
            }
        }
    }

    Node *get(int index)
    {
        if (index < 0 || index > m_Length)
        {
            return nullptr;
        }
        else
        {
            Node *temp = m_Head;
            for (int i = 0; i < index; ++i)
            {
                temp = temp->m_Next;
            }

            return temp;
        }
    }

    bool set(int index, int value)
    {
        Node *temp = get(index);

        if (temp)
        {
            temp->m_Value = value;
            return true;
        }
        else
        {
            std::cout << "Linked List of index " << index << " is out of bound!\n";
            return false;
        }
    }

    void getHead()
    {
        std::cout << "Head: " << m_Head->m_Value << std::endl;
    }

    void getTail()
    {
        std::cout << "Tail: " << m_Tail->m_Value << std::endl;
    }

    void getLength()
    {
        std::cout << "Length: " << m_Length << std::endl;
    }

private:
    Node *m_Head;
    Node *m_Tail;
    int m_Length;
};

int main()
{
    LinkedList *ll = new LinkedList(5);
    ll->append(7);
    ll->append(10);
    ll->append(12);
    // ll->printList();

    // std::cout << "--------------REMOVE LAST--------------\n";
    // ll->removeLast();
    // ll->removeLast();
    // ll->removeLast();
    // ll->removeLast();

    ll->prepend(1);
    ll->prepend(8);

    ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();
    // ll->removeFirst();

    ll->set(10, 20);

    ll->printList();

    std::cout << "Get: " << ll->get(2)->m_Value << std::endl;
    std::cout << "Get: " << ll->get(3)->m_Value << std::endl;

    // ll->getHead();
    // ll->getTail();
    ll->getLength();

    delete ll;

    return 0;
}