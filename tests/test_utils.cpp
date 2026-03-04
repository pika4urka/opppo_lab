#include <gtest/gtest.h>
#include "utils/utils.h"

// Тесты для parser_resolution
TEST(UtilsTest, ParseResolutionValid) {
    pairVals pr;
    utils::parser_resolution(pr, "1920x1080");
    
    EXPECT_EQ(pr.first, "1920");
    EXPECT_EQ(pr.second, "1080");
}

TEST(UtilsTest, ParseResolutionAnotherValid) {
    pairVals pr;
    utils::parser_resolution(pr, "800x600");
    
    EXPECT_EQ(pr.first, "800");
    EXPECT_EQ(pr.second, "600");
}

TEST(UtilsTest, ParseResolutionInvalidNoX) {
    pairVals pr;
    EXPECT_THROW(utils::parser_resolution(pr, "19201080"), std::invalid_argument);
}

TEST(UtilsTest, ParseResolutionEmpty) {
    pairVals pr;
    EXPECT_THROW(utils::parser_resolution(pr, ""), std::invalid_argument);
}

// Тесты для mult
TEST(UtilsTest, MultValid) {
    EXPECT_EQ(utils::mult("1920", "1080"), 1920 * 1080);
    EXPECT_EQ(utils::mult("800", "600"), 800 * 600);
    EXPECT_EQ(utils::mult("0", "1080"), 0);
}

// Тесты для check_equal
TEST(UtilsTest, CheckEqualTrue) {
    EXPECT_TRUE(utils::check_equal("128", "128"));
    EXPECT_TRUE(utils::check_equal("0", "0"));
}

TEST(UtilsTest, CheckEqualFalse) {
    EXPECT_FALSE(utils::check_equal("128", "256"));
    EXPECT_FALSE(utils::check_equal("128", "64"));
}

// Тесты для check_less
TEST(UtilsTest, CheckLessTrue) {
    EXPECT_TRUE(utils::check_less("64", "128"));
    EXPECT_TRUE(utils::check_less("0", "1"));
}

TEST(UtilsTest, CheckLessFalse) {
    EXPECT_FALSE(utils::check_less("128", "64"));
    EXPECT_FALSE(utils::check_less("128", "128"));  // равно - не меньше
}

// Тесты для check_more
TEST(UtilsTest, CheckMoreTrue) {
    EXPECT_TRUE(utils::check_more("256", "128"));
    EXPECT_TRUE(utils::check_more("128", "64"));
}

TEST(UtilsTest, CheckMoreFalse) {
    EXPECT_FALSE(utils::check_more("64", "128"));
    EXPECT_FALSE(utils::check_more("128", "128"));  // равно - не больше
}

// Тесты для check_num
TEST(UtilsTest, CheckNumValid) {
    EXPECT_NO_THROW(utils::check_num("123"));
    EXPECT_NO_THROW(utils::check_num("0"));
    EXPECT_NO_THROW(utils::check_num("999"));
}

TEST(UtilsTest, CheckNumInvalid) {
    EXPECT_THROW(utils::check_num("abc"), std::invalid_argument);
    EXPECT_THROW(utils::check_num("12a3"), std::invalid_argument);
    EXPECT_THROW(utils::check_num(""), std::invalid_argument);
}