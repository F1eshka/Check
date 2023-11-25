#include <iostream>
#include <string>
using namespace std;

struct DataTime {
	unsigned short day{};
	unsigned short month{};
	long long year{};
	unsigned short hour{};
	unsigned short minuts{};
	string weekday;
};

struct Check {

	string brand;
	string adress;
	string nameproduct;
	unsigned int kassa{};
	float price{};
	float mymoney{};
	unsigned int PDV{};
	float wm{};
	float AKC{};
	int surrenders;
	unsigned int TSEnummer{};
	DataTime now;
};

void InfoChek(Check& c)
{
	cout << "Введите название магазина:";
	cin >> c.brand;

	cout << "Введите адрес: ";
	cin >> c.adress;

	cout << "Введите номер кассы: ";
	cin >> c.kassa;

	cout << "Введите день:";
	cin >> c.now.day;

	if (c.now.day < 1 || c.now.day > 31)
	{
		cout << "Неправильно введён день!\n";
		throw "НЕВЕРНЫЙ ДЕНЬ!";
	}

	cout << "Введите месяц:";
	cin >> c.now.month;

	if (c.now.month < 1 || c.now.month > 12)
	{
		cout << "Неправильно введён месяц!\n";
		throw "НЕВЕРНЫЙ МЕСЯЦ!";
	}

	cout << "Введите год:";
	cin >> c.now.year;

	cout << "Введите часы:";
	cin >> c.now.hour;
	if (c.now.hour<0 || c.now.hour > 23)
	{
		cout << "Неправильно введенны часы!\n";
		throw "НЕПРАВИЛЬНО!";
	}
	cout << "Введите минуты:";
	cin >> c.now.minuts;

	if (c.now.minuts < 0 || c.now.minuts > 60)
	{
		cout << "Неправильно введены минуты!\n";
		throw "НЕПРАВИЛЬНО!";
	}

	cout << "Введите название продукта: ";
	cin >> c.nameproduct;

	cout << "Введите цену: ";
	cin >> c.price;

	if (c.now.month < 0)
	{
		cout << "Неправильно введён прайс!\n";
		throw "НЕВЕРНЫЙ ПРАЙС!";
	}

	cout << "Сколько вы заплатили: ";
	cin >> c.mymoney;

	if (c.mymoney < c.price)
	{
		cout << "Неправильно введено кол-во денег!\n";
		throw "НЕПРАВИЛЬНО!";
	}

	cout << "Введите транзакционный номер: ";
	cin >> c.TSEnummer;

	if (c.TSEnummer < 0)
	{
		cout << "Неправильно введён транзакционный номер!\n";
		throw "НЕПРАВИЛЬНЫЙ ТРАНЗАКЦИОННЫЙ НОМЕР!";
	}

	cout << "Введите ПДВ в %: ";
	cin >> c.PDV;

	int a = (14 - c.now.month) / 12;
	int y = c.now.year - a;
	int m = c.now.month + 12 * a - 2;
	int wd = (c.now.day + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400) % 7;

	string weekdays[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
	c.now.weekday = weekdays[wd];
	c.wm = (c.price / 100) * c.PDV;
	c.AKC = c.price - c.wm;
	c.surrenders = c.price - c.mymoney;
}

void PrintCheck(const Check& c)
{
	cout << "\t" << c.brand << "\n";
	cout << "\t" << c.adress << "\n";
	cout << "\t" << "Название товара: " << c.nameproduct << "\n";
	cout << "\t" << "Номер кассы:" << c.kassa << "\n";
	cout << "\t";
	printf("%.2f $ \n\t", c.price);
	cout << "-------------------------------------"<<"\n\t";
	printf("Прайс:          %.2f $ \n\t", c.price);
	printf("Ваши деньги:     %.2f $\n\t", c.mymoney);
	cout << "-------------------------------------" << "\n\t";
	cout << "ПДВ %" << "\n\t";
	cout << c.PDV<< "%" << "\t";
	printf("%.2f\t", c.wm);
	printf("   %.2f\t\t", c.AKC);
	printf("%.2f\t\n", c.price);
	cout << "\t";
	cout << "Сумма: " << "\t";
	printf("%.2f\t", c.wm);
	printf("   %.2f\t\t", c.AKC);
	printf("%.2f\t\n", c.price);
	cout << "\t";
	cout << "-------------------------------------" << "\n\t";
	cout<< c.now.weekday << ", ";
	printf("%02d.%02d.%04d", c.now.day, c.now.month, c.now.year);
	cout << "\t";
	cout << "Время: " << c.now.hour << ":" << c.now.minuts<<"\n";
}

int main()
{
	setlocale(LC_ALL, "");
	Check now;
	InfoChek(now);
	PrintCheck(now);
}