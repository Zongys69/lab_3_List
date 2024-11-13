#include "list.h"

#include <gtest.h>

TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(List<int> l());
}

TEST(List, ñan_create_list_with_positive_lenght)
{
	ASSERT_NO_THROW(List<int> l(5));
}

TEST(List, cant_create_list_with_negative_index)
{
	ASSERT_ANY_THROW(List<int> l(-5));
}

TEST(List, can_create_list_with_parametr)
{
	ASSERT_NO_THROW(List<int> l(5, 6));
}

TEST(List, can_create_list_by_copied_link)
{
	List<int> l(5);
	ASSERT_NO_THROW(List<int> l1(l));
}

TEST(List, copied_list_is_equal_to_sourse_one)
{
	List<int> l(5);
	List<int> l1(l);
	ASSERT_EQ(l, l1);
}

TEST(List, can_get_size_of_list)
{
	List<int> l(5,6);
	int s = l.size();
	ASSERT_EQ(s, 5);
}

TEST(List, can_get_element) 
{
	List<int> l(5);
	l[4] = 6;
	int s = 6;
	ASSERT_EQ(s, l[4]);
}
TEST(List, cant_get_element_with_index_larger_then_list_size)
{
	List<int> l(5, 6);
	ASSERT_ANY_THROW(l[6]);
}


TEST(List, can_insert_element)
{
	List<int> l(5, 6);
	List<int> l1(6, 6);

	l[3] = 3;
	l1[3] = 3;

	List<int>::Node* current = l.get_first();

	for (int i = 0; i < 4; i++)
		current = current->next;

	l.insert(6, current);

	ASSERT_EQ(l, l1);
}
TEST(List, can_insert_element_to_empty_list)
{
	List<int> l;
	List<int> l1(1, 4);

	l.insert(4, nullptr);

	ASSERT_EQ(l, l1);
}


TEST(List, can_insert_front_element)
{
	List<int> l(5, 6);
	List<int> l1(6, 6);

	l[3] = 3;
	l1[3] = 3;

	l.insert_front(6);

	ASSERT_EQ(l, l1);
}

TEST(List, can_insert_front_element_to_empty_list)
{
	List<int> l;
	List<int> l1(1, 6);

	l.insert_front(6);

	ASSERT_EQ(l, l1);
}
TEST(List, can_find_element)
{
	List<int> l(5, 6);
	ASSERT_NO_THROW(l.find(6));
}

TEST(List, cant_find_element_not_in_list)
{
	List<int> l(5, 6);
	ASSERT_EQ(l.find(12), nullptr);
}

TEST(List, can_erase_element)
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 2;
	l[2] = 3;
	List<int> l1(2);
	l1[0] = 1;
	l1[1] = 3;

	List<int>::Node* current = l.get_first();

	for (int i = 0; i < 1; i++)
		current = current->next;

	l.erase(current);

	ASSERT_EQ(l, l1);
}

TEST(List, can_erase_front_element)
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 2;
	l[2] = 3;
	List<int> l1(2);
	l1[0] = 2;
	l1[1] = 3;

	
	l.erase_front();

	ASSERT_EQ(l, l1);
}

TEST(List, cant_erase_in_empty_list)
{
	List<int> l;
	ASSERT_ANY_THROW(l.erase(nullptr));
}

TEST(List, cant_erase_front_in_empty_list)
{
	List<int> l;
	ASSERT_ANY_THROW(l.erase_front());
}
//test for iterator
TEST(Iterator, can_begin_iteratot)
{
	List<int> l(5);
	ASSERT_NO_THROW(auto it = l.begin());
}

TEST(Iterator, can_end_iterator)
{
	List<int> l(5);
	ASSERT_NO_THROW(auto it = l.end());
}

TEST(Iterator, can_iterator_step_ahead)
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 3;
	l[2] = 2;

	auto it = l.begin();
	it++;

	ASSERT_EQ(l[1], * it);
}

TEST(Iterator, cant_iterator_step_out_of_range )
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 3;
	l[2] = 2;

	auto it = l.begin();
	it++;
	
	ASSERT_ANY_THROW(it++);
}

TEST(Iterator, can_get_element)
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 3;
	l[2] = 2;

	auto it = l.begin();
	it++;

	ASSERT_EQ(&(l[1]), it.operator->());
}

TEST(Iterator, equal_iterators_are_equal)
{
	List<int> l(3);
	l[0] = 1;
	auto it1 = l.begin();
	auto it2 = l.begin();

	ASSERT_EQ(it1 == it2, true);
}

TEST(Iterator, not_equal_iterators_are_equal)
{
	List<int> l(3);
	l[0] = 1;
	l[1] = 2;
	l[2] = 3;
	auto it1 = l.begin();
	auto it2 = l.begin();
	it2++;
	ASSERT_EQ(it1 == it2, false);
}


