#ifndef CPPDS_LINKED_LIST
#define CPPDS_LINKED_LIST

namespace cppds {
    template<typename T>
    struct Node{
        T data;
        Node *next;
    };

    template<class T>
    class LinkedList {
    private:
        Node<T> *head;
    public:
        LinkedList(){
            this->head = nullptr;
        }

        ~LinkedList(){
            Node<T> *current = head;
            while (current != nullptr) {
                Node<T> *temp = current;
                current = current->next;
                delete temp;
            }
        }

        class Iterator {
        private:
            Node<T> *current;
        public:
            explicit Iterator(Node<T> *node) : current(node) {}
            T& operator*() const {
                return current->data;
            }

            Iterator& operator++() {
                current = current->next;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return current != other.current;
            }
        };

        Iterator begin() {
            return Iterator(head);
        }

        Iterator end() {
            return Iterator(nullptr);
        }

        void push_back(T data){
            if(this->head == nullptr){
                this->head = new Node<T>{data, nullptr};
                return;
            }
            Node<T> *current = this->head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Node<T>{data, nullptr};
        }

        void push_front(T data){
            this->head = new Node<T>{data, this->head};
        }

        void pop_front() {
            if (head == nullptr) {
                return;
            }
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }

        void pop_back() {
            if (head == nullptr) {
                return;
            }
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            Node<T> *current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }

        Node<T> get_head() const{
            return head;
        }
    };
}

#endif