//SmartCar.h
#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <string>
#include <vector>
#include <fstream>

class Tire {
public:
    std::string model; // 轮胎型号
    std::string size;  // 轮胎尺寸
};

class Chassis {
public:
    std::string id; // 底盘编号
    std::string model = "SCOUT MINI";
    int wheelBase = 451; // 轴距，单位mm
    int wheelTrack = 490; // 轮距，单位mm
    int minGroundClearance = 115; // 最小离地间隙，单位mm
    int minTurningRadius = 0; // 最小转弯半径，单位m
    std::string driveType = "四轮四驱";
    int maxRange = 10; // 最大行程，单位KM
    std::vector<Tire> tires; // 轮胎信息

    Chassis();
};

class AGX {
public:
    std::string model = "AGX Xavier";
    int AI = 32; // TOPS
    int cudaCores = 512;
    int tensorCores = 64;
    int memory = 32; // 显存，单位GB
    int storage = 32; // 存储，单位GB
};

class Camera {
public:
    std::string model = "RealSense D435i";
    std::string cameraType = "D430";
    std::string rgbFrameResolution = "1920*1080";
    int rgbFrameRate = 30;
    std::string fov = "87*58";
    int depthFrameRate = 90;
};

class Lidar {
public:
    std::string model = "RS-Helios-16p";
    int channels = 16;
    int testRange = 100; // 测试范围，单位m
    int power = 8; // 功耗，单位W
};

class Gyroscope {
public:
    std::string model = "CH110";
    std::string manufacturer = "NXP";
};

class LCD {
public:
    float size = 11.6; // 尺寸
    std::string model = "super";
};

class Battery {
public:
    std::string parameters = "24V/15Ah";
    std::string externalPower = "24V";
    int chargeTime = 2; // 充电时长，单位小时
};

class SmartCar {
public:
    std::string id; // 智能小车编号
    Chassis chassis;
    AGX agx;
    Camera camera;
    Lidar lidar;
    Gyroscope gyroscope;
    LCD lcd;
    Battery battery;
    std::string studentId;   // 分配的学生学号
    std::string studentName; // 分配的学生姓名

    void saveToFile(std::ofstream& outFile) const;
    void loadFromFile(std::ifstream& inFile);
    void displayInfo() const;
};

#endif // SMARTCAR_H
