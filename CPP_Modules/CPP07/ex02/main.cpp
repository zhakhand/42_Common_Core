#include <iostream>
#include <string>
#include "Array.hpp"

void testBasicConstruction() {
    std::cout << "Testing basic construction..." << std::endl;
    
    try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "✓ Default constructor: size = " << arr1.size() << std::endl;
        
        // Test parameterized constructor
        Array<int> arr2(5);
        std::cout << "✓ Parameterized constructor: size = " << arr2.size() << std::endl;
        
        // Check zero-initialization
        std::cout << "✓ Elements are zero-initialized: ";
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error in basic construction: " << e.what() << std::endl;
    }
}

void testCopyConstructor() {
    std::cout << "\nTesting copy constructor..." << std::endl;
    
    try {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        Array<int> copy(original);
        std::cout << "✓ Copy created with size: " << copy.size() << std::endl;
        
        std::cout << "✓ Original values: ";
        for (unsigned int i = 0; i < original.size(); ++i)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << "✓ Copied values: ";
        for (unsigned int i = 0; i < copy.size(); ++i)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
        
        // Test deep copy
        original[0] = 999;
        std::cout << "✓ After modifying original[0] to 999, copy[0] = " << copy[0] << " (should still be 10)" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error in copy constructor: " << e.what() << std::endl;
    }
}

void testAssignmentOperator() {
    std::cout << "\nTesting assignment operator..." << std::endl;
    
    try {
        Array<int> arr1(3);
        arr1[0] = 100;
        arr1[1] = 200;
        arr1[2] = 300;
        
        Array<int> arr2(2);
        arr2 = arr1;
        
        std::cout << "✓ Assignment completed, arr2 size: " << arr2.size() << std::endl;
        std::cout << "✓ arr2 values: ";
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
        
        // Test self-assignment
        arr1 = *(&arr1);
        std::cout << "✓ Self-assignment completed, size still: " << arr1.size() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error in assignment operator: " << e.what() << std::endl;
    }
}

void testIndexOperator() {
    std::cout << "\nTesting index operator..." << std::endl;
    
    try {
        Array<int> arr(4);
        
        // Test write access
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        
        std::cout << "✓ Write access completed" << std::endl;
        
        // Test read access
        std::cout << "✓ Read access values: ";
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        
        // Test const version
        const Array<int>& constRef = arr;
        std::cout << "✓ Const access to first element: " << constRef[0] << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error in index operator: " << e.what() << std::endl;
    }
}

void testBoundsChecking() {
    std::cout << "\nTesting bounds checking..." << std::endl;
    
    Array<int> arr(3);
    
    // Test out of bounds access
    try {
        arr[3];
        std::cout << "✗ Should have thrown exception for index 3" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "✓ Out of bounds exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✓ Exception caught (unexpected type): " << e.what() << std::endl;
    }
    
    try {
        arr[100];
        std::cout << "✗ Should have thrown exception for index 100" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "✓ Large index exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✓ Exception caught (unexpected type): " << e.what() << std::endl;
    }
}

void testWithDifferentTypes() {
    std::cout << "\nTesting with different types..." << std::endl;
    
    // Test with double
    try {
        Array<double> doubleArr(3);
        doubleArr[0] = 3.14;
        doubleArr[1] = 2.71;
        doubleArr[2] = 1.41;
        std::cout << "✓ Double array values: ";
        for (unsigned int i = 0; i < doubleArr.size(); ++i)
            std::cout << doubleArr[i] << " ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✗ Error with double: " << e.what() << std::endl;
    }
    
    // Test with string
    try {
        Array<std::string> stringArr(2);
        stringArr[0] = "Hello";
        stringArr[1] = "World";
        std::cout << "✓ String array values: ";
        for (unsigned int i = 0; i < stringArr.size(); ++i)
            std::cout << "\"" << stringArr[i] << "\" ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✗ Error with string: " << e.what() << std::endl;
    }
    
    // Test with char
    try {
        Array<char> charArr(4);
        charArr[0] = 'T';
        charArr[1] = 'e';
        charArr[2] = 's';
        charArr[3] = 't';
        std::cout << "✓ Char array values: ";
        for (unsigned int i = 0; i < charArr.size(); ++i)
            std::cout << charArr[i];
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✗ Error with char: " << e.what() << std::endl;
    }
}

void testLargeArrays() {
    std::cout << "\nTesting large arrays..." << std::endl;
    
    try {
        Array<int> largeArr(1000);
        std::cout << "✓ Large array created with size: " << largeArr.size() << std::endl;
        
        // Fill with values
        for (unsigned int i = 0; i < largeArr.size(); ++i)
            largeArr[i] = i * 2;
        std::cout << "✓ Large array filled with values" << std::endl;
        
        // Check first and last few values
        std::cout << "✓ First 5 values: ";
        for (unsigned int i = 0; i < 5; ++i) 
            std::cout << largeArr[i] << " ";
        std::cout << std::endl;
    
        std::cout << "✓ Last 5 values: ";
        for (unsigned int i = largeArr.size() - 5; i < largeArr.size(); ++i)
            std::cout << largeArr[i] << " ";
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error with large arrays: " << e.what() << std::endl;
    }
}

void testMemoryManagement() {
    std::cout << "\nTesting memory management..." << std::endl;
    
    try {
        // Create and destroy many arrays
        for (int i = 0; i < 100; ++i) {
            Array<int> temp(100);
            for (unsigned int j = 0; j < temp.size(); ++j) 
                temp[j] = j;
        }
        std::cout << "✓ Created and destroyed 100 arrays of size 100 each" << std::endl;
        // Test assignment in loop
        Array<int> persistent(50);
        for (int i = 0; i < 10; ++i) {
            Array<int> temp(i + 1);
            for (unsigned int j = 0; j < temp.size(); ++j) 
                temp[j] = j * 10;
            if (i % 2 == 0) 
                persistent = temp;
        }
        std::cout << "✓ Multiple assignments completed, final size: " << persistent.size() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error in memory management: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== Array Template Class Test Suite ===" << std::endl;
    
    testBasicConstruction();
    testCopyConstructor();
    testAssignmentOperator();
    testIndexOperator();
    testBoundsChecking();
    testWithDifferentTypes();
    testLargeArrays();
    testMemoryManagement();
    
    std::cout << "\n=== Test suite completed ===" << std::endl;
    
    return 0;
}