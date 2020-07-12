#include <iostream> //escribimos las librerias y bases del programa
#include <string.h>
using namespace std;

const int longCad = 20;

struct costoXarticulo
{
    char nombreArticulo[longCad + 1];
    int cantidad;
    float preciox;
    float costoPorart;
}; //declaramos la estructura en la que se va a basar nuestro programa

string nombre;
int n; // Cantidad de articulos
float Total = 0.0;
//declaramos las variables afuera para no tener problemas si las usamos en otra funcion o en el main
int funcion1()
{

    cout << endl
         << "ingrese la cantidad de articulos" << endl;
    cin >> n; // declarada antes para poder usar el for del arreglo de productos
    fflush(stdin);

    costoXarticulo productos[n];

    cout << "ingrese el nombre, cantidad y precio de los productos" << endl;

    for (int i = 0; i < n; i++) //usamos un for para poder llenar los arreglos de producto, nombre, cantidad y precio
    {
        cout << "Nombre del producto: ";
        getline(cin, nombre, '\n');
        strncpy(productos[i].nombreArticulo, nombre.c_str(), longCad);
        productos[i].nombreArticulo[longCad] = '\0';
        cout << "Ingrese la cantidad de producto: ";
        cin >> productos[i].cantidad;
        cout << "Ingrese el precio por unidad: ";
        cin >> productos[i].preciox;

        cout << endl;

        fflush(stdin);
    }

    for (int j = 0; j < n; j++)//usamos un for para sacar el costo por articulo de los arreglos
    {
        productos[j].costoPorart = productos[j].preciox * productos[j].cantidad;
    }

    for (int i = 0; i < n; i++)//usamos un for para poder calcular el total
    {
        Total = Total + productos[i].costoPorart;
    }
    cout << "****************************************** " << endl; // esto es meramente estetico para darle ambiente de ticket
    cout << "su factura es: " << endl;
    for (int i = 0; i < n; i++) // usamos otro for para mostrar todos los datos de la factura
    {
        cout << "nombre del articulo: " << productos[i].nombreArticulo << endl;
        cout << "Cantidad: " << productos[i].cantidad << endl;
        cout << "Costo por unidad: " << productos[i].preciox << endl;
        cout << "Costo por articulo: " << productos[i].costoPorart << endl;
    }

    cout << "Su total es de: " << Total << endl;
    cout << "****************************************** " << endl; // esto es meramente estetico para darle ambiente de ticket
}

int main(void)
{
    funcion1(); //llamamos a las funciones porque el programa se ejecuta del main

    return 0;
}