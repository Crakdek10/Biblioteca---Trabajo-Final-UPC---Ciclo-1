//Integrantes: Gerardo Chavez Ayala (U202314672) y Jean Tardio (U202316090) PIN:123
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;
using namespace System;

struct libros
{
	int codigo;
	string titulo;
	string genero;
	float costo;
	string estado;
};

struct sedes
{
	int numero;
	string codigo;
	string nombre;
	string distrito;
	string correo;
};

struct reserva
{
	string sedecodigo;
	string librogenero;
	int librocodigo;
	int DiaRecogida;
	int MesRecogida;
	int A�oRecogida;
	int HoraRecogida;
	int DiaDevolucion;
	int MesDevolucion;
	int A�oDevolucion;
	string estadodevol;
};

void Imprimir_inicio()
{
	int tablero[7][17] =
	{
	{1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1},
	{1 , 1 , 1 , 2 , 2 , 2 , 1 , 2 , 2 , 2 , 1 , 2 , 2 , 2 , 1 , 1 , 1},
	{1 , 1 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 1 , 1},
	{1 , 1 , 1 , 2 , 2 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 2 , 2 , 1 , 1 , 1},
	{1 , 1 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 1 , 1 , 1 , 1},
	{1 , 1 , 1 , 2 , 2 , 2 , 1 , 2 , 1 , 2 , 1 , 2 , 1 , 1 , 1 , 1 , 1},
	{1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1},
	};

	Console::SetCursorPosition(16, 1);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "BIBLIOTECA NACIONAL DEL PERU";
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "===";

	int x = 24, y = 3;

	for (int i = 0; i < 7; i++)
	{
		Console::SetCursorPosition(x, y);
		y++;

		for (int j = 0; j < 17; j++) 
		{
			if (tablero[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::DarkCyan;
				cout << char(219);
			}
			else
				if (tablero[i][j] == 2)
				{
					Console::ForegroundColor = ConsoleColor::White;
					cout << char(219);
				}
		}
		cout << endl << endl;
	}
	Console::SetCursorPosition(27, 11);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "INTEGRANTES";
	Console::SetCursorPosition(22, 12);
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "Gerardo Chavez Ayala";
	Console::SetCursorPosition(23, 13);
	cout << "Jean Carlos Tardio" << endl;
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "Presione";
	_getch();
} 

int menu_general()
{
	int opc1;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	cout << "Bibliota Nacional del Peru";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;;
	cout << "[1]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Informacion (sedes-libros-reservas)" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[2]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Menu para clientes" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[3]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Menu para administradores" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[4]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Salir" << endl;
	Console::ForegroundColor = ConsoleColor::Yellow;
	do { cout << "Que opcion desea? : "; 
	Console::ForegroundColor = ConsoleColor::Blue; 
	cin >> opc1; } while (opc1 < 1 || opc1 > 4); return opc1;
}

void generar_libros(libros* arrlibros, int nlibros)
{
	Random dado;									
	string titulo[] = { "EL JARAMA", "LA VERGUENZA", "PURA PASION", "LA FILOMENA", "CANTO GENERAL", "CREPUSCULARIO", "EDIPO REY", "LA CELESTINA", "LAS NUBES", "ANTIGONA" };
	string genero[] = { "NARRATIVO", "LIRICO", "DRAMATICO" };
	string estado[] = { "DISPONIBLE", "RESERVADO" };
		
	for (int i = 0; i < nlibros; i++)
	{
		arrlibros[i].codigo = 100 + i;
		arrlibros[i].titulo = titulo[dado.Next(0, 10)];
		arrlibros[i].estado = estado[dado.Next(0, 2)];
		
		if (arrlibros[i].titulo == "EL JARAMA" || arrlibros[i].titulo == "LA VERGUENZA" || arrlibros[i].titulo == "PURA PASION")
			arrlibros[i].genero = "NARRATIVO";
		else
			if (arrlibros[i].titulo == "LA FILOMENA" || arrlibros[i].titulo == "CANTO GENERAL" || arrlibros[i].titulo == "CREPUSCULARIO")
				arrlibros[i].genero = "LIRICO";
			else
				arrlibros[i].genero = "DRAMATICO";
		
		if (arrlibros[i].genero == "NARRATIVO")
			arrlibros[i].costo = 20;
		else
			if (arrlibros[i].genero == "DRAMATICO")
				arrlibros[i].costo = 15;
			else
				arrlibros[i].costo = 10;

		_sleep(20);
	}
}

void mostrar_sedes(sedes* arrsedes, int nsedes)
{
	string nombre[4] = { "MONTERRICO", "VILLA", "SAN ISIDRO", "SAN MIGUEL" };
	string distrito[4] = { "SURCO", "CHORRILLOS", "SAN ISIDRO", "SAN MIGUEL" };
	string codigo[4] = { "MO", "VI", "SI", "SM" };
	string correo[4] = { "monterrico@biblio.edu.pe", "villa@biblio.edu.pe", "sanisidro@biblio.edu.pe", "sanmiguel@biblio.edu.pe" };
	int numero[4] = { 7494710, 9816694, 4545338, 6363265 };

	for (int i = 0; i < nsedes; i++)
	{
		arrsedes[i].nombre = nombre[i];
		arrsedes[i].distrito = distrito[i];
		arrsedes[i].codigo = codigo[i];
		arrsedes[i].correo = correo[i];
		arrsedes[i].numero = numero[i];
	}
}

void generar_reservas(reserva* arrreserva, libros* arrlibros, int nlibros, int& nreservas)
{
	Random dado;
	string sedecodigo[] = { "MO", "VI", "SI", "SM" };
	string estadovol[] = { "A TIEMPO", "TARDIO", "EN PROCESO"};
	int PosReserva = 0;

	for (int i = 0; i < nlibros; i++)
	{
		if (arrlibros[i].estado == "RESERVADO")
		{
			nreservas++;
			arrreserva[PosReserva].sedecodigo = sedecodigo[dado.Next(0, 4)];
			arrreserva[PosReserva].A�oRecogida = dado.Next(2022, 2024);
			arrreserva[PosReserva].MesRecogida = dado.Next(01, 12);
			arrreserva[PosReserva].DiaRecogida = dado.Next(01, 26);
			arrreserva[PosReserva].A�oDevolucion = arrreserva[PosReserva].A�oRecogida;
			arrreserva[PosReserva].MesDevolucion = arrreserva[PosReserva].MesRecogida;
			arrreserva[PosReserva].DiaDevolucion = arrreserva[PosReserva].DiaRecogida + 3;
			arrreserva[PosReserva].HoraRecogida = dado.Next(0, 23);
			arrreserva[PosReserva].librocodigo = arrlibros[i].codigo;
			arrreserva[PosReserva].estadodevol = estadovol[dado.Next(0, 3)];
			PosReserva++;
		}
	}
}

void informacion_sedes_libros_reservas(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int nsedes, int nlibros, int nreservas)
{
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Informacion (sedes-libros-reservas)";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;;

	cout << "Listado de sedes: " << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Nombre" << "\t\t" << "Codigo" << "\t" << "Numero" << "\t " << "Distrito" << "\t" << "Correo" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	for (int i = 0; i < nsedes; i++)
	{
		cout << arrsedes[i].nombre;
		if (arrsedes[i].nombre.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrsedes[i].codigo << "\t" << arrsedes[i].numero << "\t " << arrsedes[i].distrito;
		if (arrsedes[i].distrito.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrsedes[i].correo << endl;
	}
	cout << endl;

	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Listado de libros: " << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Codigo" << '\t' << "Titulo" << "\t\t" << "Genero" << "\t\t" << "Costo" << '\t' <<"Estado" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	for (int i = 0; i < nlibros; i++)
	{
		cout << arrlibros[i].codigo << "\t" << arrlibros[i].titulo;
		if (arrlibros[i].titulo.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrlibros[i].genero;
		if (arrlibros[i].genero.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrlibros[i].costo << '\t';
		if (arrlibros[i].estado == "RESERVADO")
		{
			Console::ForegroundColor = ConsoleColor::Red;
			cout << arrlibros[i].estado << endl;
		}
		else
			if (arrlibros[i].estado == "DISPONIBLE")
			{
				Console::ForegroundColor = ConsoleColor::Green;
				cout << arrlibros[i].estado << endl;
			}
			else
			{
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << arrlibros[i].estado << endl;
			}
		Console::ForegroundColor = ConsoleColor::White;
	}
	cout << endl;

	if (nreservas > 0)
	{
		Console::ForegroundColor = ConsoleColor::Green;	
		cout << "Historial de reservas: " << endl;
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Sede" << '\t' << "Libro" << "\t" << "Reservado" << "\t" << "Max devolucion" << "\t" << "Hora" << "\t" << "Estado" << endl;
		Console::ForegroundColor = ConsoleColor::White;

		for (int i = 0; i < nreservas; i++)
		{
			cout << arrreserva[i].sedecodigo << '\t' << arrreserva[i].librocodigo << '\t';
			cout << "(" << arrreserva[i].DiaRecogida << "/" << arrreserva[i].MesRecogida << "/" << arrreserva[i].A�oRecogida << ")" << '\t';
			cout << "(" << arrreserva[i].DiaDevolucion << "/" << arrreserva[i].MesDevolucion << "/" << arrreserva[i].A�oDevolucion << ")" << '\t';
			if (arrreserva[i].HoraRecogida < 12)
				cout << arrreserva[i].HoraRecogida << "am" << '\t';
			else
				cout << arrreserva[i].HoraRecogida << "pm" << '\t';

            if (arrreserva[i].estadodevol == "A TIEMPO")
            {
                Console::ForegroundColor = ConsoleColor::Green;
                cout << arrreserva[i].estadodevol << endl;
            }
            else if (arrreserva[i].estadodevol == "TARDIO")
            {
                Console::ForegroundColor = ConsoleColor::Red;
                cout << arrreserva[i].estadodevol << endl;
            }
            else if (arrreserva[i].estadodevol == "PERDIDO")
            {
                Console::ForegroundColor = ConsoleColor::Yellow;
                cout << arrreserva[i].estadodevol << endl;
            }
            else
            {
                Console::ForegroundColor = ConsoleColor::White;
                cout << arrreserva[i].estadodevol << endl;
            }
            Console::ForegroundColor = ConsoleColor::White;
		}
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "No hay reservas registradas" << endl;
	}
}

int menu_clientes()
{
	int opc2;

	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Menu para clientes";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	cout << "[1]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reservar una reserva" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[2]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Registro de devolucion" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[3]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "salir" << endl;
	Console::ForegroundColor = ConsoleColor::Yellow;
	do { cout << "Que opcion desea? : "; 
	Console::ForegroundColor = ConsoleColor::Blue;
	cin >> opc2; } while (opc2 < 1 || opc2 > 3); return opc2;
}

void Reservar_una_reserva(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int nsedes, int nlibros, int nreservas)
{
	int diasultimoEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int diaspenultimoEnMes[] = { 30, 27, 30, 29, 30, 29, 30, 30, 29, 30, 29, 30 };
	int diasantepenultimoEnMes[] = { 29, 26, 29, 28, 29, 28, 29, 29, 28, 29, 28, 29 };
	bool GeneroValido = false, CodigoValido = false, SedeValido = false;

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reservar una reserva";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	cout << "Listado de libros: " << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Codigo" << '\t' << "Titulo" << "\t\t" << "Genero" << "\t\t" << "Costo" << '\t' << "Estado" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	for (int i = 0; i < nlibros; i++)
	{
		if (arrlibros[i].estado == "DISPONIBLE")
		{
			cout << arrlibros[i].codigo << "\t" << arrlibros[i].titulo;
			if (arrlibros[i].titulo.length() < 8)
				cout << "\t\t";
			else
				cout << "\t";
			cout << arrlibros[i].genero;
			if (arrlibros[i].genero.length() < 8)
				cout << "\t\t";
			else
				cout << "\t";
			cout << arrlibros[i].costo << '\t';
			Console::ForegroundColor = ConsoleColor::Green;
			cout << arrlibros[i].estado << endl;
			Console::ForegroundColor = ConsoleColor::White;
		}
	}
	cout << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	do
	{
		cout << "Ingrese el genero literario (NARRATIVO, LIRICO, DRAMATICO) del libro: ";
		cin >> arrreserva[nreservas].librogenero;
		cout << endl;

		for (int i = 0; i < nlibros; i++)
			if (arrreserva[nreservas].librogenero == arrlibros[i].genero && arrlibros[i].estado == "DISPONIBLE")
				GeneroValido = true;
	} while (GeneroValido == false);

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reservar una reserva";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	cout << "Listado de libros: " << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Codigo" << '\t' << "Titulo" << "\t\t" << "Costo" << '\t' << "Estado" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	for (int i = 0; i < nlibros; i++)
		if (arrreserva[nreservas].librogenero == arrlibros[i].genero && arrlibros[i].estado == "DISPONIBLE")
		{
			cout << arrlibros[i].codigo << '\t' << arrlibros[i].titulo;
			if (arrlibros[i].titulo.length() < 8)
				cout << "\t\t";
			else
				cout << "\t";
			cout << arrlibros[i].costo << '\t';
			Console::ForegroundColor = ConsoleColor::Green;
			cout << arrlibros[i].estado << endl;
			Console::ForegroundColor = ConsoleColor::White;
		}
	cout << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	do
	{
		cout << "Ingrese el codigo del libro a reservar: ";
		cin >> arrreserva[nreservas].librocodigo;
		cout << endl;

		for (int i = 0; i < nlibros; i++)
			if (arrreserva[nreservas].librocodigo == arrlibros[i].codigo && arrreserva[nreservas].librogenero == arrlibros[i].genero && arrlibros[i].estado == "DISPONIBLE")
				CodigoValido = true;
	} while (CodigoValido == false);

	for (int i = 0; i < nlibros; i++)
		if (arrreserva[nreservas].librocodigo == arrlibros[i].codigo)
		{
			Console::ForegroundColor = ConsoleColor::White;
			cout << "El libro ";
			Console::ForegroundColor = ConsoleColor::Green;
			cout << arrlibros[i].titulo;
			Console::ForegroundColor = ConsoleColor::White;
			cout << " fue seleccionado" << endl;
		}
	_sleep(2000);

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reservar una reserva";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	do
	{
		cout << "Ingrese la fecha (DIA MES ANO) actual de reserva del libro: ";
		cin >> arrreserva[nreservas].DiaRecogida >> arrreserva[nreservas].MesRecogida >> arrreserva[nreservas].A�oRecogida;
		cout << endl;
	} while (arrreserva[nreservas].DiaRecogida < 1 || arrreserva[nreservas].DiaRecogida > 31
		|| arrreserva[nreservas].MesRecogida < 1 || arrreserva[nreservas].MesRecogida > 12
		|| arrreserva[nreservas].A�oRecogida < 1900 || arrreserva[nreservas].A�oRecogida > 2023
		|| (arrreserva[nreservas].DiaRecogida > 31 && (arrreserva[nreservas].MesRecogida == 1
		|| arrreserva[nreservas].MesRecogida == 3 || arrreserva[nreservas].MesRecogida == 5
		|| arrreserva[nreservas].MesRecogida == 7 || arrreserva[nreservas].MesRecogida == 8
		|| arrreserva[nreservas].MesRecogida == 10 || arrreserva[nreservas].MesRecogida == 12))
		|| (arrreserva[nreservas].DiaRecogida > 30 && (arrreserva[nreservas].MesRecogida == 4
		|| arrreserva[nreservas].MesRecogida == 6 || arrreserva[nreservas].MesRecogida == 9
		|| arrreserva[nreservas].MesRecogida == 11)) || (arrreserva[nreservas].DiaRecogida > 28
		&& arrreserva[nreservas].MesRecogida == 2));

	do
	{
		cout << "Ingrese la hora (00-23) actual de reserva del libro: ";
		cin >> arrreserva[nreservas].HoraRecogida;
		cout << endl;
	} while (arrreserva[nreservas].HoraRecogida < 0 || arrreserva[nreservas].HoraRecogida > 23);

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reservar una reserva";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	cout << "Listado de sedes: " << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Nombre" << "\t\t" << "Codigo" << "\t" << "Numero" << "\t " << "Distrito" << "\t" << "Correo" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	for (int i = 0; i < nsedes; i++)
	{
		cout << arrsedes[i].nombre;
		if (arrsedes[i].nombre.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrsedes[i].codigo << "\t" << arrsedes[i].numero << "\t " << arrsedes[i].distrito;
		if (arrsedes[i].distrito.length() < 8)
			cout << "\t\t";
		else
			cout << "\t";
		cout << arrsedes[i].correo << endl;
	}
	cout << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	do
	{
		cout << "Ingrese el codigo de la sede donde recogera el libro: ";
		cin >> arrreserva[nreservas].sedecodigo;
		cout << endl;
		for (int i = 0; i < nsedes; i++)
			if (arrreserva[nreservas].sedecodigo == arrsedes[i].codigo)
				SedeValido = true;
	} while (SedeValido == false);

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reserva reservada";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reserva exitosa, procesando boleta";
	_sleep(500);
	cout << ".";
	_sleep(500);
	cout << ".";
	_sleep(500);
	cout << ".";
	_sleep(1000);

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reserva reservada";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::DarkBlue;
	cout << "DATOS DE LA RESERVA";
	_sleep(650);
	cout << endl << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Codigo de la sede: ";
	_sleep(500);
	cout << "\t\t";
	Console::ForegroundColor = ConsoleColor::White;
	cout << arrreserva[nreservas].sedecodigo;
	_sleep(520);
	cout << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Codigo del libro: ";
	_sleep(490);
	cout << "\t\t";
	Console::ForegroundColor = ConsoleColor::White;
	cout << arrreserva[nreservas].librocodigo;
	_sleep(520);
	cout << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Fecha de reserva: ";
	_sleep(490);
	cout << "\t\t";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "(" << arrreserva[nreservas].DiaRecogida << "/" << arrreserva[nreservas].MesRecogida << "/" << arrreserva[nreservas].A�oRecogida << ")" << endl;
	_sleep(520);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Hora de la reserva: ";
	_sleep(490);
	cout << "\t\t";
	Console::ForegroundColor = ConsoleColor::White;

	if (arrreserva[nreservas].HoraRecogida < 12)
		cout << arrreserva[nreservas].HoraRecogida << "am" << endl;
	else
		cout << arrreserva[nreservas].HoraRecogida << "pm" << endl;
	_sleep(520);

	if (arrreserva[nreservas].DiaRecogida == diasultimoEnMes[arrreserva[nreservas].MesRecogida - 1])
	{
		arrreserva[nreservas].DiaDevolucion = 3;
		arrreserva[nreservas].MesDevolucion = arrreserva[nreservas].MesRecogida + 1;
	}
	else
		if (arrreserva[nreservas].DiaRecogida == diaspenultimoEnMes[arrreserva[nreservas].MesRecogida - 1])
		{
			arrreserva[nreservas].DiaDevolucion = 2;
			arrreserva[nreservas].MesDevolucion = arrreserva[nreservas].MesRecogida + 1;
		}
		else
			if (arrreserva[nreservas].DiaRecogida == diasantepenultimoEnMes[arrreserva[nreservas].MesRecogida - 1])
			{
				arrreserva[nreservas].DiaDevolucion = 1;
				arrreserva[nreservas].MesDevolucion = arrreserva[nreservas].MesRecogida + 1;
			}
			else
			{
				arrreserva[nreservas].DiaDevolucion = arrreserva[nreservas].DiaRecogida + 3;
				arrreserva[nreservas].MesDevolucion = arrreserva[nreservas].MesRecogida;
			}
	if (arrreserva[nreservas].MesDevolucion > 12)
	{
		arrreserva[nreservas].MesDevolucion = 1;
		arrreserva[nreservas].A�oDevolucion = arrreserva[nreservas].A�oRecogida + 1;
	}
	else
	{
		arrreserva[nreservas].A�oDevolucion = arrreserva[nreservas].A�oRecogida;
	}
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Fecha max de devolucion: ";
	_sleep(490);
	cout << '\t';
	Console::ForegroundColor = ConsoleColor::White;
	cout << "(" << arrreserva[nreservas].DiaDevolucion << "/" << arrreserva[nreservas].MesDevolucion << "/" << arrreserva[nreservas].A�oDevolucion << ")" << endl;
	_sleep(520);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Hora max de devolucion: ";
	_sleep(490);
	cout << '\t';
	Console::ForegroundColor = ConsoleColor::White;
	if (arrreserva[nreservas].HoraRecogida < 12)
		cout << arrreserva[nreservas].HoraRecogida << "am" << endl;
	else
	{
		cout << arrreserva[nreservas].HoraRecogida << "pm" << endl;
	}

	for (int i = 0; i < nlibros; i++)
		if (arrreserva[nreservas].librocodigo == arrlibros[i].codigo)
			arrlibros[i].estado = "RESERVADO";

	arrreserva[nreservas].estadodevol = "EN PROCESO";

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

int Registro_de_devolucion()
{
	char respPD;

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registro de devolucion";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	do { cout << "Ingrese si devolvera (D) o si perdio (P) el libro: "; cin >> respPD; cout << endl; } while (respPD != 'D' && respPD != 'P');
	return respPD;
}

void libro_perdido(libros* arrlibros, reserva* arrreserva, int nlibros, int nreservas)
{
	int codigoperdido;
	bool Comprobarcodigoperdido = false;

	if (nreservas == 0)
	{
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "Todavia no hay reservas, por favor reserva un libro";
		cout << endl;
	}
	else
	{
		do
		{
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "Ingrese el codigo del libro: ";
			cin >> codigoperdido;
			cout << endl;
			for (int i = 0; i < nlibros; i++)
				if (codigoperdido == arrlibros[i].codigo && arrlibros[i].estado == "RESERVADO")
					for (int j = 0; j < nreservas; j++)
						if (arrreserva[j].librocodigo == codigoperdido && arrreserva[j].estadodevol == "EN PROCESO")
						{
							Comprobarcodigoperdido = true;
							arrlibros[i].estado = "PERDIDO";
							arrreserva[j].estadodevol = "PERDIDO";
						}
			if (Comprobarcodigoperdido == false)
				Console::ForegroundColor = ConsoleColor::Red;
				cout << "Este codigo no es valido" << endl << endl;
				Console::ForegroundColor = ConsoleColor::Yellow;
		} while (Comprobarcodigoperdido == false);

		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===";
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registro de devolucion";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===" << endl << endl;
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registrando perdida";
		_sleep(500);
		cout << ".";
		_sleep(500);
		cout << ".";
		_sleep(500);
		cout << "." << endl << endl;
		_sleep(1000);
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "Se le esta enviando un reporte al correo de la sede";
		_sleep(700);
		cout << ".";
		_sleep(700);
		cout << ".";
		_sleep(700);
		cout << ".";

		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===";
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registro de devolucion";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===" << endl << endl;

		for (int i = 0; i < nlibros; i++)
			if (codigoperdido == arrlibros[i].codigo)
			{
				_sleep(1000);
				Console::ForegroundColor = ConsoleColor::Blue;
				cout << "DATOS DE LA DEVOLUCION" << endl << endl;
				_sleep(700);
				Console::ForegroundColor = ConsoleColor::White;
				cout << "La multa a pagar es de ";
				Console::ForegroundColor = ConsoleColor::Red;
				cout << arrlibros[i].costo;
				Console::ForegroundColor = ConsoleColor::White;
				cout << " soles";
				cout << endl;
			}
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void libro_devuelto(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int nsedes, int nlibros, int& nreservas)
{
	int codigolibroDevolucion, diaDevolucion, mesDevolucion, a�oDevolucion, horaDevolucion;
	string codigosedeDevolucion;
	bool ComprobarcodigosedeDevolucion = false, ComprobarcodigolibroDevolucion = false, Comprobarfecha = false, Comprobarhora = false;

	if (nreservas == 0)
	{
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===";
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registro de devolucion";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===" << endl << endl;

		Console::ForegroundColor = ConsoleColor::Red;
		cout << "Todavia no hay reservas, por favor reserva un libro";
		cout << endl;
	}
	else
	{
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===";
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registro de devolucion";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===" << endl << endl;

		cout << "Listado de sedes: " << endl;
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Nombre" << "\t\t" << "Codigo" << "\t" << "Numero" << "\t " << "Distrito" << "\t" << "Correo" << endl;
		Console::ForegroundColor = ConsoleColor::White;

		for (int i = 0; i < nsedes; i++)
		{
			cout << arrsedes[i].nombre;
			if (arrsedes[i].nombre.length() < 8)
				cout << "\t\t";
			else
				cout << "\t";
			cout << arrsedes[i].codigo << "\t" << arrsedes[i].numero << "\t " << arrsedes[i].distrito;
			if (arrsedes[i].distrito.length() < 8)
				cout << "\t\t";
			else
				cout << "\t";
			cout << arrsedes[i].correo << endl;
		}
		cout << endl;
		Console::ForegroundColor = ConsoleColor::Yellow;

		do
		{
			cout << "Ingrese el codigo de la sede donde reservo: ";
			cin >> codigosedeDevolucion;
			cout << endl;
			for (int i = 0; i < nreservas; i++)
				if (codigosedeDevolucion == arrreserva[i].sedecodigo)
					ComprobarcodigosedeDevolucion = true;
		} while (ComprobarcodigosedeDevolucion == false);

		cout << "Ingrese el codigo del libro: ";
		cin >> codigolibroDevolucion;
		cout << endl;
		for (int i = 0; i < nreservas; i++)
			if (codigolibroDevolucion == arrreserva[i].librocodigo && codigosedeDevolucion == arrreserva[i].sedecodigo 
				&& arrreserva[i].estadodevol == "EN PROCESO")
				ComprobarcodigolibroDevolucion = true;

		Console::Clear();
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===";
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "Registro de devolucion";
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "===" << endl << endl;
		Console::ForegroundColor = ConsoleColor::Yellow;

		if (ComprobarcodigolibroDevolucion == false)
		{
			Console::ForegroundColor = ConsoleColor::Red;
			cout << "Codigo o sede incorrectos!" << endl;
		}
		else
		{
			Console::ForegroundColor = ConsoleColor::Green;
			cout << "Historial de reservas: " << endl;
			Console::ForegroundColor = ConsoleColor::Blue;
			cout << "Sede" << '\t' << "Libro" << "\t" << "Reservado" << "\t" << "Max devolucion" << "\t" << "Hora" << endl;
			Console::ForegroundColor = ConsoleColor::White;
			for (int i = 0; i < nreservas; i++)
			{
				if (codigosedeDevolucion == arrreserva[i].sedecodigo && codigolibroDevolucion == arrreserva[i].librocodigo)
				{
					cout << arrreserva[i].sedecodigo << '\t' << arrreserva[i].librocodigo << '\t';
					cout << "(" << arrreserva[i].DiaRecogida << "/" << arrreserva[i].MesRecogida << "/" << arrreserva[i].A�oRecogida << ")" << '\t';
					cout << "(" << arrreserva[i].DiaDevolucion << "/" << arrreserva[i].MesDevolucion << "/" << arrreserva[i].A�oDevolucion << ")" << '\t';
					if (arrreserva[i].HoraRecogida < 12)
						cout << arrreserva[i].HoraRecogida << "am" << endl << endl;
					else
						cout << arrreserva[i].HoraRecogida << "pm" << endl << endl;
				}
			}

			Console::ForegroundColor = ConsoleColor::Yellow;
			do
			{
				cout << "Ingrese la fecha actual (DIA MES ANO) de devolucion: ";
				cin >> diaDevolucion >> mesDevolucion >> a�oDevolucion;
				cout << endl;
				for (int i = 0; i < nreservas; i++)
					if ((a�oDevolucion == arrreserva[i].A�oRecogida && mesDevolucion == arrreserva[i].MesRecogida && diaDevolucion >= arrreserva[i].DiaRecogida)
						|| (a�oDevolucion == arrreserva[i].A�oRecogida && mesDevolucion > arrreserva[i].MesRecogida)
						|| (a�oDevolucion > arrreserva[i].A�oRecogida && mesDevolucion <= arrreserva[i].MesRecogida))
						if (codigolibroDevolucion == arrreserva[i].librocodigo && codigosedeDevolucion == arrreserva[i].sedecodigo)
							Comprobarfecha = true;
			} while (Comprobarfecha == false || diaDevolucion < 1 || diaDevolucion > 31 || mesDevolucion < 1 || mesDevolucion > 12
						|| a�oDevolucion < 1900 || a�oDevolucion > 2023 || (diaDevolucion > 31 && (mesDevolucion == 1
						|| mesDevolucion == 3 || mesDevolucion == 5 || mesDevolucion == 7 || mesDevolucion == 8
						|| mesDevolucion == 10 || mesDevolucion == 12)) || (diaDevolucion > 30 && (mesDevolucion == 4
						|| mesDevolucion == 6 || mesDevolucion == 9 || mesDevolucion == 11)) || (diaDevolucion > 28
						&& mesDevolucion == 2));

			do
			{
				cout << "Ingrese la hora (00-23) de devolucion: ";
				cin >> horaDevolucion;
				cout << endl;
				for (int i = 0; i < nreservas; i++)
					if (!(a�oDevolucion == arrreserva[i].A�oRecogida && mesDevolucion == arrreserva[i].MesRecogida && diaDevolucion == arrreserva[i].DiaRecogida
						&& horaDevolucion < arrreserva[i].HoraRecogida))
						if (codigolibroDevolucion == arrreserva[i].librocodigo && codigosedeDevolucion == arrreserva[i].sedecodigo)
							Comprobarhora = true;
			} while (Comprobarhora == false || horaDevolucion < 0 || horaDevolucion > 23);

			for (int i = 0; i < nreservas; i++)
				if (codigolibroDevolucion == arrreserva[i].librocodigo && codigosedeDevolucion == arrreserva[i].sedecodigo)
				{
					if (a�oDevolucion < arrreserva[i].A�oDevolucion ||
						(a�oDevolucion == arrreserva[i].A�oDevolucion && mesDevolucion < arrreserva[i].MesDevolucion) ||
						(a�oDevolucion == arrreserva[i].A�oDevolucion && mesDevolucion == arrreserva[i].MesDevolucion &&
						(diaDevolucion < arrreserva[i].DiaDevolucion ||
						(diaDevolucion == arrreserva[i].DiaDevolucion && horaDevolucion <= arrreserva[i].HoraRecogida))))
					{
						Console::ForegroundColor = ConsoleColor::White;
						cout << "No se aplica ninguna multa." << endl;

						arrreserva[i].estadodevol = "A TIEMPO";
					}
					else
						{
							Console::ForegroundColor = ConsoleColor::White;
							cout << "Se aplica una multa de"; 
							Console::ForegroundColor = ConsoleColor::Red;
							cout << " 10 soles ";
							Console::ForegroundColor = ConsoleColor::White;
							cout << "por devolucion tardia" << endl; 

							arrreserva[i].estadodevol = "TARDIO";
						}
				}
				for (int i = 0; i < nlibros; i++)
					if (codigolibroDevolucion == arrlibros[i].codigo)
						arrlibros[i].estado = "DISPONIBLE";
		}
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

int menu_administradores()
{
	int opc3;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Menu para administradores";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[1]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Registrar libros" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[2]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Registrar sedes" << endl << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[3]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte de recaudacion semanal" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[4]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte de libros devueltos y perdidos" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[5]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte de libros reservados por genero literario" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[6]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte de ingresos totales por sede" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[7]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte del genero con menor y mayor popularidad" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[8]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Reporte de la sede con mayor recaudacion" << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "[9]";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "Salir" << endl;
	Console::ForegroundColor = ConsoleColor::Yellow;
	do { cout << "Que opcion desea? : "; 
	Console::ForegroundColor = ConsoleColor::Blue;
	cin >> opc3; } while (opc3 < 1 || opc3 > 9); return opc3;
}

void Registrar_libros(libros* arrlibros, int nlibros)
{
	bool ComprobarCodigo = false, encontrado = false;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registrar libros";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "Ingrese el titulo del libro a registrar: ";
	cin.ignore();
	getline(cin, arrlibros[nlibros].titulo);
	cout << endl;

	do
	{
		encontrado = false;
		cout << "Ingrese el codigo del libro: ";
		cin >> arrlibros[nlibros].codigo;
		cout << endl;

		for (int i = 0; i < nlibros; i++)
			if (arrlibros[nlibros].codigo == arrlibros[i].codigo)
				encontrado = true;
		if (encontrado == true)
		{
			Console::ForegroundColor = ConsoleColor::Red;
			cout << "El codigo ingresado ya existe" << endl << endl;
			Console::ForegroundColor = ConsoleColor::Yellow;
		}
		else
			ComprobarCodigo = true;
	} while (ComprobarCodigo == false);

	do
	{
		cout << "Ingrese el genero literario (NARRATIVO, LIRICO, DRAMATICO) del libro a registrar: ";
		cin.ignore();
		getline(cin, arrlibros[nlibros].genero);
		cout << endl;
	} while (arrlibros[nlibros].genero != "NARRATIVO" && arrlibros[nlibros].genero != "LIRICO" && arrlibros[nlibros].genero != "DRAMATICO");

	cout << "Ingrese el costo del libro: ";
	cin >> arrlibros[nlibros].costo;

	arrlibros[nlibros].estado = "DISPONIBLE";

	_sleep(600);
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registrar libros";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registro de libro exitoso!!";
	cout << endl;
	nlibros++;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Registrar_sedes(sedes* arrsedes, int nsedes)
{
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registrar sedes";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "Ingrese el nombre de la sede a registrar: ";
	cin.ignore();
	getline(cin, arrsedes[nsedes].nombre);
	cout << endl;

	do
	{
		cout << "Ingrese el codigo (2 digitos) de la sede: ";
		cin >> arrsedes[nsedes].codigo;
		cout << endl;
	} while (arrsedes[nsedes].codigo.length() != 2);

	do
	{
		cout << "Ingrese el numero de telefono (7 digitos) de la sede: ";
		cin >> arrsedes[nsedes].numero;
		cout << endl;
	} while (arrsedes[nsedes].numero < 1000000 || arrsedes[nsedes].numero > 9999999);

	cout << "Ingrese el distrito de la sede: ";
	cin.ignore();
	getline(cin, arrsedes[nsedes].distrito);
	cout << endl;

	cout << "Ingrese el correo (XXXXX@biblio.edu.pe) de la sede: ";
	cin >> arrsedes[nsedes].correo;
	_sleep(600);
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registrar sedes";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Registro de sede exitoso!!";
	cout << endl;
	nsedes++;			

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_recaudacion_semanal(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int sedes, int nlibros, int nreservas)
{
	string sede;
	int mes, recaudacion1 = 0, recaudacion2 = 0, recaudacion3 = 0, recaudacion4 = 0;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de recaudacion semanal";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	cout << "Ingrese el codigo de la sede para el reporte: ";
	cin >> sede;
	cout << "Ingrese el mes (1-12) para el reporte: ";
	cin >> mes;

	for (int i = 0; i < nreservas; i++)
	{
		if (arrsedes[i].codigo == sede && arrreserva[i].MesDevolucion == mes)
		{
			int semana = (arrreserva[i].DiaDevolucion - 1) / 7 + 1;

			for (int j = 0; j < nlibros; j++)
			{
				if (arrreserva[i].librocodigo == arrlibros[j].codigo)
				{
					if (arrreserva[i].estadodevol == "TARDIO")
						recaudacion1 += 10;
					if (arrreserva[i].estadodevol == "PERDIDO")
						recaudacion1 += arrlibros[j].costo;
					break;
				}
			}

			if (semana == 2)
				recaudacion2 += recaudacion1;
			else if (semana == 3)
				recaudacion3 += recaudacion1;
			else if (semana == 4)
				recaudacion4 += recaudacion1;
		}
	}
	cout << "Semana 1: " << recaudacion1 << endl;
	cout << "Semana 2: " << recaudacion2 << endl;
	cout << "Semana 3: " << recaudacion3 << endl;
	cout << "Semana 4: " << recaudacion4 << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_porcentaje_libros(libros* arrlibros, reserva* arrreserva, int nlibros, int nreservas)
{
	int contTiempo = 0, contTarde = 0, contperdidos = 0, suma = 0, a�o, mes;

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de libros devueltos y perdidos";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "Ingrese el ano para generar el reporte: ";
	cin >> a�o;

	cout << "Ingrese el mes para generar el reporte: ";
	cin >> mes;

	for (int i = 0; i < nreservas; i++)
	{
		if (arrreserva[i].A�oDevolucion == a�o && arrreserva[i].MesDevolucion == mes)
		{
			if (arrreserva[i].estadodevol == "A TIEMPO" || arrreserva[i].estadodevol == "TARDIO" || arrreserva[i].estadodevol == "PERDIDO")
				suma++;
			if (arrreserva[i].estadodevol == "A TIEMPO")
				contTiempo++;
			else
				if (arrreserva[i].estadodevol == "TARDIO")
					contTarde++;
				else
					if (arrreserva[i].estadodevol == "PERDIDO")
						contperdidos++;
		}
	}
	cout << endl;
	if (suma > 0)
	{
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "Porcentaje de libros entregados a tiempo: ";
		Console::ForegroundColor = ConsoleColor::White;
		cout << contTiempo * 100.0 / suma << "%" << endl;
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "Porcentaje de libros entregados tarde: ";
		Console::ForegroundColor = ConsoleColor::White;
		cout << contTarde * 100.0 / suma << "%" << endl;
		Console::ForegroundColor = ConsoleColor::Green;
		cout << "Porcentaje de libros perdidos: ";
		Console::ForegroundColor = ConsoleColor::White;
		cout << contperdidos * 100.0 / suma << "%" << endl;
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "NO HAY RESERVAS HECHAS PARA EL MES Y ANO ESPECIFICADOS" << endl;
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_x_genero(libros* arrlibros, int nlibros)
{
	int contN = 0, contL = 0, contD = 0;
	string genero;
	for (int i = 0; i < nlibros; i++)
		if (arrlibros[i].estado == "RESERVADO")
			if (arrlibros[i].genero == "NARRATIVO")
				contN++;
			else
				if (arrlibros[i].genero == "LIRICO")
					contL++;
				else
					contD++;

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de libros reservados por genero literario";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;
	
	cout << "Cantidad de Libros narrativos: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << contN << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Cantidad de Libros liricos: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << contL << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Cantidad de Libros dramaticos: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << contD << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_ingresos_totales(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int nlibros, int nsedes, int nreservas)
{
	int a�o, ingresototalMO = 0, ingresototalVI = 0, ingresototalSI = 0, ingresototalSM = 0, tarde = 0, perdido = 0, aux;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de ingresos totales por sede";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "Ingrese el ano para ver los ingresos totales: ";
	cin >> a�o;
	cout << endl;

	for (int i = 0; i < nreservas; i++)
		if (arrreserva[i].sedecodigo == "MO" && arrreserva[i].A�oDevolucion == a�o)
		{
			if (arrreserva[i].estadodevol == "TARDIO")
				ingresototalMO += 10;
			else if (arrreserva[i].estadodevol == "PERDIDO")
				for (int j = 0; j < nlibros; j++)
					if (arrlibros[j].estado == "PERDIDO")
						ingresototalMO += arrlibros[j].costo;
		} else
			if (arrreserva[i].sedecodigo == "VI" && arrreserva[i].A�oDevolucion == a�o)
			{
				if (arrreserva[i].estadodevol == "TARDIO")
					ingresototalVI += 10;
				else if (arrreserva[i].estadodevol == "PERDIDO")
					for (int j = 0; j < nlibros; j++)
						if (arrlibros[j].estado == "PERDIDO")
							ingresototalVI += arrlibros[j].costo;
			} else
				if (arrreserva[i].sedecodigo == "SI" && arrreserva[i].A�oDevolucion == a�o)
				{
					if (arrreserva[i].estadodevol == "TARDIO")
						ingresototalSI += 10;
					else if (arrreserva[i].estadodevol == "PERDIDO")
						for (int j = 0; j < nlibros; j++)
							if (arrlibros[j].estado == "PERDIDO")
								ingresototalSI += arrlibros[j].costo;
				}
				else
					if (arrreserva[i].sedecodigo == "SM" && arrreserva[i].A�oDevolucion == a�o)
					{
						if (arrreserva[i].estadodevol == "TARDIO")
							ingresototalSM += 10;
						else if (arrreserva[i].estadodevol == "PERDIDO")
							for (int j = 0; j < nlibros; j++)
								if (arrlibros[j].estado == "PERDIDO")
									ingresototalSM += arrlibros[j].costo;
					}

	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Ingreso total por sede MO: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << ingresototalMO << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Ingreso total por sede VI: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << ingresototalVI << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Ingreso total por sede SI: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << ingresototalSI << endl;
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "Ingreso total por sede SM: ";
	Console::ForegroundColor = ConsoleColor::White;
	cout << ingresototalSM << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_popularidad_generos(libros* arrlibros, int nlibros)
{
	int contN = 0, contL = 0, contD = 0;
	string genero;
	for (int i = 0; i < nlibros; i++)
		if (arrlibros[i].estado == "RESERVADO")
			if (arrlibros[i].genero == "NARRATIVO")
				contN++;
			else
				if (arrlibros[i].genero == "LIRICO")
					contL++;
				else
					contD++;

	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de libros reservados por genero literario";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	if (contN >= contL && contN >= contD) cout << "El genero con mayor popularidad es el NARRATIVO" << endl;
	if (contL >= contN && contL >= contD) cout << "El genero con mayor popularidad es el LIRICO" << endl;
	if (contD >= contN && contD >= contL) cout << "El genero con mayor popularidad es el DRAMATICO" << endl;

	if (contN <= contL && contN <= contD) cout << "El genero con menor popularidad es el NARRATIVO" << endl;
	if (contL <= contN && contL <= contD) cout << "El genero con menor popularidad es el LIRICO" << endl;
	if (contD <= contN && contD <= contL) cout << "El genero con menor popularidad es el DRAMATICO" << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void Reporte_menor_mayor_recaudacion(libros* arrlibros, sedes* arrsedes, reserva* arrreserva, int nlibros, int nsedes, int nreservas)
{
	int a�o, ingresototalMO = 0, ingresototalVI = 0, ingresototalSI = 0, ingresototalSM = 0, tarde = 0, perdido = 0, aux;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===";
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "Reporte de ingresos totales por sede";
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "===" << endl << endl;

	for (int i = 0; i < nreservas; i++)
		if (arrreserva[i].sedecodigo == "MO")
		{
			if (arrreserva[i].estadodevol == "TARDIO")
				ingresototalMO += 10;
			else if (arrreserva[i].estadodevol == "PERDIDO")
				for (int j = 0; j < nlibros; j++)
					if (arrlibros[j].estado == "PERDIDO")
						ingresototalMO += arrlibros[j].costo;
		}
		else
			if (arrreserva[i].sedecodigo == "VI")
			{
				if (arrreserva[i].estadodevol == "TARDIO")
					ingresototalVI += 10;
				else if (arrreserva[i].estadodevol == "PERDIDO")
					for (int j = 0; j < nlibros; j++)
						if (arrlibros[j].estado == "PERDIDO")
							ingresototalVI += arrlibros[j].costo;
			}
			else
				if (arrreserva[i].sedecodigo == "SI")
				{
					if (arrreserva[i].estadodevol == "TARDIO")
						ingresototalSI += 10;
					else if (arrreserva[i].estadodevol == "PERDIDO")
						for (int j = 0; j < nlibros; j++)
							if (arrlibros[j].estado == "PERDIDO")
								ingresototalSI += arrlibros[j].costo;
				}
				else
					if (arrreserva[i].sedecodigo == "SM")
					{
						if (arrreserva[i].estadodevol == "TARDIO")
							ingresototalSM += 10;
						else if (arrreserva[i].estadodevol == "PERDIDO")
							for (int j = 0; j < nlibros; j++)
								if (arrlibros[j].estado == "PERDIDO")
									ingresototalSM += arrlibros[j].costo;
					}

	Console::ForegroundColor = ConsoleColor::Green;
	if (ingresototalMO >= ingresototalVI && ingresototalMO >= ingresototalSI && ingresototalMO >= ingresototalSM) cout << "La sede MO tiene la mayor recaudacion" << endl;
	if (ingresototalVI >= ingresototalMO && ingresototalVI >= ingresototalSI && ingresototalVI >= ingresototalSM) cout << "La sede VI tiene la mayor recaudacion" << endl;
	if (ingresototalSI >= ingresototalMO && ingresototalSI >= ingresototalVI && ingresototalSI >= ingresototalSM) cout << "La sede SI tiene la mayor recaudacion" << endl;
	if (ingresototalSM >= ingresototalMO && ingresototalSM >= ingresototalVI && ingresototalSM >= ingresototalSI) cout << "La sede SM tiene la mayor recaudacion" << endl;

	if (ingresototalMO <= ingresototalVI && ingresototalMO <= ingresototalSI && ingresototalMO <= ingresototalSM) cout << "La sede MO tiene la menor recaudacion" << endl;
	if (ingresototalVI <= ingresototalMO && ingresototalVI <= ingresototalSI && ingresototalVI <= ingresototalSM) cout << "La sede VI tiene la menor recaudacion" << endl;
	if (ingresototalSI <= ingresototalMO && ingresototalSI <= ingresototalVI && ingresototalSI <= ingresototalSM) cout << "La sede SI tiene la menor recaudacion" << endl;
	if (ingresototalSM <= ingresototalMO && ingresototalSM <= ingresototalVI && ingresototalSM <= ingresototalSI) cout << "La sede SM tiene la menor recaudacion" << endl;

	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << endl << endl;
	_sleep(2000);
	cout << "Presione para retroceder";
	_getch();
}

void main()
{
	int opciones, opc2, opc3, opcD;
	int PIN;
	int nsedes = 4;
	int nlibros = 15;
	int nreservas = 0;
	libros* arrlibros = new libros[20];
	sedes* arrsedes = new sedes[10];
	reserva* arrreserva = new reserva[50];

	Imprimir_inicio();
	generar_libros(arrlibros, nlibros);
	mostrar_sedes(arrsedes, nsedes);
	generar_reservas(arrreserva, arrlibros, nlibros, nreservas);
	do
	{
		Console::Clear();
		opciones = menu_general();

		switch (opciones)
		{
		case 1:
			Console::Clear();
			informacion_sedes_libros_reservas(arrlibros, arrsedes, arrreserva, nsedes, nlibros, nreservas);
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << endl << endl;
			_sleep(2000);
			cout << "Presione para retroceder";
			_getch();
			break;

		case 2:
			Console::Clear();
			opc2 = menu_clientes();
			switch (opc2)
			{
			case 1:
				Reservar_una_reserva(arrlibros, arrsedes, arrreserva, nsedes, nlibros, nreservas);
				nreservas++;
				break;
			case 2:
				opcD = Registro_de_devolucion();
				switch (opcD)
				{
				case 'P':
					libro_perdido(arrlibros, arrreserva, nlibros, nreservas);
					break;
				case 'D':
					libro_devuelto(arrlibros, arrsedes, arrreserva, nsedes, nlibros, nreservas);
					break;
				}
				break;
			case 3:
				_sleep(1000);
				cout << endl;
				cout << "Usted esta retrocediendo";
				_sleep(500);
				cout << ".";
				_sleep(500);
				cout << ".";
				_sleep(500);
				cout << ".";
				_sleep(700);
			}
			break;

		case 3:
			Console::Clear();
			Console::ForegroundColor = ConsoleColor::Green;
			cout << "===";
			Console::ForegroundColor = ConsoleColor::Blue;
			cout << "Menu para administradores";
			Console::ForegroundColor = ConsoleColor::Green;
			cout << "===" << endl << endl;
			Console::ForegroundColor = ConsoleColor::White;
			cout << "Ingrese PIN de administrador: ";
			Console::ForegroundColor = ConsoleColor::Blue;
			cin >> PIN;
			if (PIN == 123)
			{
				opc3 = menu_administradores();
				switch (opc3)
				{
				case 1:
					Registrar_libros(arrlibros, nlibros);
					nlibros++;
					break;
				case 2:
					Registrar_sedes(arrsedes, nsedes);
					nsedes++;
					break;
				case 3:
					Reporte_recaudacion_semanal(arrlibros, arrsedes, arrreserva, nsedes, nlibros, nreservas);
					break;
				case 4:
					Reporte_porcentaje_libros(arrlibros, arrreserva, nlibros, nreservas);
					break;
				case 5:
					Reporte_x_genero(arrlibros, nlibros);
					break;
				case 6:
					Reporte_ingresos_totales(arrlibros, arrsedes, arrreserva, nlibros, nsedes, nreservas);
					break;
				case 7:
					Reporte_popularidad_generos(arrlibros, nlibros);
					break;
				case 8:
					Reporte_menor_mayor_recaudacion(arrlibros, arrsedes, arrreserva, nlibros, nsedes, nreservas);
					break;
				case 9:
					_sleep(1000);
					cout << endl;
					cout << "Usted esta retrocediendo";
					_sleep(500);
					cout << ".";
					_sleep(500);
					cout << ".";
					_sleep(500);
					cout << ".";
					_sleep(700);
				}
			}
			else
			{
				cout << endl;
				Console::ForegroundColor = ConsoleColor::Red;
				cout << "Codigo incorrecto" << endl;
				_sleep(1300);
			}
			break;
		case 4:
			Console::Clear();
			cout << endl;
			Console::ForegroundColor = ConsoleColor::Blue;
			cout << "Usted salio del programa." << endl << endl;
			_sleep(1600);
		}
	} while (opciones != 4);

	delete[] arrlibros;
	delete[] arrsedes;
	delete[] arrreserva;
}