#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "heap.h"

TEST_CASE( "Heap - Test size function") {
	Heap testHeap;
	
	REQUIRE(testHeap.size() == 0);

	testHeap.insert(10);
	testHeap.insert(20);
	testHeap.insert(5);
	testHeap.insert(30);
	testHeap.insert(12);
	testHeap.insert(42);
	testHeap.insert(17);
	testHeap.insert(23);
    REQUIRE(testHeap.size() == 8);

    testHeap.removeLargestElement();
    REQUIRE(testHeap.size() == 7);
}


TEST_CASE( "Heap - Removing elements in order") {
	Heap testHeap;
	testHeap.insert(10);
	testHeap.insert(20);
	testHeap.insert(5);
	testHeap.insert(30);
	testHeap.insert(12);
	testHeap.insert(42);
	testHeap.insert(17);
	testHeap.insert(23);

	// elements should be removed largest to smallest
	// 42 => 30 => 23 => 20 => 17 => 12 => 10 => 5
    REQUIRE(testHeap.removeLargestElement() == 42);
    REQUIRE(testHeap.removeLargestElement() == 30);
    REQUIRE(testHeap.removeLargestElement() == 23);
    REQUIRE(testHeap.removeLargestElement() == 20);
    REQUIRE(testHeap.removeLargestElement() == 17);
    REQUIRE(testHeap.removeLargestElement() == 12);
    REQUIRE(testHeap.removeLargestElement() == 10);
    REQUIRE(testHeap.removeLargestElement() == 5);
}


TEST_CASE( "Heap - Removing from empty heap") {
	Heap testHeap;
	REQUIRE(testHeap.size() == 0);

	// empty heap should return -1
    REQUIRE(testHeap.removeLargestElement() == -1);
}


TEST_CASE( "Heap - topDownHeapify function") {
	Heap testHeap;
	int testArray[8] = {10, 20, -5, 30, 12, 42, 17, 23};

	REQUIRE(testHeap.topDownHeapify(testArray, 8) == 7);

    // elements should be removed largest to smallest
	// 42 => 30 => 23 => 20 => 17 => 12 => 10
	// negatives are not inserted
    REQUIRE(testHeap.removeLargestElement() == 42);
    REQUIRE(testHeap.removeLargestElement() == 30);
    REQUIRE(testHeap.removeLargestElement() == 23);
    REQUIRE(testHeap.removeLargestElement() == 20);
    REQUIRE(testHeap.removeLargestElement() == 17);
    REQUIRE(testHeap.removeLargestElement() == 12);
    REQUIRE(testHeap.removeLargestElement() == 10);
}

TEST_CASE( "Heap - topDownHeapify, adding to a non empty heap") {
	Heap testHeap;

	testHeap.insert(10);
	testHeap.insert(20);
	testHeap.insert(5);

	int testArray[5] = {30, 12, 42, 17, 23};

	REQUIRE(testHeap.topDownHeapify(testArray, 5) == 5);

    // elements should be removed largest to smallest
	// 42 => 30 => 23 => 20 => 17 => 12 => 10 => 5
    REQUIRE(testHeap.removeLargestElement() == 42);
    REQUIRE(testHeap.removeLargestElement() == 30);
    REQUIRE(testHeap.removeLargestElement() == 23);
    REQUIRE(testHeap.removeLargestElement() == 20);
    REQUIRE(testHeap.removeLargestElement() == 17);
    REQUIRE(testHeap.removeLargestElement() == 12);
    REQUIRE(testHeap.removeLargestElement() == 10);
    REQUIRE(testHeap.removeLargestElement() == 5);
}


TEST_CASE( "Heap - bottomUpHeapify function") {
	Heap testHeap;
	int testArray[8] = {10, 20, -5, 30, 12, 42, 17, 23};
	
	REQUIRE(testHeap.bottomUpHeapify(testArray, 8) == 7);

    // elements should be removed largest to smallest
	// 42 => 30 => 23 => 20 => 17 => 12 => 10 => 5
    REQUIRE(testHeap.removeLargestElement() == 42);
    REQUIRE(testHeap.removeLargestElement() == 30);
    REQUIRE(testHeap.removeLargestElement() == 23);
    REQUIRE(testHeap.removeLargestElement() == 20);
    REQUIRE(testHeap.removeLargestElement() == 17);
    REQUIRE(testHeap.removeLargestElement() == 12);
    REQUIRE(testHeap.removeLargestElement() == 10);
}

TEST_CASE( "Heap - bottomUpHeapify, adding to a non empty heap") {
	Heap testHeap;

	testHeap.insert(10);
	testHeap.insert(20);
	testHeap.insert(5);

	int testArray[5] = {30, 12, 42, 17, 23};

	REQUIRE(testHeap.bottomUpHeapify(testArray, 5) == 5);

    // elements should be removed largest to smallest
	// 42 => 30 => 23 => 20 => 17 => 12 => 10 => 5
    REQUIRE(testHeap.removeLargestElement() == 42);
    REQUIRE(testHeap.removeLargestElement() == 30);
    REQUIRE(testHeap.removeLargestElement() == 23);
    REQUIRE(testHeap.removeLargestElement() == 20);
    REQUIRE(testHeap.removeLargestElement() == 17);
    REQUIRE(testHeap.removeLargestElement() == 12);
    REQUIRE(testHeap.removeLargestElement() == 10);
    REQUIRE(testHeap.removeLargestElement() == 5);
}




