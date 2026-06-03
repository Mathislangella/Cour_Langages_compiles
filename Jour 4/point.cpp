#include <iostream>

class Point {
    private:
        double x;    
        double y;
    public:
       
        Point(double xi, double yi) { x = xi; y = yi; }
        
        double getX() const { return x; }
        double getY() const { return y; }
        void afficher() const {
            std::cout << "(" << x << ", " << y << ")\n";
        }
};

int main() {
    Point p1(3.0, 4.0);
    Point p2(10.0, 20.0);
    p1.afficher();    p2.afficher();
    std::cout << "p1 x: " << p1.getX() << ", y: " << p1.getY() << "\n";
    std::cout << "p2 x: " << p2.getX() << ", y: " << p2.getY() << "\n";
    return 0;
}
