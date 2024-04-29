#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstddef>
#include <exception>

template < class T > class Matrix
{
private:
    size_t rows;
    size_t cols;
    size_t size;
    T* data;
public:
    Matrix();
    Matrix(size_t size);
    Matrix(size_t rows, size_t cols);
    void resize(size_t rows, size_t cols);
    Matrix(const Matrix<T> &other);
    T getElement(size_t i, size_t j) const;
    void setElement(size_t i, size_t j, T value);
    const Matrix<T> &operator=(const Matrix<T> &other);
    ~Matrix();
};

template< class T >
Matrix<T>::Matrix(): size(0), rows(0), cols(0)
{
    data = new T[1];
}

template< class T >
Matrix<T>::Matrix(size_t size): size(size), rows(1), cols(size)
{
    data = new T[size];
}

template< class T >
Matrix<T>::Matrix(size_t rows, size_t cols): size(rows*cols), rows(rows), cols(cols)
{
    data = new T[size];
}

template< class T >
void Matrix<T>::resize(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;
    this->size = rows*cols;
    delete [] data;
    data = new T[size]; 
}

template< class T >
Matrix<T>::Matrix(const Matrix<T> &other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->size = other.size;
    data = new T[size];
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
        {
            T val = other.getElement(i, j);
            setElement(i, j, val);
        }
    }
}

template< class T >
T Matrix<T>::getElement(size_t i, size_t j) const {
    return data[i*cols+j];
}

template< class T >
void Matrix<T>::setElement(size_t i, size_t j, T value) {
    data[i*cols+j] = value;
}

template< class T >
const Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->size = other.size;
    resize(size);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
        {
            T val = other.getElement(i, j);
            setElement(i, j, val);
        }
    }
    return *this;
}

// template< class T >
// Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) {
//     if (this->cols != other.cols || this->rows != other.rows)
//     {
//         throw std::range_error("Cannot add matrices of different sizes.")
//     }
    
//     Matrix<T> Added = other;
//     for (size_t i = 0; i < rows; i++) {
//         for (size_t j = 0; j < cols; j++)
//         {
//             setElement(i, j, val);
//         }
//     }
// }

template< class T >
Matrix<T>::~Matrix()
{
    delete [] data;
}

#endif // _MATRIX_H_