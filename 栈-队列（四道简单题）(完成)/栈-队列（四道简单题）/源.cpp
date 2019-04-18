#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//用队列实现栈
//注意队列是后入前出
class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int> q;
	queue<int> q1;
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		while (q.size() != 1)
		{
			q1.push(q.front());
			q.pop();
		}
		int count = 0;
		count = q.front();
		q.pop();

		while (!q1.empty())
		{
			q.push(q1.front());
			q1.pop();
		}
		return count;
	}

	/** Get the top element. */
	int top()
	{
		return q.back();

	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return q.empty();
	}
};
//用栈实现队列
class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int> s;
	stack<int> s1;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		s.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{

		while (s.empty() == 0)
		{
			s1.push(s.top());
			s.pop();
		}

		int count = s1.top();
		s1.pop();

		while (s1.empty() == 0)
		{
			s.push(s1.top());
			s1.pop();
		}

		return count;

	}

	/** Get the front element. */
	int peek()
	{
		stack<int> s2(s);
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		int res = s1.top();
		while (!s1.empty())
		{
			s1.pop();
		}
		return res;

		/*while(!s.empty())
		{
		s1.push(s.top());
		s.pop();
		}
		int res = s1.top();
		while(!s1.empty())
		{
		s.push(s1.top());
		s1.pop();
		}
		return res;*/
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return s.empty();
	}
};
//最小栈

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack()
	{

	}

	void push(int x)
	{
		s.push(x);

		if (s1.empty() || s1.top() >= x)
		{
			s1.push(x);
		}
	}

	void pop()
	{
		int cur = s.top();
		s.pop();

		if (s1.top() == cur)
			s1.pop();
	}

	int top()
	{
		return s.top();
	}

	int getMin()
	{
		return s1.top();
	}
private:
	stack<int> s;
	stack<int> s1;
};