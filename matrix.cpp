#include <iostream>
using namespace std;

class Matrix {
private:
    int data[2][2]; // Двумерный массив

public:
    
    Matrix() : data{{0}} {}
    Matrix(int a11, int a12, int a21, int a22) {
        data[0][0] = a11;
        data[0][1] = a12;
        data[1][0] = a21;
        data[1][1] = a22;
    }

    
    int getElement(int row, int col) const { return data[row][col]; } // Чтение
    void setElement(int row, int col, int value) { data[row][col] = value; } // Запись

    
    Matrix operator+(const Matrix& rhs) const { // Сложение 
        return Matrix(
            data[0][0] + rhs.data[0][0],
            data[0][1] + rhs.data[0][1],
            data[1][0] + rhs.data[1][0],
            data[1][1] + rhs.data[1][1]
        );
    }

    Matrix operator-(const Matrix& rhs) const { // Вычитание 
        return Matrix(
            data[0][0] - rhs.data[0][0], 
            data[0][1] - rhs.data[0][1],
            data[1][0] - rhs.data[1][0],
            data[1][1] - rhs.data[1][1]
        );
    }

    Matrix operator*(const Matrix& rhs) const { // Умножение 
        Matrix result;
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
                for(int k=0; k<2; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    Matrix operator*(int scalar) const { // Умножение на скаляр 
        return Matrix(
            data[0][0]*scalar,
            data[0][1]*scalar,
            data[1][0]*scalar,
            data[1][1]*scalar
        );
    }

    
    bool operator==(const Matrix& rhs) const { // Проверка равентсва 
        for(int i=0; i<2; ++i) 
            for(int j=0; j<2; ++j)
                if(data[i][j] != rhs.data[i][j]) return false;
        return true;
    }

    bool operator!=(const Matrix& rhs) const { return !(*this == rhs); }

    
    Matrix& operator=(const Matrix& rhs) {
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
                data[i][j] = rhs.data[i][j];
        return *this;
    }

    
    int* operator[](size_t index) { return data[index]; }
    const int* operator[](size_t index) const { return data[index]; }

    
    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);
};


ostream& operator<<(ostream& os, const Matrix& m) {
    os << "[[" << m.data[0][0] << ", " << m.data[0][1] << "],\n"
       << " [" << m.data[1][0] << ", " << m.data[1][1] << "]]";
    return os;
}


istream& operator>>(istream& is, Matrix& m) {
    cout << "Enter matrix elements (row-major order): ";
    is >> m.data[0][0] >> m.data[0][1]
       >> m.data[1][0] >> m.data[1][1];
    return is;
}

int main() {
    // Создаем матрицу
    Matrix m1(1, 2, 3 ,4);
    Matrix m2;
    
    
    cin >> m2;
    
    
    cout << "\nMatrix 1:\n" << m1; // Вывод первой матрицы
    cout << "\n\nMatrix 2:\n" << m2; // Вывод второй матрицы
    
    cout << "\n\nSum:\n" << m1 + m2; // Сложение
    cout << "\n\nDifference:\n" << m1 - m2; // Вычитание
    cout << "\n\nProduct:\n" << m1 * m2; // Умножение матриц
    
    cout << "\n\nScalar product (m1*3):\n" << m1 * 3; // Умножение на число
    
    cout << "\n\nComparison: " 
         << (m1 == m2 ? "Equal" : "Not equal"); // Сравнение
        
    cout << "\nIndex access: m1[0][1] = " << m1[0][1]; // Доступ через индексы
    
    return 0;
}
