#pragma once
#include<iostream>

class Matrix
{
    private:
        size_t _rows;
        size_t _cols;
        float* _data;

    public:
        Matrix():_data(nullptr),_rows(0),_cols(0)
        {
            std::cout<<"Constructor Matrix();"<<std::endl;
        }
        // 创建 M(rows, cols)
        Matrix(size_t row, size_t col)
        :_rows(row),_cols(col)
            {
                _data= new float[row*col]();
                std::cout<<"Constructor Matrix(size_t, size_t)"<<std::endl;
            }

        // 深拷贝！
        Matrix(const  Matrix& other):_rows(other._rows),_cols(other._cols)
        {
            if(other._data==nullptr)
            {
                _data=nullptr;
                return;
            }
            this->_data= new float[other._rows*other._cols];
            for(size_t i=0;i<other._rows*other._cols;i++)
            {
                this->_data[i]=other._data[i];
            }
            // this->_rows=other._rows;
            // this->_cols=other._cols;
        }

        Matrix& operator=(const Matrix& other) 
        {
            if(this==&other) return *this;

            //m.operator=(other) 因此 m 的原来的内容需要先删除！防止数据泄漏！！
            delete [] _data;
            this->_data= new float[other._rows*other._cols];
            for(size_t i=0;i<other._rows*other._cols;i++)
            {
                this->_data[i]=other._data[i];
            }
            this->_rows = other._rows;  // 
            this->_cols = other._cols;  // 
            return *this;
        }

        // Matrix operator+ 
        Matrix operator+(const Matrix& other) const
        {
            if(this->_rows!=other._rows||this->_cols!=other._cols)
            {
                throw std::invalid_argument("Matrix dimensions must match for addition");
            }
            Matrix temp(_rows,_cols);
            for(size_t i=0; i<_rows*_cols;i++)
            {
                temp._data[i]=this->_data[i]+other._data[i];
            }
            return temp;
        }

        // operator() 重载！ 元素访问！ 需要检查边界！！！
        float&  operator()(size_t i, size_t j) 
        {
                  if (i >= _rows || j >= _cols) {
                     throw std::out_of_range("Matrix index out of range");
                    }
           
            return  this->_data[i*this->_cols+j];

        }

        const float& operator()(size_t i, size_t j) const
        {
        if (i >= _rows || j >= _cols) {
            throw std::out_of_range("Matrix index out of range");
        }
            return _data[i * _cols + j];
        }
    
            
        ~Matrix()
        {
            delete[]_data;
            _data=nullptr;
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& m)
        {
            for(size_t i=0; i<m._rows;i++)
            {
                for(size_t j=0;j<m._cols;j++)
                {
                    os<<m._data[i*m._cols+j]<<" ";

                }
                os<<"\n";
            }

            return os;
        }

};
