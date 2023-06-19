#include "../../include/controllers/ControladorCurso.h"
#include "../../include/datatypes/DTDataCurso.h"

#include "../../include/classes/Curso/Curso.h"

#include "../../include/handlers/HandlerCurso.h"
#include "../../include/handlers/HandlerUsuario.h"
#include "../../include/handlers/HandlerIdioma.h"

#include "../../include/classes/Curso/Completar.h"
#include "../../include/classes/Curso/Curso.h"
#include "../../include/classes/Curso/Ejercicio.h"
#include "../../include/classes/Curso/Leccion.h"
#include "../../include/classes/Curso/Traducir.h"

#include <string>

using namespace std;

ControladorCurso* ControladorCurso::instancia = NULL;

HandlerCurso* ControladorCurso::coleccionCursos = NULL;
HandlerUsuario* ControladorCurso::coleccionUsuarios = NULL;
HandlerIdioma* ControladorCurso::coleccionIdiomas = NULL;



ControladorCurso::ControladorCurso() {
    ControladorCurso::coleccionCursos = HandlerCurso::getInstancia();
    ControladorCurso::coleccionUsuarios = HandlerUsuario::getInstancia();
    ControladorCurso::coleccionIdiomas = HandlerIdioma::getInstancia();
}

ControladorCurso::~ControladorCurso() {

    if (ControladorCurso::coleccionCursos != NULL) {
        ControladorCurso::coleccionCursos->deleteInstancia();
        ControladorCurso::coleccionCursos = NULL;
    }
    
}

IControladorCurso* ControladorCurso::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorCurso();
    return instancia;
}


set<string> ControladorCurso::listarCursosHabilitados() {

    HandlerCurso *h = HandlerCurso::getInstancia();
    map<string, Curso*> mapCursos = h->obtenerCursos();
    set<string> cursosDisponibles;
    string insertar;

    for(auto it = mapCursos.begin(); it != mapCursos.end(); ++it){
        //Si el curso se encuentra disponible (habilitado) lo agregamos a la lista de cursos
        if(it->second->getDisponible()){
            insertar = it->second->getNombre();
            cursosDisponibles.insert(insertar);
        }
    }

    return cursosDisponibles;
}

void ControladorCurso::seleccionarIdioma(string nombreIdioma) {
    if (coleccionIdiomas->existeIdioma(nombreIdioma))
        this->idiomaCursoActual = coleccionIdiomas->obtenerIdioma(nombreIdioma);
    else
        throw invalid_argument("No existe el idioma");
}


void ControladorCurso::altaCurso(bool disponible) {
    if(coleccionCursos->existeCurso(this->nombreCurso)){
        this->nombreCursoActual = "";
        this->descripcionCursoActual = "";
        this->idiomaCursoActual = NULL;
        this->nicknameProfesorActual = "";
        this->usuarioActual = NULL;
        this->leccionesCursoActual.clear();

        this->ejercicioActual = NULL;
        for (auto it = this->ejerciciosLeccionActual->begin(); it != this->ejerciciosLeccionActual->end(); ++it)
            delete *it;
        this->ejerciciosLeccionActual->clear();
        delete this->ejerciciosLeccionActual;

        throw invalid_argument("Ya existe un curso con ese nombre");
    }else {

        Profesor* profesor = dynamic_cast<Profesor*>(this->usuarioActual);

        //Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones)
        Curso* cursoNuevo = new Curso(this->nombreCursoActual, this->descripcionCursoActual, this->dificultadlCursoActual,
                                        disponible, this->idiomaCursoActual, profesor,
                                        this->leccionesCursoActual);
        coleccionCursos->agregarCurso(cursoNuevo);
    }
}

set<string> ControladorCurso::obtenerCursos() {
    HandlerCurso *h = HandlerCurso::getInstancia();
    map<string, Curso*> mapCursos = h->obtenerCursos();
    set<string> cursos;
    for(auto it = mapCursos.begin(); it != mapCursos.end(); ++it){
        cursos.insert(it->second->getNombre());
    }
    // Implementación de la función obtenerCursos
    // Código para obtener la lista de cursos disponibles
    return cursos;
}

void ControladorCurso::setLeccionActual(Leccion *leccion){
    this->leccionActual = leccion;
}

string ControladorCurso::getNombreCurso() {
    return nombreCurso;
}

set<string> ControladorCurso::getDataCurso() {
    set<string> dataCurso;
    // Implementación de la función getDataCurso
    // Código para obtener los datos del curso seleccionado
    return dataCurso;
}

string ControladorCurso::getNickProfesor() {
    // Implementación de la función getNickProfesor
    string nickProfesor;
    // Código para obtener el nick del profesor del curso seleccionado
    return nickProfesor;
}

set<string> ControladorCurso::getNombresCursosPrevios() {
    set<string> cursosPrevios;
    // Implementación de la función getNombresCursosPrevios
    // Código para obtener los nombres de los cursos previos del curso seleccionado
    return cursosPrevios;
}

set<DTDataLeccion> ControladorCurso::getLecciones() {
    set<DTDataLeccion> lecciones;
    // Implementación de la función getLecciones
    // Código para obtener las lecciones del curso seleccionado
    return lecciones;
}

void ControladorCurso::eliminarCurso(string nombre) {
    HandlerCurso* h= HandlerCurso::getInstancia();
  
    h->eliminarCurso(nombre);
    
    // Implementación de la función eliminarCurso
    // Código para eliminar el curso con el nombre proporcionado
}

void ControladorCurso::agregarLeccion(string tema, string objetivo) {
    Leccion* leccion = new Leccion(tema, objetivo, * this->ejerciciosLeccionActual);
    this->leccionesCursoActual.push_back(leccion);
}

void ControladorCurso::agregarEjercicio(string nombre, string tipoEjercicio, string descEjercicio) {
    if (this->ejerciciosLeccionActual == NULL)
        this->ejerciciosLeccionActual = new set<Ejercicio*>();

    if (tipoEjercicio == "Traducir" ) {
        this->ejercicioActual = new Traducir(nombre, descEjercicio);
        this->ejerciciosLeccionActual->insert(this->ejercicioActual);
        return;
    }
    if (tipoEjercicio == "Completar" ) {
        this->ejercicioActual = new Completar(nombre, descEjercicio);
        this->ejerciciosLeccionActual->insert(this->ejercicioActual);
        return;
    }

    throw invalid_argument("Tipo de ejercicio no válido");
}

void ControladorCurso::agregarLeccionACurso(Leccion *leccion){
    //curso al que queremos agregar leccion
    Curso *curso = coleccionCursos->obtenerCurso(this->nombreCurso);
    curso->agregarLeccion(leccion);
}

void ControladorCurso::ingresarNicknameEstudiante(string nomEstudiante) {
    // Código para ingresar el nickname del estudiante para realizar ejercicios o inscribirse a un curso
    if (coleccionUsuarios->existeUsuario(nomEstudiante)){
        this->nicknameUsuarioActual = nomEstudiante;
        return;
    }

    throw invalid_argument("Nickname no registrado");
}

void ControladorCurso::ingresarDatosCurso(string nombre, string desc, Nivel dificultad) {
    this->nombreCursoActual = nombre;
    this->descripcionCursoActual = desc;
    this->dificultadlCursoActual = dificultad;

    this->nicknameProfesorActual = this->usuarioActual->getNickname();
    
}

set<string> ControladorCurso::listarCursosInscrip() {
    set<string> cursosInscrip;
    // Implementación de la función listarCursosInscrip
    // Código para obtener la lista de cursos disponibles para inscripción
    return cursosInscrip;
}

set<string> ControladorCurso::mostrarCursosNoAprobados() {
    set<string> cursosNoAprobados;
    // Implementación de la función mostrarCursosNoAprobados
    // Código para obtener la lista de cursos no aprobados del estudiante
    return cursosNoAprobados;
}

set<string> ControladorCurso::mostrarEjerciciosNoAprobados() {
    set<string> ejerciciosNoAprobados;
    // Implementación de la función mostrarEjerciciosNoAprobados
    // Código para obtener la lista de ejercicios no aprobados del estudiante
    return ejerciciosNoAprobados;
}

DTEjercicio ControladorCurso::seleccionarEjercicio(string nombreEjercicio) {
    // Implementación de la función seleccionarEjercicio
    // Código para obtener los datos del ejercicio seleccionado por su nombre
    return DTEjercicio();
}

void ControladorCurso::ingresarSolucionCompletar(set<string> solC) {
    // Implementación de la función ingresarSolucionCompletar
    // Código para ingresar la solución del ejercicio de completar en el Controlador de Ejercicio
}

void ControladorCurso::ingresarSolucionTraducir(string solT) {
    // Implementación de la función ingresarSolucionTraducir
    // Código para ingresar la solución del ejercicio de traducción en el Controlador de Ejercicio
}

void ControladorCurso::marcarEjercicioAprobado() {
    // Implementación de la función marcarEjercicioAprobado
    // Código para marcar el ejercicio actual como aprobado en el Controlador de Ejercicio
}

void ControladorCurso::marcarEjercicioNoAprobado() {
    // Implementación de la función marcarEjercicioNoAprobado
    // Código para marcar el ejercicio actual como no aprobado en el Controlador de Ejercicio
}

//Operaciones para Consulta Curso


set<string> ControladorCurso::listarNombreCursos() {
    map<string, Curso*> cursos = ControladorCurso::coleccionCursos->obtenerCursos();
    set<string> nombresCursos;
    for (map<string, Curso*>::iterator it = cursos.begin(); it != cursos.end(); ++it) {
        nombresCursos.insert(it->first);
    }
    return nombresCursos;
}

void ControladorCurso::seleccionarCurso(string nombreCurso) {
    this->nombreCurso = nombreCurso;
}

DTDataCurso* ControladorCurso::mostrarDatosCurso() {
    string nombreCurso = this->nombreCurso;
    Curso * curso = coleccionCursos->obtenerCurso(nombreCurso);
    return curso->getDT();
}

void ControladorCurso::seleccionarProfesor(string nickname) {
    //Averigua si existe el profesor, lo busca en la coleccion de usuarios y lo asigna a usuarioActual
    if (coleccionUsuarios->existeUsuario(nickname)) {
        this->usuarioActual = coleccionUsuarios->obtenerUsuario(nickname);
    } else {
        throw invalid_argument("No existe el profesor");
    }
}

set<string> ControladorCurso::listarCursosNoHabilitados(){
    HandlerCurso* h= HandlerCurso::getInstancia();
    map<string,Curso*> o= h->obtenerCursos();
    set<string> resultado;

    for(map<string,Curso*>::iterator it=o.begin();it!=o.end();++it){
        if(it->second->getDisponible()==false){
            resultado.insert(it->second->getNombre());
        }
    }
    return resultado;
}

vector<string> ControladorCurso::listarLecciones(Curso *curso){
    vector<string> lecciones;
    
    vector<Leccion*> l = curso->getLecciones();
    string tema;

    for(auto it=l.begin(); it != l.end(); ++it){
        tema = (*it)->getTema();
        lecciones.push_back(tema);
    }

    return lecciones;
}

void ControladorCurso::darDeAltaCompletar(string descripcion, string fraseACompletar, vector<string> palabrasFaltantes){
    Leccion *leccion = this->leccionActual;
    leccion->crearEjercicioCompletarYAgregarlo("", descripcion, fraseACompletar, palabrasFaltantes);
}

void ControladorCurso::darDeAltaTraducir(string descripcion, string fraseATraducir, string fraseTraducida){
    Leccion *leccion = this->leccionActual;
    leccion->crearEjercicioTraducirYAgregarlo("", descripcion, fraseATraducir, fraseTraducida);
}

void ControladorCurso::agregarFraseTraducir(string fraseATraducir, string fraseTraducida){
    if (this->ejercicioActual == NULL)
        throw invalid_argument("No hay ejercicio seleccionado");

    Traducir* traducir = dynamic_cast<Traducir*>(this->ejercicioActual);
    if (traducir == NULL)
        throw invalid_argument("El ejercicio seleccionado no es de tipo Traducir");

    traducir->setFraseATraducir(fraseATraducir);
    traducir->setFraseCorrecta(fraseTraducida);
}

void ControladorCurso::agregarFraseCompletar(string fraseACompletar, vector<string> palabras){
    if (this->ejercicioActual == NULL)
        throw invalid_argument("No hay ejercicio seleccionado");

    Completar* completar = dynamic_cast<Completar*>(this->ejercicioActual);
    if (completar == NULL)
        throw invalid_argument("El ejercicio seleccionado no es de tipo Completar");
    completar->setFraseACompletar(fraseACompletar);
    completar->setPalabrasFaltantes(palabras);
}

vector<DTDataCursoAInscribir*> ControladorCurso::obtenerCursosDisponibles(set<string> cursosHabilitados){
    Estudiante* e = dynamic_cast<Estudiante*>(coleccionUsuarios->obtenerUsuario(this->nicknameUsuarioActual));
    vector<DTDataCursoAInscribir*> cursosDisp;
    Curso* curs;
    set<Curso*> cursosPrevios;
    bool estaIns, cd, noTieneCursoPrevio, cursoPrevioAprobado;
    DTDataCursoAInscribir* dcai;
    for (const auto& nomCurs: cursosHabilitados) {
        cd = true;
        //Verifica si el estudiante está inscripto a ese curso
        estaIns = e->estaInscripto(nomCurs);
        if (estaIns){
            cd = false;
        }
        else {
            //Verificar si tiene cursos previos
            curs = coleccionCursos->obtenerCurso(nomCurs);
            noTieneCursoPrevio = curs->getCursosPrevios().empty();
            if (noTieneCursoPrevio){
                cd = true;
            }
            else {
                cursosPrevios = curs->getCursosPrevios();
                for (auto it = cursosPrevios.begin(); (it != cursosPrevios.end()) && cd; ++it){         
                    cursoPrevioAprobado = (*it)->getInscripciones().find(this->nicknameUsuarioActual)->second->getAprobado();
                    if (!cursoPrevioAprobado){
                        cd = false;
                    }
                }
            }  
        }
        if (cd) {
            //Creamos el DTDataCurso con los datos de curs
            dcai = curs->getDTAInscribir();
            //Metemos en el set cursosDisp ese DTDataCurso creado
            cursosDisp.push_back(dcai);
        }
    }
    return cursosDisp;
}

void ControladorCurso::realizarInscripcion(DTDate* fechaInscripcion){
    Estudiante* e = dynamic_cast<Estudiante*> (coleccionUsuarios->obtenerUsuario(this->nicknameUsuarioActual));
    Curso* c = coleccionCursos->obtenerCurso(this->nombreCurso);
    Inscripcion* ins = new Inscripcion(fechaInscripcion, false, e, c);
    e->agregarInscripcion(this->nombreCurso, ins);
    c->agregarInscrip(this->nicknameUsuarioActual, ins);
}