#include "Number.h"

Number::Number(double _value) : value(_value)
{}

double Number::evaluate(){
    return value;

}

double *Number::getPtr() {
    return &value;
}