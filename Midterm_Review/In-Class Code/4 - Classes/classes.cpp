#include <iostream>

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;

	public:
		Date(int m, int d, int y){
			month = m;
			day = d;
			year = y;
		}

		void printDate(){
			cout << month << "/" << day << "/" << year << endl;
		}

		void setMonth(int m){
			if(m > 0 && m < 13){
				month = m;
			}
			else{
				cout << "Month is out of range." << endl;
			}
		}
};

int main(){
	Date myDateObject1 = Date(6,12,2018);
	Date myDateObject2(6,12,2018);

	myDateObject1.printDate();
	myDateObject2.printDate();

	myDateObject2.setMonth(13);
	myDateObject2.setMonth(5);
	myDateObject2.printDate();

	return 0;
}