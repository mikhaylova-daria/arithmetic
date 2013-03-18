#ifndef VECTOR_H
#include "Vector.h"
#endif
using namespace std;

    BigNum::BigNum(): sign(true){
    }
    BigNum::BigNum(const BigNum& a): sign(a.sign){
        num = a.num;
    }
    BigNum::~BigNum() {
    }
    void BigNum::input() {			//Работает
        short* buf = (short*) malloc (sizeof(short) * MAX_SIZE);
        int cap_buf = MAX_SIZE;
        int i=0;
        char c;
        std::cin>>c;
        if (c == '-'){
            this->sign = false;
            cin>>c;
        } else {
            this -> sign = true;
        }
        while (c == '0'){    // пропускает незначащие нули, введённые пользователем
            std::cin>> c;
        }
        if (c == '!') {
            this->num.push_back(0);
            free (buf);
            return;
        }
        switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            }
        bool flag = true;
        while (flag){
            std::cin>>c;
            switch (c) {
            case '1': buf[i] = 1;
                ++i;
                break;
            case '2': buf[i] = 2;
                ++i;
                break;
            case '3': buf[i] = 3;
                ++i;
                break;
            case '4': buf[i] = 4;
                ++i;
                break;
            case '5': buf[i] = 5;
                ++i;
                break;
            case '6': buf[i] = 6;
                ++i;
                break;
            case '7': buf[i] = 7;
                ++i;
                break;
            case '8': buf[i] = 8;
                ++i;
                break;
            case '9': buf[i] = 9;
                ++i;
                break;
            case '0': buf[i] = 0;
                ++i;
                break;
            case '!': flag = false;
                ++i;
                break;
            }
            if ( i == cap_buf) {
                buf = (short*) realloc(buf, cap_buf * 2 * sizeof(short));
            }
        }
        --i;//сейчас ровно столько, сколько цифр в числе
        int length_of_tail = i % radix_size;
        int x;
        for (int j = i-1; j >= length_of_tail; j-= radix_size) {
            x = 0;
            for (int q = 0; q < radix_size; ++q){
                x += (pow((float)X, (int) q) * buf[j - q]);
            }
            this->num.push_back(x);
        }
        x = 0;
        for (int j = 0; j < length_of_tail; ++j){		//Работает
            x += (pow((float)X, (int) (length_of_tail -j-1)) * buf[j]);
        }
            if (x != 0) {
                this->num.push_back(x);

            }
        free(buf);
        return;
    }

    void BigNum::output() {
        if (this->sign == false) {
            std::cout<<'-';
        }
        int size_of_vector = this->num.size_of_vector();
        for (int i = size_of_vector - 1; i >= 0; --i) {
            int w = radix / X;
            if (i != (size_of_vector - 1)) {
                int x = this->num[i];
                int z = (x / w);
                while ((z == 0)&&(w!=1)) {
                    w = w / X;
                    z = x/w;
                    std::cout<<'0';
                }
            }
                cout<<this->num[i];
        }
        return;
    }
        int BigNum::min_size (BigNum *a, BigNum *b) {
        int x = a->num.size_of_vector();
        int y = b->num.size_of_vector();
        if (x <= y ) {
            return	x;
        } else {
            return y;
        }
    }
    int BigNum::max_size (BigNum* a, BigNum* b) {
        int x = a->num.size_of_vector();
        int y = b->num.size_of_vector();
        if (x <= y ) {
            return	y;
        } else {
            return x;
        }
    }

    BigNum & BigNum::operator =(BigNum a){
        this->num = a.num;
        this->sign = a.sign;
        return *this;
    }

    BigNum&  BigNum::operator + (BigNum a) {
        if (this->sign == a.sign) {
         BigNum sum;
         sum.sign = this->sign;
         int buf = 0;
         int x;
         int min = min_size (this, &a);
         int max = max_size (this, &a);;
          BigNum max_num;
          if (max == a.num.size_of_vector()) {
              max_num = a;
            } else {
                max_num = *this;
             }
        for (int i = 0; i < min; ++i) {
            x = (this->num[i]) + a.num[i] + buf;
            buf = x / radix;
            sum.num.push_back(x % radix);
        }

        for (int i = min; i < max; ++i) {
            x = max_num.num[i] + buf;
            buf = x / radix;
            sum.num.push_back (x % radix);
        }
        return sum;
        }
    }


/*	BigNum & operator + (SMALLNUM a) {;
    }
    BigNum & operator + (BigNum a) {;
    }
    BigNum & operator -(SMALLNUM a) {
        if (a < 0){
            a=-a;
            return *this + a;
        } else {

        }
    }
    BigNum & operator * (SMALLNUM a) {;
    }
    BigNum & operator * (BigNum a) {;
    }
    BigNum & operator / (SMALLNUM a) {;
    }
    BigNum & operator / (BigNum a) {;
    }*/

    bool BigNum::operator == (BigNum a){
        if (a.sign == this->sign) {
            if (a.num == this->num) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool BigNum::operator != (BigNum a) {
        return (!(a == *this));
    }

    bool BigNum::operator >= (BigNum a) {
        if (a == *this) {
            return true;
        }
        if ((this->sign == false) && (a.sign == true)) {
            return false;
        }
        if ((this->sign == true) && (a.sign == false)) {
            return true;
        }
        int x = a.num.size_of_vector();
        int y = this->num.size_of_vector();
        if (y > x) { // учитывать только без незначащих нулей!!!
            return true;
        }
        if (y < x) {
            return false;
        }

        if (y == x) {
            for (int i = 0; i < x; ++i) {
                if (this->num[i] > a.num[i]) {
                    return true;
                }
                if (this->num[i] < a.num[i]) {
                    return false;
                }
            }
        return true;
        }
    }

    bool BigNum::operator <= (BigNum a){
        if (a == *this) {
            return true;
        }
        if ((this->sign == true) && (a.sign == false)) {
            return false;
        }
        if ((this->sign == false) && (a.sign == true)) {
            return true;
        }
        int x = a.num.size_of_vector();
        int y = this->num.size_of_vector();
        if (y > x) { // учитывать только без незначащих нулей!!!
            return false;
        }
        if (y < x) {
            return true;
        }

        if (y == x) {
            for (int i = 0; i < x; ++i) {
                if (this->num[i] > a.num[i]) {
                    return false;
                }
                if (this->num[i] < a.num[i]) {
                    return true;
                }
            }
        return true;
        }
    }


    bool BigNum::operator > (BigNum a) {
        return (!(this->operator <= (a)));
    }
    bool BigNum::operator < (BigNum a) {
        return (!(this->operator >= (a)));
    }
 /*   void BigNum::operator = (BigNum a){
        this->sign = a.sign;
        this->num = a.num;
        return;
    }*/
