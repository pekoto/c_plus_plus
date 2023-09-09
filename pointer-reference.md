# Pointer-Reference Cheatsheet

In C++, __everything__ is passed by value. I.e., a copy is made of the values, similar to Java primitives, but also for large objects.

## Pointers
* Pointers are variables that store the address of another variable or function
* The two uses of `*`:
	* To __declare__ a pointer: `int *a_ptr {&a};`
	* To __dereference__ a pointer: `std::cout << *a_ptr;` 

Example of using a pointer in a function:

```cpp
void double_data(int *int_ptr) {
   *int_ptr *= 2;
}

void display(vector<string> *v) {
    for (auto str: *v) {
        cout << str << endl;
    }
}

int main() {
    int val{100};
    double_data(&val); // NB: When param is pointer, pass in address

    cout << val << endl; // 200

	// How about making a unique_ptr

    // for iterables we have to dereference the pointer passed in to get to the object
    vector<string> v {"a", "b", "c"};
    display(&v);
}
// TODO: See replit and answer to YAQs to clarify this https://replit.com/@GrahamMc/PointerAndRef#main.cpp
```

## References
* References are an __alias__ for a variable
* Once initialized, they cannot be set to another number.
* The two uses of `&`:
	* To __declare__ an alias for another variable
	* To get the __address__ or a variable
		* The symbol is the same, but actually these are totally unrelated

## Pointers vs. References

- __Pass-by-value__
    - Default behavior
    - Function does not modify actual parameters
    - Parameter is small and efficient to copy (ints, etc)
- __Pass-by-reference using pointer__
    - Function modifies the actual parameter
    - AND parameter is expensive to copy
    - AND OK for pointer to be allowed a `nullptr` value
    - Can use const if we just want to save on expensive copying but not modify pointer/values
- __Pass-by-reference using reference__
    - Function modifies the actual parameter
    - AND parameter is expensive to copy
    - AND the pointer will never be `nullptr`
