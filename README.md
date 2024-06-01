# Graficador Geométrico

Este proyecto ha sido desarrollado para el curso de Programación 1 en la Facultad de Ingeniería de la UMG, utilizando el IDE CodeBlocks y programado en C++. El objetivo principal es crear una aplicación capaz de graficar diversas figuras geométricas con interacciones específicas basadas en la posición del cursor y las dimensiones de la pantalla, empleando conocimientos fundamentales de C++ como vectores, ciclos, manejo de archivos, y punteros.

## Características del Proyecto

### Fase 1
La primera fase del proyecto introduce las funcionalidades básicas, donde se pueden graficar las siguientes figuras geométricas:

- **Triángulo**: Se solicita al usuario el tamaño de la base y se grafica un triángulo equilátero orientado hacia abajo desde la posición actual del cursor.
- **Cuadrado**: Se solicita el tamaño de un lado y se dibuja desde la esquina superior izquierda indicada por la posición del cursor.
- **Rectángulo**: Similar al cuadrado pero solicitando ancho y alto por separado.
- **Círculo**: Se pide el radio y se dibuja el círculo centrado en la posición actual del cursor.

La pantalla del programa simula ser circular, lo que significa que cualquier figura que exceda los límites de la pantalla continuará desde el lado opuesto.

### Fase 2
La segunda fase añade optimizaciones y nuevas características:

- **Nuevas Figuras**: Incluye Línea, Rombo y Hexágono, con opciones para definir la orientación de graficado.
- **Selección de Carácter y Color**: Permite al usuario seleccionar el carácter y el color con el que se dibujarán las figuras.
- **Teclas Especiales**: Introduce teclas rápidas para seleccionar directamente la figura a graficar y ajustar configuraciones como el color o el carácter de dibujo.
- **Guardar y Cargar**: Funcionalidades para guardar el estado actual de la pantalla en un archivo y cargarlo posteriormente.

### Uso del Programa

1. Ejecute el programa desde CodeBlocks.
2. Use las teclas de dirección para mover el cursor en la pantalla.
3. Presione `F12` para acceder al menú de selección de figuras.
4. Siga las instrucciones en pantalla para seleccionar figuras y especificar sus dimensiones y orientaciones.
5. Utilice las teclas especiales para configurar el aspecto de las figuras y interactuar con el sistema de archivos.

### Configuración del Entorno

- **IDE Recomendado**: CodeBlocks con compilador de C++.
- **Sistema Operativo**: Windows, debido a las funciones específicas utilizadas para manejar la consola.

### Contribuciones y Soporte

Para contribuir a este proyecto, por favor envíe un pull request o abra un issue en este repositorio de GitHub. Para soporte, contacte al equipo de desarrollo o al catedrático del curso.

### Autores

- Victor Cancinos - Desarrollo inicial y mantenimiento

### Agradecimientos

- Agradecimientos a la Facultad de Ingeniería de la UMG y al catedrático del curso por su guía y apoyo en el desarrollo de este proyecto educativo.
