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
    void BigNum::input() {    		//Работает
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
                x += (pow((float)X,  (int)q) * buf[j - q]);
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
    BigNum BigNum::min_size (BigNum *a, BigNum *b) { // по модулю!!!!!!
        int x = a->num.size_of_vector();
        int y = b->num.size_of_vector();
        if (x <= y ) {
            return	*a;
        } else {
            return *b;
        }
    }
    BigNum BigNum::max_size (BigNum* a, BigNum* b) {   // по модулю!!!!!!
        int x = a->num.size_of_vector();
        int y = b->num.size_of_vector();
        if (x <= y ) {
            return	*b;
        } else {
            return *a;
        }
    }
    my::vector<int> BigNum::dif (BigNum max, BigNum min) {
        BigNum difference;
        int j = min.num.size_of_vector();
        for (int i = 0; i < j; ++i) {
             if(max.num [i] < min.num[i]) {
                  max.num [i] += pow(10, radix_size);
                  max.num [i+1] -= 1;
             }
             difference.num.push_back(max.num [i] - min.num[i]);
        }
        for (int i = j; i < max.num.size_of_vector(); ++i){
            if (max.num[i] < 0) {
                max.num [i] += pow(10, radix_size);
                max.num [i+1] -= 1;
            }
            difference.num.push_back(max.num[i]);
        }
        return difference.num;
    }
    BigNum BigNum::power(int n) {
        BigNum product;
        product.num.push_back(1);
        bool flag = true;
        while (flag) {
            if (n % 2 == 1) {
                product = product * (*this);
            }
            n = n / 2;
            if (n > 0) {
                product = product * product;
            } else {
                flag = false;
            }
        }
        return product;
    }


    BigNum  BigNum::operator + (BigNum a) {
        BigNum min_abs = min_size (this, &a); // минимальный по модулю
        BigNum max_abs = max_size(this, &a);// максимальный по модулю
        int min = min_abs.num.size_of_vector();
        int max = max_abs.num.size_of_vector();
        BigNum sum;
        if (this->sign == a.sign) {
         sum.sign = this->sign;
         int buf = 0;
         int x;
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
        if (buf != 0) {
            sum.num.push_back(buf);
        }
        } else {
            sum.sign = max_abs.sign;
            max_abs.sign = true;
            min_abs.sign = true;
            sum.num = dif(max_abs, min_abs);

        }
        return sum;
    }

    BigNum BigNum::operator - (BigNum a){
        BigNum max = max_size(this, &a);
        BigNum min = min_size(this, &a);
        BigNum difference;
        if (min == a) {
            difference.sign = true;
        } else {
            difference.sign = false;
        }
        int j = min.num.size_of_vector();
        for (int i = 0; i < j; ++i) {
             if(max.num [i] < min.num[i]) {
                  max.num [i] += pow(10, radix_size);
                  max.num [i+1] -= 1;
             }
             difference.num.push_back(max.num [i] - min.num[i]);
        }
        for (int i = j; i < max.num.size_of_vector(); ++i){
            if (max.num[i] < 0) {
                max.num [i] += pow(10, radix_size);
                max.num [i+1] -= 1;
            }
            difference.num.push_back(max.num[i]);
        }
        return difference;
    }


    BigNum BigNum::operator * (SMALLNUM a){
        BigNum product;
        if (this->sign == false){
                product.sign = false;
        }
        int buf = 0;
        int n = this->num.size_of_vector();
        for (int i = 0; i < n; ++i) {
            int x = this->num[i] * a + buf;
            buf = x / radix;
            product.num.push_back(x % radix);
        }
        if (buf != 0) {
            product.num.push_back(buf);
        }
        int k = product.num.size_of_vector() - 1;
        while ((product.num[k] == 0)&& (k > 0)) {
            product.num.remove_top();
            k = product.num.size_of_vector() - 1;
        }
        return product;
    }
    BigNum BigNum::operator *(BigNum a) {
        BigNum product;
        product.num.push_back(0);
        if (a.sign != this -> sign) {
            product.sign =false;
        }
        BigNum max = max_size(this, &a);
        BigNum min = min_size(this, &a);
        int n = min.num.size_of_vector();
        for (int i = 0; i < n; ++i) {
            product = product + (max *(int) min.num[i]) * pow(radix, i);
        }
        int k = product.num.size_of_vector() - 1;
        while ((product.num[k] == 0)&& (k > 0)) {
            product.num.remove_top();
            k = product.num.size_of_vector() - 1;
        }
        return product;
    }

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
    void BigNum::operator = (BigNum a){
        this->sign = a.sign;
        this->num = a.num;
        return;
    }


