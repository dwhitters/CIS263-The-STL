// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include <algorithm>
#include "catch.hpp"
#include "stl_functions.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "Vector copy test", "[std::copy]" ){
    std::vector<int> m { 1, 4, 6, 3, 7, 9, 4, 23, 42, 5, 6 };
    auto n = copyVec(m);
    CHECK( std::equal( m.begin(), m.end(), n.begin()));
}

TEST_CASE( "Vector copy retains size test", "[std::copy]" ){
    std::vector<int> m { 1, 4, 6, 3, 7, 9, 4, 23, 42, 5, 6 };
    auto n = copyVec(m);
    CHECK( m.size() == 11 );
}

TEST_CASE( "Vector copy copies negative numbers test", "[std::copy]" ){
    std::vector<int> m { 1, 4, -6, 3, 7, 9, -4, 23, -42, 5, 6 };
    auto n = copyVec(m);
    CHECK( std::equal( m.begin(), m.end(), n.begin()));
}

TEST_CASE( "Vector copy copies empty vector test", "[std::copy]" ){
    std::vector<int> m = {};
    auto n = copyVec(m);
    CHECK( std::equal( m.begin(), m.end(), n.begin()));
}

TEST_CASE( "Vector sort test", "[std::sort]" ){
    std::vector<int> m(100);
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    sortVec(m);
    CHECK( std::is_sorted(m.begin(), m.end()) );
}

TEST_CASE( "Vector reverse sort test", "[std::sort]" ){
    std::vector<int> m = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    sortVec(m);
    CHECK( std::is_sorted(m.begin(), m.end()) );
}

TEST_CASE( "Vector negative numbers sort test", "[std::sort]" ){
    std::vector<int> m = {10, -9, 8, -7, -6, 5, 4, 3, -2, 1, 0};
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    sortVec(m);
    CHECK( std::is_sorted(m.begin(), m.end()) );
}

TEST_CASE( "Vector size retained test", "[std::sort]" ){
    std::vector<int> m = {10, -9, 8, -7, -6, 5, 4, 3, -2, 1, 0};
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    sortVec(m);
    CHECK( m.size() == 11 );
}

TEST_CASE( "For-each test", "[for-each]" ){
    std::vector<int> m(100);
    std::vector<int> n(m);
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    std::copy(m.begin(), m.end(), n.begin());
    doubleVec(m);
    for(size_t i=0; i<m.size(); i++){
        CHECK( m[i] == (n[i] * 2) );
    }
}

TEST_CASE( "Double function retains vector size", "[for-each]" ){
    std::vector<int> m(100);
    std::vector<int> n(m);
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    std::copy(m.begin(), m.end(), n.begin());
    doubleVec(m);
    CHECK(m.size() == n.size());
}

TEST_CASE( "Double function handles zero", "[for-each]" ){
    std::vector<int> m(100);
    std::vector<int> n(m);
    std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
    m.at(0) = 0;
    std::copy(m.begin(), m.end(), n.begin());
    CHECK(n.at(0) == 0);
    doubleVec(m);
    CHECK(n.at(0) == 0);
}

TEST_CASE( "Contains test", "[contains]" ){
    std::vector<std::string> v;
    std::string one("One");
    std::string two("Two");
    std::string three("Three");
    std::string four("Four");
    std::string five("Five");
    v.push_back(one);
    v.push_back(three);
    v.push_back(five);
    v.push_back(four);
    CHECK( containsItem(v, one) );
    CHECK( !containsItem(v, two) );
    CHECK( containsItem(v, four) );
}

TEST_CASE( "Contains on empty vector test", "[contains]" ){
    std::vector<std::string> v = {};
    CHECK( !containsItem(v, "one") );
}

TEST_CASE( "Intersection test", "[intersection]" ){
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> b{2, 4, 6, 8, 10, 12, 14, 16, 18};
    auto c = inBoth(a, b);
    CHECK( c.size() == 5 );
    CHECK( c[0] == 2 );
    CHECK( c[1] == 4 );
    CHECK( c[2] == 6 );
    CHECK( c[3] == 8 );
    CHECK( c[4] == 10 );
}

TEST_CASE( "Intersection sorting test", "[intersection]" ){
    std::vector<int> a{6, 1, 3, 4, 18, 7, 8, 9, 10, 2};
    std::vector<int> b{2, 4, 6, 8, 10, 12, 14, 16, 18};
    auto c = inBoth(a, b);
    CHECK( c.size() == 6 );
    CHECK( c[4] == 10 );
    CHECK( c[5] == 18 );
}

TEST_CASE( "Empty intersection test", "[intersection]" ){
    std::vector<int> a{};
    std::vector<int> b{2, 4, 6, 8, 10, 12, 14, 16, 18};
    auto c = inBoth(a, b);
    CHECK( c.size() == 0 );
}

TEST_CASE( "Intersection reverse sorting test", "[intersection]" ){
    std::vector<int> a{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> b{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto c = inBoth(a, b);
    CHECK( c.size() == 11 );
    CHECK( c[0] == 0 );
    CHECK( c[10] == 10 );
}

TEST_CASE( "Intersection removes multiples test", "[intersection]" ){
    std::vector<int> a{10, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 0};
    std::vector<int> b{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto c = inBoth(a, b);
    CHECK( c.size() == 11 );
    CHECK( c[0] == 0 );
    CHECK( c[10] == 10 );
}
