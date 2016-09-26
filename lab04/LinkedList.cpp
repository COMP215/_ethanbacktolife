using namespace std;

class NodeL
{
    public:

        string data_;
        NodeL* next_;

        NodeL();
        NodeL(string data);
        ~NodeL();
};

NodeL::NodeL()
{
    this->data_ = "";
    this->next_ = NULL;
}

NodeL::NodeL(string data)
{
    this->data_ = data;
    this->next_ = NULL;
}

NodeL::~NodeL()
{
    delete(this->next_);
}

class LinkedList

{
    public:

        NodeL* head_;
        NodeL  buffer_;
        NodeL* tail_;

        LinkedList();
        void Push(string data);
        void Delete(string data);
        void Pop();
        void Display();
        void EmptyList();
};

LinkedList::LinkedList()
{
    this->head_ = &buffer_;
    this->buffer_.data_ = "Buffer";
    this->tail_ = &buffer_;
}

void LinkedList::Push(string data)
{
    NodeL* new_node = new NodeL(data);
    this->tail_->next_ = new_node;
    this->tail_ = new_node;
}

void LinkedList::Pop()
{
    if(this->head_ != this->tail_)
    {
        NodeL* p1 = this->head_;
        NodeL* p2 = this->head_->next_;

        while(p2->next_)
        {
            p1 = p1->next_;
            p2 = p2->next_;
        }

        delete(p2);
        p1->next_ = NULL;
        this->tail_ = p1;
    }
    else
    {
        cout << "List already empty" << endl;
    }
}

void LinkedList::Delete(string data)
{
    NodeL* prev = this->head_;
    NodeL* p = prev->next_;
    bool found = false;

    if(p->next_)
    {
        NodeL* next = p->next_;

        while(next && !found)
        {

            if(p->data_.compare(data) == 0)

            {
                prev->next_ = next;

                if(next)
                {
                    next = next->next_;
                }
                else
                {
                    next = NULL;
                    this->tail_ = prev;
                }

                found = true;
            }

            if(!found)
            {
                prev = prev->next_;
                p = p->next_;
                next = next->next_;
            }
        }
    }

    if(!found && this->tail_->data_ == data)
    {
        this->tail_ = prev;
        prev->next_ = NULL;
    }
}

void LinkedList::EmptyList()
{
    while(this->head_ != this->tail_)
    {
        Pop();
    }
}

void LinkedList::Display()
{
    NodeL* p = this->head_;

    while(p)
    {
        cout << p->data_ << "->";
        p = p->next_;
    }
    cout << endl;
}
