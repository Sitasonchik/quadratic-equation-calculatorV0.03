#include <iostream>
#include <math.h>
#include<Windows.h>
#include <string>

void urav(float a,float b,float c) {
    long float D;
    D = b * b - 4 * a * c;
    std::cout << "D=" << D << std::endl;
    if (D < 0) {
        D *= -1;
        if (b != 0) {
            std::cout << "x1=" << '(' << -b << " + " << 'i' << sqrt(D) << ')' << '/' << a * 2 << std::endl;
            std::cout << "x2=" << '(' << -b << " - " << 'i' << sqrt(D) << ')' << '/' << a * 2 << std::endl;
        }
        else {
            if (sqrt(D) != 2) {
                std::cout << "x1=" << 'i' << sqrt(D) << '/' << a * 2 << std::endl;
                std::cout << "x2=" << 'i' << sqrt(D) << '/' << a * 2 << std::endl;
            }
            else {
                if (a != 1) {
                    std::cout << "x1=" << 'i' << '/' << a << std::endl;
                    std::cout << "x2=" << 'i' << '/' << a << std::endl;
                }
                else {
                    std::cout << "x1=" << 'i' << std::endl;
                    std::cout << "x2=" << 'i' << std::endl;
                }
            }
        }
    }
    else {
        //x1 = (-b + sqrt(d)) / 2 / a;
        //x2 = (-b - sqrt(d)) / 2 / a;
        std::cout << "x1=" << (-b + sqrt(D)) / 2 / a << std::endl;
        std::cout << "x2=" << (-b - sqrt(D)) / 2 / a << std::endl;
    }
}
int main()
{
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    char ur[10000];
    std::string str1;
    std::cout << "example equation: ax^2 + bx + c = 0" << std::endl;
    std::cout << "enter the equation:" << std::endl;
    std::getline(std::cin, str1);
    for (int i = 0; i <= size(str1); i++) {
            ur[i] = str1[i];
    }
    int coef = 0;
    int a3 = strlen(ur);
    for (int i = 0; i < a3; i++) {
        if (ur[i] != 'x' && ur[i] != ' ' && ur[i] != '+' && ur[i] != '^' && ur[i] != '-') {
            switch (coef) {
            case(0):
                a1 = ur[i] - '0' + a1 * 10;
                break;
            case(1):
                b1 = ur[i] - '0' + b1 * 10;
                break;
            case(2):
                c1 = ur[i] - '0' + c1 * 10;
                break;
            default:
                break;
            }

        }
        else if (ur[i] == '^') {
            i++;
        }
        else if (ur[i] == ' ') {
            i+=2;
            coef++;
        }
        else if (ur[i] == '=') {
            i += 100;
        }
    }
    coef = 0;
    for (int i = 0; i < a3; i++) {
        if (ur[i] == '-') {
            i++;
            switch(coef)
            {
            case(0):
                a1 = -a1;
                break;
            case(1):
                b1 = -b1;
                break;
            case(2):
                c1 = -c1;
                break;
            default:
                break;
            }
        }
        else if (ur[i] == ' ') {
           // i++;
            coef++;
        }

    }
    urav(a1, b1, c1);
    Sleep(2200000);
}
