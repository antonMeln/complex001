#include <iostream>

using namespace std;

struct complex_t {
    float real;
    float imag;
    
    complex_t() {
        real = 0.0f;
        imag = 0.0f;
    }
    
    complex_t add( complex_t other) const {
        complex_t result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
    
    istream & read( istream & stream ) {
        float areal, aimag;
        char symbol;
        if(stream >> symbol && symbol == '(' && 
           stream >> areal && 
           stream >> symbol && symbol == ',' && 
           stream >> aimag && 
           stream >> symbol && symbol == ')') {
            real = areal;
            imag = aimag;
        }
        else {
            stream.setstate(ios::failbit);
        }

        return stream;
    }
    
    ostream & write( ostream & stream ) const {
        return stream << '(' << real << ',' << imag << ')';
    }
    
    complex_t sub( complex_t other ) const { 
        complex_t complex;

        complex.real = real - other.real;
        complex.imag = imag - other.imag;

        return complex;
    }

    complex_t mul(complex_t other) const { 
        complex_t complex;

        complex.real = real * other.real - imag * other.imag;
        complex.imag = imag * other.real + real * other.imag;

        return complex;
    }

    complex_t div(complex_t other) const { 
        complex_t complex;

        complex.real= (real * other.real + imag * other.imag) / (other.real * other.real +  other.imag * other.imag);
        complex.imag= (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);

        return complex;
    }
};

int main() {  
    complex_t a;
    if (a.read(cin)) {
        char op;
        cin >> op;
        complex_t b;
        if (b.read(cin)) {
            complex_t c;
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
        } else { 
            cout <<"An error has occured while reading input data";
        }

    } else {
        cout << "An error has occured while reading input data";
    }

    cin.get();
    cin.get();

    return 0;
}
