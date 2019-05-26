#include <iostream>
using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;
		void whatISMyBirthday(){
			cout<<"21/07/18"<<endl;

		}
	public:
		Date(int m, int d, int y){
			month = m;
			day = d;
			year = y;
		}
		void printDate(){
			cout << month <<"/"<<day<<"/"<<year<<endl;
			whatISMyBirthday();
		}
		void setMonth(int m){
			if(m>0 && m<=12)
			{
				month = m;
			}
			else{
				cout<<"month is out of range\n";
			}
		}

};

int main(){
	Date d = Date(6, 12, 2018);
	d.printDate();
	int m =34;
	//d.whatISMyBirthday();
	d.setMonth(m);
	d.setMonth(5);
	d.printDate();
	return 0;
}