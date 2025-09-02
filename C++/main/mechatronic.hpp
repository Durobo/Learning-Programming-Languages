#ifndef MECHATRONIC_HPP
#define MECHATRONIC_HPP

// Lop hinh tron
class HinhTron {
    private:
        double radius;
    public:
        explicit HinhTron(double r);
        double chu_vi () const;
        double dien_tich () const;
};

// Lop so phuc
class SoPhuc {
    private:
        double phan_thuc, phan_ao;
    public:
        explicit SoPhuc(double a, double b);
        SoPhuc cong_so_phuc(SoPhuc &temp);
        void hien_thi();
};


#endif