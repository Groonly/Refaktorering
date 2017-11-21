#include "Libs/unity/src/unity.h"
#include "calculatorFunc.h"

#define DECIMAL_PRECISSION 2

void test_KwattPris_diffrent_typ_of_values(void)
{
TEST_ASSERT_EQUAL_FLOAT(0.015, kwattPris(5, 3));
TEST_ASSERT_EQUAL_FLOAT(0, kwattPris(0, 0.1));
}

void test_ohmsLag_diffrent_typ_of_values(void)
{
TEST_ASSERT_FLOAT_WITHIN(DECIMAL_PRECISSION, 15, ohmsLag(5, 3));
TEST_ASSERT_FLOAT_WITHIN(DECIMAL_PRECISSION, 0, ohmsLag(0, 0));
}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_KwattPris_diffrent_typ_of_values);
RUN_TEST(test_ohmsLag_diffrent_typ_of_values);
return UNITY_END();
}
