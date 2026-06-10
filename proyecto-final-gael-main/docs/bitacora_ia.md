Bitácora de Uso de Inteligencia Artificial
Introducción

Durante el desarrollo del proyecto final de la asignatura de Estructuras de Datos y Algoritmos I, se utilizó un sistema de inteligencia artificial como herramienta de apoyo técnico y de consulta. Su aplicación se centró en dos áreas principales: el desarrollo de un simulador de sistema operativo implementado en lenguaje C mediante estructuras de datos, y la configuración y gestión del control de versiones utilizando Git y GitHub.

El uso de la inteligencia artificial no se limitó a la obtención de respuestas teóricas, sino que se empleó como un asistente para la resolución de errores en tiempo real, la interpretación de mensajes de compilación, la corrección de problemas de configuración del entorno de desarrollo y la estructuración del flujo de trabajo del proyecto.

Desarrollo del proyecto y apoyo en estructuras de datos

En la etapa inicial del proyecto se trabajó en la implementación de un simulador de sistema operativo basado en estructuras de datos. El sistema incluía módulos de administración de memoria, planificación de procesos y estructuras auxiliares como pilas (stack), colas (queue), colas circulares y listas enlazadas.

Durante esta fase se presentó el primer problema relacionado con la compilación del proyecto en Windows utilizando GCC. El sistema arrojaba errores del tipo “no such file or directory” al intentar compilar archivos ubicados en directorios como src/memory/memory_manager.c. Este error se debía a una estructura de rutas incorrecta o a la ejecución del compilador desde un directorio distinto al raíz del proyecto.

La inteligencia artificial intervino explicando la importancia de mantener una estructura de proyecto modular correctamente organizada, diferenciando carpetas de código fuente (src) y archivos de encabezado (include). Asimismo, se recomendó ejecutar el compilador desde el directorio raíz del proyecto y verificar las rutas relativas utilizadas en el comando de compilación.

Posteriormente, se presentaron dificultades en la implementación de algoritmos de asignación de memoria como First Fit, Best Fit y Worst Fit, así como en la correcta integración de los módulos de simulación. La inteligencia artificial ayudó a comprender la lógica de estos algoritmos, su relación con bloques de memoria y la forma en que debían estructurarse dentro del sistema para evitar inconsistencias en la administración de memoria.

También se trabajó en la incorporación de scripts en Python utilizados para la automatización de pruebas y la generación de métricas de rendimiento mediante benchmarks. En este punto, la inteligencia artificial apoyó en la interpretación del flujo de ejecución de procesos externos desde Python y su integración con el binario del simulador compilado en C.

Gestión del control de versiones con Git y GitHub

Una parte crítica del proyecto fue la configuración del sistema de control de versiones mediante Git y su integración con GitHub. En esta etapa se presentaron múltiples errores técnicos que impidieron inicialmente el correcto flujo de trabajo.

El primer problema fue que el comando git no era reconocido en la terminal de Windows PowerShell. El sistema indicaba que Git no era un comando válido, lo que evidenciaba una instalación incompleta o una configuración incorrecta del PATH del sistema operativo.

La inteligencia artificial explicó que este problema se debía a que, aunque Git estaba instalado, el sistema operativo no tenía registrada su ruta de ejecución. Se recomendó reinstalar Git asegurándose de seleccionar la opción “Git from the command line and also from 3rd-party software”, o en su defecto, agregar manualmente las rutas C:\Program Files\Git\cmd y C:\Program Files\Git\bin al PATH del sistema.

Después de resolver este problema, se presentó un segundo error relacionado con la configuración de identidad de Git. Al intentar realizar el primer commit, el sistema devolvió un mensaje indicando que no era posible detectar el autor del commit. Este problema fue solucionado mediante la configuración global de usuario utilizando los comandos git config --global user.name y git config --global user.email.

Una vez configurado el entorno, se procedió a inicializar el repositorio y conectar el proyecto con GitHub. Durante esta etapa surgió un error común en la gestión de ramas, ya que el repositorio local utilizaba la rama “master”, mientras que GitHub esperaba la rama “main”. Esto provocó errores al intentar realizar el primer push, específicamente el error “src refspec main does not match any”.

La inteligencia artificial explicó que este problema se debía a la discrepancia entre nombres de ramas y recomendó renombrar la rama local utilizando git branch -M main, lo cual estandarizó la estructura del repositorio.

Posteriormente se presentó un error de rechazo al realizar el push hacia GitHub, indicando que el repositorio remoto contenía cambios que no existían localmente. Este problema fue interpretado como un conflicto de historial entre el repositorio local y remoto. La solución consistió en realizar una sincronización previa mediante el comando git pull origin main --rebase, el cual permitió integrar los cambios remotos sin sobrescribir información existente.

Finalmente, tras resolver los conflictos de sincronización, se logró ejecutar correctamente el comando git push, completando la carga del proyecto al repositorio remoto.

Errores encontrados durante el desarrollo

Durante el desarrollo del proyecto se identificaron dos categorías principales de errores. En el ámbito del desarrollo del sistema en C, los errores estuvieron relacionados principalmente con la estructura del proyecto, la ubicación de archivos fuente y de encabezado, y fallos en la compilación derivados de rutas incorrectas. Asimismo, se presentaron dificultades en la integración de módulos de memoria y planificación de procesos, lo cual requería un análisis más profundo del flujo interno del simulador.

En el ámbito del control de versiones, los errores más relevantes incluyeron la falta de reconocimiento del comando Git en el sistema operativo, la ausencia de configuración del PATH, la falta de identidad del usuario en Git, la discrepancia entre ramas locales y remotas, y los conflictos de sincronización entre el repositorio local y GitHub.

Correcciones realizadas

Las correcciones implementadas abarcaron tanto el entorno de desarrollo como la configuración del sistema de control de versiones. En el proyecto en C, se reorganizó la estructura de carpetas para asegurar coherencia entre módulos, se corrigieron rutas de compilación y se verificó la correcta integración de los distintos componentes del simulador.

En cuanto a Git, se realizó la instalación correcta del sistema, la configuración del PATH, la definición de identidad del usuario, la normalización de la rama principal del repositorio y la sincronización completa con GitHub mediante la resolución de conflictos de historial utilizando rebase.

Estas acciones permitieron estabilizar completamente el entorno de desarrollo y asegurar la correcta integración del proyecto con un sistema de control de versiones funcional.

Validaciones realizadas

Una vez aplicadas las correcciones, se realizaron diversas validaciones para confirmar el correcto funcionamiento del sistema. Se verificó la instalación de Git mediante el comando de versión, así como la correcta detección del ejecutable en el sistema operativo. También se validó la conexión con el repositorio remoto mediante la inspección de sus referencias.

En el proyecto de software, se comprobó la compilación correcta de los módulos principales y la ejecución de scripts de prueba diseñados para evaluar el comportamiento del simulador bajo distintas condiciones.

Finalmente, se confirmó que el repositorio en GitHub contenía la versión completa y actualizada del proyecto, incluyendo código fuente, scripts auxiliares, documentación técnica y la presente bitácora de uso de inteligencia artificial.

Conclusión

El uso de inteligencia artificial durante el desarrollo del proyecto permitió resolver problemas técnicos complejos relacionados tanto con la programación en C como con la gestión de control de versiones. Su intervención facilitó la identificación de errores, la comprensión de sus causas y la aplicación de soluciones correctas de manera estructurada.

El resultado final fue un proyecto funcional, correctamente organizado y versionado, que integra conceptos de estructuras de datos, simulación de sistemas operativos y buenas prácticas de desarrollo de software mediante Git y GitHub.