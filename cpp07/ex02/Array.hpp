#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array() : _array(0), _size(0) {}
	
	Array(unsigned int n) : _array(new T[n]()), _size(n) {}
	
	Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < this->_size; ++i) {
            this->_array[i] = other._array[i];
        }
    }
	
	Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] this->_array;
            this->_size = other._size;
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++) {
                this->_array[i] = other._array[i];
            }
        }
        return *this;
    }
	
	~Array() {
        delete[] this->_array;
    }

	unsigned int getSize() const { 
		return this->_size; 
	}
	
    T& operator[](unsigned int index) const {
        if (index >= this->_size)
            throw std::out_of_range("Index out of bounds!");
        return this->_array[index];
    }
};

#endif