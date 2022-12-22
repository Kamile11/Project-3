#include "header.h"

void ivestis(data& a, int& n)
{
	string anw; //ats: suvesti ar generuoti pazymius
	char x; //skirtas patikrinti ar ivedamas pazymys yra skaicius
	int y = 0; // generacija/suvedimas

	string vardas, pavarde;
	cout << "Iveskite varda: "; cin >> vardas;
	a.setvard(vardas);
	cout << "Iveskite pavarde: "; cin >> pavarde;
	a.setpav(pavarde);
	cout << "Ar atsitiktinai sugeneruoti pazymius ? [y/n] "; cin >> anw;

	int pazymys, egzaminas, pazi;

	do
	{

		if ((anw == "n") || (anw == "N")) //rankiniu budu ivedami pazymiai
		{
			n = 1;
			cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite: [s] " << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "Iveskite " << i + 1 << " pazymi: ";
				cin >> x;
				if ((x == 's') || (x == 'S'))//jei iveda [s]
				{
					if (n > 1) //daugiau nebegalima vesti pazymiu
					{
						break;
					}
					else
					{
						cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite : [s]" << endl; //ivesta maziau nei vienas pazymys
						i--;
					}
				}
				else
				{
					if (isdigit(x)) //tiktina ar ivesta reiksme skaicius
					{
						pazymys = x - 48;
						a.setpaz(i, pazymys);
						n++;
					}
					else
					{
						cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite : [s]" << endl; //ivede ne skaiciu
						i--;
					}

				}
			}
			n--;
			cout << "Iveskite egzamino ivertinima: "; cin >> egzaminas;
			a.setegz(egzaminas);

			y++;
		}
		else if ((anw == "y") || (anw == "Y"))//generuoja atsitinktinai pazymiai
		{
			using hrClock = std::chrono::high_resolution_clock;
			std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
			std::uniform_int_distribution<int> dist(1, 10);

			n = dist(mt);

			for (int i = 0; i < n; i++) {
				pazi = dist(mt);
				a.setpaz(i, pazi);
			}

			egzaminas = dist(mt);
			a.setegz(egzaminas);

			y++;
		}
		else
		{
			cout << "Ar atsitiktinai generuoti pazymius? [y/n] "; cin >> anw;
		}
	} while (y == 0);

}
void rezultatai(data& a)
{
	cout << setw(20) << a.getvard() << " | " << setw(20) << a.getpav() << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.getvid() << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.getmed() << endl;
}
bool rikiavimas(const data& a, const data& b)
{
	return a.getvard() < b.getvard();
}
void galutinisvid(data& a, int& n) //su vidurkiu
{
	double vid;
	int suma;

	vid = 0;
	suma = 0;

	int pazymys;
	double vidurkis;

	for (int i = 0; i < n; i++)
	{
		suma += a.getpaz(i);
	}

	vid = suma / (double)(n);

	vidurkis = 0.4 * vid + 0.6 * a.getegz();
	a.setvid(vidurkis);
}
void galutinismed(data& a, int& n, vector<data>& sarasas)//su mediana
{
	double med;
	double mediana;

	//sort(a.getpaz(), a.getpaz() + n);

	if (n % 2 != 0)
	{
		med = (double)a.getpaz(n/2);
	}
	else
	{
		med = (double)(a.getpaz((n-1)/2) + a.getpaz(n/2)) / 2;
	}

	mediana = 0.4 * med + 0.6 * a.getegz();
	a.setmed(mediana);

}
void fskaitymas(data&a, int& n, vector<data>& sarasas, vector<data>& kietiakai, vector<data>& vargsiukai)
{
	//----------------------------------------------------------------------
	int r;
	cout << "Iveskite failo pavadinima: " << endl; cin >> r;
	string file = to_string(r) + ".txt";
	std::ifstream open_f(file);

	string anwf;
	string anwn;
	int m = 0;
	int z = 0;
	
	Timer t2;
		string tittle; //zodzio string
		while (tittle != "Egz.") {
			open_f >> tittle;
			if (tittle == "Egz.") break;
			else if (tittle.substr(0, 2) == "ND") {
				m++;
			}
		}
		string vardas, pavarde;
		int pazymys, egzaminas;
		while (open_f) {
			if (!open_f.eof()) {

				std::getline(open_f, vardas, ' ');
				a.setvard(vardas);
				std::getline(open_f, pavarde, ' ');
				a.setpav(pavarde);

				for (int i = 0; i < m; i++)
				{
					open_f >> pazymys;
					a.setpaz(i, pazymys);
				}
				open_f >> egzaminas;
				a.setegz(egzaminas);

				galutinisvid(a, m);

				//galutinismed(a, m);

				sarasas.push_back(a);
				z++;


			}
			else break;
		}

		open_f.close();
		cout << "Duomenu nuskaitymas is failo ir galutinio pazymio suskaiciavimas: " << t2.elapsed() << " s" << endl;
		

		sort(sarasas.begin(), sarasas.end(), rikiavimas);

		Timer t1;
		for (int i = 0; i < sarasas.size() - 1; i++)
		{

			if (sarasas[i].getvid() < 5.0)
			{
				vargsiukai.push_back(sarasas[i]);
			}
			else if (sarasas[i].getvid() >= 5.0)
			{
				kietiakai.push_back(sarasas[i]);
			}
		}
		cout << "Studentu isskirstymas i du vektorius: " << t1.elapsed() << " s" << endl;
		

		//------------------------------------------------------------------------
		std::ofstream out_f("vargsiukai.txt");
		out_f << std::left << setw(20) << "Vardas" << "| ";
		out_f << setw(20) << "Pavarde" << " | ";
		out_f << setw(20) << "Galutinis (Vid.)" << endl;
		out_f << "-----------------------------------------------------------------------------------------------------";

		std::ofstream out_k("kietiakiai.txt");
		out_k << std::left << setw(20) << "Vardas" << "| ";
		out_k << setw(20) << "Pavarde" << " | ";
		out_k << setw(20) << "Galutinis (Vid.)" << endl;
		out_k << "-----------------------------------------------------------------------------------------------------";

		


		Timer t3;
		for (int i = 1; i < vargsiukai.size(); i++)
		{
			out_f << setw(20) << vargsiukai[i].getvard() << " | " << setw(20) << vargsiukai[i].getpav() << " | ";

			out_f << setw(20) << setprecision(2) << fixed << vargsiukai[i].getvid() << " | ";

		}
		for (int i = 1; i < kietiakai.size(); i++)
		{

			out_k << setw(20) << kietiakai[i].getvard() << " | " << setw(20) << kietiakai[i].getpav() << " | ";

			out_k << setw(20) << setprecision(2) << fixed << kietiakai[i].getvid() << " | ";

		}
		out_k.close();
		out_f.close();
		
		cout << "Studentu isvedimas i du naujus failus: " << t3.elapsed() << " s" << endl;

}
void firasimas(data& a, int& n, vector<data>& sarasas)
{
	std::ofstream out_f("kursiokai_cop.txt");

	out_f << std::left << setw(20) << "Vardas" << "| ";
	out_f << setw(20) << "Pavarde" << " | ";
	out_f << setw(20) << "Galutinis (Vid.)" << " | ";
	out_f << setw(20) << "Galutinis (Med.)" << endl;
	out_f << "-----------------------------------------------------------------------------------------------------";

	for (int i = 0; i < sarasas.size(); i++) //ispauzdinimas i faila
	{
		out_f << setw(20) << sarasas[i].getvard() << " | " << setw(20) << sarasas[i].getpav() << " | ";

		out_f << setw(20) << setprecision(2) << fixed << sarasas[i].getvid() << " | ";

		out_f << setw(20) << setprecision(2) << fixed << sarasas[i].getmed();
	}
	out_f.close();

}
void generacija(std::stringstream& my_buffer, int& n, int &s) //n - studentai, s - paz
{

	//---
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);
	//---
	
	string var = "Vardas", pav = "Pavarde";
	string nd = "ND", egz = "Egz.";
	
	Timer t1;
	
		my_buffer << var << " " << pav << " ";
		for (int j = 0; j < s; j++)
		{
			my_buffer << nd << j + 1 << " ";
		}
		my_buffer << egz << endl;
		

		for (int k = 0; k < n; k++)
		{
			my_buffer << var << k + 1 << " " << pav << k + 1 << " ";
			for (int j = 0; j < s; j++) my_buffer << dist(mt) << " "; //pazymiai
			my_buffer << dist(mt) << endl; //egz paz;
		}
		string file = to_string(n) + ".txt";
		std::ofstream out_f(file);
		out_f << my_buffer.str();
		out_f.close();
		cout << n << " Failo kurimas ir jo uzdarimas " << t1.elapsed() << " s" << endl;
		my_buffer.clear();
}
