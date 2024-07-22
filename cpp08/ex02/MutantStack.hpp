#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};
		MutantStack& operator=(const MutantStack& other) {
			this->c = other.c;
			return *this;
		};
		~MutantStack() {};

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif