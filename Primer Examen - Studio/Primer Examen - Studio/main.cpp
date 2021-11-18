#include"ContenedoraDob.h"
int main() {
	int op;
	int tamd, tamp;
	string id, id2, nom,cod,gen;
	string nomS;
	float calif, rec;
	cout << "Digite el nombre del estudio" << endl;
	cin >> nomS;
	cout << "Digite el tamanio del vector de directores" << endl;
	cin >> tamd;
	cout << "Digite el tamanio del vector de peliculas" << endl;
	cin >> tamp;
	ContenedoraDob COD(tamd, tamp);
	COD.setNombreStudio(nomS);
	Director* dir = NULL;
	Pelicula* pel = NULL;
	system("pause");
	do {
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t---------------------------------Menu-----------------------------------------" << endl
			<< "\t\t\t1 -Desea insertar un nuevo Director?" << endl
			<< "\t\t\t2 -Desea Mostrar los Directores existentes? " << endl
			<< "\t\t\t3 -Desea insertar la pelicula y vincularlo con un Director?" << endl
			<< "\t\t\t4 -Desea eliminar la pelicula?" << endl
			<< "\t\t\t5 -Desea mostrar las peliculas con sus directores?" << endl
			<< "\t\t\t6 -Desea mostrar las peliculas existentes de un director especifico?" << endl
			<< "\t\t\t7 -Desea calcular el monto total por concepto de caridad?" << endl
			<< "\t\t\t8 -Desea actualizar la calificacion del director?" << endl
			<< "\t\t\t0 -Desea salir del menu?" << endl
			<< "\t\t-------------------------------------------------------------------------------" << endl
			<< "\t\t        Digite su opcion..";
		cin >> op;
		system("cls");
		cout << endl << endl;
		switch (op) {
		case 1:cout << "\t\tDigite la identificacion del director ";
			cin >> id;
			cout << "\t\tDigite el nombre del director ";
			cin >> nom;
			cout << "\t\tLa calificacion del director es: ";
			cin >> calif;
			dir = new Director(id, nom, calif);
			if (COD.insertaDir(dir))
				cout << "\t\tSe pudo ingresar el director" << endl;
			else
				cout << "\t\tNo se pudo ingresar el director" << endl;
			break;
		case 2:cout << COD.toStringDir() << endl;
			break;
		case 3:cout << "\t\tInserte el numero del director al que desea vincular la pelicula: ";
			cin >> id2;
			cout << "\t\tInserte el codigo de la pelicula: ";
			cin >> cod;
			cout << "\t\tInserte el nombre de la pelicula: ";
			cin >> nom;
			cout << "\t\tInserte el genero de la pelicula: ";
			cin >> gen;
			cout << "\t\tInserte la calificacion de la pelicula: ";
			cin >> calif;
			cout << "\t\tInserte el dinero recaudado en miles de dolares de la pelicula: ";
			cin >> rec;
			pel = new Pelicula(cod, nom, gen, calif, rec, dir);
			if (COD.insertaPel(id2, pel))
				cout << "\t\tSe pudo vincular la pelicula con el director" << endl;
			else
				cout << "\t\tNo se pudo vincular la pelicula con el director"<<endl;
			break;
		case 4:cout << "\t\tDigite el codigo de la pelicula que desea eliminar " << endl;
			cin >> id2;
			delete pel;
			pel = NULL;
			if (pel == NULL) {
				cout << "Se pudo eliminar la pelicula" << endl;
			}
			break;
		case 5:cout << COD.toStringPeli() << endl;
			break;
		case 6:cout << "\t\tInserte el numero de identificacion del director que desea buscar: ";
			cin >> id2;
			COD.peliculasDirector(id2);
			break;
		case 7:cout << "\t\tEl monto total recaudado para la caridad en miles de dolares es de: " << COD.totalRecaudadoCaridad() << endl;
			break;
		case 8:cout << "\t\tIngrese el numero de identificacion del director ";
			cin >> id2;
			cout << "\t\tLa calificacion actualizada del director es de: " << COD.califDirector(id2) << endl; 
			calif = COD.califDirector(id2);
			dir->setCalificacion(calif);
			cout << dir->toString() << endl;
			break;
		case 0:
			cout << "\t\t M U C H A S   G R A C I A S" << endl;
		}
		cout << endl << endl << endl;
		cout << "\t\t";
		system("pause");
	} while (op != 0);
	system("pause");
	return 0;
}