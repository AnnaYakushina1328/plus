#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
 *
 * @brief �������� �������
 * @return ���������� 0 ��� �������� ���������� 
 */

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string generated_string;

    random_device rd; /*��������� ��������� ������������������ � ������� ����������*/
    mt19937 generator(rd()); /*��������� ��������������� �����, ���������� 32-������ ��������������� �����*/
    uniform_int_distribution<int> distribution(0, alphabet.length() - 1); /*�������� ������������� ������������ ���������, ����� ����������� ���������
    ������� �� ���������� ����� ���������, �.�. ������ ����� ����� ��������� � ������ ������. �.�. ������������ ��� ����������� ������������
    ��������� ����� ������ ��������� ����������� ��������.*/

    /*
    *
    * @brief ���������� ��������� ������
    * @details ��������� ���� 10000 ��� � ��������� �������� ��������� ������ �� ���������� ������ � ��������������� ������
    */

    for (int i = 0; i < 10000; ++i) {
        int random_index = distribution(generator);
        generated_string += alphabet[random_index];
    }

    int counts[26] = { 0 };

    /**
    * @brief ������� ����, ������� ��� ����������� ������ ������ ��������
    * @details ���������� ������ ������ � ��������������� ������ � ����������� ��������������� ���������� ��� ���������� � ������� 'counts'
    */

    for (char c : generated_string) {
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        }
    }

    /**
    * @brief ������� ���������� ���� ������� ��������
    * @details ���������� ������ 'alphabet' � ������� ������ ������ �������� ������ � ��� ����������� �� ������� 'counts'
    */

    for (int i = 0; i < 26; ++i) {
        cout << alphabet[i] << ": " << counts[i] << endl;
    }

    return 0;
}