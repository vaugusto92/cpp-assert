#include <iostream>
#include "../include/core/assert.hpp"

void run()
{
    Assert *assertion = Assert::get_instance();

    assertion->assert_equals(0, assertion->get_assertions());
    assertion->assert_equals(0, assertion->get_test_count());
    assertion->assert_equals(0, assertion->get_failures());
    assertion->assert_equals("", assertion->get_test_name());

    assertion->testing("A very simple test");
    assertion->assert_equals(1, 1);
    assertion->assert_equals(1, 3);

    assertion->testing("Another very simple test");
    assertion->assert_equals(1, 2);
    assertion->assert_equals(2, 2);
    assertion->assert_equals(4, 2);

    assertion->testing("Testing the equality of strings");
    assertion->assert_equals("foo", "foo");
    assertion->assert_equals("foo", "bar");
    assertion->assert_equals("bar", "bar");

    assertion->testing("Testing the equality of booleans");
    assertion->assert_equals(false, false);
    assertion->assert_equals(true, true);
    assertion->assert_equals(false, true);

    assertion->testing("Testing the equality of double");
    assertion->assert_equals(2.0, 2.0);
    assertion->assert_equals(1.0, 2.0);
    assertion->assert_equals(3.0, 3.00);

    assertion->testing("Testing the membership in [1, 2, 3]");

    std::vector<int> numbers = {1, 2, 3};
    assertion->assert_contains(numbers, 1);
    assertion->assert_contains(numbers, 2);
    assertion->assert_contains(numbers, 3);
    assertion->assert_contains(numbers, 0);
}