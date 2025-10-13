/*#include <iostream>
#include <iomanip>

int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::uppercase;
	std::cout << std::setprecision(7) << std::setw(20);
	std::cout << std::setfill('0');
	std::cout << pi << std::endl;

	std::cout << std::noboolalpha << true << " - " << false << std::endl;  //ispis bool kao broj (1 ili 0)
	std::cout << std::dec << 255 << std::endl;   //decimalni
	std::cout << std::hex << 255 << std::endl;   //heksadecimalni
	std::cout << std::oct << 255 << std::endl;   //oktalni
	std::cout << std::setw(10) << std::left << 1234 << std::endl;  //livo poravnanje
	std::cout << std::setw(10) << std::right << 1234 << std::endl; //desno poravnanje
	std::cout << std::setprecision(3) << std::fixed << 3.14159265 << std::endl;  //fixna preciznost
	std::cout << std::setw(10) << std::setfill('*') << 123 << std::endl;  //ispunjavanje s '*'
	std::cout << std::flush; //isprazni std buffer
}*/