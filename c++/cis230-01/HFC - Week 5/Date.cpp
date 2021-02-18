/*
   Spencer White
   CIS 230-02 - Date
   Simple Data Class
*/

#include <iostream>

class Date {
    private:
        int month;
        int day;
        int year;

        int validateData(int m, int d, int y){
            bool flag1 = (m < 1 || m > 12);
            bool flag2 = (d < 1 || d > 31);
            bool flag3 = (y < 1900 || y > 2040);
            return !(flag1 || flag2 || flag3);
        }

        int validateDate(int m, int d, int y) {
            switch(m){
                case 2:
                    if (d > 28 && (y % 4 != 0)) {
                        return 0;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (d > 30) {
                        return 0;
                    }
                    break;
                default:
                    return 1;
            }
        }

    public:
        Date(int m=1, int d=1, int y=1900) {
            int isValidInput = validateData(m, d, y);
            int isValidDate = validateDate(m, d, y);

            if (isValidInput && isValidDate) {
                std::cout<<"VALID INPUT"<<std::endl;
                month = m;
                day = d;
                year = y;
            } else {
                month = 1;
                day = 1;
                year = 1990;
                std::cout<<"INVALID INPUT"<<std::endl;
            }
        }

        void displayDate() {
            std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
        }
};

int main() {

    // Tests - Failures
    Date date1 = Date(-1, 10, 1910);
    Date date2 = Date(13, 10, 1910);
    Date date3 = Date(1, -5, 1910);
    Date date4 = Date(1, 34, 1910);
    Date date5 = Date(1, 28, 1899);
    Date date6 = Date(1, 28, 2070);
    Date date7 = Date(4, 31, 1999);
    Date date8 = Date(6, 31, 1999);
    Date date9 = Date(9, 31, 1999);
    Date date10 = Date(11, 31, 1999);
    Date date11 = Date(2, 31, 1999);
    Date date19 = Date(2, 29, 1993);

    // Tests - Successes
    Date date12 = Date(2, 15, 1999);
    Date date13 = Date(1, 31, 2023);
    Date date14 = Date(4, 30, 2023);
    Date date15 = Date(2, 29, 2000);
    Date date16 = Date(2, 29, 2004);
    Date date17 = Date(2, 29, 2020);
    Date date18 = Date(2, 29, 1996);

    return 0;
}