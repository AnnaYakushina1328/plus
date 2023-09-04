#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
 *
 * @brief главвная функция
 * @return возвращает 0 при успешном выполнении 
 */

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string generated_string;

    random_device rd; /*формирует случайную последовательность с помощью генератора*/
    mt19937 generator(rd()); /*генератор псевдослучайных чисел, производит 32-битные псевдослучайные числа*/
    uniform_int_distribution<int> distribution(0, alphabet.length() - 1); /*линейное распределение вероятностей возникает, когда вероятность появления
    каждого из допустимых чисел одинакова, т.е. каждое число может появиться с равным шансом. т.е. используется для ограничения генерируемых
    случайных чисел только символами английского алфавита.*/

    /*
    *
    * @brief генерирует случайную строку
    * @details выполняет цикл 10000 раз и добавляет случайно выбранный символ из алфавитной строки к сгенерированной строке
    */

    for (int i = 0; i < 10000; ++i) {
        int random_index = distribution(generator);
        generated_string += alphabet[random_index];
    }

    int counts[26] = { 0 };

    /**
    * @brief подсчет того, сколько раз встречается каждый символ алфавита
    * @details перебирает каждый символ в сгенерированной строке и увеличивает соответствующее количество его нахождения в массиве 'counts'
    */

    for (char c : generated_string) {
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        }
    }

    /**
    * @brief выводит количество букв каждого алфавита
    * @details перебирает строку 'alphabet' и выводит каждый символ алфавита вместе с его количеством из массива 'counts'
    */

    for (int i = 0; i < 26; ++i) {
        cout << alphabet[i] << ": " << counts[i] << endl;
    }

    return 0;
}