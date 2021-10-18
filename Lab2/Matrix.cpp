#include <iostream>
#include <ctime>

// Объявление класса Matrix
class Matrix
{
    // Модификатор доступа (Список свойств и методов для использования внутри класса)
private:
    
    // Модификатор доступа (Список методов доступных другим функциям и объектам программы)
public:
    static const int SIZE = 5;
    static const int ROWS = SIZE;
    static const int COLS = SIZE;
    int matrix[ROWS][COLS];
    // Конструктор класса Matrix
    Matrix()
    {
        // Заполнение матрицы случайными числами
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] = rand() % 10;
            }
        }
    }

    // Вывод матрицы на консоль
    void ShowMatrix() {

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    // Геттер для матриц - возвращаем указатель на нашу матрицу (первый ее элемент)
    int* GetMatrix()
    {
        // через * берем сам указатель
        return *matrix;
    }

    // Метод умножения матриц A и B (получаем наши указатели на первые элементы матриц)
    void MatrixMultiplication(int* MatrixA, int* MatrixB)
    {
        //Создаем временные копии 
        int A[ROWS][COLS];
        int B[ROWS][COLS];

        //Циклы для извлечения матриц по указателям во временные копии
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                //* из указателя извлекает значение по этому указателю, 
                //при прибавлении к указателю единицы он возьмет следующий указатель в матрице,
                //то есть второй элемент, третий и т.д...
                A[i][j] = *MatrixA++;
                B[i][j] = *MatrixB++;
            }
        }

        //цикл для умножения матриц и записи результата в матрицу
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                //обнуление элемента матрицы с результатом
                matrix[i][j] = 0;
                for (int k = 0; k < ROWS; k++)
                {
                    //умножение матриц - сумма умножений строки на столбец
                    matrix[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
};

// Входная точка в программу
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    Matrix A;
    A.ShowMatrix();
    std::cout << "\n" << std::endl;
    Matrix B;
    B.ShowMatrix();
    std::cout << "\n" << std::endl;
    std::cout << "Результат умножения матриц А и B" << "\n" << std::endl;
    Matrix C;

    for (int i = 0; i < A.ROWS; i++)
    {
        for (int j = 0; j < A.COLS; j++)
        {
            //обнуление элемента матрицы с результатом
            C.matrix[i][j] = 0;
            for (int k = 0; k < A.ROWS; k++)
            {
                //умножение матриц - сумма умножений строки на столбец
                C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
            }
        }
    }

    //вывод получившейся матрицы
    C.ShowMatrix();
}