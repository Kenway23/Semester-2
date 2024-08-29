#include <conio.h>
#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;

    node(int val, node *n, node *p)
    {
        value = val;
        next = n;
        prev = p;
    }

    node(int v)

    {
        value = v;
    }

    node()
    {
    }
};

class double_list
{
public:
    void inserthead(int value);
    void inserttail(int val);
    void insertbefore(int value, int pos);
    void removehead();
    void removepost(int pos);
    void removetail();
    void print();

    double_list()
    {
        head = NULL;
        tail = NULL;
    }

private:
    node *head;
    node *tail;
    node *current;
    int isemty();
};
static int list = 0;

int double_list::isemty()
{
    if (head == NULL || tail == NULL)
        return 1;
    else
        return 0;
}

void double_list::inserthead(int val)
{
    if (isemty() == 1)
    {
        current = new node(val);
        head = current;
        tail = current;
        tail->next = NULL;
        head->prev = NULL;
    }
    else
    {
        current = new node();
        current->next = this->head;
        this->head->prev = current;
        current->value;
        this->head = current;
    }
    list++;
}

void double_list::inserttail(int val)
{
    if (isemty() == 1)
    {
        current = new node(val);
        head = current;
        tail = current;
        tail->next = NULL;
    }
    else
    {
        current = new node();
        current->prev = this->tail;
        this->tail->next = current;
        current->value = val;
        this->tail = current;
        current->next = NULL;
    }
    list++;
}

void double_list::removehead()
{
    if (isemty() == 1)
    {
        std::cout << "maaf, linked list kosong" << std::endl;
    }
    else
    {
        if (list == 1)
        {
            std::cout << "nilai " << head->value << " Telah dihapus" << endl;
            tail = NULL;
            head = NULL;
        }
        else
        {
            int temp = head->value;
            current = head->next;
            head = current->prev->next = current;
            head = current;
            std::cout << "nilai " << temp << " Telah dihapus" << endl;
        }
        list--;
    }
}

void double_list::removetail()
{
    if (isemty() == 1)
    {
        std::cout << "maaf, linked list kosong" << endl;
    }
    else
    {
        if (list == 1)
        {
            std::cout << "nilai " << tail->value << " Telah dihapus" << endl;
            tail = NULL;
            head = NULL;
            list--;
        }
        else
        {
            int temp = tail->value;
            current = tail;
            current = current->prev;
            tail->prev->next = NULL;
            tail = current;
            std::cout << "nilai " << temp << " Telah dihapus" << endl;
            list--;
        }
    }
}

void double_list::insertbefore(int value, int pos)
{
    if (isemty() == 1)
    {
        cout << "Maaf, linked list kosong" << endl;
    }
    else
    {
        if (pos > list)
        {
            cout << "jumlah list terlalu sedikit" << endl;
        }
        else
        {
            if (pos == 1)
            {
                inserthead(value);
            }
            else if (pos == list)
            {
                inserttail(value);
            }
            else
            {
                current = head;
                node *fixed;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }
                fixed = new node((value), current, current->prev);
                current->prev->next = fixed;
                current->prev = fixed;
                current = fixed;
                list++;
            }
        }
    }
}

void double_list::removepost(int pos)
{
    if (isemty() == 1)
    {
        cout << "Maaf, linked list kosong" << endl;
    }
    else
    {
        if (pos > list)
            cout << "Maaf, Range terlalu sedikit" << endl;
        else
        {
            if (pos == 1)
            {
                removehead();
            }
            else if (pos == list)
            {
                removetail();
            }
            else
            {
                current = head;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }
                int nilai = current->value;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                cout << "Nilai " << nilai << " Dihapus dari linked list" << endl;
                list--;
            }
        }
    }
}

void double_list::print()
{
    current = head;
    while (current != NULL)
    {
        cout << "Isi list :" << current->value << endl;
        current = current->next;
    }
}

int main()
{
    int n, pos;
    double_list *st;
    st = new double_list();

    char pilih;
    cout << "Operasi linkedlist " << endl;
    cout << "1. insertHead" << endl;
    cout << "2. insertTail" << endl;
    cout << "3. removeHead" << endl;
    cout << "4. removeTail" << endl;
    cout << "5. insert before" << endl;
    cout << "6. Remove position" << endl;
    cout << "7. Exit" << endl;

    do
    {
        cout << endl;
        cout << "Pilihan :";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
            cout << "masukkan data :";
            cin >> n;
            st->inserthead(n);
            st->print();
            break;

            case '2':
                cout<<"masukkan data :";
                cin>>n;
                st->inserttail(n);
                st->print();
                break;

            case '3':
                st->removehead();
                st->print();
                break;
            
            case '4':
                st->removetail();
                st->print();
                break;

            case '5':
                cout<<"masukkan data :";
                cin>>n;
                cout<<"masukkan posisi :"; 
                cin>>pos;
                st->insertbefore(n,pos);
                st->print();
                break;

            case '6':
                int post;
                cout<<"masukkan posisis angka yang ingin dihapus :";
                cin>>pos;
                st->removepost(pos);
                st->print();
                break;

            case '7':
                cout<<"terima kasih :";
                break;
                default:
                cout<<"salah pilih";
                break;

        }
    } while(pilih!='7');
    getch();
}