#include <iostream>

using std::cout, std::endl;

class Termostat
{
	int temperature;
	static int counter;
	//jakby z max_temperature zrobic pole statyczne(dodac static przed int const)
	//to nie mozna by tam potem korzystac z list inicjalizayjnych i zmieniac wartosco
	//max_temp
	int const max_temperature  ;
	int measureTemperature()
	{
		cout<<"Mierze temperature otoczenia"<<endl;
		return 21;
	}

	public:
	static void showCount()
	{
		cout<<"Liczba termostatow: "<<counter<<endl;
	}
	void showMaxTemperature()
	{
		cout<<"Max temperatura termostatu wynosi T_max = "<<max_temperature<<endl;
	}

	//konstruktor z domyslna max wartosc temp
	Termostat() : max_temperature(28)
	{
		temperature=measureTemperature();
		showMaxTemperature();
		counter++;

	}
	//konstruktor z mozliwoscia ustawienia max temp przy wykorzystaniu listy inicjalizacyjnej przy konstruktorze
	Termostat(int max_temperature) : max_temperature(max_temperature)
	{
		temperature = measureTemperature();
		showMaxTemperature();
		counter++;
	}
	void showTemperature()
	{
		cout<<"T = "<<temperature<<endl;
	}
	void increaseTemperature()
	{
		if(temperature <= max_temperature)
		{
			temperature++;
		}
		else
			cout<<"blad increase"<<endl;
	}
	void decreaseTemperature()
	{
		if(temperature >= 1)
		{
			temperature--;
		}
		else
			cout<<"blad decrease"<<endl;
	}
	//Destruktor
	~Termostat()
	{
		cout<<"Termostat zostal usuniety"<<endl;
		counter--;
	}

};
int Termostat::counter = 0;

int main()
{
	//wykorzystanie konstuktora z podaniem max_temp
	Termostat termostat(30);
	//wykorzystanie konstuktora z domyslna max_temp
	Termostat t2;
	//sprawdzenie metod
	t2.showTemperature();
	termostat.showTemperature();
	termostat.increaseTemperature();
	termostat.showTemperature();
	//sprawdzenie metod i czy dzialaja ograniczenia na metody
	for (int i=1; i<30; i++)
	{
		termostat.decreaseTemperature();
		termostat.showTemperature();
	};
	for (int j=1; j<40; j++)
	{
		termostat.increaseTemperature();
		termostat.showMaxTemperature();
		termostat.showTemperature();
		Termostat t;
		t.increaseTemperature();
	};
	Termostat::showCount();

}
