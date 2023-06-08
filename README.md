# prog4_2023_gr01

# Laboratorio 4 - Implementacion
Fecha Limite - lunes, 19 de junio de 2023, 15:00

[Letra del laboratorio](https://drive.google.com/file/d/1Y0D_zd7lZzLsieHDqj8DCGuhldjupDoa/view?usp=sharing)

## Funciones de Makefile
- `make` : compila el programa en limpio y lo ejecuta. Equivale a `make clean build run` o `make rerun`

- `make build`: compila el programa
- `make run` : ejecuta el programa
- `make clean` : borra los archivos .o y el ejecutable
- `make valgrind` : ejecuta el programa con valgrind

Ejecutar  para compilar en limpio y ejecutar el programa.
Ejecutar `make clean build valgrind` para compilar en limpio y ejecutar el programa con valgrind.


## Todos los casos de uso
- Alta de usuario :memo: :white_check_mark:
- Consulta de usuario :white_check_mark:
- Alta de idioma :white_check_mark: - [Diagrama de comunicacion](https://lucid.app/lucidchart/bd189033-7811-47d9-8ed5-b375405f4afd/edit?viewport_loc=89%2C-35%2C1966%2C1054%2C0_0&invitationId=inv_79068b57-019b-4de9-a9d3-1806658e2078)
- Consultar idiomas :white_check_mark:
- Alta de curso :memo:
- Agregar lección
- Agregar ejercicio
- Habilitar curso
- Eliminar curso :memo:
- Consultar curso
- Inscribirse a curso
- Realizar ejercicio :memo:
- Consultar estadísticas :memo:
- Suscribirse a notificaciones :memo:
- Consulta de notificaciones :memo: :white_check_mark:
- Eliminar suscripciones :memo:

Los casos de uso marcados con :memo: tienen sus diagramas de comunicacion desde el laboratorio 3.
Los casos de uso marcados con :white_check_mark: estan implementados.

Se debe modificar los archivos .h y .cpp de cada caso de uso, y agregar los archivos .h y .cpp de cada entidad que se necesite.
Despues se tiene que modificar el Makefile para que compile los archivos nuevos.

# Laboratorio 3 - Diseño
- [Documento de Word](https://finguy-my.sharepoint.com/:w:/g/personal/ivan_arriola_fing_edu_uy/ERzphtEka7JFuR_Gi3pB9pABNgsM6_nyMeSTR1DvscjRQQ?e=WfN7dr)
- [Letra PDF](https://drive.google.com/file/d/17chVHTmNlhoKWHBJRXUi1Gq9RBr7hDw0/view?usp=drive_link)
- [Carpeta General de archivos del laboratorio](https://drive.google.com/drive/folders/17ClHWC9tWL7NhrbmM17Po3jbBHjzcfmm?usp=sharing) en Drive para subir las imagenes de los diagramas, los links, archivos de drawio, etc
- [Diagrama De Clase de Diseño](https://lucid.app/lucidchart/3458c2c8-6672-4edd-9548-c3d645f5ea91/edit?invitationId=inv_7c7f22eb-924c-46ee-8132-b38194db2913)

## Diagramas de Comunicacion por Caso de Uso

### Alta de usuario

Diagramas:
- Alta Estudiante
- Ingresar Datos Profesor
- Alta Profesor
- Ingresar Usuario
- Ingresar Datos Estudiante
- Listar Nombres de Idiomas Disponibles
- Seleccionar Idiomas

### Alta de curso


### Eliminar curso
Diagramas:
- Obtener Cursos :question:
- Eliminar Curso

### Realizar ejercicio

Diagramas:
- Ingresar Nickname Estudiante
- Listar Cursos Inscriptos
- MOstrar Cursos No Aprobados
- Seleccionar Curso :question:
- Mostrar Ejercicio No Aprobados
- Seleccionar Ejercicio
- Mostrar Ejercicio
- Ingresar Sol Completar
- Ingresar SOl Traducir
- Marcar Ejercicio Aprobado
- Marcar Ejercicio No Aprobado
- 
### Consultar estadísticas

Diagramas:
- Listar Nicknames Estudiantes :question:
- Seleccionar Estudiante :question:
- Listar Cursos Estudiante 
- Listar Nickname Profesores :question:
- Seleccionar Profesor :question:
- Listar Cursos Profesor
- Listar Cursos :question:
- Seleccionar Curso :question:
- Listar Info Curso

### Suscribirse a notificaciones
Diagramas:
- Listar Idiomas No Suscriptos
- Suscribirse

### Consulta de notificaciones
Diagramas:
- Listar Notificaciones
- Eliminar Notificaciones


### Eliminar suscripciones
Diagramas:
- Listar Idiomas Suscriptos
- Eliminar Suscripcion


# Laboratorio 2 - Analisis 
[Documento de Word](https://onedrive.live.com/edit.aspx?resid=4E0A101CDC8F4A2F!189&ithint=file%2cdocx&authkey=!AKC4te03l7HlkPA)
[Letra de Laboratorio](https://drive.google.com/file/d/1pWrl68r8fAUNFgne8Zzs5a3b1wM2B2w1/view?usp=sharing)

# Laboratorio 1 - Analisis

[Diagrama de Laboratorio 1](https://lucid.app/documents/view/f7ecc9ab-83bd-4ba7-abec-bfbdf07caae4).

