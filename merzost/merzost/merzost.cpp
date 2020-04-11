/* Лабораторная работа 1 по дисциплине МРЗвИС
    Выполнена студентами группы 821702 БГУИР
    Ефимовой Александрой Александровной
    Ивановским Владиславом Александровичем
    Разработано консольное приложение с имитацией конвейерной архитектуры для умножения заданного множества пар двоичных чисел
*/

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <ctime>

using namespace std;
int times, razrad1, razrad2, razrad3;
vector <bool> nul;

void pair_operation(int pair, int razrad, int operation) {
    cout << "Pair " << pair << "  " << razrad << "."<<operation<< "operation" << endl;
}
vector <bool> to_binary_straight(int num)
{
    vector <bool> res;
    size_t size;
    int num_;
    num_ = abs(num);
    while (num_)
    {
        res.emplace(res.begin(), num_ % 2);
        num_ /= 2;
    }
    size = res.size();
    for (size_t i = 0; i < 6 - size; i++)
    {
        res.emplace(res.begin(), 0);
    }
    if (num < 0)
    {
        res[0] = 1;
    }
    return res;
}
vector <bool> addition(vector <bool> a, vector <bool> b)
{
    vector <bool> res;
    bool trans = false;
    for (size_t i = 0; i = a.size() - b.size(); i++)
    {
        b.push_back(0);
        //b.emplace(b.begin(), 0); //дополняем меньшее число до совпадения кол-ва разрядов
    }
    for (size_t i = a.size(); i > 0; i--)
    {
        if (a[i - 1] == 0 && b[i - 1] == 0 && trans == false)
        {
            res.emplace(res.begin(), 0);
            trans = false;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 0 && trans == true)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 0 && trans == false)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 0 && trans == true)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 1 && trans == false)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 1 && trans == true)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 1 && trans == false)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 1 && trans == true)
        {
            res.emplace(res.begin(), 1);
            trans = true;
        }
    }
    return res;
} 
vector <int> enter_numbers_in_vector(vector<int> v, int pairs){
    for (int i = 0; i < pairs; i++)
    {
        int n1;
        cin >> n1;
        v.push_back(n1);
    }
    return v;
}
void vector_to_binary(int pairs, vector <int> v) {
    for (int i = 0; i < pairs; i++)
    {
        vector <bool> res;
        res = to_binary_straight(v[i]);
        cout << v[i] << "  -  ";
        for (int i = 0; i < res.size(); i++)
        {
            if (i == 4)
            {
                cout << ".";
            }
            cout << res[i];
        }
        cout << endl;
    }
   
}
int what_stage() {
    int n, stage;
    bool s = false;
    while (s == false) {
        cout << "How many stages do you want?  (1/2/3/6/18)" << endl;
        cin >> n;
        if (n == 1 || n == 2 || n == 3 || n == 6 || n == 18)
        {
            stage = n;
            s = true;
        }
    };
    cout << endl;
    return stage;
}
void time()
{
    times++;
    times++;
    times++;
    cout << endl<<times<<endl;

}
int razrad_change(int razrad) {
   return razrad++;
}
void crop(int j) {
    if (j == 4||j==8)
    {
        cout << ".";
    }
}
void print_bool_vector_with_crop(vector<bool>v){
    for (int j = 0; j < v.size(); j++)
    {
        if (j == 4)
        {
            cout << ".";
        }
        cout << v[j];
    }
}
void straight_line(){
    for (int i = 0; i < 20; i++)
    {
        printf("%c", 254);
    }
}
void before_calculation(vector<bool>v1, vector<bool>v2, int pair) {
   
    cout << "Pair "<< pair<<":" << endl;
    print_bool_vector_with_crop(v1);
    cout << endl;
    print_bool_vector_with_crop(v2);
    cout << endl;
    straight_line();
    cout << endl;
}
vector <bool> stage1understage1(vector<bool>v1, vector<bool>v2, int razrad, int pair) {
    pair_operation(pair, razrad, 1);
    vector<bool> first;
    if (v2[v2.size() - razrad] == 0)
    {


        for (int j = 0; j < v2.size(); j++)
        {
            first.push_back(0);
        }
        for (int j = 0; j < first.size(); j++)
        {
            crop(j);
            cout << first[j];
        }

    }
    else
    {

        for (int j = 0; j < v2.size(); j++)
        {
            first.push_back(v1[j]);
        }
        for (int j = 0; j < first.size(); j++)
        {
            crop(j);
            cout << first[j];
        }

    }
    cout << endl;
    straight_line();
    cout << endl;
    return first;
}
void nul_vector() {
    for (int i = 0; i < 6; i++)
    {
        nul.push_back(0);
    }
}
vector<bool> stage1understage2(vector<bool>first, vector<bool>secondb_before, int razrad, int pair) {
    pair_operation(pair, razrad,2);
    vector<bool> sum = addition(secondb_before, first);
    for (int j = 0; j < sum.size(); j++)
    {
        crop(j);
        cout << sum[j];
    }
    cout << endl;
    straight_line();
    cout << endl;
    return sum;
}
vector<bool> stage1understage3(vector<bool>sum, int razrad, int pair) {
    pair_operation(pair, razrad, 3);
    vector <bool> second(sum.size() + 1);

    for (int i = 1; i < sum.size() + 1; i++)
    {
        second[i] = sum[i - 1];
    }
    for (int j = 0; j < second.size(); j++)
    {
        crop(j);
        cout << second[j];
    }
    cout << endl;
    straight_line();
    cout << endl;
    return second;
}
vector<bool> stage_3operations(vector<bool>num1,vector<bool>num2, vector<bool> second_before,int razrad,int pair) {
      vector<bool> vector1 = stage1understage1(num1, num2, razrad, pair);
      vector<bool> sum = stage1understage2(vector1, second_before, razrad, pair);
      vector<bool> vector2 = stage1understage3(sum, razrad, pair);
     // razrad++;
      return vector2;
}
int main()
{
    //счетчики разрядов
    razrad1 = 1;
    razrad2 = 1;
    razrad3 = 1;
    //заполнение нулевого вектора
    nul_vector();

    //задаем количество пар
    int pairs;
    cout << "How much pairs of number do you want to multiply?" << endl;
    pairs = 3;
    cout << 3 << endl;
    //cin >> pairs;

    //записываем введеные значения в вектора
    cout << "enter " << pairs << " numbers(<63) in the first vector" << endl;
    vector<int>v1 = enter_numbers_in_vector(v1, pairs);

    cout << "enter " << pairs << " numbers (<63) in the second vector" << endl;
    vector<int>v2 = enter_numbers_in_vector(v2, pairs);


    //вывод вектора переведенные в двоичный код числа
    cout << "the first vector" << endl;
    vector_to_binary(pairs, v1);

    cout << "the second vector" << endl;
    vector_to_binary(pairs, v2);


    //спрашиваем сколько этапов будет
    int stage = what_stage();
    int operations_in_stage = 18 / stage;
    cout << "----------------------------------------------------" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    //допустим у нас 3 пары хз как сделать любое количество пока что
    //переводим из десятичного вида числа которые будем умножать в бинарный и записываем каждый в свой вектор тк раньше мы блять просто вывели и никуда не записали
    vector<bool> pair1num1 = to_binary_straight(v1[0]);
    vector<bool> pair1num2 = to_binary_straight(v2[0]);
    vector<bool> pair2num1 = to_binary_straight(v1[1]);
    vector<bool> pair2num2 = to_binary_straight(v2[1]);
    vector<bool> pair3num1 = to_binary_straight(v1[2]);
    vector<bool> pair3num2 = to_binary_straight(v2[2]);


    //записываем для каждой пары ее номер и выводим 2 числа для умножения друг под другом и белую толстую прямую
    before_calculation(pair1num1, pair1num2, 1);
    before_calculation(pair2num1, pair2num2, 2);
    before_calculation(pair3num1, pair3num2, 3);

    //пример записи одного этапа из 3х операций с коментами функция stage_3operations объединяет их
    /*
    //записывание вектора из нулей или вектора равного первому вектору
    vector<bool> pair1razrad1vector1= stage1understage1(pair1num1, pair1num2,razrad1, 1);
    //записываем сумму
    vector<bool> pair1razrad1sum = stage1understage2(pair1razrad1vector1, nul, razrad1, 1);
    //записываем вектор со сдвигом
    vector<bool> pair1razrad1vector2 = stage1understage3(pair1razrad1sum, razrad1, 1);
    razrad1++;

    //записывание вектора из нулей или вектора равного первому вектору
    vector<bool> pair1razrad2vector1 = stage1understage1(pair1num1, pair1num2, razrad1, 1);
    //записываем сумму
    vector<bool> pair1razrad2sum = stage1understage2(pair1razrad2vector1, pair1razrad1vector2, razrad1, 1);
    //записываем вектор со сдвигом
    vector<bool> pair1razrad2vector2 = stage1understage3(pair1razrad2sum, razrad1, 1);
    razrad1++;

    //записывание вектора из нулей или вектора равного первому вектору
    vector<bool> pair1razrad3vector1 = stage1understage1(pair1num1, pair1num2, razrad1, 1);
    //записываем сумму
    vector<bool> pair1razrad3sum = stage1understage2(pair1razrad3vector1, pair1razrad2vector2, razrad1, 1);
    //записываем вектор со сдвигом
    vector<bool> pair1razrad3vector2 = stage1understage3(pair1razrad3sum, razrad1, 1);
    razrad1++;*/

    //пример записи одной пары полностью
    /*
    vector<bool> vector1 = stage_3operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++;
    vector<bool> vector2 = stage_3operations(pair1num1, pair1num2, vector1, razrad1, 1); razrad1++;
    vector<bool> vector3 = stage_3operations(pair1num1, pair1num2, vector2, razrad1, 1); razrad1++;
    vector<bool> vector4 = stage_3operations(pair1num1, pair1num2, vector3, razrad1, 1); razrad1++;
    vector<bool> vector5 = stage_3operations(pair1num1, pair1num2, vector4, razrad1, 1); razrad1++;
    vector<bool> vector6 = stage_3operations(pair1num1, pair1num2, vector5, razrad1, 1);
    */

    switch (stage)
    {
    case 1:
    {

        vector<bool> vector11 = stage_3operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage_3operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();
        vector<bool> vector13 = stage_3operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();
        vector<bool> vector14 = stage_3operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();
        vector<bool> vector15 = stage_3operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector16 = stage_3operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector21 = stage_3operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++; time();
        vector<bool> vector22 = stage_3operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++; time();
        vector<bool> vector23 = stage_3operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++; time();
        vector<bool> vector24 = stage_3operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++; time();
        vector<bool> vector25 = stage_3operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector26 = stage_3operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector31 = stage_3operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++; time();
        vector<bool> vector32 = stage_3operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++; time();
        vector<bool> vector33 = stage_3operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++; time();
        vector<bool> vector34 = stage_3operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++; time();
        vector<bool> vector35 = stage_3operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage_3operations(pair3num1, pair3num2, vector35, razrad3, 3); time();
        break;
    }
    
    case 2:
    {
        vector<bool> vector11 = stage_3operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage_3operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();
        vector<bool> vector13 = stage_3operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage_3operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage_3operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();
        vector<bool> vector22 = stage_3operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage_3operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector23 = stage_3operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage_3operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector31 = stage_3operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage_3operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++; time();
        vector<bool> vector32 = stage_3operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage_3operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector33 = stage_3operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage_3operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector34 = stage_3operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++; time();
        vector<bool> vector35 = stage_3operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage_3operations(pair3num1, pair3num2, vector35, razrad3, 3); time();
        break;
    }
    case 3:
    {
        vector<bool> vector11 = stage_3operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage_3operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage_3operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector13 = stage_3operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();
        vector<bool> vector22 = stage_3operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage_3operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();

        vector<bool> vector31 = stage_3operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector23 = stage_3operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage_3operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector32 = stage_3operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage_3operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage_3operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector33 = stage_3operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage_3operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector34 = stage_3operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage_3operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector35 = stage_3operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage_3operations(pair3num1, pair3num2, vector35, razrad3, 3); time();

        break;

    }
    case 6:
    {
        vector<bool> vector11 = stage_3operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage_3operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector12 = stage_3operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();

        vector<bool> vector31 = stage_3operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector22 = stage_3operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector13 = stage_3operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();

        vector<bool> vector32 = stage_3operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector23 = stage_3operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage_3operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();

        vector<bool> vector33 = stage_3operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage_3operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage_3operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();


        vector<bool> vector34 = stage_3operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage_3operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage_3operations(pair1num1, pair1num2, vector15, razrad1, 1); time();


        vector<bool> vector35 = stage_3operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage_3operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector36 = stage_3operations(pair3num1, pair3num2, vector35, razrad3, 3); time();

        break;
    }
   
    case 18:
    {
        //1-первый вектор 1-пара 1-разряд 
        //sum вектор 1-пара 1-разряд
        //2-второй вектор 1-пара 1-разряд


        vector<bool> vector111 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector121 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum11 = stage1understage2(vector111, nul, razrad1, 1); 
       
        vector<bool> vector131 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum21 = stage1understage2(vector121, nul, razrad2, 2);
        vector<bool> vector211 = stage1understage3(sum11, razrad1, 1); razrad1++; time();

        vector<bool> sum31 = stage1understage2(vector131, nul, razrad3, 3);
        vector<bool> vector221 = stage1understage3(sum21, razrad2, 2); razrad2++;
        vector<bool> vector112 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector231 = stage1understage3(sum31, razrad3, 3); razrad3++;
        vector<bool> vector122 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum12 = stage1understage2(vector112, vector211, razrad1, 1); 

        vector<bool> vector132 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum22 = stage1understage2(vector122, vector221, razrad2, 2);
        vector<bool> vector212 = stage1understage3(sum12, razrad1, 1); razrad1++; time();

        vector<bool> sum32 = stage1understage2(vector132, vector231, razrad3, 3);
        vector<bool> vector222 = stage1understage3(sum22, razrad2, 2); razrad2++;
        vector<bool> vector113 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector232 = stage1understage3(sum32, razrad3, 3); razrad3++;
        vector<bool> vector123 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum13 = stage1understage2(vector113, vector212, razrad1, 1); 

        vector<bool> vector133 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum23 = stage1understage2(vector123, vector222, razrad2, 2);
        vector<bool> vector213 = stage1understage3(sum13, razrad1, 1); razrad1++; time();

        vector<bool> sum33 = stage1understage2(vector133, vector232, razrad3, 3);
        vector<bool> vector223 = stage1understage3(sum23, razrad2, 2); razrad2++;
        vector<bool> vector114 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector233 = stage1understage3(sum33, razrad3, 3); razrad3++;
        vector<bool> vector124 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum14 = stage1understage2(vector114, vector213, razrad1, 1); 

        vector<bool> vector134 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum24 = stage1understage2(vector124, vector223, razrad2, 2);
        vector<bool> vector214 = stage1understage3(sum14, razrad1, 1); razrad1++; time();

        vector<bool> sum34 = stage1understage2(vector134, vector233, razrad3, 3);
        vector<bool> vector224 = stage1understage3(sum24, razrad2, 2); razrad2++;
        vector<bool> vector115 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector234 = stage1understage3(sum34, razrad3, 3); razrad3++;
        vector<bool> vector125 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum15 = stage1understage2(vector115, vector214, razrad1, 1); 

        vector<bool> vector135 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum25 = stage1understage2(vector125, vector224, razrad2, 2);
        vector<bool> vector215 = stage1understage3(sum15, razrad1, 1); razrad1++; time();

        vector<bool> sum35 = stage1understage2(vector135, vector234, razrad3, 3);
        vector<bool> vector225 = stage1understage3(sum25, razrad2, 2); razrad2++;
        vector<bool> vector116 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector235 = stage1understage3(sum35, razrad3, 3); razrad3++;
        vector<bool> vector126 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum16 = stage1understage2(vector116, vector215, razrad1, 1); 

        vector<bool> vector136 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum26 = stage1understage2(vector126, vector225, razrad2, 2);
        vector<bool> vector216 = stage1understage3(sum16, razrad1, 1); razrad1++; time();

        vector<bool> sum36 = stage1understage2(vector136, vector235, razrad3, 3);
        vector<bool> vector226 = stage1understage3(sum26, razrad2, 2); razrad2++; 

        vector<bool> vector236 = stage1understage3(sum36, razrad3, 3); razrad3++; 

        times++;
        times++;
        cout << endl << times << endl;

        break;
    }
    }
}

    /*////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    for (int i = 0; i < pairs; i++)
    {
        times = 0;
        cout <<endl<< "Pair " << i+1 << endl;

        vector<bool> number1 = to_binary_straight(v1[i]);
        vector<bool> number2 = to_binary_straight(v2[i]);

        for (int j = 0; j < number1.size(); j++)
        {
            if (j == 4)
            {
                cout << ".";
            }
            cout << number1[j];
        }
        
        cout << endl;

        for (int j = 0; j < number2.size(); j++)
        {
            if (j == 4)
            {
                cout << ".";
            }
            cout << number2[j];
        }
        cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254); 
        }
        cout<< endl;

        /////////////////////////
        //11111111111111111111111111
        vector<bool> first;
        if (number2[number2.size()-1] == 0)
        {
            
            
            for (int j = 0; j < number2.size(); j++)
            {
                first.push_back(0);
            }
            for (int j = 0; j < first.size(); j++)
            {
                if (j == 4)
                {
                    cout << ".";
                }
                cout << first[j];
            }
            time(); cout << endl;
        }
        else
        {
            
            for (int j = 0; j < number2.size(); j++)
            {
                first.push_back(number1[j]);
            }
            for (int j = 0; j < first.size(); j++)
            {
                if (j == 4)
                {
                    cout << ".";
                }
                cout << first[j];
            }
            time(); cout << endl;
        }

        ////////////////////////////////////////////

        vector <bool> second(first.size()+1);
        
        for (int i = 1; i < first.size() + 1; i++)
        {
            second[i] = first[i-1];
        }
        for (int j = 0; j < second.size(); j++)
        {
            if (j == 4)
            {
                cout << ".";
            }
            cout << second[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl;
        //////////////////////////////////////////////
        //22222222222222222222222222222222222222222222

        vector<bool> first2;
        if (number2[number2.size() - 2] == 0)
        {
            for (int j = 0; j < number2.size(); j++)
            {
                first2.push_back(0);
            }
            for (int j = 0; j < first2.size(); j++)
            {
                if (j == 4)
                {
                    cout << ".";
                }
                cout << first2[j];
            }
            time(); cout << endl;
        }
        else
        {

            for (int j = 0; j < number2.size(); j++)
            {
                first2.push_back(number1[j]);
            }
            for (int j = 0; j < first2.size(); j++)
            {
                if (j == 4)
                {
                    cout << ".";
                }
                cout << first2[j];
            }
            time(); cout << endl;
        }

        /////////////////////////////////////////////////////

        vector<bool> sum2 = addition(second, first2);
        for (int j = 0; j < sum2.size(); j++)
        {
            if (j == 4)
            {
                cout << ".";
            }
            cout << sum2[j];
        }
        time(); cout << endl;

        ////////////////////////////////////////////////////

        vector <bool> second2(sum2.size() + 1);

        for (int i = 1; i < sum2.size() + 1; i++)
        {
            second2[i] = sum2[i - 1];
        }
        for (int j = 0; j < second2.size(); j++)
        {
            if (j == 4)
            {
                cout << ".";
            }
            cout << second2[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl;

        ///////////////////////////////////////////////////
        //3333333333333333333333333333333333333333
        vector<bool> first3;
        if (number2[number2.size() - 3] == 0)
        {
            for (int j = 0; j < number2.size(); j++)
            {
                first3.push_back(0);
            }
            for (int j = 0; j < first3.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first3[j];
            }
            time(); cout << endl;
        }
        else
        {

            for (int j = 0; j < number2.size(); j++)
            {
                first3.push_back(number1[j]);
            }
            for (int j = 0; j < first3.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first3[j];
            }
            time(); cout << endl;
        }

        /////////////////////////////////////////////////////

        vector<bool> sum3 = addition(second2, first3);
        for (int j = 0; j < sum3.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << sum3[j];
        }
        time(); cout << endl;

        ////////////////////////////////////////////////////

        vector <bool> second3(sum3.size() + 1);

        for (int i = 1; i < sum3.size() + 1; i++)
        {
            second3[i] = sum3[i - 1];
        }
        for (int j = 0; j < second3.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << second3[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl;
        /////////////////////////////////////////////////////
        //44444444444444444444444444444444444444444
        vector<bool> first4;
        if (number2[number2.size() - 4] == 0)
        {
            for (int j = 0; j < number2.size(); j++)
            {
                first4.push_back(0);
            }
            for (int j = 0; j < first4.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first4[j];
            }
            time(); cout << endl;
        }
        else
        {

            for (int j = 0; j < number2.size(); j++)
            {
                first4.push_back(number1[j]);
            }
            for (int j = 0; j < first4.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first4[j];
            }
            time(); cout << endl;
        }

        /////////////////////////////////////////////////////

        vector<bool> sum4 = addition(second3, first4);
        for (int j = 0; j < sum4.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << sum4[j];
        }
        time(); cout << endl;

        ////////////////////////////////////////////////////

        vector <bool> second4(sum4.size() + 1);

        for (int i = 1; i < sum4.size() + 1; i++)
        {
            second4[i] = sum4[i - 1];
        }
        for (int j = 0; j < second4.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << second4[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl;
        /////////////////////////////////////////////////
        //55555555555555555555555555555555555555555555555
        vector<bool> first5;
        if (number2[number2.size() - 5] == 0)
        {
            for (int j = 0; j < number2.size(); j++)
            {
                first5.push_back(0);
            }
            for (int j = 0; j < first5.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first5[j];
            }
            time(); cout << endl;
        }
        else
        {

            for (int j = 0; j < number2.size(); j++)
            {
                first5.push_back(number1[j]);
            }
            for (int j = 0; j < first5.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first5[j];
            }
            time(); cout << endl;
        }

        /////////////////////////////////////////////////////

        vector<bool> sum5 = addition(second4, first5);
        for (int j = 0; j < sum5.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << sum5[j];
        }
        time(); cout << endl;

        ////////////////////////////////////////////////////

        vector <bool> second5(sum5.size() + 1);

        for (int i = 1; i < sum5.size() + 1; i++)
        {
            second5[i] = sum5[i - 1];
        }
        for (int j = 0; j < second5.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << second5[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl;
        //////////////////////////////////////////////////
        //666666666666666666666666666666666666666666666666
        vector<bool> first6;
        if (number2[number2.size() - 6] == 0)
        {
            for (int j = 0; j < number2.size(); j++)
            {
                first6.push_back(0);
            }
            for (int j = 0; j < first6.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first6[j];
            }
            time(); cout << endl;
        }
        else
        {

            for (int j = 0; j < number2.size(); j++)
            {
                first6.push_back(number1[j]);
            }
            for (int j = 0; j < first6.size(); j++)
            {
                if (j == 4 || j == 8)
                {
                    cout << ".";
                }
                cout << first6[j];
            }
            time(); cout << endl;
        }

        /////////////////////////////////////////////////////

        vector<bool> sum6 = addition(second5, first6);
        for (int j = 0; j < sum6.size(); j++)
        {
            if (j == 4 || j == 8)
            {
                cout << ".";
            }
            cout << sum6[j];
        }
        time(); cout << endl;

        ////////////////////////////////////////////////////

        vector <bool> second6(sum6.size() + 1);

        for (int i = 1; i < sum6.size() + 1; i++)
        {
            second6[i] = sum6[i - 1];
        }
        for (int j = 0; j < second6.size(); j++)
        {
            if (j == 4 || j==8)
            {
                cout << ".";
            }
            cout << second6[j];
        }
        time(); cout << endl;
        for (int i = 0; i < 20; i++)
        {
            printf("%c", 254);
        }
        cout << endl << endl;

        //int sam=0;
        //cout << sam << " " << second6[i]<<endl;
        //for (int i = 11; i >= 0; i--)
        //{
        //    for (int k = 0; k < 12; k++)
        //    {
        //        sam = sam + (pow(2, k) * second6[i]);
        //        cout << sam << " " << second6[i] << endl;
        //        break;
        //    }
        //}
        //cout << sam;



        //char bin[12];
        //int Chislo = 0;
       

        //for (int i = 0; i < 12; i++)
        //{
        //    bin[i] = second6[i];
        //}

        //for (int i = 0; i < strlen(bin); i++)
        //{
        //    Chislo *= 2;
        //    Chislo += bin[i] - '0';  // '0'-'0' равно 0, '1'-'0' Равно 1
        //}
        //cout  << Chislo << endl;
       
    }

}
*/
