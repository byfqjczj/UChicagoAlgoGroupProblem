#include "pch.h"
#include "C:\Users\ylhy2\Desktop\C++\integerstack\integerstack\integerstack.cpp"
//basic behavior for all 4 functions
TEST(BasicBehaviorTest) {
	IntStack s = IntStack();
	for (int i = 0; i < 100; i++)
	{
		s.push(i);
		EXPECT_EQ(i, s.peek());
		EXPECT_EQ(i,s.pop());
		EXPECT_EQ(0, s.size());
	}
	for (int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	for (int i = 99; i <= 0; i--)
	{
		EXPECT_EQ(i, s.peek());
		EXPECT_EQ(i, s.pop());
		EXPECT_EQ(i, s.size());
	}
}
//alloc and dealloc 1 million nodes onto the stack, handeled in 500 ms. Not great, not terrible
TEST(StressTest) {
	IntStack s = IntStack();
	for (int i = 0; i < 1000000; i++)
	{
		s.push(i);
		EXPECT_EQ(s.size(), i+1);
	}
	for (int i = 1000000; i > 0; i--)
	{
		s.pop();
		EXPECT_EQ(s.size(), i-1);
	}
}
//testing for popping and peeking on empty stacks
TEST(ErrorTest) {
	IntStack s = IntStack();
	EXPECT_ANY_THROW(s.pop());
	EXPECT_ANY_THROW(s.peek());
	for (int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	for (int i = 0; i < 100; i++)
	{
		s.pop();
	}
	EXPECT_ANY_THROW(s.pop());
	EXPECT_ANY_THROW(s.peek());
}
//popping at 0, and then proceed to see if the stack is robust enough to continue to provide correct behaviors
TEST(UndefinedBehavior) {
	IntStack s = IntStack();
	EXPECT_ANY_THROW(s.pop());
	EXPECT_EQ(s.size(), 0);
	s.push(10);
	EXPECT_EQ(s.size(), 1);
	EXPECT_EQ(s.peek(), 10);
}