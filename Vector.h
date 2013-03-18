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
        int size_of_vector();
        void output ();
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
        BigNum(const BigNum &a);
        ~BigNum();
        void input();
        void output();
        int min_size (BigNum *a, BigNum *b);
        int max_size (BigNum *a, BigNum *b);
    //	BigNum & operator + (SMALLNUM a);
        BigNum & operator + (BigNum a);
        /*BigNum & operator -(SMALLNUM a);
        BigNum & operator * (SMALLNUM a);
        BigNum & operator * (BigNum a);
        BigNum & operator / (SMALLNUM a);
        BigNum & operator / (BigNum a);*/
        BigNum & operator = (BigNum a);
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

