#include <gtest.h>
#include "list.h"

TEST(TSortedList, can_create_enpty_list)
{
	ASSERT_NO_THROW(TSortedList<int> lst);
}

//Append
TEST(TSortedList, can_append_data_to_list)
{
	TSortedList<int> lst;
	ASSERT_NO_THROW(lst.Append(10));
}

TEST(TSortedList, data_appends_to_list)
{
	TSortedList<int> lst;
	lst.Append(10);
	ASSERT_EQ(lst.At(0), 10);
}

TEST(TSortedList, can_not_get_data_using_at_method_by_wrong_indx)
{
	TSortedList<int> lst;
	lst.Append(10);
	ASSERT_ANY_THROW(lst.At(7));
}

//Push_back method
TEST(TSortedList,can_push_back_data_to_list_in_correct_order)
{
	TSortedList<int> lst;
	ASSERT_NO_THROW(lst.Push_Back(8));
	ASSERT_NO_THROW(lst.Push_Back(10));
}

TEST(TSortedList, push_back_append_data_to_list_in_correct_order)
{
	TSortedList<int> lst;
	lst.Push_Back(8);
	lst.Push_Back(10);

	ASSERT_EQ(lst.At(0), 8);
	ASSERT_EQ(lst.At(1), 10);
}

TEST(TSortedList, can_not_push_back_data_to_list_in_uncorrect_order)
{
	TSortedList<int> lst;
	lst.Push_Back(10);
	ASSERT_ANY_THROW(lst.Push_Back(6));
}

//Iterator
TEST(TSortedList, can_get_data_with_using_iterator)
{
	TSortedList<int> lst;
	lst.Append(4);
	lst.Append(5);

	auto iter = lst.begin();
	ASSERT_EQ((*iter),4);

	iter++;
	ASSERT_EQ((*iter), 5);
}

//Copy constructor
TEST(TSortedList, can_create_list_from_other_list)
{
	TSortedList<int> lst1;
	lst1.Push_Back(7);
	lst1.Push_Back(10);

	ASSERT_NO_THROW(TSortedList<int> lst2 = lst1);
}

TEST(TSortedList, copied_list_copied_correctly)
{
	TSortedList<int> lst1;
	lst1.Push_Back(8);
	lst1.Push_Back(9);
	lst1.Push_Back(10);

	TSortedList<int> lst2 = lst1;

	auto iter1 = lst1.begin();
	auto iter2 = lst2.begin();

	ASSERT_EQ(*iter1 == *iter2,true);
	iter1++;
	iter2++;

	ASSERT_EQ(*iter1 == *iter2, true);
	iter1++;
	iter2++;

	ASSERT_EQ(*iter1 == *iter2, true);
}

TEST(TSortedList, copied_list_have_his_own_memory)
{
	TSortedList<int> lst1;
	lst1.Push_Back(8);
	lst1.Push_Back(9);
	lst1.Push_Back(10);

	TSortedList<int> lst2 = lst1;

	lst1.Push_Back(11);
	lst2.Push_Back(13);

	auto iter1 = lst1.begin();
	auto iter2 = lst2.begin();

	ASSERT_EQ(*iter1 == *iter2, true);
	iter1++;
	iter2++;

	ASSERT_EQ(*iter1 == *iter2, true);
	iter1++;
	iter2++;

	ASSERT_EQ(*iter1 == *iter2, true);
	iter1++;
	iter2++;

	ASSERT_EQ(*iter1, 11);
	ASSERT_EQ(*iter2, 13);
}