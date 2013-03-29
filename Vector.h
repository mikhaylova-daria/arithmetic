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
    #define radix 10000
    #define X 10 //число, степенью которого является основание (только 10 )
    #define radix_size 4 //степень 10
    #define MAX_SIZE 1024
    #define SMALLNUM int
    namespace  my {
    template <typename T> class vector;
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
        int put_on_bot (T const new_);//положить на "дно"
        int size_of_vector();
        void output ();
        int remove_top();
        T &operator [] (int pos);
        const T &operator [] (int pos) const;
        my::vector<T> &operator = (my::vector<T> const& a);
        bool operator == (my::vector<T> const&a);
        bool operator != (my::vector<T> const& a);
        };

    class BigNum
    {
        my::vector<int> num;
        bool sign;
    public:
        BigNum();
        BigNum(SMALLNUM x);
        BigNum(const BigNum &a);
        ~BigNum();
        void input();
        void output();
        BigNum min_size (BigNum *a, BigNum *b);
        BigNum max_size (BigNum *a, BigNum *b);
        my::vector<int> dif (BigNum , BigNum );
        BigNum power(int);
        BigNum Karatsuba(BigNum a);
        void remove_null ();
    //    BigNum & operator + (SMALLNUM a);
        BigNum operator + (BigNum a);
        BigNum operator -(BigNum a);
        BigNum operator * (SMALLNUM a);
        BigNum operator * (BigNum a);
        /*BigNum & operator / (SMALLNUM a);
        BigNum & operator / (BigNum a);*/
        void  operator = (BigNum a);
        bool operator == (BigNum a);
        bool operator != (BigNum a);
        bool operator >= (BigNum a);
        bool operator <= (BigNum a);
        bool operator > (BigNum a);
        bool operator < (BigNum a);
        friend BigNum division_of_numbers_similar_length__return_modulo (BigNum dividend, BigNum divider, SMALLNUM &quotient);
        friend BigNum division(BigNum dividend, BigNum divider, BigNum &quotient);// Возвращают остаток от деления (обе)!!!
    };
    #include "Vector2.h"
    #include "BigNum.h"

#endif
