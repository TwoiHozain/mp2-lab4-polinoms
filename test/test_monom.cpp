#include <gtest.h>
#include "polinom.h"

//Create from number
TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom m(1.0,1,1,1));
}

TEST(Monom, can_not_create_monom_with_x_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m(1.0,MaxPow+5, 1, 1));
}

TEST(Monom, can_not_create_monom_with_y_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m(1.0, 1, MaxPow + 5, 1));
}

TEST(Monom, can_not_create_monom_with_z_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m(1.0, 1, 1, MaxPow + 5));
}

//Create from string
TEST(Monom, can_not_create_monom_from_string_with_x_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m("1.0*x^"+ std::to_string(MaxPow + 5)+"*y^1*z^1"));
}

TEST(Monom, can_not_create_monom_from_string_with_y_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m("1.0*x^1*y^"+ std::to_string(MaxPow + 5) + "*z^1"));
}

TEST(Monom, can_not_create_monom_from_string_with_z_pow_greater_then_max_pow)
{
	ASSERT_ANY_THROW(Monom m("1.0*x^1*y^1*z^"+std::to_string(MaxPow + 5)));
}

TEST(Monom, can_create_monom_from_string_with_negative_int_coefficient)
{
	ASSERT_NO_THROW(Monom m("-1*x^1*y^1*z^1"));
}

TEST(Monom, can_create_monom_from_string_with_positiv_int_coefficient)
{
	ASSERT_NO_THROW(Monom m("1*x^1*y^1*z^1"));
}

TEST(Monom, can_create_monom_from_string_with_negative_floating_point_coefficient)
{
	ASSERT_NO_THROW(Monom m("-1.0*x^1*y^1*z^1"));
}

TEST(Monom, can_create_monom_from_string_with_positiv_floating_point_coefficient)
{
	ASSERT_NO_THROW(Monom m("1.0*x^1*y^1*z^1"));
}

TEST(Monom, can_create_monom_from_string_with_negative_exponential_form_coefficient)
{
	ASSERT_NO_THROW(Monom m("-1.0e+1*x^1*y^1*z^1"));
}

TEST(Monom, can_create_monom_from_string_with_positiv_exponential_form_coefficient)
{
	ASSERT_NO_THROW(Monom m("1.0e+1*x^1*y^1*z^1"));
}

TEST(Monom, can_add_monom_with_equal_pow)
{
	Monom m1(1.0, 2, 2, 2), m2(2.0, 2, 2, 2);
	Monom m3 = m1 + m2;

	ASSERT_EQ(m3.GetA(),3.0);
	ASSERT_EQ(m3.GetPow(), 222);
}

TEST(Monom, can_not_add_monom_with_non_equal_pow)
{
	Monom m1(1.0, 2, 2, 2), m2(1.0, 3, 2, 2);
	ASSERT_ANY_THROW(m1+m2);
}

TEST(Monom, can_sub_monom_with_equal_pow)
{
	Monom m1(1.0, 2, 2, 2), m2(2.0, 2, 2, 2);
	Monom m3 = m1 - m2;

	ASSERT_EQ(m3.GetA(), -1.0);
	ASSERT_EQ(m3.GetPow(), 222);
}

TEST(Monom, can_not_sub_monom_with_non_equal_pow)
{
	Monom m1(1.0, 2, 2, 2), m2(1.0, 3, 2, 2);
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(Monom, can_multiply_monoms)
{
	Monom m1(1.0, 2, 2, 2), m2(4.0, 2, 2, 2);
	ASSERT_NO_THROW(m1*m2);
}

TEST(Monom, can_multiply_monoms_correctly)
{
	Monom m1(2, 2, 2, 2), m2(4, 2, 2, 2);
	Monom m3=m1 * m2;

	ASSERT_EQ(m3.GetA(),8);
	ASSERT_EQ(m3.GetPow(),444);
}

TEST(Monom, can_multiply_monom_by_number)
{
	Monom m1(2, 2, 2, 2);
	float a = 4;

	ASSERT_NO_THROW(m1*a);
}

TEST(Monom, can_multiply_monom_by_correctly)
{
	Monom m1(2, 2, 2, 2);
	Monom m2 = m1* 4;

	ASSERT_EQ(m2.GetA(),8);
	ASSERT_EQ(m2.GetPow(),222);
}

TEST(Monom, can_compare_monoms_correctly_greater)
{
	Monom m1(2, 2, 2, 2), m2(4, 3, 2, 2);

	ASSERT_EQ(m2>m1,true);
}

TEST(Monom, can_compare_monoms_correctly_less)
{
	Monom m1(2, 2, 2, 2), m2(4, 3, 2, 2);

	ASSERT_EQ(m1 < m2, true);
}

TEST(Monom, can_compare_monoms_correctly_equal)
{
	Monom m1(2, 2, 2, 2), m2(2, 2, 2, 2);

	ASSERT_EQ(m1 == m2, true);
}

//POLYNOM
//Create from number
TEST(Polynom, can_create_polinom)
{
	ASSERT_NO_THROW(Polynom p);
}

TEST(Polynom, can_create_polinom_from_correct_string)
{
	ASSERT_NO_THROW(Polynom p("1*x^1+1*y^2"));
}

TEST(Polynom, can_create_polinom_from_correct_string_correctly)
{
	Polynom p("1*x^1+1*y^2");
	Monom m1(1.0,0,2,0),m2(1.0,1,0,0);

	ASSERT_EQ(p.At(0),m1);
	ASSERT_EQ(p.At(1), m2);
}

TEST(Polynom, can_copy_polinom)
{
	Polynom p1("1*x^1+1*y^2");
	Polynom p2(p1);

	ASSERT_EQ(p1==p2,true);
}

TEST(Polynom, copy_polinom_have_his_own_memory)
{
	Polynom p1("2*z^1");
	Polynom p2(p1);

	Monom m1(2, 1, 0, 0);
	Monom m2(5, 1, 0, 0);

	p1.Append(Monom("2*x^1"));
	p2.Append(Monom("5*x^1"));

	ASSERT_EQ(p1.At(1),m1);
	ASSERT_EQ(p2.At(1),m2);
}

TEST(Polynom, can_add_polinoms)
{
	Polynom p1("1*x^1");
	Polynom p2("3*z^1");

	Polynom p3 = p1 + p2;

	ASSERT_EQ(p3.At(0),Monom(3, 0, 0, 1));
	ASSERT_EQ(p3.At(1),Monom(1, 1, 0, 0));
}

TEST(Polynom, can_sub_polinoms)
{
	Polynom p1("1*x^1");
	Polynom p2("3*z^1");

	Polynom p3 = p1 - p2;

	ASSERT_EQ(p3.At(0), Monom(-3, 0, 0, 1));
	ASSERT_EQ(p3.At(1), Monom(1, 1, 0, 0));
}

TEST(Polynom, can_mult_at_scalar_polinoms)
{
	Polynom p1("3*z^1+1*x^1");

	Polynom p2 = p1 * 2.0;

	ASSERT_EQ(p2.At(0), Monom(6, 0, 0, 1));
	ASSERT_EQ(p2.At(1), Monom(2, 1, 0, 0));
}

TEST(Polynom, can_mult_at_polinom_polinoms)
{
	Polynom p1("1*x^1");
	Polynom p2("3*z^1");

	Polynom p3 = p1 * p2;

	ASSERT_EQ(p3.At(0), Monom(3, 1, 0, 1));
}
