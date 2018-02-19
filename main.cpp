#include <iostream>
using namespace std;
struct complex_t {
    complex_t(){
        real =0.0f;
        imag = 0.0f;
    }
    float real;
    float imag;
    complex_t add( complex_t other)const{
        complex_t result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
    istream & read (istream & stream){
        float m, n;
        char a, b, c;

        if (stream >> a && a == '(' && stream >> m && stream >> b && b == ',' && stream >> n && stream >> c && c == ')') {
            real = m;
            imag = n;
        }
        else stream.setstate(ios::failbit);

        return stream;
    }
    ostream & write (ostream & stream, complex_t complex)  {
        return stream << "(" << real << "," << imag << ")";
    }
    complex_t sub(complex_t other)const
    { complex_t complex;

        complex.real= real - other.real;
        complex.imag= imag - other.imag;

        return complex;
    }


    complex_t mul(complex_t other) const
    { complex_t complex;

        complex.real= (real * other.real- imag * other.imag)  ;
        complex.imag= (imag * other.real + real * other.imag);

        return complex;
    }

    complex_t div(complex_t other)const
    { complex_t complex;

        complex.real= (real * other.real + imag * other.imag)/(other.real * other.real +  other.imag * other.imag);
        complex.imag= (imag * other.real - real * other.imag)/(other.real * other.real + other.imag * other.imag);

        return complex;
    }
};



int main() {
    complex_t a,b;
    complex_t c;
    char op;
    if (a.read(cin)) {
        cin >> op;
        if (b.read(cin)) {
            switch (op) {
                case '+':
                    c = a.add(b);
                    c.write(cout,c);
                    break;
                case '-':
                    c = a.sub(b);
                    c.write(cout,c);

                    break;
                case '*':
                    c = a.mul(b);
                    c.write(cout,c);
                    break;
                case '/':
                    c = a.div(b);
                    c.write(cout,c);
                    break;
            }
        }else  cout <<"An error has occured while reading input data";

    }else  cout << "An error has occured while reading input data";

    cin.get();
    cin.get();

    return 0;
}
