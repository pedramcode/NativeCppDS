#ifndef CPPDS_DYNAMIC_ARRAY
#define CPPDS_DYNAMIC_ARRAY

namespace cppds{
    template<class T>
    class DynamicArray {
    private:
        T *data;
        unsigned int capacity;
        unsigned int length;
    public:
        DynamicArray(){
            data = nullptr;
            capacity = 1;
            length = 0;
        }

        explicit DynamicArray(unsigned int _capacity):capacity(_capacity){
            data = (T*) malloc(sizeof(T) * _capacity);
            length = 0;
        }

        ~DynamicArray() {
            free(data);
        }

        class Iterator {
        private:
            T *ptr;

        public:
            explicit Iterator(T *p) : ptr(p) {}

            T& operator*() const {
                return *ptr;
            }

            Iterator& operator++() {
                ++ptr;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return ptr != other.ptr;
            }
        };

        Iterator begin() {
            return Iterator(data);
        }

        Iterator end() {
            return Iterator(data + length);
        }

        T& operator[](unsigned int index) {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        void push_back(T item){
            if (data == nullptr) {
                data = (T*)malloc(sizeof(T));
                capacity = 1;
            } else if (length >= capacity) {
                capacity *= 2;
                data = (T*)realloc(data, sizeof(T) * capacity);
            }

            data[length] = item;
            length++;
        }

        T pop_back(){
            if (length == 0) {
                throw std::runtime_error("Cannot pop from an empty array.");
            }

            T poppedItem = data[length - 1];
            length--;

            if (length < capacity / 2) {  // Corrected condition here
                capacity /= 2;
                data = (T*)realloc(data, sizeof(T) * capacity);
            }

            return poppedItem;
        }
    };
}

#endif