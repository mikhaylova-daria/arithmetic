#ifndef VECTOR_H
#define VECTOR_H
	#ifndef _IOSTREAM
		#include <iostream>
		#define  _IOSTREAM
	#endif
	#ifndef _NEW
		#include <new>
		#define  _NEW
	#endif
	#ifndef MATH_H
		#include <math.h>
		#define MATH_H
	#endif
	#define radix 100000
	#define X 10 //число, степенью которого является основание (только 10 )
	#define radix_size 5 //степень 10
	#define MAX_SIZE 1024
	#define SMALLNUM int
	namespace  my {
	template <typename T> class vector;
	template <> class my::vector<bool>;
	}

	template <typename T> class my::vector
	{
		T *p_vector;
		int  size;
		int capacity;
	public:
		vector();
		vector (int _capacity);
		vector (vector const &a);
		~vector();
		int push_back (T const new_);
		const int &size_of_vector();
		void output ();	
		T &operator [] (int pos);
		const T &operator [] (int pos) const;
		my::vector<T> &operator = (my::vector<T> const& a);
		bool operator == (my::vector<T> const&a);
		bool operator != (my::vector<T> const& a);
		};

	template <> class my::vector<bool>{
		char* p_vector;
		int  size;
		int capacity;
	public:
		vector() ;
		vector(int _capacity);
		vector (vector const &a);
		~vector();
		int push_back(bool const new_);
		const int &size_of_vector();
		void output();
		int operator [] (int pos);
		void set(bool _new, int pos);
		my::vector<bool> &operator = (my::vector<bool> const& a);
		bool operator == (my::vector<bool> const&a);
		bool operator != (my::vector<bool> const& a);
	};  
	class BigNum
	{
		my::vector<int> num;
		bool sign;
	public:
		BigNum();
		~BigNum();
		void input();
		void output();
	/*	BigNum & operator + (SMALLNUM a);
		BigNum & operator + (BigNum a);
		BigNum & operator -(SMALLNUM a);
		BigNum & operator * (SMALLNUM a);
		BigNum & operator * (BigNum a);
		BigNum & operator / (SMALLNUM a);
		BigNum & operator / (BigNum a);*/
		bool operator == (BigNum a);
		bool operator != (BigNum a);
		bool operator >= (BigNum a);
		bool operator <= (BigNum a);
		bool operator > (BigNum a);
		bool operator < (BigNum a);
	};
	#include "Vector2.h"
	#include "BigNum.h"
	
#endif
