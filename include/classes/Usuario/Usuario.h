#ifndef USUARIO
#define USUARIO

#include <set>
#include <string>
#include <vector>

#include "../../datatypes/DTNotificacion.h"
#include "../../datatypes/DTDataCursoProfesor.h"

using namespace std;

/*Clase Abstracta*/
class Usuario {
  private:
    string nickname;
    string contrasenia;
    string nombre;
    string descripcion;
    vector<DTNotificacion> notificacionesRecibidas;
    void agregarNotificacion(DTNotificacion notificacion);

  public:
    Usuario();
    Usuario(string nickname, string contrasenia, string nombre, string descripcion);

    // Getters
    string getNickname();
    string getContrasenia();
    string getNombre();
    string getDescripcion();
    vector<DTNotificacion> getNotificacionesRecibidas();

    // Setters
    void setNickname(string nickname);
    void setContrasenia(string contrasenia);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);

    // Operaciones
    void enviarNotificacion(string nombreCurso, string nombreIdioma);
    virtual bool esProfesor() = 0;
    virtual set<string> obtenerIdiomas() = 0;
    void eliminarNotificacionesRecibidas();
    virtual bool esEstudiante() = 0;
    virtual set<DTDataCursoProfesor> getCursosProfesor() = 0;

    virtual ~Usuario();

};

#endif