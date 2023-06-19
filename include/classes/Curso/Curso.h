#ifndef CURSO
#define CURSO

#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

#include "../../enums/NIVEL.h"

#include "Leccion.h"
#include "../Idioma.h"
#include "../Usuario/Profesor.h"
#include "../Inscripcion.h"

#include "../../datatypes/DTDataCurso.h"
#include "../../datatypes/DTDataCursoAInscribir.h"

class Curso {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        bool disponible;

        //pseudoatributos
        vector<Leccion*> lecciones; // Las lecciones tienen ejercicios / Las lecciones estan ordenadas
        Idioma* idioma;
        Profesor* profesor;
        set<Curso*> cursosPrevios;

        map<string, Inscripcion*> inscripciones; // nicknameEstudiante, Inscripcion

    public:
        Curso();
        Curso(string nombre, string descripcion, Nivel nivel, bool disponible);
        Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones);
        // Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones, set<Curso*> cursosPrevios);

        // Getters
        string getNombre();
        string getDescripcion();
        Nivel getNivel();
        bool getDisponible();
        vector<Leccion*> getLecciones();
        set<Curso*> getCursosPrevios();

        map<string, Inscripcion*> getInscripciones();

        DTDataCurso* getDT();
        DTDataCursoAInscribir* getDTAInscribir();

        // Setters
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setNivel(Nivel nivel);
        void setDisponible(bool disponible);
        void setCursosPrevios(set<Curso*> cursosPrevios);

        // Operaciones
        set<string> obtenerEjNoAprobados();
        void agregarLeccion(Leccion* leccion);
        // void agregarCursoPrevio(Curso* cursoPrevio);
        float getCantEjsTotal();
        float calcPromedioAvance();
        int getCantLecciones();
        void agregarInscrip(string nickE, Inscripcion* i);

        ~Curso();

};

#endif 