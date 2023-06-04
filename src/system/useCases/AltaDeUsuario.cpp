#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"


using namespace std;

/*
  Nombre **Alta de usuario**
  Actores **Usuario**
  Sinopsis: El caso de uso comienza cuando se desea dar de alta un usuario en el sistema.
  El Usuario ingresa un nickname (pseudónimo), una contraseña (de al menos 6 caracteres), un nombre y una descripción.
  En caso de tratarse de un estudiante, se ingresa también el nombre del país donde reside,
  mientras que, si se trata de un profesor, se ingresa el nombre del instituto donde trabaja.
  Además, el Sistema lista los idiomas disponibles para que el Usuario seleccione aquellos en los que se especializa el profesor.
  El Usuario debe seleccionar al menos un idioma.
  Finalmente, el Sistema da de alta el nuevo usuario con los datos ingresados.
  En caso de que ya exista en el sistema un usuario con el nickname ingresado,
  el Sistema comunica el error y no se da de alta el usuario.
*/

void Sistema::altaDeUsuario() {
  imprimirMensaje("Alta de Usuario");

  // Ingresar nickname 
  string nickname = ingresarParametro("el nickname");

  // Ingresar password
  string password;
  do {
    password = ingresarParametro("el password");
    if (password.length() < 6) {
      cout << "El password debe tener al menos 6 caracteres" << endl;
    }
  } while (password.length() < 6);

  // Ingresar nombre
  string nombre = ingresarParametro("el nombre");

  // Ingresar descripcion
  string descripcion = ingresarParametro("la descripcion");

  // Imprimir datos ingresados
  cout << "Datos ingresados: " << endl;
  cout << "Nickname: " << nickname << endl;
  cout << "Password: " << password << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Descripcion: " << descripcion << endl;

  try {
    controladorUsuario->ingresarUsuario(nickname, password, nombre, descripcion);
  } catch (invalid_argument &e) {
    imprimirMensaje("Error: " + string(e.what()));
    imprimirMensaje("No se puede crear el usuario");
    return;
  }


  cout << "Tipo de usuario: " << endl;
  cout << "0. Profesor" << endl;
  cout << "1. Estudiante" << endl;

  int tipoUsuario = ingresarOpcion(1);

  if (tipoUsuario == 0) { // Profesor
  
    string instituto = ingresarParametro("el instituto");
    controladorUsuario->ingresarDatosProfesor(instituto);

    cout << "Lista de Idiomas disponibles " << endl;
    set<string> idiomas = controladorUsuario->listarNombresDeIdiomasDisponibles();
    

    if(idiomas.size() == 0){
      imprimirMensaje("No hay idiomas disponibles");
      imprimirMensaje("No se puede crear un profesor");
      return;
    }

    imprimirSet(idiomas, "Idiomas");

    set<string> idiomasSeleccionados;

    imprimirMensaje("Ingrese los idiomas en los que se especializa el profesor");
    imprimirMensaje("Ingrese los idiomas uno por uno");
    imprimirMensaje("Ingrese 0 para terminar de ingresar idiomas");

    string idioma;
    do {
      idioma = ingresarParametro("el idioma");
      if (idioma != "0") {
        idiomasSeleccionados.insert(idioma);
      }
    } while (idioma != "0");

    controladorUsuario->altaProfesor(idiomasSeleccionados);
    cout << "Profesor creado con exito" << endl;
    
  } else if (tipoUsuario == 1) { // Estudiante
    cout << "Ingrese el pais: ";
    string pais;
    cin >> pais;
    controladorUsuario->ingresarDatosEstudiante(pais);
    controladorUsuario->altaEstudiante();
    cout << "Estudiante creado con exito" << endl;
  }
}
