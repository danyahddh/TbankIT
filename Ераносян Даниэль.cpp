#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<long long> getFibonacciInRange(long long start, long long end) {
    vector<long long> fibNumbers;
    long long prev = 0, curr = 1;

    while (prev <= end) {
        if (prev >= start) {
            fibNumbers.push_back(prev);
        }
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }

    return fibNumbers;
}

void validateRange(long long start, long long end) {
    if (start >= end) {
        throw invalid_argument("Ошибка: первое число должно быть меньше второго");
    }
}

string formatOutput(const vector<long long>& fibNumbers) {
    if (fibNumbers.empty()) {
        return "В заданном диапазоне нету чисел Фибоначчи";
    }

    stringstream ss;
    for (size_t i = 0; i < fibNumbers.size(); ++i) {
        if (i > 0) {
            ss << " ";
        }
        ss << fibNumbers[i];
    }
    return ss.str();
}

int main() {
    try {
        long long start, end;
        cin >> start >> end;

        validateRange(start, end);

        vector<long long> fibonacciNumbers = getFibonacciInRange(start, end);
        cout << formatOutput(fibonacciNumbers) << endl;

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "Упс, произошла ошибка: " << e.what() << endl;
    }

    return 0;
}
