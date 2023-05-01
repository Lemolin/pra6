#include "bigNumCalc.h"
using namespace std;

list<int> bigNumCalc::buildBigNum(string numString) {
    list<int> list;
    for (int i = 0;i<numString.size();i++) {
        list.push_back(stoi(string(1,numString[i])));
    }
    return list;
}

list<int> bigNumCalc::add(list<int> num1, list<int> num2) {
    list<int> result;
    int num = 0;

    while (!num1.empty() || !num2.empty()) {
        int digit1 = 0, digit2 = 0;
        if (!num1.empty()) {
            digit1 = num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            digit2 = num2.back();
            num2.pop_back();
        }
        int sum = digit1 + digit2 + num;
        result.push_front(sum % 10);
        num = sum / 10;
    }
    if (num) {
        result.push_front(num);
    }
 
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}

list<int> bigNumCalc::sub(list<int> num1, list<int> num2) {
    list<int> result;
    int num = 0;

 
    while (!num1.empty() || !num2.empty()) {
        int digit1 = 0, digit2 = 0;
        if (!num1.empty()) {
            digit1 = num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            digit2 = num2.back();
            num2.pop_back();
        }
        int a = digit1 - digit2 - num;
        if (a < 0) {
            a += 10;
            num = 1;
        }
        else {
            num = 0;
        }
        result.push_front(a);
    }

    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}

list<int>bigNumCalc::mul(list<int> num1, list<int> num2) {
    list<int> result;
    int num = 0;
    int d2 = num2.front();
    while (!num1.empty()) {
        int d1 = num1.back();
        num1.pop_back();
        int b = d1 * d2 + num;
        result.push_front(b % 10);
        num = b / 10;
    }
    if (num) {
        result.push_front(num);
    }

    num2.pop_front();
    while (!num2.empty()) {
        int d2 = num2.front();
        num2.pop_front();
        list<int> temp;
        for (int i = 0; i < result.size(); i++) {
            temp.push_back(result.front());
            result.pop_front();
        }
        num = 0;
        while (!temp.empty()) {
            int d1 = temp.back();
            temp.pop_back();
            int b = d1 * d2 + num;
            result.push_front(b % 10);
            num = b / 10;
        }
        if (num) {
            result.push_front(num);
        }
    }
    return result;
}
