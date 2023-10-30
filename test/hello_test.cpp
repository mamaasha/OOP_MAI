#include "gtest/gtest.h"
#include "Thirteen.h"

TEST(ThirteenTest1, Constructor) {
    Thirteen first("123");

    EXPECT_EQ(first.getDigitAt(0), 1);
    EXPECT_EQ(first.getDigitAt(1), 2);
    EXPECT_EQ(first.getDigitAt(2), 3);
}

TEST(ThirteenTest2, Addition) {
    Thirteen first("5");
    Thirteen second("8");

    Thirteen sum = first + second;

    ASSERT_EQ(sum.getSize(), 2);
    EXPECT_EQ(sum.getDigitAt(0), 0);
    EXPECT_EQ(sum.getDigitAt(1), 1);
}

TEST(ThirteenTest3, Addition) {
    Thirteen first("123");
    Thirteen second("321");

    Thirteen sum = first + second;

    ASSERT_EQ(sum.getSize(), 3);
    EXPECT_EQ(sum.getDigitAt(0), 4);
    EXPECT_EQ(sum.getDigitAt(1), 4);
    EXPECT_EQ(sum.getDigitAt(2), 4);
}

TEST(ThirteenTest4, Equfirstlity) {
    Thirteen first("123");
    Thirteen second("123");

    ASSERT_TRUE(first == second);
}

TEST(ThirteenTest6, Assignment) {
    Thirteen first("123");
    Thirteen second;

    second = first;

    ASSERT_EQ(second.getSize(), 3);
    EXPECT_EQ(second.getDigitAt(0), 1);
    EXPECT_EQ(second.getDigitAt(1), 2);
    EXPECT_EQ(second.getDigitAt(2), 3);
    EXPECT_TRUE(first == second); // Проверка на равенство
}

TEST(ThirteenTest7, Operfirsttor) {
    Thirteen first("321");
    Thirteen second("123");

    ASSERT_TRUE(first > second);
}

TEST(ThirteenTest9, Sum) {
    Thirteen first("5");
    Thirteen second("A");

    Thirteen sum = first + second;

    ASSERT_EQ(sum.getSize(), 2);
    EXPECT_EQ(sum.getDigitAt(0), 2);
    EXPECT_EQ(sum.getDigitAt(1), 1);
}

TEST(ThirteenTest10, Sum) {
    Thirteen first("55");
    Thirteen second("A");

    Thirteen sum = first + second;

    ASSERT_EQ(sum.getSize(), 2);
    EXPECT_EQ(sum.getDigitAt(0), 2);
    EXPECT_EQ(sum.getDigitAt(1), 6);
}

// TEST(ThirteenTest11, Diff1) {
//     Thirteen first("123");
//     Thirteen second("321");

//     EXPECT_THROW(first - second, std::invalid_argument);
// }

// TEST(ThirteenTest12, Diff2) {
//     Thirteen first("321");
//     Thirteen second("123");

//     Thirteen diff = first - second;

//     ASSERT_EQ(diff.getSize(), 3);
//     EXPECT_EQ(diff.getDigitAt(0), 'B');
//     EXPECT_EQ(diff.getDigitAt(1), 0);
//     EXPECT_EQ(diff.getDigitAt(2), 2);
// }