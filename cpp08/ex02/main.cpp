# include "MutantStack.hpp"
# include "Color.hpp"
# include <list>

void testMutantStack() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << GRN ">----- Testing MutantStack iteration: -----<" NC << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << YEL "Elements: " NC;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl << std::endl;
}

void testList() {
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << GRN ">----- Testing std::list iteration: -----<" NC << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    std::cout << YEL "Elements: " NC;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl << std::endl;
}

void testEquality() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << GRN ">----- Comparing MutantStack and std::list elements: -----<" NC << std::endl;
    MutantStack<int>::iterator mstack_it = mstack.begin();
    std::list<int>::iterator list_it = lst.begin();
    bool isEqual = true;

    while (mstack_it != mstack.end() && list_it != lst.end()) {
        if (*mstack_it != *list_it) {
            isEqual = false;
            break;
        }
        ++mstack_it;
        ++list_it;
    }

    if (mstack_it != mstack.end() || list_it != lst.end()) {
        isEqual = false;
    }

    if (isEqual) {
        std::cout << "MutantStack and std::list contain the " YEL "same " NC "elements!" << std::endl;
    } else {
        std::cout << "MutantStack and std::list contain " YEL "different" NC " elements!" << std::endl;
    }
}

int main() {
    // Test MutantStack iteration
    testMutantStack();

    // Test std::list iteration
    testList();

    // Compare MutantStack and std::list elements
    testEquality();

    return 0;
}