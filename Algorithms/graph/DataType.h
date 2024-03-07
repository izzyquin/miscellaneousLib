#ifndef DATATYPE_H
#define DATATYPE_H

#include <iostream>

class DataType {
private:
    int data;
public:
    DataType(int d);

    int getData() const;

    void setData(int d);

    DataType& operator=(const DataType& d);
    bool operator==(const DataType& d);
    friend std::ostream& operator<<(std::ostream& os, const DataType& obj);

    bool operator<(const DataType& other) const;

    bool operator==(const DataType& other) const;
};

#endif // DATATYPE_H
