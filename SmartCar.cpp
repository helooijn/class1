#include "SmartCar.h"
#include <fstream>
#include <iostream>

// 构造函数，初始化轮胎信息
Chassis::Chassis() {
    tires.resize(4);
    for (int i = 0; i < 4; ++i) {
        if (i % 2 == 0) {
            tires[i].model = "公路轮";
        } else {
            tires[i].model = "麦克纳姆轮";
        }
        tires[i].size = "175mm";
    }
}

// 将智能小车信息保存到文件
void SmartCar::saveToFile(std::ofstream& outFile) const {
    if (outFile.is_open()) {
        outFile << "编号: " << id << "\n";
        // 底盘信息
        outFile << "底盘编号: " << chassis.id << "\n";
        outFile << "底盘型号: " << chassis.model << "\n";
        outFile << "轴距: " << chassis.wheelBase << "mm\n";
        outFile << "轮距: " << chassis.wheelTrack << "mm\n";
        outFile << "最小离地间隙: " << chassis.minGroundClearance << "mm\n";
        outFile << "最小转弯半径: " << chassis.minTurningRadius << "m\n";
        outFile << "驱动形式: " << chassis.driveType << "\n";
        outFile << "最大行程: " << chassis.maxRange << "KM\n";
        // 轮胎信息
        for (int i = 0; i < chassis.tires.size(); ++i) {
            outFile << "轮胎" << (i + 1) << "型号: " << chassis.tires[i].model << "\n";
            outFile << "轮胎" << (i + 1) << "尺寸: " << chassis.tires[i].size << "\n";
        }
        // AGX套件信息
        outFile << "AGX型号: " << agx.model << "\n";
        outFile << "AI: " << agx.AI << " TOPS\n";
        outFile << "CUDA核心: " << agx.cudaCores << "\n";
        outFile << "Tensor CORE: " << agx.tensorCores << "\n";
        outFile << "显存: " << agx.memory << "GB\n";
        outFile << "存储: " << agx.storage << "GB\n";
        // 摄像头信息
        outFile << "摄像头型号: " << camera.model << "\n";
        outFile << "摄像头类型: " << camera.cameraType << "\n";
        outFile << "RGB帧分辨率: " << camera.rgbFrameResolution << "\n";
        outFile << "RGB帧率: " << camera.rgbFrameRate << "\n";
        outFile << "FOV: " << camera.fov << "\n";
        outFile << "深度帧率: " << camera.depthFrameRate << "\n";
        // 激光雷达信息
        outFile << "激光雷达型号: " << lidar.model << "\n";
        outFile << "通道数: " << lidar.channels << "\n";
        outFile << "测试范围: " << lidar.testRange << "m\n";
        outFile << "功耗: " << lidar.power << "W\n";
        // 9轴陀螺仪信息
        outFile << "陀螺仪型号: " << gyroscope.model << "\n";
        outFile << "厂家: " << gyroscope.manufacturer << "\n";
        // 液晶显示屏信息
        outFile << "液晶显示屏尺寸: " << lcd.size << "\n";
        outFile << "液晶显示屏型号: " << lcd.model << "\n";
        // 电池模块信息
        outFile << "电池参数: " << battery.parameters << "\n";
        outFile << "对外供电: " << battery.externalPower << "\n";
        outFile << "充电时长: " << battery.chargeTime << "H\n";
        // 学生信息
        outFile << "学生学号: " << studentId << "\n";
        outFile << "学生姓名: " << studentName << "\n";
        outFile << "--------------------------\n";
    }
}

// 显示智能小车的所有信息
void SmartCar::displayInfo() const {
    std::cout << "编号: " << id << "\n";
    std::cout << "底盘编号: " << chassis.id << "\n";
    std::cout << "底盘型号: " << chassis.model << "\n";
    std::cout << "轴距: " << chassis.wheelBase << "mm\n";
    std::cout << "轮距: " << chassis.wheelTrack << "mm\n";
    std::cout << "最小离地间隙: " << chassis.minGroundClearance << "mm\n";
    std::cout << "最小转弯半径: " << chassis.minTurningRadius << "m\n";
    std::cout << "驱动形式: " << chassis.driveType << "\n";
    std::cout << "最大行程: " << chassis.maxRange << "KM\n";
    for (int i = 0; i < chassis.tires.size(); ++i) {
        std::cout << "轮胎" << (i + 1) << "型号: " << chassis.tires[i].model << "\n";
        std::cout << "轮胎" << (i + 1) << "尺寸: " << chassis.tires[i].size << "\n";
    }
    std::cout << "AGX型号: " << agx.model << "\n";
    std::cout << "AI: " << agx.AI << " TOPS\n";
    std::cout << "CUDA核心: " << agx.cudaCores << "\n";
    std::cout << "Tensor CORE: " << agx.tensorCores << "\n";
    std::cout << "显存: " << agx.memory << "GB\n";
    std::cout << "存储: " << agx.storage << "GB\n";
    std::cout << "摄像头型号: " << camera.model << "\n";
    std::cout << "摄像头类型: " << camera.cameraType << "\n";
    std::cout << "RGB帧分辨率: " << camera.rgbFrameResolution << "\n";
    std::cout << "RGB帧率: " << camera.rgbFrameRate << "\n";
    std::cout << "FOV: " << camera.fov << "\n";
    std::cout << "深度帧率: " << camera.depthFrameRate << "\n";
    std::cout << "激光雷达型号: " << lidar.model << "\n";
    std::cout << "通道数: " << lidar.channels << "\n";
    std::cout << "测试范围: " << lidar.testRange << "m\n";
    std::cout << "功耗: " << lidar.power << "W\n";
    std::cout << "陀螺仪型号: " << gyroscope.model << "\n";
    std::cout << "厂家: " << gyroscope.manufacturer << "\n";
    std::cout << "液晶显示屏尺寸: " << lcd.size << "\n";
    std::cout << "液晶显示屏型号: " << lcd.model << "\n";
    std::cout << "电池参数: " << battery.parameters << "\n";
    std::cout << "对外供电: " << battery.externalPower << "\n";
    std::cout << "充电时长: " << battery.chargeTime << "H\n";
    std::cout << "学生学号: " << studentId << "\n";
    std::cout << "学生姓名: " << studentName << "\n";
}
