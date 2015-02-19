//
//  main.cpp
//  PrimerParcialEje1
//
//  Created by Santiago Rodriguez Fernandez on 19/02/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#include <iostream>
#include <string>

void conDecHex(int num, std::string& hex);

int main()
{
    int num = 0;
    std::cout << "Ingresa un numero: ";
    std::cin >> num;
    std::cin.sync();
    std::string hex;
    conDecHex(num, hex);
    std::cout << "\nEl valor en hexadecimal es = 0x" << hex << std::endl;
    std::cin.get();
    }
void conDecHex(int num, std::string& hex)
    {
        int h;
        if (num == 0)
        {
            return;
        }
        h = num % 16;
        num = num / 16;
        conDecHex(num, hex);
        if (h >= 10)
        {
            hex = hex + char('A' + h - 10);
        }
        else
        {
            hex = hex + char('0' + h);
        }
    }


/*#include <iostream>

void conDecHex(int num);
int main()

{
    int num;
    std::cout << "Ingresa tu numero en decimal: ";
    std::cin >> num;
    std::cout << "Tu numero en hexadecimal es: " << "0x";
    conDecHex(num);
    return 0;
}
void conDecHex(int num)
{
    int h;

    if (num == 0)
    {
        return;
    }
    h = num % 16;
    num = num / 16;
    conDecHex(num);
    if (h >= 10)
    {
        std::cout << char(h + 55);
        }
        else
        {
            std::cout << h;
        }
        }
*/
