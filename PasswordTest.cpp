/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, identical_chars)
{
	Password my_password;
	int result = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, result);
}

TEST(PasswordTest, check_case)
{
	Password my_password;
	int result = my_password.count_leading_characters("zZ");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, no_identical)
{
	Password my_password;
	int result = my_password.count_leading_characters("xyz");
	ASSERT_EQ(1, result);
}

TEST(PasswordTest, spaces_leading)
{
	Password my_password;
	int result = my_password.count_leading_characters("    z");
	ASSERT_EQ(4, result);
}

TEST(PasswordTest, is_empty)
{
	Password my_password;
	int result = my_password.count_leading_characters("");
	ASSERT_EQ(0, result);
}

TEST(PasswordTest, only_lower_case)
{
	Password my_password;
	bool result = my_password.has_mixed_case("onlylowercase");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, only_upper_case)
{
	Password my_password;
	bool result = my_password.has_mixed_case("ONLYUPPERCASE");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, is_mixed)
{
	Password my_password;
	bool result = my_password.has_mixed_case("IsMixed");
	ASSERT_TRUE(result);
}