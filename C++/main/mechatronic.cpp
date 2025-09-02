#include <iostream>
#include "mechatronic.hpp"

constexpr double PI = 3.14;

// Bai tap ve lop Hinh Tron --chu vi --dien tich.
HinhTron::HinhTron(double r) : radius(r) {}

double HinhTron::chu_vi() const {
    return 2 * PI * radius;
}

double HinhTron::dien_tich() const {
    return PI * radius * radius;
}

// Bai tap ve lop So Phuc --cong so phuc --hien thi.
SoPhuc::SoPhuc(double a, double b) : phan_thuc(a), phan_ao(b) {}

SoPhuc SoPhuc::cong_so_phuc(SoPhuc &temp) {
    return SoPhuc(phan_thuc + temp.phan_thuc, phan_ao + temp.phan_ao);
}

void SoPhuc::hien_thi() {
    std::cout << phan_thuc;
    if (phan_ao < 0) {
        std::cout << " - " << -phan_ao << "i" << std::endl;
    }
    else {
        std::cout << " + " << phan_ao << "i" << std::endl;
    }
}