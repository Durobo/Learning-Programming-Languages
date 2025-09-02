#include <iostream>
#include <vector>
#include "mechatronic.hpp"

int main() {
    std::vector<SoPhuc> arr_complex = {SoPhuc(1, 2), SoPhuc(2, 3), SoPhuc(3, 4), SoPhuc(4, 5), SoPhuc(5, 6)};
    SoPhuc tong(0, 0);
    for (int i = 0; i < 5; i++) {
        tong = tong.cong_so_phuc(arr_complex[i]);
    }
    tong.hien_thi();
}