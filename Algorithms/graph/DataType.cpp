#include "DataType.h"

DataType::DataType(int d) : data(d) {}

int DataType::getData() const {
    return data;
}

void DataType::setData(int d) {
    data = d;
}

DataType& DataType::operator=(const DataType& d) {
    if (this != &d) {
        setData(d.getData());
    }
    return *this;
}

bool DataType::operator==(const DataType& d) {
    return (this->data == d.getData());
}

std::ostream& operator<<(std::ostream& os, const DataType& obj)// Overload the << operator as a friend function
{
    os << "{";
    os << obj.getData(); // Output the data member of the object
    os << "}";
    return os;
}

bool DataType::operator<(const DataType& other) const {
    return data < other.data;
}

bool DataType::operator==(const DataType& other) const {
    return data == other.data;
}
