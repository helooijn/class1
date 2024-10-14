#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <cctype>
#include "SmartCar.h"

// 生成指定长度的随机字母和数字组合
std::string generateRandomString(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string result;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, sizeof(alphanum) - 2);

    for (int i = 0; i < length; ++i) {
        result += alphanum[dist(generator)];
    }
    return result;
}

// 生成小车编号（cqusn打头的16位数字和字母）
std::string generateCarId() {
    return "cqusn" + generateRandomString(11);
}

// 生成底盘编号（dp打头的8位数字和字母）
std::string generateChassisId() {
    return "dp" + generateRandomString(6);
}

// 录入小车信息
void inputCarInfo(SmartCar& car) {
    car.id = generateCarId();
    std::cout << "智能小车编号已生成: " << car.id << std::endl;  // 输出生成的智能小车编号

    car.chassis.id = generateChassisId();
    std::cout << "底盘编号已生成: " << car.chassis.id << std::endl;  // 输出生成的底盘编号

    std::cout << "输入学生学号: ";
    std::cin >> car.studentId;
    std::cout << "输入学生姓名: ";
    std::cin >> car.studentName;
}

// 保存所有小车信息到文件
void saveAllCarsToFile(const std::vector<SmartCar>& cars, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "无法打开文件!" << std::endl;
        return;
    }

    for (const auto& car : cars) {
        car.saveToFile(outFile);
    }

    std::cout << "小车信息已保存至文件: " << filename << std::endl;
    outFile.close();
}

// 浏览小车信息
void browseCars(const std::vector<SmartCar>& cars) {
    int index = 0; // 初始显示第1辆车
    char command;
    cars[index].displayInfo(); // 显示第一辆车信息
    std::cout << "按n查看下一辆小车，按p查看上一辆小车，按q退出浏览" << std::endl;

    while (true) {
        std::cin >> command;
        if (command == 'n') {
            if (index < cars.size() - 1) {
                index++; // 只有不是最后一辆时，才允许下一辆
                cars[index].displayInfo();
            } else {
                std::cout << "已经是最后一辆小车，无法再向后浏览。" << std::endl;
            }
        } else if (command == 'p') {
            if (index > 0) {
                index--; // 只有不是第一辆时，才允许上一辆
                cars[index].displayInfo();
            } else {
                std::cout << "已经是第一辆小车，无法再向前浏览。" << std::endl;
            }
        } else if (command == 'q') {
            break; // 退出浏览
        } else {
            std::cout << "无效指令，请重新输入。" << std::endl;
        }
    }
}

int main() {
    std::vector<SmartCar> cars(10);

    // 录入10台小车的信息
    for (int i = 0; i < 10; ++i) {
        std::cout << "录入第" << (i + 1) << "辆小车的信息: " << std::endl;
        inputCarInfo(cars[i]);  // 每次录入时生成并显示编号
    }

    // 保存小车信息到文件
    saveAllCarsToFile(cars, "smart_cars.txt");

    // 浏览小车信息
    browseCars(cars);

    return 0;
}
