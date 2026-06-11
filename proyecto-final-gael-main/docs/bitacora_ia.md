Bitácora de Uso de Inteligencia Artificial
Introducción

Durante el desarrollo del proyecto final de la asignatura de Estructuras de Datos y Algoritmos I, se utilizó inteligencia artificial como herramienta de apoyo técnico para la resolución de problemas, depuración de código, comprensión de errores y gestión del control de versiones. Su uso fue constante a lo largo del desarrollo del simulador de sistema operativo y durante la configuración del repositorio en GitHub.

Prompts utilizados

Durante el desarrollo del proyecto, los prompts utilizados estuvieron enfocados en dos áreas principales: la construcción del sistema en C y la resolución de problemas relacionados con Git y GitHub.

En la parte del desarrollo del sistema, se realizaron consultas relacionadas con la estructura del proyecto, la organización de archivos en carpetas como src e include, errores de compilación con GCC en Windows y la implementación de estructuras de datos como pilas, colas y listas enlazadas. También se solicitaron explicaciones sobre algoritmos de asignación de memoria como First Fit, Best Fit y Worst Fit, así como apoyo en la integración de módulos del simulador y en la ejecución de scripts en Python para pruebas y benchmarks.

En la parte de control de versiones, los prompts estuvieron relacionados con la instalación de Git, errores al ejecutar comandos en PowerShell, configuración del PATH del sistema, inicialización de repositorios, sincronización con GitHub, errores de ramas (master y main), y conflictos al realizar push y pull entre repositorios locales y remotos.

Respuestas generadas por la IA

La inteligencia artificial proporcionó explicaciones detalladas y soluciones paso a paso para cada problema presentado.

En el área de desarrollo del sistema, explicó cómo estructurar correctamente un proyecto modular en C, cómo organizar los archivos fuente y de encabezado, y cómo corregir errores de compilación derivados de rutas incorrectas. También ayudó a comprender la lógica de los algoritmos de asignación de memoria y su implementación dentro del simulador.

En el área de Git y GitHub, la IA explicó cómo instalar Git correctamente en Windows, cómo configurar el PATH del sistema, cómo verificar la instalación mediante comandos como git --version, y cómo inicializar y conectar un repositorio local con GitHub. Además, proporcionó soluciones a errores comunes como la falta de configuración de usuario, el conflicto entre ramas master y main, el error “src refspec main does not match any” y los problemas de sincronización entre repositorios locales y remotos mediante git pull --rebase.

Errores encontrados

Durante el desarrollo del proyecto se presentaron diversos errores técnicos.

En el desarrollo del sistema en C, se encontraron errores de compilación debido a rutas incorrectas de archivos fuente, especialmente en módulos dentro del directorio src/memory. También se presentaron problemas en la organización del proyecto, lo que generó dificultades para compilar correctamente todos los módulos del simulador. Adicionalmente, hubo complicaciones en la integración de estructuras de datos y en la ejecución de scripts de prueba.

En el uso de Git, los errores más relevantes fueron que el comando git no era reconocido en PowerShell, lo que indicaba una instalación incompleta o falta de configuración del PATH. También se presentó un error al realizar commits debido a la falta de configuración de identidad del usuario. Posteriormente, surgieron conflictos relacionados con la rama principal del repositorio, ya que el proyecto local utilizaba master mientras que GitHub utilizaba main. Finalmente, se presentó un error de rechazo al realizar push debido a diferencias entre el historial local y remoto.

Correcciones realizadas

Las correcciones en el desarrollo del sistema incluyeron la reorganización de la estructura de carpetas del proyecto, la corrección de rutas de compilación en GCC, y la integración adecuada de los módulos de memoria, procesos y planificación. También se ajustó la lógica de algunos componentes para asegurar la coherencia del simulador.

En cuanto a Git, se realizó la instalación correcta del sistema, la configuración del PATH en Windows, la definición de la identidad del usuario mediante git config, la corrección de la rama principal del repositorio mediante git branch -M main, y la sincronización del repositorio local con GitHub utilizando git pull origin main --rebase para resolver conflictos de historial. Finalmente, se logró realizar el push exitoso del proyecto completo.

Validaciones realizadas

Se realizaron validaciones en distintos niveles del proyecto.

En el sistema de control de versiones, se verificó la correcta instalación de Git mediante el comando git --version, así como la correcta detección del ejecutable en el sistema. También se validó la conexión con el repositorio remoto mediante git remote -v y la correcta sincronización del historial de cambios con GitHub.

En el sistema desarrollado en C, se validó la correcta compilación de los módulos principales del simulador y la ejecución de pruebas mediante scripts automatizados. Finalmente, se confirmó que el repositorio en GitHub contenía la versión completa y actualizada del proyecto, incluyendo código fuente, documentación y la bitácora de inteligencia artificial.

Conclusión

El uso de inteligencia artificial permitió resolver problemas técnicos complejos relacionados tanto con el desarrollo del sistema en C como con la configuración del control de versiones en Git y GitHub. Su apoyo fue fundamental para identificar errores, comprender sus causas y aplicar soluciones correctas de manera estructurada, logrando la correcta finalización e integración del proyecto.